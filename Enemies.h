//
//  Enemies.h
//  FirstRPG
//
//  Created by Tianci on 07/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__Enemies__
#define __FirstRPG__Enemies__

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

#endif /* defined(__FirstRPG__Enemies__) */
class Enemies
{
public:
    Enemies(int passed_x, int passed_y, int type);
    ~Enemies(void);
    
    enum enemytype
    {
        jet,
        meteor
    };
    int GetX() {return locationx;}
    int GetY() {return locationy;}

    
    int Getframe() {return frame;}
    void incframe() {frame++;}
    void draw(Uint32* passed_pixels);
    void move(int x) {locationy = locationy+x;}
    void drawgrey(Uint32* pixels, int n, int i);
    void drawred(Uint32* pixels, int n, int i);
    void drawdgrey(Uint32* pixels, int n, int i);
    void drawyellow(Uint32* pixels, int n, int i);
    int gettimecheck() {return timecheck;}
    void settimecheck(int g) {timecheck =g;}
    
private:
    int locationx;
    int locationy;
    int type;
    Uint32* pixels;
    int frame;
    int timecheck;

};