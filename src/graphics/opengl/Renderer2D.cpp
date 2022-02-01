#include <scp/utils/file-utils.hpp>
#include <scp/math/Vector2.hpp>
#include <scp/math/Vector4.hpp>

#include <scp/graphics/opengl/Renderer2D.hpp>

#include <scp/graphics/VertexLayout.hpp>
#include <scp/graphics/Sprite.hpp>

#include <scp/math.hpp>
#include <scp/math/projections.hpp>
#include <scp/Window.hpp>

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

static inline std::vector<uint32_t> generateIndices(uint32_t vertexOffset)
{
    std::vector<uint32_t> indices(6);
    indices[0] = vertexOffset + 0;
    indices[1] = vertexOffset + 1;
    indices[2] = vertexOffset + 2;
    indices[3] = vertexOffset + 0;
    indices[4] = vertexOffset + 3;
    indices[5] = vertexOffset + 2;
    
    return indices;
}

Renderer2D::Renderer2D(std::string_view shaderSource):
    m_shader(shaderSource, "2D renderer shader"),
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
    m_textures.push_back(Texture2D(p_path, GL_LINEAR_MIPMAP_LINEAR));
}

void Renderer2D::addTextureImpl(std::vector<uint8_t> p_data, bool p_raw)
{
    m_textures.push_back(Texture2D(p_data, p_raw));
}

void Renderer2D::beginImpl()
{
    // Get information about the window
    Window& window = Window::getInstance();
    
    // Update the projection matrix
    m_projectionMatrix = math::projections::orthgraphic<float>(window.getWidth(), 0.0f, 0.0f, window.getHeight(), 1.0f, 0.0f);
    
    // Bind the vertex array
    m_vertexArray.bind();
    
    // Reset the buffer read write offset
    m_bufferOffset = 0;
    m_indexBufferOffset = 0;
    m_indexOffset = 0;
    m_vertexOffset = 0;
    
    // Use the shader
    m_shader.use();
    
    // Set the project matrix
    m_shader.setUniform("projection", m_projectionMatrix);
}

void Renderer2D::drawTexturedQuadImpl(float width, float height, float posX, float posY, float uvRight, float uvLeft, float uvTop, float uvBottom, int8_t texture)
{
    std::vector<Vertex> vertices(4);
    
    vertices[0].position.x = posX;
    vertices[0].position.y = posY;
    vertices[0].uv.x = uvRight;
    vertices[0].uv.y = uvTop;
    
    vertices[1].position.x = posX;
    vertices[1].position.y = posY + height;
    vertices[1].uv.x = uvRight;
    vertices[1].uv.y = uvBottom;
    
    vertices[2].position.x = posX + width;
    vertices[2].position.y = posY + height;
    vertices[2].uv.x = uvLeft;
    vertices[2].uv.y = uvBottom;
    
    vertices[3].position.x = posX + width;
    vertices[3].position.y = posY;
    vertices[3].uv.x = uvLeft;
    vertices[3].uv.y = uvTop;
    
    for (Vertex& vertex: vertices)
    {
        vertex.color = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
        vertex.texture = texture;
    }
    
    std::vector<uint32_t> indices = generateIndices(m_vertexOffset);
    
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
    
    vertices[0].position.x = posX;
    vertices[0].position.y = posY;
    
    vertices[1].position.x = posX;
    vertices[1].position.y = posY + height;
    
    vertices[2].position.x = posX + width;
    vertices[2].position.y = posY + height;
    
    vertices[3].position.x = posX + width;
    vertices[3].position.y = posY;
    
    for (Vertex& vertex: vertices)
    {
        vertex.color = Vector4(red, green, blue, alpha);
        vertex.uv = Vector2(0.0f, 0.0f);
        vertex.texture = -1.0f;
    }
    
    std::vector<uint32_t> indices = generateIndices(m_vertexOffset);
    
    m_vertexBuffer.setSubData(vertices, m_bufferOffset);
    m_elementBuffer.setSubData(indices, m_indexBufferOffset);
    
    m_bufferOffset += 4 * sizeof(Vertex);
    m_indexBufferOffset += 6 * sizeof(uint32_t);
    m_indexOffset += 6;
    m_vertexOffset += 4;
}

void Renderer2D::drawSpriteImpl(const Sprite& p_sprite)
{
    std::vector<Vertex> vertices(4);
    
    vertices[0].position = Vector2<float>(p_sprite.matrix * Vector4<float>(1.0f, 0.0f, 0.0f, 1.0f));
    vertices[1].position = Vector2<float>(p_sprite.matrix * Vector4<float>(1.0f, 1.0f, 0.0f, 1.0f));
    vertices[2].position = Vector2<float>(p_sprite.matrix * Vector4<float>(0.0f, 1.0f, 0.0f, 1.0f));
    vertices[3].position = Vector2<float>(p_sprite.matrix * Vector4<float>(0.0f, 0.0f, 0.0f, 1.0f));
    
    for (uint8_t i = 0; i < 4; i++)
    {
        vertices[i].uv = p_sprite.uv[i];
        vertices[i].color = p_sprite.baseColor;
        vertices[i].texture = p_sprite.texture;
    }
    
    m_vertexBuffer.setSubData(vertices, m_bufferOffset);
    m_elementBuffer.setSubData(generateIndices(m_vertexOffset), m_indexBufferOffset);
    
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