#include <algorithm>

#include <scp/graphics/opengl/ElementBuffer.hpp>

using scp::graphics::opengl::ElementBuffer;

ElementBuffer::ElementBuffer(uint32_t p_size, unsigned int p_usage)
{
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_size, nullptr, p_usage);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

ElementBuffer::ElementBuffer(ElementBuffer& src)
{
    glBindBuffer(GL_COPY_READ_BUFFER, src.m_handle);
    
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
    
    int32_t sourceBufferSize = 0;
    glGetBufferParameteriv(GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &sourceBufferSize);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sourceBufferSize, nullptr, src.m_usage);
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_ELEMENT_ARRAY_BUFFER, 0, 0, sourceBufferSize);
    
    glBindBuffer(GL_COPY_READ_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

ElementBuffer& ElementBuffer::operator=(ElementBuffer& p_rhs)
{
    ElementBuffer newBuffer = p_rhs;
    swap(*this, newBuffer);
    return *this;
}

ElementBuffer::ElementBuffer(ElementBuffer&& src)
{
    moveFrom(src);
}

ElementBuffer& ElementBuffer::operator=(ElementBuffer&& p_rhs)
{
    destroy();
    moveFrom(p_rhs);
    return *this;
}

void ElementBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
}

void ElementBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::swap(ElementBuffer& p_a, ElementBuffer& p_b)
{
    std::swap(p_a.m_handle, p_b.m_handle);
    std::swap(p_a.m_usage, p_b.m_usage);
}

ElementBuffer::~ElementBuffer()
{
    destroy();
}

void ElementBuffer::moveFrom(ElementBuffer& src)
{
    m_handle = src.m_handle;
    m_usage = src.m_usage;
    
    // Reset the source values, because ownership has been moved!
    src.m_handle = 0;
    src.m_usage = 0;
}

void ElementBuffer::destroy()
{
    glDeleteBuffers(1, &m_handle);
}