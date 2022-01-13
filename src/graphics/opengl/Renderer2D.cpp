#include <scp/utils/file-utils.hpp>
#include <scp/math/Vector2.hpp>
#include <scp/math/Vector4.hpp>

#include <scp/graphics/opengl/Renderer2D.hpp>

#include <scp/graphics/VertexLayout.hpp>

using scp::graphics::opengl::Renderer2D;
using scp::graphics::opengl::VertexBuffer;
using scp::graphics::opengl::VertexArray;
using scp::graphics::opengl::ElementBuffer;

using scp::math::Vector2;
using scp::math::Vector4;

namespace fileutils = scp::utils::file_utils;

struct Vertex
{
    Vector2<float> position;
    Vector2<float> uv;
    Vector4<float> color;
    float texture;
};

Renderer2D::Renderer2D():
    m_shader(fileutils::loadAsString("../shaders/opengl_renderer2d.glsl"), "../shaders/opengl_renderer2d.glsl"),
    m_vertexArray(),
    m_vertexBuffer(1024 * sizeof(Vertex), GL_DYNAMIC_DRAW),
    m_elementBuffer(1024 * sizeof(Vertex), GL_DYNAMIC_DRAW)
{
    m_vertexArray.bind();
    m_elementBuffer.bind();
    
    VertexLayout aPosition = {};
    aPosition.type = VertexLayout::Type::Float;
    aPosition.size = 2;
    aPosition.stride = sizeof(Vertex);
    aPosition.offset = offsetof(Vertex, position);
    
    m_vertexArray.addAttribute(0, m_vertexBuffer, aPosition);
    
    VertexLayout aUV = {};
    aUV.type = VertexLayout::Type::Float;
    aUV.size = 2;
    aUV.stride = sizeof(Vertex);
    aUV.offset = offsetof(Vertex, uv);
    
    m_vertexArray.addAttribute(1, m_vertexBuffer, aUV);
    
    VertexLayout aColor = {};
    aColor.type = VertexLayout::Type::Float;
    aColor.size = 4;
    aColor.stride = sizeof(Vertex);
    aColor.offset = offsetof(Vertex, color);
    
    m_vertexArray.addAttribute(2, m_vertexBuffer, aColor);
    
    VertexLayout aTexture = {};
    aTexture.type = VertexLayout::Type::Float;
    aTexture.size = 1;
    aTexture.stride = sizeof(Vertex);
    aTexture.offset = offsetof(Vertex, texture);
    
    m_vertexArray.addAttribute(3, m_vertexBuffer, aTexture);
    
    // Set the texture units
    m_shader.use();
    for (uint8_t i = 0; i < 32; i++)
    {
        m_shader.setUniform(std::string("textures[") + std::to_string(i) + std::string("]"), i);
    }
}

void Renderer2D::addTextureImpl(std::string_view p_path)
{
    m_textures.push_back(Texture2D(p_path));
}

void Renderer2D::addTextureImpl(std::vector<uint8_t> p_data, bool p_raw)
{
    m_textures.push_back(Texture2D(p_data, p_raw));
}

void Renderer2D::beginImpl()
{
    // Bind the vertex array
    m_vertexArray.bind();
    
    // Reset the buffer read write offset
    m_bufferOffset = 0;
    m_indexBufferOffset = 0;
    m_indexOffset = 0;
    m_vertexOffset = 0;
    
    // Use the shader
    m_shader.use();
}

