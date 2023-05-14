#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace glimac {

class TrackballCamera {
private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;

public:
    TrackballCamera() : m_fDistance(5.f), m_fAngleX(0.f), m_fAngleY(0.f) {}

    void moveFront(float delta) {
        m_fDistance += delta;
    }

    void rotateLeft(float degrees) {
        m_fAngleY += glm::radians(degrees);
    }

    void rotateUp(float degrees) {
        m_fAngleX += glm::radians(degrees);
    }

    glm::mat4 getViewMatrix() const {
        glm::mat4 viewMatrix(1.f);
        viewMatrix = glm::translate(viewMatrix, glm::vec3(0.f, 0.f, -m_fDistance));
        viewMatrix = glm::rotate(viewMatrix, m_fAngleX, glm::vec3(1.f, 0.f, 0.f));
        viewMatrix = glm::rotate(viewMatrix, m_fAngleY, glm::vec3(0.f, 1.f, 0.f));
        return viewMatrix;
    }
};

}
