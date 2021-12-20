
#include <scp/graphics/opengl/VertexArray.hpp>

using scp::graphics::opengl::VertexArray;

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_handle);
}

VertexArray::VertexArray(VertexArray&& p_src)
{
    moveFrom(p_src);
}

VertexArray& VertexArray::operator=(VertexArray&& p_rhs)
{
    glDeleteVertexArrays(1, &m_handle);
    moveFrom(p_rhs);
}

void VertexArray::addAttribute(uint8_t p_index, VertexBuffer& p_buffer, VertexLayout& p_layout)
{
    glBindVertexArray(m_handle);
    
    p_buffer.bind();
    
    GLenum type;
    switch (p_layout.type)
    {
        case VertexLayout::Type::Float:
            type = GL_FLOAT;
            break;
        case VertexLayout::Type::Double:
            type = GL_DOUBLE;
            break;
        case VertexLayout::Type::Int:
            type = GL_INT;
            break;
        case VertexLayout::Type::UnsignedInt:
            type = GL_UNSIGNED_INT;
            break;
    }
    
    glVertexAttribPointer(p_index, p_layout.size, type, GL_FALSE, p_layout.stride, reinterpret_cast<void*>(p_layout.offset));
    glEnableVertexAttribArray(p_index);
    
    glBindVertexArray(0);
}

void VertexArray::bind() const
{
    glBindVertexArray(m_handle);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_handle);
}

void VertexArray::moveFrom(VertexArray& p_src)
{
    m_handle = p_src.m_handle;
    
    p_src.m_handle = 0;
}