#version 330 core

in vec3 fragPosition;
in vec3 fragNormal;
in vec2 fragTexCoords;

out vec4 outColor;

void main()
{
    vec3 normalizedNormal = normalize(fragNormal);
    outColor = vec4(normalizedNormal, 1.0);
}
