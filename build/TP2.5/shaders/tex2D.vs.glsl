#version 330 core

in vec2 position;
in vec2 texCoord;

out vec2 fragTexCoord;

uniform mat3 uModelMatrix;
uniform float uTime;

void main() {
    float angle = uTime;
    mat3 rotationMatrix = mat3(
        cos(angle), -sin(angle), 0.0,
        sin(angle), cos(angle), 0.0,
        0.0, 0.0, 1.0
    );

    // Translation matrix to move the triangles to the center of the screen
    mat3 translationMatrix = mat3(
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.5, 0.5, 1.0
    );

    vec2 transformedPosition = (uModelMatrix * translationMatrix * rotationMatrix * vec3(position, 1.0)).xy;
    gl_Position = vec4(transformedPosition, 0.0, 1.0);
    fragTexCoord = texCoord;
}
