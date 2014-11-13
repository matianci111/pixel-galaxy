//
//  Gameupdate.h
//  FirstRPG
//
//  Created by Tianci on 07/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__Gameupdate__
#define __FirstRPG__Gameupdate__

#include <iostream>
#include "Enemies.h"
#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "SDL_Setup.h"
#include "bullet.h"
#include <SDL2_mixer/SDL_mixer.h>

using namespace std;

#endif /* defined(__FirstRPG__Gameupdate__) */
class Gameupdate
{
public:
    Gameupdate(SDL_Setup* passed_sdl_setup);
    ~Gameupdate(void);
    void enemyspawn();
    void enemyupdate();
    void enemydespawn();
    void bulletspawn(int Passed_MousedX, int Passed_MouseY);
    void difficulty();
    
    void collision(int passed_x, int passed_y);
    bool checklose(int passed_locationx, int passed_locationy);
    void explosionfinish(int i);
    void initialize();
    
    
    vector<Enemies*> Getlocations() {return locations;}
    vector<Enemies*> Getjets() {return jets;}
    vector<Enemies*> Getmeteors() {return meteors;}
    vector<bullet*> Getbullets() {return bullets;}
    int Getscore() {return score;}
    
    
    
private:
    vector<Enemies*> jets;
    vector<Enemies*> meteors;
    vector<bullet*> bullets;
    vector<Enemies*> locations;
    
    int enemymax;
    int enemycurrent;
    int type;
    int startingx;
    
    int MouseX;
    int MouseY;
    
    int locationx;
    int locationy;
    
    Enemies* enemy;
    Enemies* player;
    bullet* bul;
    int animationdelay;
    int timecheck;
    int difficultycheck;
    
    SDL_Setup* sdl_setup;
    bool pressed;
    int score;
    
    bool Gamelose;
    bool explosionlose;
    Mix_Chunk* laser;
    Mix_Chunk* blast;
    bool lasersound;
    int spawnspeed;
    int divisionspawn;
    int divisionline;
    
};