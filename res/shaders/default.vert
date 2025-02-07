#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 color; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec4 mouseFactor;

void main() {
    gl_Position = vec4(aPos, 1.0);
    color = vec4(aPos, 0) * view * projection * mouseFactor;
}
