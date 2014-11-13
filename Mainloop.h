//
//  Mainloop.h
//  FirstRPG
//
//  Created by Tianci on 06/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__Mainloop__
#define __FirstRPG__Mainloop__

#include <iostream>
#include "SDL_Setup.h"
#include "Playerjet.h"
#include "Gameupdate.h"
#include "Gamedraw.h"
#include "text.h"
#include "option.h"
#include "savenload.h"

#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2/SDL.h>

#endif /* defined(__FirstRPG__Mainloop__) */
class Mainloop
{
public:
    Mainloop(void);
    ~Mainloop(void);
    void MainGame();
    void Gamelose();
    void Gaming();
    void showoption();
    
    enum optiontype
    {
        nothing,
        newgame,
        score,
        about,
        quitgame
    };
    
private:
    bool gamequit;
    
    Uint32* pixels;
    SDL_Texture* texture;
    SDL_Setup* sdl_setup;
    
    int MouseX;
    int MouseY;
    
    Playerjet* Player;
    Gamedraw* draw;
    Gameupdate* update;
    SDL_Texture* background;
    SDL_Rect rect;
    Uint32* galaxy;
    int pitch;
    bool gamelose;
    bool atoption;
    int returned_optiontype;
    
    option* entergame;
    option* scoreboard;
    option* creditboard;
    option* gamepause;
    int currenttype;
    int timecheck;
    int n;
 
    savenload* load;
    vector<int> scores;
    
    Mix_Music* music;
    bool playmusic;
};
