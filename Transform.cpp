//
//  Transform.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform()
{
    position  = { 0, 0 };
    scale     = { 1.0, 1.0 };
    rotationZ = 0.0;
    alignment = TOP_LEFT;
}

Transform::~Transform()
{
    
}

Int2D Transform::getPosition()
{
    return position;
}

Float2D Transform::getScale()
{
    return scale;
}

float Transform::getRotationZ()
{
    return rotationZ;
}

Alignment Transform::getAlignment()
{
    return alignment;
}