#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 color; 

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    // Extract camera forward direction (negative Z axis of the view matrix)
    vec3 forwardDir = normalize(vec3(-view[0][2], -view[1][2], -view[2][2]));

    // Map direction to RGB (x → Red, y → Green, z → Blue)
    color = vec4(0.5 + 0.5 * forwardDir, 1.0);
}

