#version 330 core

in vec2 vPosition;

out vec4 fragColor;

vec2 complexSqr(vec2 z) {
    return vec2(z.x * z.x - z.y * z.y, 2.0 * z.x * z.y);
}

void main() {
    const int Nmax = 100;
    vec2 c = vPosition;
    vec2 z = vec2(0.0);
    int j = 0;

    for (int i = 0; i < Nmax; i++) {
        z = complexSqr(z) + c;

        if (length(z) > 2.0) {
            j = i;
            break;
        }
    }

    fragColor = vec4(vec3(float(j) / float(Nmax)), 1.0);
}
