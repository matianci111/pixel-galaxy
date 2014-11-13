//
//  text.h
//  FirstRPG
//
//  Created by Tianci on 09/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__text__
#define __FirstRPG__text__

#include <iostream>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "SDL_Setup.h"
#include <sstream>
#endif /* defined(__FirstRPG__text__) */

using namespace std;

class text
{
public:
    text(SDL_Setup* passed_sdl_setup, int h, int passed_x, int passed_y, string passed_string);
    ~text(void);
    void writetext();
    
private:
    TTF_Font* font;
    SDL_Surface* message;
    SDL_Texture* Texture_text;
    SDL_Rect textRect;
    SDL_Color textColor;
    SDL_Setup* sdl_setup;
    
    int w;
    int h;
    int x;
    int y;
    string finaltext;
};
