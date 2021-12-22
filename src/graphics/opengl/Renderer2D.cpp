#include <scp/utils/file-utils.hpp>
#include <scp/math/Vector2.hpp>

#include <scp/graphics/opengl/Renderer2D.hpp>

#include <scp/graphics/VertexLayout.hpp>

using scp::graphics::opengl::Renderer2D;
using scp::graphics::opengl::VertexBuffer;
using scp::graphics::opengl::VertexArray;
using scp::graphics::opengl::ElementBuffer;

using scp::math::Vector2;

namespace fileutils = scp::utils::file_utils;

struct Vertex
{
    Vector2<float> position;
    Vector2<float> uv;
    uint64_t spriteId;
};

Renderer2D::Renderer2D():
    m_shader(fileutils::loadAsString("../shaders/renderer2d.glsl")),
    m_vertexArray(),
    m_nextSpriteID(0),
    m_numberOfElements(0)
{
    m_vertexArray.bind();
    
    m_vertexBuffer = VertexBuffer(256 * sizeof(Vertex));
    m_elementBuffer = ElementBuffer(256 * sizeof(uint32_t));
    
    m_elementBuffer.bind();
    
    VertexLayout aPosition = {};
    aPosition.type = VertexLayout::Type::Float;
    aPosition.size = 2;
    aPosition.offset = offsetof(Vertex, position);
    aPosition.stride = sizeof(Vertex);
    
    VertexLayout aUV = {};
    aUV.type = VertexLayout::Type::Float;
    aUV.size = 2;
    aUV.offset = offsetof(Vertex, uv);
    aUV.stride = sizeof(Vertex);
    
    VertexLayout aSpriteID = {};
    aSpriteID.type = VertexLayout::Type::UnsignedInt;
    aSpriteID.size = 1;
    aSpriteID.offset = offsetof(Vertex, spriteId);
    aSpriteID.stride = sizeof(Vertex);
    
    m_vertexArray.addAttribute(0, m_vertexBuffer, aPosition);
    m_vertexArray.addAttribute(1, m_vertexBuffer, aUV);
    m_vertexArray.addAttribute(2, m_vertexBuffer, aSpriteID);
}

uint64_t Renderer2D::addSpriteImpl(uint32_t width, uint32_t height, float uvOffsetX, float uvOffsetY)
{
    std::vector<Vertex> vertices(4);
    vertices[0].position.x = width * 0.5;
    vertices[0].position.y = height * 0.5;
    vertices[0].uv.x = uvOffsetX + width;
    vertices[0].uv.y = uvOffsetY;
    vertices[0].spriteId = m_nextSpriteID;
    
    vertices[1].position.x = width * 0.5;
    vertices[1].position.y = height * -0.5;
    vertices[1].uv.x = uvOffsetX + width;
    vertices[1].uv.y = uvOffsetY + height;
    vertices[1].spriteId = m_nextSpriteID;
    
    vertices[2].position.x = width * -0.5;
    vertices[2].position.y = height * -0.5;
    vertices[2].uv.x = uvOffsetX;
    vertices[2].uv.y = uvOffsetY + height;
    vertices[2].spriteId = m_nextSpriteID;
    
    vertices[3].position.x = width * -0.5;
    vertices[3].position.y = height * 0.5;
    vertices[3].uv.x = uvOffsetX;
    vertices[3].uv.y = uvOffsetY;
    vertices[3].spriteId = m_nextSpriteID;
    
    std::vector<uint32_t> indices(6);
    indices[0] = 0 + (m_nextSpriteID * 6);
    indices[1] = 1 + (m_nextSpriteID * 6);
    indices[2] = 2 + (m_nextSpriteID * 6);
    
    indices[3] = 0 + (m_nextSpriteID * 6);
    indices[4] = 3 + (m_nextSpriteID * 6);
    indices[5] = 2 + (m_nextSpriteID * 6);
    
    m_numberOfElements = m_numberOfElements + 6;
    
    m_vertexBuffer.setSubData(vertices, m_nextSpriteID * 4 * sizeof(Vertex));
    m_elementBuffer.setSubData(indices, m_nextSpriteID * 6 * sizeof(uint32_t));
    
    uint64_t currentSpriteID = m_nextSpriteID;
    m_nextSpriteID++;
    
    return currentSpriteID;
}

void Renderer2D::renderImpl()
{
    m_shader.use();
    
    m_vertexArray.bind();
    glDrawElements(GL_TRIANGLES, m_numberOfElements, GL_UNSIGNED_INT, nullptr);
    m_vertexArray.unbind();
}

Renderer2D::~Renderer2D()
{
    
}