#version 330 core

out vec4 FragColor;
in vec3 pos;
uniform vec2 mousePos;

vec3 norm_distance_from_center(vec3 pos) {
    vec3 center = vec3(0.0);
    vec3 dist = abs(center - pos);
    return dist;
}

void main() {
    FragColor = vec4(norm_distance_from_center(pos), 1.0);
}
