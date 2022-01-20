//#@ vertex
#version 330 core
layout (location = 0) in vec2 aPos;

uniform mat4 model;

void main()
{
    gl_Position = model * vec4(aPos, 0.0, 1.0);
}

//#@ fragment
#version 330 core
out vec4 color;

void main()
{
    color = vec4(0.0, 1.0, 0.0, 1.0);
}