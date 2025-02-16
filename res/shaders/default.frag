#version 330 core

out vec4 FragColor;
in vec3 pos;
uniform vec2 mouse;

vec3 norm_distance_from_center(vec3 pos) {
    vec2 npos = vec2(pos.x, pos.y);
    if (distance(mouse, npos) < max(abs(sinh(pos.x)), abs(tanh(pos.y)))) {
        return vec3(distance(pos, vec3(mouse, 0)));
    } else {
        return vec3(0.0);
    }
}

void main() {
    FragColor = vec4(norm_distance_from_center(pos), 1.0);
}
