//
//  Spritesheet.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 23/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Spritesheet.hpp"

Spritesheet::Spritesheet( Texture * texture, int frames, int clipWidth, int clipHeight, SDL_Color colorKey )
{
    this->totalFrames = 0;
    
    this->frames       = frames;
    this->currentFrame = 0;
    
    this->clipWidth    = clipWidth;
    this->clipHeight   = clipHeight;

    this->loop         = true;
    
    this->colorKey     = colorKey;
    
    this->clip.clear();
    
    this->texture      = NULL;
    
    load( texture );
}

Spritesheet::~Spritesheet()
{
    totalFrames  = 0;
    frames       = 0;
    currentFrame = 0;
    clipWidth    = 0;
    clipHeight   = 0;
    loop         = true;
    colorKey     = {0,0,0,0};
    texture      = NULL;
    
    dispose();
}

bool Spritesheet::load( Texture * texture )
{
    dispose();
    
    bool success = true;
    
    if( texture == NULL )
    {
        printf( "Empty texture pointer! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        this->texture = texture;
        
        if ( frames > 0 )
        {
            for (int y=0, iFrame=0; y<texture->getHeight() && iFrame<frames; y+=clipHeight)
            {
                for (int x=0; x<=texture->getWidth() && iFrame<frames; x+=clipWidth, iFrame++)
                {
                    SDL_Rect * rect = new SDL_Rect();
                    rect->x = x;
                    rect->y = y;
                    rect->w = clipWidth;
                    rect->h = clipHeight;
                    
                    clip.push_back( rect );
                }
            }
        }
    }
    
    return success;
}

void Spritesheet::dispose()
{
    for (auto it = clip.begin(); it != clip.end(); ++it)
    {
        delete *it;
    }
    clip.clear();
}

void Spritesheet::draw( SDL_Renderer * renderer, Transform * transform )
{
    //Set clip rendering dimensions
    if( clip.size() > 0 )
    {
        Int2D pos = adjustPosition( transform );
        
        //Set rendering space and render to screen
        SDL_Rect renderQuad = { pos.x, pos.y, texture->getWidth(), texture->getHeight() };
        
        renderQuad.w = clip.at(currentFrame)->w;
        renderQuad.h = clip.at(currentFrame)->h;
        
        //Render to screen
        SDL_RenderCopy( renderer, texture->getTexture(), clip.at(currentFrame), &renderQuad );
        
        nextFrame();
    }
}

void Spritesheet::nextFrame()
{
    currentFrame = totalFrames / frames;
    
    if ( loop && frames>1 )
    {
        if ( currentFrame >= frames )
        {
            currentFrame = 0;
            totalFrames  = 0;
        }
        else
        {
            totalFrames++;
        }
    }
}

Int2D Spritesheet::adjustPosition( Transform * transform )
{
    Int2D position = transform->getPosition() ;
    
    switch ( transform->getAlignment() ) // horizontal
    {
        case TOP_LEFT:
        case CENTER_LEFT:
        case BOTTOM_LEFT:
            break;
            
        case TOP_CENTER:
        case CENTER_CENTER:
        case BOTTOM_CENTER:
            
            position.x -= clipWidth/2;
            
            break;
            
        case TOP_RIGHT:
        case CENTER_RIGHT:
        case BOTTOM_RIGHT:
            
            position.x -= clipWidth;
            
            break;
    }
    
    switch ( transform->getAlignment() ) // vertical
    {
        case TOP_LEFT:
        case TOP_CENTER:
        case TOP_RIGHT:
            break;
            
        case CENTER_LEFT:
        case CENTER_CENTER:
        case CENTER_RIGHT:
            
            position.y -= clipHeight/2;
            
            break;
            
        case BOTTOM_LEFT:
        case BOTTOM_CENTER:
        case BOTTOM_RIGHT:
            
            position.y -= clipHeight;
            
            break;
    }
    
    return position;
}

void Spritesheet::reset()
{
    currentFrame = 0;
}

