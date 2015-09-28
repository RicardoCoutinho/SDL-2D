//
//  SDLApp.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef SDLApp_hpp
#define SDLApp_hpp

// SDL Libraries
#include <SDL2/SDL.h>

// system libraries
#include <stdio.h>
#include <iostream>
#include <ostream>

// custom libraries
#include "Game.hpp"
#include "Timer.hpp"

using namespace std;

class SDLApp {
    
    const int SCREEN_WIDTH  = 500;
    const int SCREEN_HEIGHT = 500;
    
    SDL_Window   * window;
    SDL_Renderer * renderer;
    
protected:
    
    Game * game;
    
public:
    
    SDLApp();
    
    bool init();
    void close();
    void run();
};

#endif /* SDLApp_hpp */
