#include <scp/math.hpp>
#include <scp/math/transformations.hpp>

#include <scp/graphics/Sprite.hpp>

using scp::graphics::Sprite;
namespace trans = scp::math::transformations;

void Sprite::applyTransforms()
{
    matrix = scp::math::Matrix4(1.0f);
    matrix = trans::scale(matrix, scale);
    matrix = trans::translate(matrix, position);
}