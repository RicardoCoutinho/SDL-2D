//
//  Sound.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Sound_hpp
#define Sound_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>

// System libraries
#include <stdio.h>
#include <string>
#include <regex>

using namespace std;

const string REGEX_SOUND = "^.*\\.(flac|ogg|oga|mp3)$";

class Sound
{
    string path;
    Mix_Chunk * sound;
    
public:
    
    Sound( string path );
    ~Sound();
    
    bool load();
    
    void dispose();
    
    void play();
    
    string getPath();
};

#endif /* Sound_hpp */
