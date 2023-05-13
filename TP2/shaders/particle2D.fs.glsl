#version 330 core

in vec3 vFragColor;
in vec2 vPosition;

out vec4 fragColor;

float alpha=1;
float beta=80;

void main() {
    float distanceToCenter = distance(vPosition, vec2(0.0, 0.0)); 
    float attenuation = alpha * exp(-beta * distanceToCenter * distanceToCenter); 
    vec3 finalColor = vFragColor * attenuation;

    fragColor = vec4(finalColor, 1.0);
}
