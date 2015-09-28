//
//  GameObject.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

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
#include "Transform.hpp"
#include "ObjectState.hpp"
#include "Sound.hpp"

using namespace std;

class GameObject : public Transform
{
    int id;
    ObjectStateType type;
    
    vector<ObjectState *> states;
    
public:
    GameObject(int id, ObjectStateType type);
    ~GameObject();
};

#endif /* GameObject_hpp */
