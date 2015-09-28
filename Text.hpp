//
//  Text.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

// System libraries
#include <stdio.h>
#include <string>

// Custom libraries
#include "Types.hpp"
#include "Texture.hpp"

using namespace std;

const string REGEX_FONT = "^.*\\.(ttf)$";

static int DEFAULT_SIZE = 30;

class Text: public Texture
{
    string path;
    int size;
    TTF_Font * font;
    
public:
    
    Text( string path );
    Text( string path, int size );
    ~Text();
    
    bool load();
    
    void dispose();
    
    void draw( SDL_Renderer * renderer, Int2D position, SDL_Color color, string text );
    
    string getPath();
    int getSize();
    
    void setSize( int size );
};


#endif /* Text_hpp */
