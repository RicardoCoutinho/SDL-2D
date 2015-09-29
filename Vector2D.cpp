//
//  Vector2D.cpp
//  SDL 2D Game Template
//
//  Created by José Ricardo de Sousa Coutinho on 29/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Vector2D.hpp"

Vector2D::Vector2D( float x, float y)
{
    mX = x;
    mY = y;
}

float Vector2D::getX()
{
    return mX;
}

float Vector2D::getY()
{
    return mY;
}

void Vector2D::setX(float x)
{
    mX = x;
}

void Vector2D::setY(float y)
{
    mY = y;
}

float Vector2D::length()
{
    return sqrt( mX * mX + mY * mY );
}

void Vector2D::normalize()
{
    float l = length();
    
    if ( l > 0 )
    {
        (*this) *= 1 / l;
    }
}

