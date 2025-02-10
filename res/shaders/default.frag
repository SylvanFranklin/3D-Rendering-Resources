#version 330 core

out vec4 FragColor;
uniform vec3 triangleColor;
in vec4 color;

void main() {
    FragColor = color * vec4(1.2, 1.0, 0.8, 1.0); // Slight color shift for variety
} 

