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
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotationAxis;
    float rotationAngle;
    glm::vec3 color;

    void updateModelMatrix() {
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngle), rotationAxis);
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
        modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
    }
};


int main(int argc, char** argv) {
    SDLWindowManager windowManager(800, 600, "GLImac");

    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    Sphere sphere(1, 32, 16);
    Quadrilateral quadrilateral(2.0f, 2.0f);

    GLuint sphereVBO, sphereVAO;
    glGenBuffers(1, &sphereVBO);
    glGenVertexArrays(1, &sphereVAO);

    glBindVertexArray(sphereVAO);

    glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount() * sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint quadVBO, quadVAO;
    glGenBuffers(1, &quadVBO);
    glGenVertexArrays(1, &quadVAO);

    glBindVertexArray(quadVAO);

    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, quadrilateral.getVertexCount() * sizeof(ShapeVertex), quadrilateral.getDataPointer(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "/shaders/directionnallight.vs.glsl", applicationPath.dirPath() + "/shaders/directionallight.fs.glsl");
    program.use();

    GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uKdLoc = glGetUniformLocation(program.getGLId(), "uKd");
    GLint uKsLoc = glGetUniformLocation(program.getGLId(), "uKs");
    GLint uShininessLoc = glGetUniformLocation(program.getGLId(), "uShininess");
    GLint uLightDirLoc = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
    GLint uLightIntensityLoc = glGetUniformLocation(program.getGLId(), "uLightIntensity");
    GLint uColor = glGetUniformLocation(program.getGLId(), "uColor");

    std::vector<Object> objects;

    glm::vec3 gris = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 jaune = glm::vec3(1.0f, 1.0f, 0.1f);
    glm::vec3 rouge = glm::vec3(1.0f, 0.5f, 0.0f);

    Object contrepoids;
    contrepoids.modelMatrix = glm::mat4(1.0f);
    contrepoids.position = glm::vec3(-1.0f, 0.0f, -10.0f);
    contrepoids.scale = glm::vec3(1.0f);
    contrepoids.rotationAxis = glm::vec3(0.0f, 0.0f,1.0f);
    contrepoids.rotationAngle = 45.0f;
    contrepoids.kd = glm::vec3(0.5f, 0.5f, 0.5f);
    contrepoids.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    contrepoids.color = jaune;
    contrepoids.shininess = 64.0f;
    contrepoids.vao = quadVAO;
    contrepoids.vertexCount = quadrilateral.getVertexCount();
    contrepoids.updateModelMatrix();
    objects.push_back(contrepoids);

    Object manivelle;
    manivelle.modelMatrix = glm::mat4(1.0f);
    manivelle.position = glm::vec3(1.0f, 2.0f, -10.1f);
    manivelle.scale = glm::vec3(3.0f,0.7f,1.0f);
    manivelle.rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
    manivelle.rotationAngle = 45.0f;
    manivelle.kd = glm::vec3(0.5f, 0.5f, 0.5f);
    manivelle.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    manivelle.color = jaune;
    manivelle.shininess = 64.0f;
    manivelle.vao = quadVAO;
    manivelle.vertexCount = quadrilateral.getVertexCount();
    manivelle.updateModelMatrix();
    objects.push_back(manivelle);

    Object bielle;
    bielle.modelMatrix = glm::mat4(1.0f);
    bielle.position = glm::vec3(5.9f, 2.2f, -10.0f);
    bielle.scale = glm::vec3(4.0f,0.2f,1.0f);
    bielle.rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
    bielle.rotationAngle = -25.0f;
    bielle.kd = glm::vec3(0.5f, 0.3f, 0.5f);
    bielle.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    bielle.color = gris;
    bielle.shininess = 64.0f;
    bielle.vao = quadVAO;
    bielle.vertexCount = quadrilateral.getVertexCount();
    bielle.updateModelMatrix();
    objects.push_back(bielle);

    Object rail;
    rail.modelMatrix = glm::mat4(1.0f);
    rail.position = glm::vec3(4.5f, 0.7f, -10.2f);
    rail.scale = glm::vec3(5.8f,0.5f,1.0f);
    rail.rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
    rail.rotationAngle = 0.0f;
    rail.kd = glm::vec3(0.5f, 0.5f, 0.5f);
    rail.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    rail.color = rouge;
    rail.shininess = 64.0f;
    rail.vao = quadVAO;
    rail.vertexCount = quadrilateral.getVertexCount();
    rail.updateModelMatrix();
    objects.push_back(rail);

    Object pistonhead;
    pistonhead.modelMatrix = glm::mat4(1.0f);
    pistonhead.position = glm::vec3(9.4f, 0.6f, -9.99f);
    pistonhead.scale = glm::vec3(0.5f,0.5f,0.3f);
    pistonhead.rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
    pistonhead.rotationAngle = 0.0f;
    pistonhead.kd = glm::vec3(0.5f, 0.5f, 0.5f);
    pistonhead.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    pistonhead.color = jaune;
    pistonhead.shininess = 64.0f;
    pistonhead.vao = quadVAO;
    pistonhead.vertexCount = quadrilateral.getVertexCount();
    pistonhead.updateModelMatrix();
    objects.push_back(pistonhead);

    Object sol;
    sol.modelMatrix = glm::mat4(1.0f);
    sol.position = glm::vec3(0.0f, -1.5f, 0.0f);
    sol.scale = glm::vec3(20.0f);
    sol.rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
    sol.rotationAngle = 90.0f;
    sol.kd = glm::vec3(0.5f, 0.5f, 0.5f);
    sol.ks = glm::vec3(1.0f, 1.0f, 1.0f);
    sol.color = gris;
    sol.shininess = 64.0f;
    sol.vao = quadVAO;
    sol.vertexCount = quadrilateral.getVertexCount();
    sol.updateModelMatrix();
    objects.push_back(sol);

    glm::vec3 lightDir(1.0f, -0.5f, -1.0f);
    glm::vec3 lightIntensity(1.0f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    FreeflyCamera freeflyCamera;
    float sensitivity = 0.1f;
    glm::ivec2 previousMousePos(0, 0);

    bool done = false;
    while (!done) {
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if (e.type == SDL_QUIT) {
                done = true;
            }
            else if (e.type == SDL_MOUSEMOTION && windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) {
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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 projMatrix = glm::perspective(glm::radians(70.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glm::mat4 viewMatrix = freeflyCamera.getViewMatrix();

        for (auto& object : objects) {
            glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(projMatrix * viewMatrix * object.modelMatrix));
            glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix * object.modelMatrix));
            glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(viewMatrix * object.modelMatrix))));
            glUniform3fv(uKdLoc, 1, glm::value_ptr(object.kd));
            glUniform3fv(uKsLoc, 1, glm::value_ptr(object.ks));
            glUniform1f(uShininessLoc, object.shininess);
            glUniform3fv(uLightDirLoc, 1, glm::value_ptr(lightDir));
            glUniform3fv(uLightIntensityLoc, 1, glm::value_ptr(lightIntensity));
            glUniform3fv(uColor, 1, glm::value_ptr(object.color));
                    glBindVertexArray(object.vao);

            glDrawArrays(GL_TRIANGLES, 0, object.vertexCount);

            glBindVertexArray(0);
        }

        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &sphereVBO);
    glDeleteVertexArrays(1, &sphereVAO);
    glDeleteBuffers(1, &quadVBO);
    glDeleteVertexArrays(1, &quadVAO);

    return 0;
}

