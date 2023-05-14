#version 330 core

in vec3 vNormal;
in vec3 vColor; // Received color attribute

out vec4 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;
vec3 uAmbientLight= vec3(1.0f,1.0f,1.0f); // Ambient light color
uniform vec3 uColor;


void main()
{
    vec3 lightDir = normalize(uLightDir_vs);
    vec3 normal = normalize(vNormal);
    vec3 viewDir = normalize(-gl_FragCoord.xyz);

    vec3 diffuse = uKd * max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 specular = uKs * pow(max(dot(reflectDir, viewDir), 0.0), uShininess);

    vec3 ambient = uAmbientLight * uKd; // Ambient term

    // Use the color attribute passed from the vertex shader
    vec3 color = uColor * (ambient + diffuse + specular);

    fFragColor = vec4(color, 1.0);
}
