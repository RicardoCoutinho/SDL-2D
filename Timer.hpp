//
//  Timer.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

// SDL Libraries
#include <SDL2/SDL.h>

// System libraries
#include <stdio.h>
#include <sstream>

using namespace std;

// Global variables
const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

// The application time based timer
class Timer
{
    // The clock time when the timer started
    Uint32 mStartTicks;
    
    // The ticks stored when the timer was paused
    Uint32 mPausedTicks;
    
    // The timer status
    bool mPaused;
    bool mStarted;
    
public:
    // Initializes variables
    Timer();
    
    // The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();
    
    // Gets the timer's time
    Uint32 getTicks();
    
    // Checks the status of the timer
    bool isStarted();
    bool isPaused();
};


#endif /* Timer_hpp */
