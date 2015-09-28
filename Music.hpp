//
//  Music.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Music_hpp
#define Music_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>

// System libraries
#include <stdio.h>
#include <string>

using namespace std;

const string REGEX_MUSIC = "^.*\\.(flac|ogg|oga|mp3)$";

class Music
{
    string path;
    Mix_Music * music;
    
public:
    
    Music( string path );
    ~Music();
    
    bool load();
    
    void dispose();
    
    void play();
    void resume();
    void pause();
    void stop();
    
    string getPath();
    
};

#endif /* Music_hpp */
