#version 330 core

out vec4 FragColor;

uniform vec4 shapeColor;

void main()
{
    FragColor = shapeColor;
}