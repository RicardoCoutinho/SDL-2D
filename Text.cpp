//
//  Text.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Text.hpp"

Text::Text( string path ):Texture( path )
{
    this->path = path;
    this->size = DEFAULT_SIZE;
    
    font = NULL;
}

Text::Text( string path, int size ):Texture( path )
{
    this->path = path;
    this->size = size;
    
    font = NULL;
}

Text::~Text()
{
    dispose();
}

bool Text::load()
{
    dispose();
    
    bool success = true;
    
    // Open the Text
    font = TTF_OpenFont( path.c_str(), size );
    
    if ( font == NULL)
    {
        printf( "Unable to load font from %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError() );
        success = false;
    }
    
    return success;
}

void Text::dispose()
{
    if ( font != NULL )
    {
        TTF_CloseFont( font );
        font = NULL;
    }
    
    Texture::dispose();
}

void Text::draw( SDL_Renderer * renderer, Int2D position, SDL_Color color, string text )
{
    bool success;
    
    dispose();
    
    if ( font == NULL )
    {
        success = load();
    }
    
    if ( success )
    {
        //Render text surface
        SDL_Surface * textSurface = TTF_RenderText_Blended(font, text.c_str(), color );
        
        if( textSurface == NULL )
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
        else
        {
            //Create texture from surface pixels
            SDL_Texture * texture = SDL_CreateTextureFromSurface( renderer, textSurface );
            
            if( texture == NULL )
            {
                printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                // Draw text
                SDL_Rect clip = {0, 0, textSurface->w, textSurface->h };
                
                Texture::setTexture( texture );
                Texture::setWidth( textSurface->w );
                Texture::setHeight( textSurface->h );
                
                Texture::draw( renderer, position, &clip );
            }
            
            // Get rid of old surface
            SDL_FreeSurface( textSurface );
        }
    }
}

string Text::getPath()
{
    return path;
}

int Text::getSize()
{
    return size;
}

void Text::setSize( int size )
{
    this->size = size;
}