void Renderer2D::drawTexturedQuadImpl(float width, float height, float posX, float posY, float uvRight, float uvLeft, float uvTop, float uvBottom, int8_t texture)
{
    std::vector<Vertex> vertices(4);
    
    vertices[0].position.x = (width / 2) + posX;
    vertices[0].position.y = (height / 2) + posY;
    vertices[0].color = Vector4(0.0f);
    vertices[0].color.w = 1.0f;
    vertices[0].uv.x = uvRight;
    vertices[0].uv.y = uvTop;
    vertices[0].texture = texture;
    
    vertices[1].position.x = (width / 2) + posX;
    vertices[1].position.y = (height / -2) + posY;
    vertices[1].color = Vector4(0.0f);
    vertices[1].color.w = 1.0f;
    vertices[1].uv.x = uvRight;
    vertices[1].uv.y = uvBottom;
    vertices[1].texture = texture;
    
    vertices[2].position.x = (width / -2) + posX;
    vertices[2].position.y = (height / -2) + posY;
    vertices[2].color = Vector4(0.0f);
    vertices[2].color.w = 1.0f;
    vertices[2].uv.x = uvLeft;
    vertices[2].uv.y = uvBottom;
    vertices[2].texture = texture;
    
    vertices[3].position.x = (width / -2) + posX;
    vertices[3].position.y = (height / 2) + posY;
    vertices[3].color = Vector4(0.0f);
    vertices[3].color.w = 1.0f;
    vertices[3].uv.x = uvLeft;
    vertices[3].uv.y = uvTop;
    vertices[3].texture = texture;
    
    std::vector<uint32_t> indices(6);
    indices[0] = m_vertexOffset + 0;
    indices[1] = m_vertexOffset + 1;
    indices[2] = m_vertexOffset + 2;
    indices[3] = m_vertexOffset + 0;
    indices[4] = m_vertexOffset + 3;
    indices[5] = m_vertexOffset + 2;
    
    m_vertexBuffer.setSubData(vertices, m_bufferOffset);
    m_elementBuffer.setSubData(indices, m_indexBufferOffset);
    
    m_bufferOffset += 4 * sizeof(Vertex);
    m_indexBufferOffset += 6 * sizeof(uint32_t);
    m_indexOffset += 6;
    m_vertexOffset += 4;
}

void Renderer2D::drawSolidColoredQuadImpl(float width, float height, float posX, float posY, float red, float green, float blue, float alpha)
{
    std::vector<Vertex> vertices(4);
    
    vertices[0].position.x = width * 0.5 + posX;
    vertices[0].position.y = height * 0.5 + posY;
    vertices[0].color.x = red;
    vertices[0].color.y = green;
    vertices[0].color.z = blue;
    vertices[0].color.w = alpha;
    vertices[0].uv.x = 0;
    vertices[0].uv.y = 0;
    vertices[0].texture = -1;
    
    vertices[1].position.x = width * 0.5 + posX;
    vertices[1].position.y = height * -0.5 + posY;
    vertices[1].color.x = red;
    vertices[1].color.y = green;
    vertices[1].color.z = blue;
    vertices[1].color.w = alpha;
    vertices[1].uv.x = 0;
    vertices[1].uv.y = 0;
    vertices[1].texture = -1;
    
    vertices[2].position.x = width * -0.5 + posX;
    vertices[2].position.y = height * -0.5 + posY;
    vertices[2].color.x = red;
    vertices[2].color.y = green;
    vertices[2].color.z = blue;
    vertices[2].color.w = alpha;
    vertices[2].uv.x = 0;
    vertices[2].uv.y = 0;
    vertices[2].texture = -1;
    
    vertices[3].position.x = width * -0.5 + posX;
    vertices[3].position.y = height * 0.5 + posY;
    vertices[3].color.x = red;
    vertices[3].color.y = green;
    vertices[3].color.z = blue;
    vertices[3].color.w = alpha;
    vertices[3].uv.x = 0;
    vertices[3].uv.y = 0;
    vertices[3].texture = -1;
    
    std::vector<uint32_t> indices(6);
    indices[0] = m_vertexOffset + 0;
    indices[1] = m_vertexOffset + 1;
    indices[2] = m_vertexOffset + 2;
    indices[3] = m_vertexOffset + 0;
    indices[4] = m_vertexOffset + 3;
    indices[5] = m_vertexOffset + 2;
    
    m_vertexBuffer.setSubData(vertices, m_bufferOffset);
    m_elementBuffer.setSubData(indices, m_indexBufferOffset);
    
    m_bufferOffset += 4 * sizeof(Vertex);
    m_indexBufferOffset += 6 * sizeof(uint32_t);
    m_indexOffset += 6;
    m_vertexOffset += 4;
}

void Renderer2D::endImpl()
{
    // Bind the textures
    for (uint16_t i = 0; i < m_textures.size(); i++)
    {
        m_textures[i].setTextureUnit(i);
        m_textures[i].bind();
    }
    
    glDrawElements(GL_TRIANGLES, m_indexOffset, GL_UNSIGNED_INT, nullptr);
}