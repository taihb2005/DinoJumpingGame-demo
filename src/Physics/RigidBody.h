#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Vector2f.h"
#include "InputFromPlayer.h"

const float MASS_UNIT = 1.0f;
const float GRAVITY = 9.8f;

const float MOVING_BACKWARD = -1;
const float MOVING_FORWARD = 1;

const float MOVING_UPWARD = -1;
const float MOVING_DOWNWARD = 1;

class RigidBody
{
    public:
        RigidBody();
        inline void SetMass(float m){m_Mass = m * MASS_UNIT;};

        inline void setGravity(float gravity){m_Gravity = gravity;};

        inline void SetForce(Vector2f F){m_Force = F;};
        inline void SetForceX(float Fx){m_Force.X = Fx;};
        inline void SetForceY(float Fy){m_Force.Y = Fy;};

        inline void ApplyFriction(Vector2f Fr){m_Friction = Fr;};
        inline void ApplyFrictionX(float Frx){m_Friction.X = Frx;};
        inline void ApplyFrictionY(float Fry){m_Friction.Y = Fry;};

        inline void UnsetForce(){m_Force = {0 , 0};};
        inline void UnsetFriction(){m_Friction = {0 , 0};};

        inline Vector2f getPosition(){return m_Position;};
        inline Vector2f getVelocity(){return m_Velocity;};
        inline Vector2f getAcceleration(){return m_Acceleration;};

        void Update(float dt);

    private:
        float m_Mass; //Objects mass
        float m_Gravity; //Gravitation

        Vector2f m_Force;
        Vector2f m_Friction;
        Vector2f m_Velocity;
        Vector2f m_Acceleration;
        Vector2f m_Position;

};

#endif // RIGIDBODY_H
