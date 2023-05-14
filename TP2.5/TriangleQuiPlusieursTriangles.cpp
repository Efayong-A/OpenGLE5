#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>

using namespace glimac;

struct Vertex2DUV {
    glm::vec2 position;
    glm::vec2 texCoord;

    Vertex2DUV() {}
    Vertex2DUV(glm::vec2 position, glm::vec2 texCoord) : position(position), texCoord(texCoord) {}
};

glm::mat3 translate(float tx, float ty) {
    return glm::mat3(
        1.0f, 0.0f, tx,
        0.0f, 1.0f, ty,
        0.0f, 0.0f, 1.0f
    );
}

glm::mat3 scale(float sx, float sy) {
    return glm::mat3(
        sx, 0.0f, 0.0f,
        0.0f, sy, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

glm::mat3 rotate(float angle) {
    float rad = glm::radians(angle);
    float c = glm::cos(rad);
    float s = glm::sin(rad);

    return glm::mat3(
        c, -s, 0.0f,
        s, c, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    FilePath vertexShaderPath(argv[1]);
    FilePath fragmentShaderPath(argv[2]);

    Program program = loadProgram(applicationPath.dirPath() + "/shaders/" + vertexShaderPath,
                                  applicationPath.dirPath() + "/shaders/" + fragmentShaderPath);
    program.use();

    // Get the location of the uniform variables
    GLint uModelMatrixLocation = glGetUniformLocation(program.getGLId(), "uModelMatrix");
    GLint uColor = glGetUniformLocation(program.getGLId(), "uColor");
    GLint uTimeLocation = glGetUniformLocation(program.getGLId(), "uTime");



    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    glm::vec3 colors[] = {
        glm::vec3(1.0f, 0.0f, 0.0f),   // Red
        glm::vec3(0.0f, 1.0f, 0.0f),   // Green
        glm::vec3(0.0f, 0.0f, 1.0f),   // Blue
        glm::vec3(1.0f, 1.0f, 0.0f)    // Yellow
    };
    
    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    std::vector<Vertex2DUV> vertices;
    vertices.push_back(Vertex2DUV(glm::vec2(-0.5f, -0.5f), glm::vec2(0.f, 0.f)));
    vertices.push_back(Vertex2DUV(glm::vec2(0.5f, -0.5f), glm::vec2(1.f, 0.f)));
    vertices.push_back(Vertex2DUV(glm::vec2(0.0f, 0.5f), glm::vec2(0.5f, 1.f)));

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex2DUV), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_TEXCOORD = 1;

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, position));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, texCoord));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Application loop:
    bool done = false;
    float time = 0.0f; // Initial value of time

    while (!done) {
        // Event loop:
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if (e.type == SDL_QUIT) {
                done = true;
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        time += 1.0f;

        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Loop through each quadrant and draw a rotating triangle
        for (int i = 0; i < 4; i++) {
            // Calculate the translation vector for the current quadrant
            float tx = (i % 2 == 0) ? -10 : 10;
            float ty = (i < 2) ? -10 : 10;

            // Calculate the scale factor for the current quadrant
            float scaleFactor = 0.5f;

            // Create the model matrix
            glm::mat3 modelMatrix = translate(tx, ty) * scale(scaleFactor, scaleFactor) * rotate(time * (i % 2 == 0 ? 1.0f : -1.0f));

            // Pass the model matrix to the shader
            glUniformMatrix3fv(uModelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
            glUniform3fv(uColor, 1, glm::value_ptr(colors[i]));
            glUniform1f(uTimeLocation, time/10);


            // Draw the triangle
            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glBindVertexArray(0);
        }

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}
