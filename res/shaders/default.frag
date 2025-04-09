#version 330 core

out vec4 FragColor;
in vec3 pos;
uniform vec2 mouse;

uniform vec4 influences;


float whitenoise(vec2 p) {
    float random = dot(p, vec2(12.0, 78.0));
    random = sin(random);
    random = random * 43758.5453;
    random = fract(random);
    return random;
}
float whitenoise2(vec2 p) {
    float random = dot(p, vec2(16.0, 78.0));
    random = cos(random);
    random = random * 887589.5453;
    random = fract(random);
    return random;
}

float octive_noise(float octives) {
    vec2 uv = gl_FragCoord.xy;
    uv = uv / vec2(1512, 982);
    uv = uv * octives;
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

    return valueNoise;
}

void main() {
    vec3 lightWater = vec3(0, 63, 178) / 255.0; // #003FB2
    vec3 deepWater = vec3(15, 81, 198) / 255.0; // #0F51C6
    vec3 lightSand = vec3(192, 181, 131) / 255.0; // #C0B583
    vec3 darkSand = vec3(166, 150, 99) / 255.0; // #A69663
    vec3 darkForest = vec3(58, 97, 19) / 255.0; // #3A6113
    vec3 forest = vec3(61, 98, 22) / 255.0; // #3D6216
    vec3 lightForest = vec3(121, 157, 81) / 255.0; // #799D51
    vec3 darkRock = vec3(141, 140, 122) / 255.0; // #8D8C7A
    vec3 lightRock = vec3(160, 164, 145) / 255.0; // #A0A491
    vec3 snow = vec3(235, 235, 235) / 255.0; // #EBEBEB

    vec3 color = vec3(0, 62, 178) / 255.0;
    float water_strength = 0.55;
    float sand_strength = 0.65;
    float dirt_strength = 0.69;
    float forest_strength = 0.75;
    float rock_strength = 0.95;
    vec2 uv = gl_FragCoord.xy;

    float valueNoise = octive_noise(8.0) * influences[0];
    valueNoise += octive_noise(16.0) * influences[1];
    valueNoise += octive_noise(32.0) * influences[2];
    valueNoise += octive_noise(64.0) * influences[3];

    if (valueNoise < 0.35) {
        color = lightWater;
    } else if (valueNoise < 0.4) {
        color = deepWater;
    } else if (valueNoise < 0.43) {
        color = lightSand;
    } else if (valueNoise < 0.5) {
        color = darkSand;
    } else if (valueNoise < 0.6) {
        color = darkForest;
    } else if (valueNoise < 0.68) {
        color = lightForest;
    } else if (valueNoise < 0.8) {
        color = darkRock;
    } else if (valueNoise < 0.9) {
        color = lightRock;
    } else {
        color = snow;
    }

    FragColor = vec4(color, 1);
}
