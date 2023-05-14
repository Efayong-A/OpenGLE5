#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace glimac {

class FreeflyCamera {
private:
    glm::vec3 m_Position;
    float m_fPhi;
    float m_fTheta;
    glm::vec3 m_FrontVector;
    glm::vec3 m_LeftVector;
    glm::vec3 m_UpVector;

    void computeDirectionVectors() {
        m_FrontVector = glm::vec3(
            sin(m_fPhi) * cos(m_fTheta),
            sin(m_fTheta),
            cos(m_fPhi) * cos(m_fTheta)
        );

        m_LeftVector = glm::vec3(
            sin(m_fTheta - glm::half_pi<float>()),
            0.f,
            cos(m_fTheta - glm::half_pi<float>())
        );

        m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
    }

public:
    FreeflyCamera()
        : m_Position(glm::vec3(0.f, 0.f, 0.f)), m_fPhi(glm::pi<float>()), m_fTheta(0.f) {
        computeDirectionVectors();
    }

    glm::mat4 getViewMatrix() const {
        return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
    }

    void moveLeft(float t) {
        m_Position += t * m_LeftVector;
    }

    void moveFront(float t) {
        m_Position += t * m_FrontVector;
    }

    void rotateLeft(float degrees) {
        m_fPhi += glm::radians(degrees);
        computeDirectionVectors();
    }

    void rotateUp(float degrees) {
        m_fTheta += glm::radians(degrees);
        computeDirectionVectors();
    }
};

} 