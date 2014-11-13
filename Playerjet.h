//
//  Playerjet.h
//  FirstRPG
//
//  Created by Tianci on 06/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__Playerjet__
#define __FirstRPG__Playerjet__

#include <iostream>
#include <SDl2/SDL.h>

#endif /* defined(__FirstRPG__Playerjet__) */
class Playerjet
{
public:
    Playerjet(int Passed_MousedX, int Passed_MouseY, Uint32* passed_pixel);
    ~Playerjet(void);
    void Drawjet(int Passed_MousedX, int Passed_MouseY);
    
    void drawgrey(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY);
    void drawred(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY);
    void drawdgrey(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY);
    void drawyellow(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY);
    
    int GetX() {return locationx;}
    int GetY() {return locationy;}
    
private:
    int MouseX;
    int MouseY;
    int locationx;
    int locationy;
    
    Uint32* pixels;
};