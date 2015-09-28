//
//  Spritesheet.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 23/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Spritesheet_hpp
#define Spritesheet_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// System libraries
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

// Custom libraries
#include "Types.hpp"
#include "Texture.hpp"

using namespace std;

class Spritesheet
{
    const int FRAMES_PER_SECOND = 30; // this needs to be a variable passed by argument in the constructor, like speed or sampleSpeed
    int totalFrames;
    
    int frames;
    int currentFrame;
    
    int clipWidth;
    int clipHeight;
    
    bool loop;
    
    SDL_Color colorKey;
    
    vector<SDL_Rect *> clip;
    
    Texture * texture;
    
    Int2D adjustPosition( Transform * transform );
    void nextFrame();
    
protected:
    
    
public:
    
    Spritesheet( Texture * texture, int frames, int clipWidth, int clipHeight, SDL_Color colorKey );
    ~Spritesheet();
    
    bool load( Texture * texture );
    
    void dispose();
    
    void draw( SDL_Renderer * renderer, Transform * transform );
};

#endif /* Spritesheet_hpp */
