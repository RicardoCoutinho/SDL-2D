//
//  Texture.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Texture.hpp"


Texture::Texture( string path )
{
    this->path = path;
    texture = NULL;
    
    width = 0;
    height = 0;
}

Texture::~Texture()
{
    path = "";
    dispose();
    
    width = 0;
    height = 0;
}

bool Texture::load( SDL_Renderer * renderer )
{
    dispose();
    
    bool success = true;
    
    SDL_Surface * surface = IMG_Load( path.c_str() );
    
    if( surface == NULL )
    {
        printf( "Unable to load image from %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        
        if ( texture == NULL)
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            success = false;
        }
        else
        {
            width  = surface->w;
            height = surface->h;
        }
        
        SDL_FreeSurface( surface );
    }
    
    return success;
}

void Texture::dispose()
{
    if ( texture != NULL )
    {
        SDL_DestroyTexture( texture );
        texture = NULL;
    }
}

void Texture::draw( SDL_Renderer * renderer, Int2D position, SDL_Rect * clip )
{
    Int2D pos = position; //position2DwithAlignment( position,  );
    
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { pos.x, pos.y, width, height };
    
    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    //Render to screen
    SDL_RenderCopy( renderer, texture, clip, &renderQuad );
}

Int2D Texture::adjustPosition( Transform * transform )
{
    Int2D position = transform->getPosition();
    
    switch ( transform->getAlignment() ) // horizontal
    {
        case TOP_LEFT:
        case CENTER_LEFT:
        case BOTTOM_LEFT:
            break;
            
        case TOP_CENTER:
        case CENTER_CENTER:
        case BOTTOM_CENTER:
            
            position.x -= width/2;
            
            break;
            
        case TOP_RIGHT:
        case CENTER_RIGHT:
        case BOTTOM_RIGHT:
            
            position.x -= width;
            
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
            
            position.y -= height/2;
            
            break;
            
        case BOTTOM_LEFT:
        case BOTTOM_CENTER:
        case BOTTOM_RIGHT:
            
            position.y -= height;
            
            break;
    }
    
    return position;
}

string Texture::getPath()
{
    return path;
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}

SDL_Texture * Texture::getTexture()
{
    return texture;
}

void Texture::setTexture( SDL_Texture * texture )
{
    this->texture = texture;
}

void Texture::setWidth( int width )
{
    this->width = width;
}

void Texture::setHeight( int height )
{
    this->height = height;
}