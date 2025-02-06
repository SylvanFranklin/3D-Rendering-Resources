#version 330 core

in vec3 vertexColor;
out vec4 FragColor;

uniform vec3 triangleColor;

void main() {
    FragColor = vec4(triangleColor, 1.0);
}
