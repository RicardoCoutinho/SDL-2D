//
//  SDLApp.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "SDLApp.hpp"

SDLApp::SDLApp()
{
    window = NULL;
    game   = NULL;
}

// Initialize application display variables
bool SDLApp::init(const char * title, int posX, int posY, int width, int height, bool fullscreen)
{
    bool success = true;
    int flags;
    
    // Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
            success = false;
        }
        
        if ( fullscreen )
        {
            flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
        }
        else
        {
            flags = SDL_WINDOW_SHOWN;
        }
        
        // Create window
        window = SDL_CreateWindow( title, posX, posY, width, height, flags );
        
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            // Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                
                // Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
                
                // Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
            
            game = new Game( renderer );
            
            return true;
        }
    }
    
    return success;
}

// Initialize application display variables
bool SDLApp::init()
{
    return init( "SDL App Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, false );
}

// Close and delete every allocated asset
void SDLApp::close()
{
    delete game;
    game = NULL;
    
    //Destroy window & renderer
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window   = NULL;
    renderer = NULL;
    
    //Quit SDL subsystems
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

// Run SDL application
void SDLApp::run()
{
    
    // just a poor initialization
    
    Text * exampleText = new Text( "asset/font/Treamd.ttf", 30 );
    
    Texture * texture = new Texture( "asset/texture/foo.png" );
    texture->load( renderer );

    Spritesheet * spritesheet = new Spritesheet( texture, 4, 64, 205, {0,0xFF,0xFF,1} );
    
    Transform * transform = new Transform( {250,250}, {1.0,1.0}, 0.0, CENTER_CENTER );
    
    bool
        quit = false, //Main loop flag
        keyDown;
    
    // Event handler
    SDL_Event e;
    
    Timer
        fpsTimer, // The frames per second timer
        capTimer; // The frames per second cap timer
    
    float avgFPS;
    
    // Start counting frames per second
    int countedFrames = 0, frameTicks;
    
    // In memory text stream
    stringstream timeText;
    
    // Start frames per second timer
    fpsTimer.start();
    
    // While application is running
    while( !quit )
    {
        countedFrames++;
        keyDown = false;
        
        // Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            switch( e.type )
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    keyDown = true;
                    break;
                case SDL_KEYUP:
                    if ( e.key.keysym.scancode == SDL_SCANCODE_ESCAPE ) { quit = true; }
                    keyDown = false;
                    break;
                default:
                    break;
            }
        }
     
        // Calculate and correct fps
        avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        
        // Set text to be rendered
        //cout << "Average Frames Per Second (With Cap): " << avgFPS << endl;
        
        
        //Clear screen
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        
        // Apply the image
        //  SDL_RenderCopy( renderer, backgroundTex, NULL, NULL );
        //SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
        
        /*
         
         INSERT
         
         CODE
         
         HERE
         
         */
        
        exampleText->draw( renderer, { 250, 50 }, { 0x00, 0x00, 0x00, 0xFF }, "example text" );
        
        spritesheet->draw( renderer, transform );
        
        
        // Update the surface
        SDL_UpdateWindowSurface( window );
        
        // Update screen
        SDL_RenderPresent( renderer );
        
        // If frame finished early
        frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICK_PER_FRAME )
        {
            // Wait remaining time
            SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
        }
    }
}
