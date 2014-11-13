//
//  Gamedraw.h
//  FirstRPG
//
//  Created by Tianci on 07/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__Gamedraw__
#define __FirstRPG__Gamedraw__

#include <iostream>
#include "Gameupdate.h"
#include "Enemies.h"
#include "text.h"
#include <sstream>

#endif /* defined(__FirstRPG__Gamedraw__) */
class Gamedraw
{
public:
    Gamedraw(Uint32* passed_pixels, Gameupdate* passed_update, SDL_Setup* passed_sdl_setup);
    ~Gamedraw(void);
    void drawenemy(Uint32* passed_pixels);
    void drawscore(int x, int y, int size);
    void drawexplosion(Uint32* passed_pixels);
    void drawred(Uint32* pixels, int n, int i, int explosionx, int explosiony);
    void draworange(Uint32* pixels, int n, int i, int expx, int expy);
    void drawrect(int x, int y, int h, int w, Uint32* passed_pixels);
    void fillrect(int x, int y, int h, int w, Uint32* passed_pixels);

    
private:
    vector<Enemies*> jets;
    vector<Enemies*> meteors;
    vector<bullet*> bullets;
    vector<Enemies*> locations;

    
    Uint32* pixels;
    Gameupdate* update;
    SDL_Setup* sdl_setup;
    
    text* Text;
    int score;
    int explosionx;
    int explosiony;
    int frames;

};
