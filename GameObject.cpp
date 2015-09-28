//
//  GameObject.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(int id, ObjectStateType type, vector<ObjectState *> * states)
{
    this->id   = id;
    this->type = type;
    this->states = states;
    

}

GameObject::~GameObject()
{
    if ( states != NULL )
    {
        for (auto it = states->begin(); it != states->end(); ++it)
        {
            delete *it;
        }
        states->clear();
        
        delete states;
    }
}

void GameObject::init()
{
    
}

void GameObject::dispose()
{

}

void GameObject::draw()
{
    
}