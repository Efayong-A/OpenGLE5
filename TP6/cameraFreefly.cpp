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
#include <glimac/TrackballCamera.hpp>
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
    Program program = loadProgram(applicationPath.dirPath() + "shaders/globes.vs.glsl", applicationPath.dirPath() + "shaders/globes.fs.glsl");
    program.use();

    // Get uniform locations
    GLint uMVPMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrixLoc = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrixLoc = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Matrices
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f / 600.f, 0.1f, 100.f);

    // Generate 32 random rotation axes for the moons
    std::vector<glm::vec3> rotationAxes;
    for (int i = 0; i < 32; ++i) {
        rotationAxes.push_back(glm::sphericalRand(1.f));
    }
    // Trackball camera
    TrackballCamera trackballCamera;
    float sens = 0.8f;
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
                trackballCamera.rotateUp(-deltaMousePos.y * sens);
                trackballCamera.rotateLeft(-deltaMousePos.x * sens);

                std::cout << "Mouse Delta: x=" << deltaMousePos.x << ", y=" << deltaMousePos.y << std::endl;

                previousMousePos = currentMousePos;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && (e.button.button == SDL_BUTTON_WHEELUP || e.button.button == SDL_BUTTON_WHEELDOWN)) {
                // Update camera distance based on mouse wheel scrolling
                float delta = 0.f;
                if (e.button.button == SDL_BUTTON_WHEELUP) {
                    delta = 1.f;
                }
                else if (e.button.button == SDL_BUTTON_WHEELDOWN) {
                    delta = -1.f;
                }
                trackballCamera.moveFront(delta * 0.1f);
            }
        }

        /*********************************
         * RENDERING CODE
         *********************************/

        // Clear color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update camera view matrix
        glm::mat4 ViewMatrix = trackballCamera.getViewMatrix();

        // Iterate through the rotation axes and draw the moons
        for (int i = 0; i < 32; ++i) {
            glm::mat4 ModelMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -5.f));
            ModelMatrix = glm::rotate(ModelMatrix, windowManager.getTime(), rotationAxes[i]);
            ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-2.f, 0.f, 0.f));
            ModelMatrix = glm::scale(ModelMatrix, glm::vec3(0.2f, 0.2f, 0.2f));

            glm::mat4 MVMatrix = ViewMatrix * ModelMatrix;

            // Send matrices to the GPU
            glUniformMatrix4fv(uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
            glUniformMatrix4fv(uMVMatrixLoc, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));

            // Bind VAO
            glBindVertexArray(vao);

            // Draw the sphere
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

            // Unbind VAO
            glBindVertexArray(0);
        }

        // Update the display
        windowManager.swapBuffers();
    }

    // Delete VAO and VBO
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}