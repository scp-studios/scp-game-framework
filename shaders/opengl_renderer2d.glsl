//#@ vertex
#version 330 core
layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 aUV;
layout (location = 2) in uint spriteID;

void main()
{
    gl_Position = vec4(aPosition, 0.0, 1.0);
}

//#@ fragment
#version 330 core
out vec4 color;

void main()
{
    color = vec4(0.0, 1.0, 0.0, 1.0);
}