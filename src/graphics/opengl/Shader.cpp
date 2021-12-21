#include <sstream>
#include <string>

#include <scp/graphics/opengl/Shader.hpp>
#include <scp/utils/string_utils.hpp>

using scp::graphics::opengl::Shader;
namespace string_utils = scp::utils::string_utils;

struct ShaderSources
{
    std::string vertex;
    std::string fragment;
};

static ShaderSources processShader(std::string_view shaderContent)
{
    std::stringstream shaderStream;
    shaderStream << shaderContent;
    
    enum class ShaderMode
    {
        None, Vertex, Fragment
    };
    
    ShaderMode shaderMode = ShaderMode::None;
    
    std::stringstream vertexStream;
    std::stringstream fragmentStream;
    
    while (shaderStream)
    {
        std::string line;
        std::getline(shaderStream, line);
        
        if (string_utils::startsWith(line, "//#@"))
        {
            if (string_utils::startsWith(line, "//#@ vertex"))
            {
                shaderMode = ShaderMode::Vertex;
            }
            else if (string_utils::startsWith(line, "//#@ fragment"))
            {
                shaderMode = ShaderMode::Fragment;
            }
        }
        else
        {
            switch (shaderMode)
            {
                case ShaderMode::Vertex:
                    vertexStream << line << "\n";
                    break;
                case ShaderMode::Fragment:
                    fragmentStream << line << "\n";
                    break;
                default:
                    break;
            }
        }
    }
    
    return { vertexStream.str(), fragmentStream.str() };
}










static unsigned int createShader(std::string_view p_source, unsigned int p_type, std::string_view p_name = "shader")
{
    const char* source = p_source.data();
    
    unsigned int shader = glCreateShader(p_type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    
    int success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        int errorLogLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogLength);
        char* errorLog = new char[errorLogLength];
        glGetShaderInfoLog(shader, errorLogLength, &errorLogLength, errorLog);
        
        std::cerr << "[ERROR]: Failed to compile shader " << p_name << ":\n" << errorLog << "\n\n";
        
        delete[] errorLog;
    }
    
    return shader;
}










static unsigned int createProgram(unsigned int p_vertex, unsigned int p_fragment, std::string_view p_name)
{
    unsigned int shader = glCreateProgram();
    glAttachShader(shader, p_vertex);
    glAttachShader(shader, p_fragment);
    glLinkProgram(shader);
    
    int success = 0;
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
        int errorLogLength = 0;
        glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &errorLogLength);
        char* errorLog = new char[errorLogLength];
        glGetProgramInfoLog(shader, errorLogLength, &errorLogLength, errorLog);
        
        std::cerr << "[ERROR]: Failed to link " << p_name << ":\n" << errorLog << "\n\n";
        
        delete[] errorLog;
    }
    
    return shader;
}










Shader::Shader(std::string_view source, std::string_view name)
{
    ShaderSources shaderSources = processShader(source);
    unsigned int vertex = createShader(shaderSources.vertex, GL_VERTEX_SHADER, name);
    unsigned int fragment = createShader(shaderSources.fragment, GL_FRAGMENT_SHADER, name);
    
    m_shader = createProgram(vertex, fragment, name);
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}










Shader::Shader(std::string_view p_vertexSource, std::string_view p_fragmentSource, std::string_view p_geometrySource, std::string_view p_name)
{
    (void) p_geometrySource;
    
    unsigned int vertex = createShader(p_vertexSource, GL_VERTEX_SHADER);
    unsigned int fragment = createShader(p_fragmentSource, GL_FRAGMENT_SHADER);
    
    m_shader = createProgram(vertex, fragment, p_name);
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}










Shader::Shader(Shader&& p_src)
{
    moveFrom(p_src);
}










Shader& Shader::operator=(Shader&& p_rhs)
{
    destory();
    moveFrom(p_rhs);
    return *this;
}










void Shader::use() const
{
    glUseProgram(m_shader);
}










void Shader::setUniform(std::string_view name, bool value)
{
    int location = glGetUniformLocation(m_shader, name.data());
    glUniform1i(location, value);
}










void Shader::setUniform(std::string_view name, int value)
{
    int location = glGetUniformLocation(m_shader, name.data());
    glUniform1i(location, value);
}










void Shader::setUniform(std::string_view name, float value)
{
    int location = glGetUniformLocation(m_shader, name.data());
    glUniform1f(location, value);
}










void Shader::setUniform(std::string_view name, float valueX, float valueY)
{
    int location = glGetUniformLocation(m_shader, name.data());
    glUniform2f(location, valueX, valueY);
}










void Shader::setUniform(std::string_view name, float valueX, float valueY, float valueZ)
{
    int location = glGetUniformLocation(m_shader, name.data());
    glUniform3f(location, valueX, valueY, valueZ);
}










void Shader::setUniform(std::string_view name, float valueX, float valueY, float valueZ, float valueW)
{
    int location = glGetUniformLocation(m_shader, name.data());
    glUniform4f(location, valueX, valueY, valueZ, valueW);
}









Shader::~Shader()
{
    destory();
}









void Shader::moveFrom(Shader& source)
{
    m_shader = source.m_shader;
    
    // Reset the source members, because ownership has been moved!
    source.m_shader = 0;
}










void Shader::destory()
{
    glDeleteProgram(m_shader);
}