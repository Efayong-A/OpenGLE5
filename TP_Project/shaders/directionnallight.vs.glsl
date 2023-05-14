#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec3 vNormal; // Pass the normal to the fragment shader

void main()
{
    gl_Position = uMVPMatrix * vec4(aPosition, 1.0);
    vNormal = -mat3(uNormalMatrix) * aNormal; // Assign the normal value
}

mat3 translate(float tx, float ty) {
    return mat3(
        vec3(1, 0, tx),
        vec3(0, 1, ty),
        vec3(0, 0, 1)
    );
};

mat3 scale(float sx, float sy) {
    return mat3(
        vec3(sx, 0, 0),
        vec3(0, sy, 0),
        vec3(0, 0, 1)
    );
};

mat3 rotate(float a) {
    float rad = radians(a);
    float c = cos(rad);
    float s = sin(rad);

    return mat3(
        vec3(c, -s, 0),
        vec3(s, c, 0),
        vec3(0, 0, 1)
    );
};