//
//  Animation.hpp
//  SDL-2D
//
//  Created by José Ricardo de Sousa Coutinho on 23/10/15.
//  Copyright © 2015 José Ricardo de Sousa Coutinho. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include "Sprite.hpp"

enum typeAnimation {tEaseInQuad, tEaseOutQuad, tEaseInOutQuad,
    tEaseInCubic, tEaseOutCubic, tEaseInOutCubic,
    tEaseInQuart, tEaseOutQuart, tEaseInOutQuart,
    tEaseOutBack, tLinear};

enum attributeAnimation { tNada, tAlpha, tPos, tAlphaPos };


class Animation
{
    Sprite * sprite;
    
    int start;
    int end;
    int current;
    
    bool loop;
    
    int duration;
    
    typeAnimation type;
    attributeAnimation attribute;
    
protected:
    
    
public:
    
    Animation( Sprite * sprite, int start, int end, bool loop );
    ~Animation();
    
    bool load( Sprite * sprite );
    void dispose();
    
    void draw( SDL_Renderer * renderer, Transform * transform );
    
    void reset();
};

#endif /* Animation_hpp */
