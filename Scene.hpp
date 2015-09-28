//
//  Scene.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 26/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

// System libraries
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Custom libraries
#include "Types.hpp"
#include "GameObject.hpp"
#include "Music.hpp"

using namespace std;

class Scene
{
    vector<GameObject *> players;
    vector<GameObject *> adversaries;
    vector<GameObject *> extras;
    
    vector<Texture *> textures;
    vector<Music *>   music;
    vector<Sound *>   sounds;
    
    
    SDL_Renderer * renderer;
    
    // loading assets
    bool load( string path );
    
public:
    Scene( SceneType type, int code, SDL_Renderer * renderer );
    ~Scene();
    
    // initialize scene resources
    bool init();
    
    // close scene
    void close();
    
    // run scene logic
    void run();
};

#endif /* Scene_hpp */
