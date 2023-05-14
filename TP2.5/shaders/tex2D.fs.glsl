#version 330 core

in vec2 vTexCoord;
in vec2 fragTexCoord;

uniform vec3 uColor;
uniform sampler2D uTexture;


out vec4 fragColor;

void main() {
    vec4 texColor = texture(uTexture, fragTexCoord);
    fragColor = vec4(texColor.rgb, 1.0);
}
