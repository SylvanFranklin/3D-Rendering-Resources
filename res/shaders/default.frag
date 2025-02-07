#version 330 core

out vec4 FragColor;
uniform vec3 triangleColor;
in vec4 color;

void main() {
    FragColor = color;
} 
