#include <scp/physics/AxisAlignedBoxCollider.hpp>

using scp::physics::AxisAlignedBoxCollider;

AxisAlignedBoxCollider::AxisAlignedBoxCollider(uint16_t right, uint16_t left, uint16_t top, uint16_t bottom, std::string_view name):
                                               m_right(right),
                                               m_left(left),
                                               m_top(top),
                                               m_bottom(bottom),
                                               m_name(name)
{
    
}

bool AxisAlignedBoxCollider::hasCollidedWith(const AxisAlignedBoxCollider& other) const
{
    return (
        (
            (m_bottom >= other.m_top && m_bottom <= other.m_bottom) 
            || 
            (m_top <= other.m_bottom && m_top >= other.m_top)
        )
        &&
        (
            (m_left <= other.m_right && m_left >= other.m_left)
            ||
            (m_right >= other.m_left && m_right <= other.m_right)
        )
    );
}

void AxisAlignedBoxCollider::move(double x, double y)
{
    m_right += x;
    m_left += x;
    m_top += y;
    m_bottom += y;
}

void AxisAlignedBoxCollider::moveAlongY(double s)
{
    m_top += s;
    m_bottom += s;
}

void AxisAlignedBoxCollider::moveAlongX(double s)
{
    m_right += s;
    m_left += s;
}

std::string AxisAlignedBoxCollider::getName() const
{
    return m_name;
}