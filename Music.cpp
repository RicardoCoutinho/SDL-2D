//
//  Music.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Music.hpp"

Music::Music( string path )
{
    this->path = path;
    music = NULL;
}

Music::~Music()
{
    path = "";
    dispose();
}

bool Music::load()
{
    dispose();
    
    bool success = true;
    regex regexp { REGEX_MUSIC , regex_constants::ECMAScript };
    
    if ( regex_match( path, regexp ) )
    {
        music = Mix_LoadMUS( path.c_str() );
        
        if( music == NULL )
        {
            printf( "Failed to load music from %s! SDL_mixer Error: %s\n", path.c_str(), Mix_GetError() );
            success = false;
        }
    }
    else
    {
        printf( "Failed to load music from %s! Incompatible format\n", path.c_str() );
        success = false;
    }
    
    return success;
}

void Music::dispose()
{
    if ( music != NULL )
    {
        Mix_FreeMusic( music );
        music = NULL;
    }
}

void Music::play()
{
    //If music is playing
    if( Mix_PlayingMusic() != 0 )
    {
        stop();
    }
    
    //Play the music
    Mix_PlayMusic( music, -1 );
}

void Music::resume()
{
    //If the music is playing and not paused
    if( Mix_PlayingMusic() != 0 && Mix_PausedMusic() != 1)
    {
        //Resume the music
        Mix_ResumeMusic();
    }
}

void Music::pause()
{
    //If the music is playing and paused
    if( Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 1 )
    {
        //Resume the music
        Mix_ResumeMusic();
    }
}

void Music::stop()
{
    Mix_HaltMusic();
}

string Music::getPath()
{
    return path;
}
