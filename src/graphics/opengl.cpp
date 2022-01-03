#include <glad/glad.h>
#include <string>
#include <iostream>

#include <scp/graphics/opengl.hpp>

static void openGLDebugCallback(GLenum p_source, GLenum p_type, GLuint p_id, GLenum p_severity, GLsizei p_length, const GLchar *p_message, const void *p_userParam)
{
    std::string source;
    switch (p_source)
    {
    case GL_DEBUG_SOURCE_API:
        source = "API";
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        source = "SHADER COMPILER";
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        source = "WINDOW SYSTEM";
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        source = "THIRD PARTY";
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        source = "APPLICATION";
        break;
    case GL_DEBUG_SOURCE_OTHER:
        source = "OTHER";
        break;
    }
    
    std::ostream* output;
    
    std::string type;
    switch (p_type)
    {
    case GL_DEBUG_TYPE_ERROR:
        type = "ERROR";
        output = &std::cerr;
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        type = "DEPRECATED_BEHAVIOUR";
        output = &std::cout;
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        type = "UNDEFINED_BEHAVIOUR";
        output = &std::cout;
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        type = "PERFROMANCE";
        output = &std::cerr;
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        type = "PORTABILITY";
        output = &std::cout;
        break;
    case GL_DEBUG_TYPE_MARKER:
        type = "MARKER";
        output = &std::cout;
        break;
    case GL_DEBUG_TYPE_PUSH_GROUP:
        type = "PUSH_GROUP";
        output = &std::cerr;
        break;
    case GL_DEBUG_TYPE_POP_GROUP:
        type = "POP_GROUP";
        output = &std::cout;
        break;
    case GL_DEBUG_TYPE_OTHER:
        type = "OTHER";
        output = &std::cout;
        break;
    }
    
    std::string severity;
    
    switch (p_severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
        output = &std::cerr;
        severity = "HIGH";
    case GL_DEBUG_SEVERITY_MEDIUM:
        output = &std::cerr;
        severity = "MEDIUM";
    case GL_DEBUG_SEVERITY_LOW:
        output = &std::cout;
        severity = "LOW";
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        output = &std::cout;
        severity = "NOTIFICATION";
    }
    
    *(output) << "[OPENGL]: (Src: " << source << ", T: " << type << ", Sev: " << severity << "): " << p_message << std::endl;
    return;
}

void scp::graphics::opengl::enableContextDebugging()
{
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    
    glDebugMessageCallback(openGLDebugCallback, nullptr);
}

void scp::graphics::opengl::enable2DBlending()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
}