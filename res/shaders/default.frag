#version 330 core

out vec4 FragColor;

uniform vec3 triangleColor;

void main() {
    FragColor = vec4(triangleColor, 1.0);
}
