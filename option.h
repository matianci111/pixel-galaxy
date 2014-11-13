//
//  option.h
//  FirstRPG
//
//  Created by Tianci on 13/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__option__
#define __FirstRPG__option__

#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "Gamedraw.h"
#include "Gameupdate.h"
#include "text.h"
#include <sstream>

using namespace std;

#endif /* defined(__FirstRPG__option__) */
class option
{
public:
    option(SDL_Setup* passed_sdl_setup, Gameupdate* passed_update, Uint32* passed_pixels);
    ~option(void);
    void drawblocks(int passed_mousex, int passed_mousey, int xoff, int yoff, int h, int w, Uint32* passed_pixels);
    void drawtexts(int h, int xoff, int yoff, string str);
    bool mousecheck(int passed_mousex, int passed_mousey, int xoff, int yoff, int x_w, int y_h);
    void drawscores(vector<int> passed_scores);
    
private:
    int mousex;
    int mousey;

    Gamedraw* draw;
    SDL_Setup* sdl_setup;
    Gameupdate* update;
    Uint32* pixels;
    text* Text;
    bool mousepressed;
    
};