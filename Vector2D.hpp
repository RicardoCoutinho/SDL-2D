//
//  Vector2D.hpp
//  SDL 2D Game Template
//
//  Created by José Ricardo de Sousa Coutinho on 29/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <math.h>

class Vector2D
{
    float mX;
    float mY;
    
public:
    Vector2D( float x, float y);
    
    float getX();
    float getY();
    
    void setX(float x);
    void setY(float y);
    
    float length();
    void normalize();
    
    Vector2D operator+ (const Vector2D & v2) const
    {
        return Vector2D( mX + v2.mX, mY + v2.mY );
    };
    
    friend Vector2D& operator+= (Vector2D & v1, const Vector2D& v2)
    {
        v1.mX += v2.mX;
        v1.mY += v2.mY;
        
        return v1;
    };
    
    Vector2D operator- (const Vector2D & v2) const
    {
        return Vector2D( mX - v2.mX, mY - v2.mY );
    };
    
    friend Vector2D& operator-= (Vector2D & v1, const Vector2D& v2)
    {
        v1.mX -= v2.mX;
        v1.mY -= v2.mY;
        
        return v1;
    };
    
    Vector2D operator* (float scalar)
    {
        return Vector2D(mX * scalar, mY * scalar);
    };
    
    Vector2D& operator*= (float scalar)
    {
        mX *= scalar;
        mY *= scalar;
        
        return *this;
    }
    
    Vector2D operator/ (float scalar)
    {
        return Vector2D(mX / scalar, mY / scalar);
    };
    
    Vector2D& operator/= (float scalar)
    {
        mX /= scalar;
        mY /= scalar;
        
        return *this;
    }
};

#endif /* Vector2D_hpp */
