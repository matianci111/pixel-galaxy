//
//  bullet.cpp
//  FirstRPG
//
//  Created by Tianci on 08/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "bullet.h"
bullet::bullet(int passed_x, int passed_y)
{
    locationx = passed_x;
    locationy = passed_y;
}
bullet::~bullet(void)
{
    
}

void bullet::draw(Uint32* passed_pixels){
    pixels = passed_pixels;

    for(int i=-5; i<10; i++)
    {
        for(int j=-2; j<2; j++)
        {
            if(!(locationy+i <= 0 || locationy+i >= 750 || locationx+j <= 0 || locationx+j >= 600))
            {
                pixels[(locationy+i) * 600 + (locationx+j)] = (0xFF << 24) | (0x00 << 16) | (0xFF << 8) | 0xFF ;
            }
        }
    }
}
