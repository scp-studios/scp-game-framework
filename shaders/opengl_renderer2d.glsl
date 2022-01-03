//#@ vertex
#version 430 core
layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 aUV;
layout (location = 2) in vec4 aColor;
layout (location = 3) in float aTexture;

out vec4 color;
out float myTexture;
out vec2 uv;

void main()
{
    gl_Position = vec4(aPosition, 0.0, 1.0);
    color = aColor;
    myTexture = aTexture;
    uv = aUV;
}

//#@ fragment
#version 430 core
out vec4 outColor;

uniform sampler2D textures[32];

in vec4 color;
in float myTexture;
in vec2 uv;

void main()
{
    int textureIndex = int(myTexture);
    vec4 textureColor = texture(textures[textureIndex], uv);
    
    float finalAlpha = textureColor.w;
    
    if (textureColor.w == 1.0)
    {
        finalAlpha = color.w;
    }
    
    //outColor = vec4(1.0, 0.0, 0.0, textureColor.w) + color;
    outColor = vec4(vec3(textureColor) + vec3(color), finalAlpha);
}