//
//  GameObject.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 24/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(int id, ObjectStateType type)
{
    this->id   = id;
    this->type = type;
    
    states.clear();
}

GameObject::~GameObject()
{
    for (auto it = states.begin(); it != states.end(); ++it)
    {
        delete *it;
    }
    states.clear();
}

