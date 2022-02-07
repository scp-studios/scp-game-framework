#ifndef AE069409_165F_4668_B9FE_27666A88ACE4
#define AE069409_165F_4668_B9FE_27666A88ACE4

#include "pch.hpp"

namespace scp::physics
{
    class AxisAlignedBoxCollider
    {
    public:
        AxisAlignedBoxCollider(
            uint16_t right = 100, 
            uint16_t left = 0, 
            uint16_t top = 0, 
            uint16_t bottom = 100,
            std::string_view name = "Axis Aligned Box Collider"
        );
        
        bool hasCollidedWith(const AxisAlignedBoxCollider& other) const;
        
        void move(uint16_t x, uint16_t y);
        
        std::string getName() const;
        
    private:
        uint16_t m_right;
        uint16_t m_left;
        uint16_t m_top;
        uint16_t m_bottom;
        
        std::string m_name;
    };
}

#endif /* AE069409_165F_4668_B9FE_27666A88ACE4 */
