//
//  SDL_Setup.h
//  FirstRPG
//
//  Created by Tianci on 06/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__SDL_Setup__
#define __FirstRPG__SDL_Setup__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#endif /* defined(__FirstRPG__SDL_Setup__) */
class SDL_Setup
{
public:
    SDL_Setup(void);
    ~SDL_Setup(void);
    SDL_Event* GetEvent() {return event;}
    SDL_Renderer* GetRenderer() {return renderer;}
    SDL_Texture* GetTexture() {return texture;}
    Uint32* GetPixels() {return pixels;}
    
private:
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Texture * texture;
    Uint32* pixels;
    SDL_Event* event;

};