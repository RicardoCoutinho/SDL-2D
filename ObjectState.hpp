//
//  ObjectState.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef ObjectState_hpp
#define ObjectState_hpp

// SDL Libraries
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// System libraries
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

// Custom libraries
#include "Types.hpp"
#include "Spritesheet.hpp"

using namespace std;

class ObjectState : public Transform
{
    ObjectStateType state;
    
    Spritesheet * spritesheet;
    
public:
    ObjectState( ObjectStateType state, Spritesheet * spritesheet );
    ~ObjectState();
    
    
};

#endif /* ObjectState_hpp */
