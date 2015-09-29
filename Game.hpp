//
//  Game.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

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

// Custom libraries
#include "Types.hpp"
#include "Scene.hpp"

using namespace std;

class Game
{
    SDL_Renderer * renderer;
    
    // current scene in use
    Scene * scene;
    
    // temporary scene for transitions between scenes
    Scene * temp;
    
    // Game related variables from scenes/configuration
    // examples:
    // unsigned int highestScore;
    // int config_gameSpeed;
    // ...
    
public:
    Game( SDL_Renderer * renderer );
    ~Game();
    
    // initialize game scenes
    bool init();
    
    // close all scenes
    void close();
    
    // close temporary scene
    void closeTemp();
    
    // run game as a scene manager
    void run();
    
};

#endif /* Game_hpp */
