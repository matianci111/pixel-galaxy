//
//  main.cpp
//  FirstRPG
//
//  Created by Tianci on 01/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_Setup.h"
#include "Mainloop.h"
#include <cstdlib>
#include <ctime>
#include <SDL2_ttf/SDL_ttf.h>
using namespace std;

int main(int argc, const char * argv[])
{
    Mainloop* maingame = new Mainloop;
    maingame->MainGame();
    delete maingame;
    return 0;
    
}




   
