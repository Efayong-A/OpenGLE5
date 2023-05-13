#version 330 core

in vec3 vFragColor;
in vec2 vPosition;

out vec4 fragColor;

float pattern1(vec2 position) {
    return length(fract(5.0 * position));
}

float pattern2(vec2 position) {
    return length(abs(fract(5.0 * position) * 2.0 - 1.0));
}

float pattern3(vec2 position) {
    return mod(floor(10.0 * position.x) + floor(10.0 * position.y), 2.0);
}

float pattern4(vec2 position) {
    return smoothstep(0.3, 0.32, length(fract(5.0 * position) - 0.5));
}

float pattern5(vec2 position) {
    return smoothstep(0.4, 0.5, max(abs(fract(8.0 * position.x - 0.5 * mod(floor(8.0 * position.y), 2.0)) - 0.5), abs(fract(8.0 * position.y) - 0.5)));
}

void main() {
    vec3 finalColor = vFragColor;

    // Appliquer la formule de votre choix
    float patternValue = pattern3(vPosition);
    finalColor *= patternValue;

    fragColor = vec4(finalColor, 1.0);
}
