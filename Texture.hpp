//
//  Texture.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// System libraries
#include <stdio.h>
#include <string>

// Custom libraries
#include "Types.hpp"
#include "Transform.hpp"

using namespace std;

const string REGEX_TEXTURE = "^.*\\.(jpg|png|gif|bmp|jpeg|lbm|pcx|pnm|tga|tiff|webp|xcf|xpm|xv)$";

class Texture
{
    string path;
    SDL_Texture * texture;
    
    int width;
    int height;
    
    Int2D adjustPosition( Transform * transform );
    
public:
    
    Texture( string path );
    ~Texture();
    
    bool load( SDL_Renderer * renderer );
    
    void dispose();
    
    void draw( SDL_Renderer * renderer, Int2D position, SDL_Rect * clip );
    
    string getPath();
    int getWidth();
    int getHeight();
    SDL_Texture * getTexture();
    
    void setTexture( SDL_Texture * texture );
    void setWidth( int width );
    void setHeight( int height );
    
};

#endif /* Texture_hpp */
