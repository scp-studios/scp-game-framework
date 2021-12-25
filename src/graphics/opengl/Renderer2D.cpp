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

