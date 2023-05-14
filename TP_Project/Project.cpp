#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Sphere.hpp>
#include <glimac/Quadrilateral.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <SDL/SDL.h>
#include <vector>
#include <fstream> 
#include <sstream> 

using namespace glimac;

struct Object {
    glm::mat4 modelMatrix;
    glm::vec3 kd;
    glm::vec3 ks;
    float shininess;
    GLuint vao;
    GLsizei vertexCount;
    glm::vec3 position;      // Position de l'objet
    glm::vec3 scale;         // Échelle de l'objet
    glm::vec3 rotationAxis;  // Axe de rotation
    float rotationAngle;     // Angle de rotation

    void updateModelMatrix() {
        // Mise à jour de la matrice de modèle en fonction des attributs de l'objet
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngle), rotationAxis);
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
        modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
    }
};


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * INITIALIZATION CODE
     *********************************/

    // Create a sphere
    Sphere sphere(1, 32, 16);

    // Create a quadrilateral
    Quadrilateral quadrilateral(2.0f, 2.0f); // Set the width and height of the quadrilateral

    // Create VBO and VAO for the sphere
    GLuint sphereVBO, sphereVAO;
    glGenBuffers(1, &sphereVBO);
    glGenVertexArrays(1, &sphereVAO);

    // Bind sphere VAO
    glBindVertexArray(sphereVAO);

    // Bind sphere VBO
    glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

    // Set attribute pointers for sphere position, normal, and texture coordinates
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));

    // Unbind sphere VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Create VBO and VAO for the quadrilateral
    GLuint quadVBO, quadVAO;
    glGenBuffers(1, &quadVBO);
    glGenVertexArrays(1, &quadVAO);

    // Bind quadrilateral VAO
    glBindVertexArray(quadVAO);

    // Bind quadrilateral VBO
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, quadrilateral.getVertexCount() * sizeof(ShapeVertex), quadrilateral.getDataPointer(), GL_STATIC_DRAW);

    // Set attribute pointers for quadrilateral position, normal, and texture coordinates
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));

    // Unbind quadrilateral VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Load shaders and create program
    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "/shaders/directionnallight.vs.glsl", applicationPath.dirPath() + "/shaders/directionallight.fs.glsl");
    program.use();

    // Get uniform locations
    GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uKdLoc = glGetUniformLocation(program.getGLId(), "uKd");
    GLint uKsLoc = glGetUniformLocation(program.getGLId(), "uKs");
    GLint uShininessLoc = glGetUniformLocation(program.getGLId(), "uShininess");
    GLint uLightDirLoc = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
    GLint uLightIntensityLoc = glGetUniformLocation(program.getGLId(), "uLightIntensity");

    // Declaration du vecteur objects
    std::vector<Object> objects;

    // Add sphere object to the array
    Object object1;
    object1.modelMatrix = glm::mat4(1.0f);
    object1.position = glm::vec3(1.0f, 0.0f, 0.0f); // Position de la sphère
    object1.scale = glm::vec3(1.0f); // Échelle de la sphère
    object1.rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f); // Axe de rotation
    object1.rotationAngle = 45.0f; // Angle de rotation en degrés
    object1.kd = glm::vec3(0.8f, 0.8f, 0.8f);
    object1.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    object1.shininess = 32.0f;
    object1.vao = sphereVAO;
    object1.vertexCount = sphere.getVertexCount();
    object1.updateModelMatrix(); // Mettre à jour la matrice de modèle
    objects.push_back(object1);

    // Add quadrilateral object to the array
    Object object2;
    object2.modelMatrix = glm::mat4(1.0f);
    object2.position = glm::vec3(0.0f, 0.0f, 0.0f); // Position du quadrilatère
    object2.scale = glm::vec3(1.0f); // Échelle du quadrilatère
    object2.rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f); // Axe de rotation
    object2.rotationAngle = 60.0f; // Angle de rotation en degrés
    object2.kd = glm::vec3(0.0f, 0.0f, 1.0f);
    object2.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    object2.shininess = 64.0f;
    object2.vao = quadVAO;
    object2.vertexCount = quadrilateral.getVertexCount();
    object2.updateModelMatrix(); // Mettre à jour la matrice de modèle
    objects.push_back(object2);




    // Set light properties
    glm::vec3 lightDir(1.0f, -0.5f, -1.0f);
    glm::vec3 lightIntensity(1.0f, 1.0f, 1.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Freefly camera
    FreeflyCamera freeflyCamera;
    float sensitivity = 0.1f;
    glm::ivec2 previousMousePos(0, 0);

    // Application loop:
    bool done = false;
    while (!done) {
        // Event loop:
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if (e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            else if (e.type == SDL_MOUSEMOTION && windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) {
                // Update camera rotation based on mouse movement
                glm::ivec2 currentMousePos = windowManager.getMousePosition();
                glm::ivec2 deltaMousePos = currentMousePos - previousMousePos;
                freeflyCamera.rotateLeft(-deltaMousePos.x * sensitivity);
                freeflyCamera.rotateUp(-deltaMousePos.y * sensitivity);

                previousMousePos = currentMousePos;
            }
            else if (!windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) {
                previousMousePos = windowManager.getMousePosition();
            }
            else if (e.type == SDL_KEYDOWN) {
                if (windowManager.isKeyPressed(SDLK_z)) {
                    freeflyCamera.moveFront(1.f);
                }
                if (windowManager.isKeyPressed(SDLK_s)) {
                    freeflyCamera.moveFront(-1.f);
                }
                if (windowManager.isKeyPressed(SDLK_q)) {
                    freeflyCamera.moveLeft(1.f);
                }
                if (windowManager.isKeyPressed(SDLK_d)) {
                    freeflyCamera.moveLeft(-1.f);
                }
            }
        }

        // Clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set the camera matrices
        glm::mat4 projMatrix = glm::perspective(glm::radians(70.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glm::mat4 viewMatrix = freeflyCamera.getViewMatrix();

        // Render each object in the array
        for (auto& object : objects) {
            // Mettre à jour la matrice de modèle
            //object.updateModelMatrix();

            glm::mat4 mvpMatrix = projMatrix * viewMatrix * object.modelMatrix;
            glm::mat4 normalMatrix = glm::transpose(glm::inverse(viewMatrix * object.modelMatrix));

            // Set uniform values
            glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
            glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix * object.modelMatrix));
            glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
            glUniform3fv(uKdLoc, 1, glm::value_ptr(object.kd));
            glUniform3fv(uKsLoc, 1, glm::value_ptr(object.ks));
            glUniform1f(uShininessLoc, object.shininess);
            glUniform3fv(uLightDirLoc, 1, glm::value_ptr(lightDir));
            glUniform3fv(uLightIntensityLoc, 1, glm::value_ptr(lightIntensity));

            // Bind VAO
            glBindVertexArray(object.vao);

            // Draw the object
            glDrawArrays(GL_TRIANGLES, 0, object.vertexCount);

            // Unbind VAO
            glBindVertexArray(0);
        }


        // Swap buffers
        windowManager.swapBuffers();
    }

    // Clean up
    glDeleteBuffers(1, &sphereVBO);
    glDeleteVertexArrays(1, &sphereVAO);
    glDeleteBuffers(1, &quadVBO);
    glDeleteVertexArrays(1, &quadVAO);

    return 0;
}

