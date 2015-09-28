//
//  Scene.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 26/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene( SceneType type, int code, SDL_Renderer * renderer )
{
    switch ( type )
    {
        case MENU:
            
            break;
            
        case LEVEL:
            
            break;
            
        default:
            break;
    }
    
    this->renderer = renderer;
}

Scene::~Scene()
{
    close();
    
    this->renderer = NULL;
}

bool Scene::load( string path )
{
    bool success = false;
    
    if ( path.find("/texture/") != -1 )
    {
        Texture * temp = new Texture( path );
        if ( temp != NULL && temp->load( renderer ) )
        {
            textures.push_back( temp );
            success = true;
        }
    }
    else if ( path.find("/music/") != -1 )
    {
        Music * temp = new Music( path );
        if ( temp != NULL && temp->load() )
        {
            music.push_back( temp );
            success = true;
        }
    }
    else if ( path.find("/sound/") != -1 )
    {
        Sound * temp = new Sound( path );
        if ( temp != NULL && temp->load())
        {
            sounds.push_back( temp );
            success = true;
        }
    }
    
    cout << "Loading :: " << ((success) ? "success" : "failed ") << path << " . " << endl;
    
    return success;
}

bool Scene::init()
{
    bool success = true;
    
    // examples:
    // load( "asset/texture/name.png" );
    // load( "asset/music/name.ogg" );
    // load( "asset/sound/name.ogg" );
    
    return success;
}

void Scene::close()
{
    for (auto it = players.begin(); it != players.end(); ++it)
    {
        delete *it;
    }
    players.clear();
    
    for (auto it = adversaries.begin(); it != adversaries.end(); ++it)
    {
        delete *it;
    }
    adversaries.clear();
    
    for (auto it = extras.begin(); it != extras.end(); ++it)
    {
        delete *it;
    }
    extras.clear();
    
    for (auto it = textures.begin(); it != textures.end(); ++it)
    {
        delete *it;
    }
    textures.clear();
    
    for (auto it = music.begin(); it != music.end(); ++it)
    {
        delete *it;
    }
    music.clear();
    
    for (auto it = sounds.begin(); it != sounds.end(); ++it)
    {
        delete *it;
    }
    sounds.clear();
}

