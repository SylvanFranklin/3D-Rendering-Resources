#version 330 core

out vec4 FragColor;
in vec3 pos;
uniform vec2 mousePos;

vec3 get_color(vec3 pos) {
    vec3 center = vec3(mousePos, 0.0);
    return abs(center - pos);
}

void main() {
    FragColor = vec4(get_color(pos), 1.0);
}
