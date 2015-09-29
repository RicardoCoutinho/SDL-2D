//
//  Game.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Game.hpp"

Game::Game( SDL_Renderer * renderer )
{
    this->renderer = renderer;
    
    init();
}

Game::~Game()
{
    renderer = NULL;
    
    close();
}

bool Game::init()
{
    bool success = true;
    
    scene = new Scene( LEVEL, 0, renderer );
    
    if ( scene == NULL )
    {
        success = false;
    }
    
    return success;
}

void Game::close()
{
    if ( scene != NULL )
    {
        delete scene;
    }
    scene = NULL;
    
    if ( temp != NULL )
    {
        delete temp;
    }
    temp = NULL;
}

void Game::closeTemp()
{
    if ( temp != NULL )
    {
        delete temp;
    }
    temp = NULL;
}

void Game::run()
{
    scene->run();

}

