//
//  SDL_Setup.cpp
//  FirstRPG
//
//  Created by Tianci on 06/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "SDL_Setup.h"

SDL_Setup::SDL_Setup(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Shoot Airplane", 0, 100, 600, 750, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 600, 750);
    pixels = new Uint32[600 * 750];
    memset(pixels, 255, 600 * 750 * sizeof(Uint32));
    event = new SDL_Event;
}

SDL_Setup::~SDL_Setup(void)
{
    SDL_DestroyWindow(window);
    delete[] pixels;
    delete event;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}