#include <stb_image.h>
#include <iostream>

#include <scp/graphics/opengl/Texture2D.hpp>

using scp::graphics::opengl::Texture2D;

Texture2D::Texture2D(std::string_view imagePath)
{
    int32_t width, height, nrChannels;
    uint8_t* imageData = stbi_load(imagePath.data(), &width, &height, &nrChannels, 0);
    
    if (imageData == nullptr)
    {
        std::cerr << "[ERROR]: Failed to find or load " << imagePath << std::endl;
        m_handle = 0;
        return;
    }
    
    glGenTextures(1, &m_handle);
    glBindTexture(GL_TEXTURE_2D, m_handle);
    
    GLenum format;
    switch (nrChannels)
    {
    case 1:
        format = GL_RED;
    case 2:
        format = GL_RG;
    case 3:
        format = GL_RGB;
    case 4:
        format = GL_RGBA;
    default:
        format = GL_RGB;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    stbi_image_free(imageData);
}

Texture2D::Texture2D(std::vector<uint8_t> p_imageData, bool p_raw)
{
    uint8_t* imageData = nullptr;
    
    int32_t width, height, nrChannels;
    
    if (p_raw)
    {
        imageData = p_imageData.data();
    }
    else
    {
        imageData = stbi_load_from_memory(p_imageData.data(), p_imageData.size(), &width, &height, &nrChannels, 0);
        
        if (imageData == nullptr)
        {
            std::cerr << "[ERROR]: Failed to process an image data." << std::endl;
        }
    }
    
    glGenTextures(1, &m_handle);
    glBindTexture(GL_TEXTURE_2D, m_handle);
    
    GLenum format;
    switch (nrChannels)
    {
    case 1:
        format = GL_RED;
    case 2:
        format = GL_RG;
    case 3:
        format = GL_RGB;
    case 4:
        format = GL_RGBA;
    default:
        format = GL_RGB;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    if (!p_raw)
    {
        stbi_image_free(imageData);
    }
}

Texture2D::Texture2D(Texture2D& src)
{
    glBindTexture(GL_TEXTURE_2D, src.m_handle);
    
    int32_t width = 0;
    glGetTextureParameteriv(GL_TEXTURE_2D, GL_TEXTURE_WIDTH, &width);
    int32_t height = 0;
    glGetTextureParameteriv(GL_TEXTURE_2D, GL_TEXTURE_HEIGHT, &height);
    int32_t depth = 0;
    glGetTextureParameteriv(GL_TEXTURE_2D, GL_TEXTURE_DEPTH, &depth);
    
    glGenTextures(1, &m_handle);
    glBindTexture(GL_TEXTURE_2D, m_handle);
    
    glCopyImageSubData(src.m_handle, GL_TEXTURE_2D, 0, 0, 0, 0, m_handle, GL_TEXTURE_2D, 0, 0, 0, 0, width, height, depth);
    
    glBindBuffer(GL_TEXTURE_2D, 0);
}

Texture2D& Texture2D::operator=(Texture2D& p_rhs)
{
    Texture2D newObject(p_rhs);
    swap(newObject, *this);
}

Texture2D::Texture2D(Texture2D&& p_src)
{
    moveFrom(p_src);
}

Texture2D& Texture2D::operator=(Texture2D&& p_rhs)
{
    destroy();
    moveFrom(p_rhs);
}