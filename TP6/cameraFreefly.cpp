#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Sphere.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glm/gtc/random.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <SDL/SDL.h>

using namespace glimac;

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

    // Create VBO and VAO for the sphere
    GLuint vbo, vao;
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);

    // Bind VAO
    glBindVertexArray(vao);

    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

    // Set attribute pointers for position, normal, and texture coordinates
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));

    // Unbind VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Load shaders and create program
    FilePath applicationPath(argv[0]);
    Program program = loadProgram("/home/semag/Desktop/GLImac-Template/TP6/shaders/directionnallight.vs.glsl", "/home/semag/Desktop/GLImac-Template/TP6/shaders/pointlight.fs.glsl");
    program.use();

    // Get uniform locations
    GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uKdLoc = glGetUniformLocation(program.getGLId(), "uKd");
    GLint uKsLoc = glGetUniformLocation(program.getGLId(), "uKs");
    GLint uShininessLoc = glGetUniformLocation(program.getGLId(), "uShininess");
    GLint uLightDirLoc = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
    GLint uLightIntensityLoc =glGetUniformLocation(program.getGLId(), "uLightIntensity");
    // Set material properties
    glm::vec3 kd(0.8f, 0.8f, 0.8f);
    glm::vec3 ks(1.0f, 1.0f, 1.0f);
    float shininess = 32.0f;

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
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
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
            else if(!windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)){
                previousMousePos =windowManager.getMousePosition();
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
        glm::mat4 mvMatrix = freeflyCamera.getViewMatrix() * glm::mat4(1.0f);
        glm::mat4 mvpMatrix = projMatrix * mvMatrix;
        glm::mat4 normalMatrix = glm::transpose(glm::inverse(mvMatrix));

        // Set uniform values
        glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
        glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(mvMatrix));
        glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
        glUniform3fv(uKdLoc, 1, glm::value_ptr(kd));
        glUniform3fv(uKsLoc, 1, glm::value_ptr(ks));
        glUniform1f(uShininessLoc, shininess);
        glUniform3fv(uLightDirLoc, 1, glm::value_ptr(lightDir));
        glUniform3fv(uLightIntensityLoc, 1, glm::value_ptr(lightIntensity));

        // Bind VAO
        glBindVertexArray(vao);

        // Draw the sphere
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        // Unbind VAO
        glBindVertexArray(0);

        // Swap buffers
        windowManager.swapBuffers();
    }

    // Clean up
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return 0;
}
