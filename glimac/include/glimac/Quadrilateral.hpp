#pragma once

#include <vector>

#include "common.hpp"

namespace glimac {

class Quadrilateral {
    // Alloue et construit les données (implémentation dans le .cpp)
    void build(GLfloat width, GLfloat height);

public:
    // Constructeur: alloue le tableau de données et construit les attributs des vertex
    Quadrilateral(GLfloat width, GLfloat height) :
        m_nVertexCount(0) {
        build(width, height); // Construction (voir le .cpp)
    }

    // Renvoie le pointeur vers les données
    const ShapeVertex* getDataPointer() const {
        return &m_Vertices[0];
    }

    // Renvoie le nombre de vertex
    GLsizei getVertexCount() const {
        return m_nVertexCount;
    }

private:
    std::vector<ShapeVertex> m_Vertices;
    GLsizei m_nVertexCount; // Nombre de sommets
};

} // namespace glimac
