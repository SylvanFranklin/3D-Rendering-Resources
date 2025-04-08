#version 330 core

out vec4 FragColor;
in vec3 pos;
uniform vec2 mouse;

float whitenoise(vec2 p) {
    float random = dot(p, vec2(12.0, 78.0));
    random = sin(random);
    random = random * 43758.5453;
    random = fract(random);
    return random;
}

void main() {
    vec2 uv = gl_FragCoord.xy;
    uv = uv / vec2(1512, 982);
    uv = uv * 8.0;
    vec2 griduv = fract(uv);
    vec2 gridid = floor(uv);

    griduv = smoothstep(0, 1, griduv);

    float botleft = whitenoise(gridid);
    float botright = whitenoise(gridid + vec2(1.0, 0.0));
    float b = mix(botleft, botright, griduv.x);

    float topleft = whitenoise(gridid + vec2(0.0, 1.0));
    float topright = whitenoise(gridid + vec2(1.0, 1.0));
    float t = mix(topleft, topright, griduv.x);

    float valueNoise = mix(b, t, griduv.y);

    vec3 color = vec3(15, 94, 156) / 255.0;
    float water_strength = 0.4;
    float sand_strength = 0.5;
    float forest_strength = 0.8;
    float tiers = 8;

    if (valueNoise < water_strength) {
        color += vec3(floor(tiers * valueNoise / water_strength) / tiers);
    } else if (valueNoise < sand_strength) {
        color = vec3(255, 231, 135) / 255.0;
    } else if (valueNoise < forest_strength) {
        color = vec3(11, 110, 79) / 255.0;
    } else {
        color = vec3(1.0);
    }

    FragColor = vec4(color, 1.0);
}
