//
//  Transform.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

// System libraries
#include <stdio.h>

// Custom libraries
#include "Types.hpp"

class Transform
{
    Int2D position;
    
    Float2D scale;
    
    float rotationZ;
    
    Alignment alignment;
    
protected:
    
    
public:
    
    Transform(Int2D position, Float2D scale, float rotationZ, Alignment alignment);
    Transform();
    ~Transform();
    
    Int2D getPosition();
    Float2D getScale();
    float getRotationZ();
    Alignment getAlignment();
    
    void setPosition(Int2D position);
    void setScale(Float2D scale);
    void setRotationZ(float rotationZ);
    void setAlignment(Alignment alignment);
};

#endif /* Transform_hpp */
