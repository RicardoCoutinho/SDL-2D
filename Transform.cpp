//
//  Transform.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform(Int2D position, Float2D scale, float rotationZ, Alignment alignment)
{
    setPosition(position);
    setScale(scale);
    setRotationZ(rotationZ);
    setAlignment(alignment);
}

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

void Transform::setPosition(Int2D position)
{
    this->position.x = position.x;
    this->position.y = position.y;
}

void Transform::setScale(Float2D scale)
{
    this->scale.x = scale.x;
    this->scale.y = scale.y;
}

void Transform::setRotationZ(float rotationZ)
{
    this->rotationZ = rotationZ;
}

void Transform::setAlignment(Alignment alignment)
{
    this->alignment = alignment;
}


