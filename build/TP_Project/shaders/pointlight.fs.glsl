#version 330 core

// Entrées
in vec3 vPosition_vs;
in vec3 vNormal;

// Sortie
out vec4 fFragColor;

// Uniforms
uniform vec3 uKd;         // Coefficient de réflexion diffuse du matériau
uniform vec3 uKs;         // Coefficient de réflexion spéculaire du matériau
uniform float uShininess; // Exposant de brillance du matériau
uniform vec3 uLightPos_vs;     // Position de la lumière ponctuelle en view space
uniform vec3 uLightIntensity;  // Intensité (couleur) de la lumière ponctuelle

void main() {
    vec3 lightDir = normalize(uLightPos_vs - vPosition_vs);
    vec3 normal = normalize(vNormal);
    vec3 viewDir = normalize(-vPosition_vs);

    // Calcul de la distance entre le fragment et la lumière ponctuelle
    float distance = length(uLightPos_vs - vPosition_vs);

    // Calcul de l'atténuation quadratique
    float attenuation = 1.0 / (distance * distance);

    // Calcul de la composante diffuse
    vec3 diffuse = uKd * max(dot(normal, lightDir), 0.0) * attenuation;

    // Calcul de la composante spéculaire
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 specular = uKs * pow(max(dot(reflectDir, viewDir), 0.0), uShininess) * attenuation;

    // Calcul de la couleur finale
    vec3 color = diffuse + specular;

    fFragColor = vec4(color, 1.0);
}