//
//  main.cpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#include "SDLApp.hpp"

int main(int argc, const char * argv[])
{
    SDLApp * app = new SDLApp();
    
    if ( app->init() )
    {
        app->run();
    }
    
    app->close();
    
    return 0;
}