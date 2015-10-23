//
//  Sprite.hpp
//  SDL-2D
//
//  Created by José Ricardo de Sousa Coutinho on 23/10/15.
//  Copyright © 2015 José Ricardo de Sousa Coutinho. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "Texture.hpp"

class Sprite
{
    Texture * spritesheet;
    
    int startWidth;
    int startHeight;
    
    int width;
    int height;
};

#endif /* Sprite_hpp */
