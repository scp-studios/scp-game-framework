#ifndef AE069409_165F_4668_B9FE_27666A88ACE4
#define AE069409_165F_4668_B9FE_27666A88ACE4

#include "pch.hpp"

namespace scp::physics
{
    SCPGFFUNC class AxisAlignedBoxCollider
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
        
        void move(double x, double y);
        
        // Alter the Y position
        void moveAlongY(double s);
        
        // Alter the X position
        void moveAlongX(double s);
        
        std::string getName() const;
        
    private:
        double m_right;
        double m_left;
        double m_top;
        double m_bottom;
        
        std::string m_name;
    };
}

#endif /* AE069409_165F_4668_B9FE_27666A88ACE4 */
