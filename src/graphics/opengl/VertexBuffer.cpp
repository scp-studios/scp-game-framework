#include <algorithm>

#include <scp/graphics/opengl/VertexBuffer.hpp>

using scp::graphics::opengl::VertexBuffer;

VertexBuffer::VertexBuffer(uint32_t p_size, unsigned int p_usage): m_usage(p_usage)
{
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ARRAY_BUFFER, p_size, nullptr, p_usage);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::VertexBuffer(VertexBuffer& src)
{
    glBindBuffer(GL_COPY_READ_BUFFER, src.m_handle);
    
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    
    int32_t sourceBufferSize = 0;
    glGetBufferParameteriv(GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &sourceBufferSize);
    glBufferData(GL_ARRAY_BUFFER, sourceBufferSize, nullptr, src.m_usage);
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_ARRAY_BUFFER, 0, 0, sourceBufferSize);
    
    glBindBuffer(GL_COPY_READ_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer& p_rhs)
{
    VertexBuffer newBuffer = p_rhs;
    swap(*this, newBuffer);
    return *this;
}

VertexBuffer::VertexBuffer(VertexBuffer&& src)
{
    moveFrom(src);
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& p_rhs)
{
    destroy();
    moveFrom(p_rhs);
    return *this;
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::clearBuffer(uint32_t size, unsigned int usage)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, usage);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::swap(VertexBuffer& p_a, VertexBuffer& p_b)
{
    std::swap(p_a.m_handle, p_b.m_handle);
    std::swap(p_a.m_usage, p_b.m_usage);
}

VertexBuffer::~VertexBuffer()
{
    destroy();
}

void VertexBuffer::moveFrom(VertexBuffer& src)
{
    m_handle = src.m_handle;
    m_usage = src.m_usage;
    
    // Reset the source values, because ownership has been moved!
    src.m_handle = 0;
    src.m_usage = 0;
}

void VertexBuffer::destroy()
{
    glDeleteBuffers(1, &m_handle);
}