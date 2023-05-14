#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/Quadrilateral.hpp"

namespace glimac {

void Quadrilateral::build(GLfloat width, GLfloat height) {
    // Construit un quadrilatère avec les sommets (-width/2, -height/2), (-width/2, height/2),
    // (width/2, height/2), (width/2, -height/2)

    std::vector<ShapeVertex> data;

    ShapeVertex vertex1;
    vertex1.position = glm::vec3(-width/2, -height/2, 0.f);
    vertex1.normal = glm::vec3(0.f, 0.f, 1.f);
    vertex1.texCoords = glm::vec2(0.f, 0.f);
    data.push_back(vertex1);

    ShapeVertex vertex2;
    vertex2.position = glm::vec3(-width/2, height/2, 0.f);
    vertex2.normal = glm::vec3(0.f, 0.f, 1.f);
    vertex2.texCoords = glm::vec2(0.f, 1.f);
    data.push_back(vertex2);

    ShapeVertex vertex3;
    vertex3.position = glm::vec3(width/2, height/2, 0.f);
    vertex3.normal = glm::vec3(0.f, 0.f, 1.f);
    vertex3.texCoords = glm::vec2(1.f, 1.f);
    data.push_back(vertex3);

    ShapeVertex vertex4;
    vertex2.position = glm::vec3(-width/2, -height/2, 0.f);
    vertex2.normal = glm::vec3(0.f, 0.f, 1.f);
    vertex2.texCoords = glm::vec2(0.f, 1.f);
    data.push_back(vertex2);

    ShapeVertex vertex5;
    vertex3.position = glm::vec3(width/2, height/2, 0.f);
    vertex3.normal = glm::vec3(0.f, 0.f, 1.f);
    vertex3.texCoords = glm::vec2(1.f, 1.f);
    data.push_back(vertex3);

    ShapeVertex vertex6;
    vertex4.position = glm::vec3(width/2, -height/2, 0.f);
    vertex4.normal = glm::vec3(0.f, 0.f, 1.f);
    vertex4.texCoords = glm::vec2(1.f, 0.f);
    data.push_back(vertex4);

    m_Vertices = std::move(data);
    m_nVertexCount = 6;
}

}
