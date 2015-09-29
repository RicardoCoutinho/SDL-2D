//
//  GameObject.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(int id, ObjectStateType type, Transform * transform, vector<ObjectState *> * states)
{
    this->id   = id;
    this->type = type;
    this->transform = transform;
    this->states = states;
}

GameObject::~GameObject()
{
    this->id   = 0;
    this->type = IDLE;
    
    dispose();
}

void GameObject::init()
{
    
}

void GameObject::dispose()
{
    if ( transform != NULL )
    {
        delete transform;
    }
    transform = NULL;
    
    if ( states != NULL )
    {
        for (auto it = states->begin(); it != states->end(); ++it)
        {
            delete *it;
        }
        states->clear();
        
        delete states;
    }
    states = NULL;
}

void GameObject::draw( SDL_Renderer * renderer, Transform * transform )
{
    states->at( type )->draw( renderer, transform );
}