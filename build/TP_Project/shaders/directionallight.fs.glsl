#version 330 core

// Entrées
in vec3 vNormal;

// Sortie
out vec4 fFragColor;

// Uniforms
uniform vec3 uKd;         // Coefficient de réflexion diffuse du matériau
uniform vec3 uKs;         // Coefficient de réflexion spéculaire du matériau
uniform float uShininess; // Exposant de brillance du matériau
uniform vec3 uLightDir_vs;     // Direction de la lumière directionnelle en view space
uniform vec3 uLightIntensity;  // Intensité (couleur) de la lumière directionnelle

void main() {
    vec3 lightDir = normalize(uLightDir_vs);
    vec3 normal = normalize(vNormal);
    vec3 viewDir = normalize(-gl_FragCoord.xyz);

    // Calcul de la composante diffuse
    vec3 diffuse = uKd * max(dot(normal, lightDir), 0.0);

    // Calcul de la composante spéculaire
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 specular = uKs * pow(max(dot(reflectDir, viewDir), 0.0), uShininess);

    // Calcul de la couleur finale
    vec3 color = diffuse + specular;

    fFragColor = vec4(vec3(1.0f, 0.0f, 0.0f), 1.0);
}
