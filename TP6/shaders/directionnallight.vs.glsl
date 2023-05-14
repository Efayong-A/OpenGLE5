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
