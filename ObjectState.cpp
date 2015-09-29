//
//  ObjectState.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "ObjectState.hpp"

ObjectState::ObjectState( ObjectStateType state, Spritesheet * spritesheet )
{
    this->state       = state;
    this->spritesheet = spritesheet;
}

ObjectState::~ObjectState()
{
    delete spritesheet;
}

void ObjectState::draw( SDL_Renderer * renderer, Transform * transform )
{
    spritesheet->draw( renderer, transform );
}