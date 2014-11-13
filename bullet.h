//
//  bullet.h
//  FirstRPG
//
//  Created by Tianci on 08/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__bullet__
#define __FirstRPG__bullet__

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>


#endif /* defined(__FirstRPG__bullet__) */
class bullet
{
public:
    bullet(int passed_x, int passed_y);
    ~bullet(void);
    
    int GetX() {return locationx;}
    int GetY() {return locationy;}
    void draw(Uint32* passed_pixels);
    void move() {locationy = locationy-13;}
    
private:
    int locationx;
    int locationy;
    Uint32* pixels;
};