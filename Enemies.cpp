//
//  Enemies.cpp
//  FirstRPG
//
//  Created by Tianci on 07/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "Enemies.h"
Enemies::Enemies(int passed_x, int passed_y, int passed_type)
{
    locationx = passed_x;
    locationy = passed_y;
    type = passed_type;
    frame = 0;
    timecheck = SDL_GetTicks();
}
Enemies::~Enemies(void)
{
    
}

void Enemies::draw(Uint32* passed_pixels){
    pixels = passed_pixels;
    if(!(locationy+70 > 750))
    {
        if(type == jet)
        {
            for(int i=-20; i<20; i++)
            {
                for(int j=20; j<=24; j++)
                drawgrey(pixels, j, i);
            }
            for(int i=-18; i<18; i++)
            {
                for(int j=17; j<=19; j++)
                    drawgrey(pixels, j, i);
                for(int j=25; j<=28; j++)
                    drawgrey(pixels, j, i);
            }
            for(int i=-16; i<16; i++)
            {
                for(int j=29; j<=31; j++)
                    drawgrey(pixels, j, i);
            }
            for(int i=-14; i<14; i++)
            {
                for(int j=13; j<=16; j++)
                    drawgrey(pixels, j, i);
                for(int j=32; j<=36; j++)
                    drawgrey(pixels, j, i);
               
            }
            for(int i=-12; i<12; i++)
            {
                for(int j=9; j<=12; j++)
                    drawgrey(pixels, j, i);
                for(int j=37; j<=40; j++)
                    drawgrey(pixels, j, i);
                
            }
            for(int i=-10; i<10; i++)
            {
                for(int j=7; j<=8; j++)
                    drawgrey(pixels, j, i);
                for(int j=41; j<=45; j++)
                    drawgrey(pixels, j, i);
                
            }
            for(int i=-8; i<8; i++)
            {
                for(int j=46; j<=50; j++)
                    drawgrey(pixels, j, i);
               
            }
            for(int i=-5; i<5; i++)
            {

                for(int j=50; j<=53; j++)
                    drawgrey(pixels, j, i);
                
            }
            for(int i=-3; i<3; i++)
            {
                
                for(int j=53; j<=56; j++)
                    drawgrey(pixels, j, i);
                
            }
            //below draw glass
            for(int i=-8; i<8; i++)
            {
                
                for(int j=32; j<=43; j++)
                    drawred(pixels, j, i);
                
            }
            for(int i=-7; i<7; i++)
            {
                drawred(pixels, 44, i);
                drawred(pixels, 31, i);
                
            }
            for(int i=-6; i<6; i++)
            {

                drawred(pixels, 30, i);
                drawred(pixels, 45, i);
            }
            //draw rear
            for(int n=6; n<=17;n++)
            {
                drawdgrey(pixels, n, -11);
                drawdgrey(pixels, n, -3);
                drawdgrey(pixels, n, 10);
                drawdgrey(pixels, n, 2);
                for(int j=-10; j<=-4; j++)
                    drawyellow(pixels, n, j);
                for(int j=3; j<=9; j++)
                    drawyellow(pixels, n, j);

            }
            for(int i=-10;i<-4;i++)
                drawdgrey(pixels, 5, i);
            for(int i=3;i<9;i++)
                drawdgrey(pixels, 5, i);
            for(int i=3;i<9;i++)
                drawdgrey(pixels, 18, i);
            for(int i=-10;i<-4;i++)
                drawdgrey(pixels, 18, i);
            

            
        }
        if(type == meteor)
        {
            for(int i=-26;i<=26;i++)
                for(int j =6; j<=44;j++)
                drawyellow(pixels, j, i);
            for(int i=-24;i<=24;i++)
            {
                drawyellow(pixels, 4, i);
                 drawyellow(pixels, 5, i);
                drawyellow(pixels, 46, i);
                drawyellow(pixels, 45, i);
            }
            for(int i=-22;i<=22;i++)
            {
                drawyellow(pixels, 2, i);
                drawyellow(pixels, 3, i);
                drawyellow(pixels, 48, i);
                drawyellow(pixels, 47, i);
            }
            for(int i=-20;i<=20;i++)
            {
                drawyellow(pixels, 0, i);
                drawyellow(pixels, 1, i);
                drawyellow(pixels, 50, i);
                drawyellow(pixels, 49, i);
            }
        }
    }
}

void Enemies::drawgrey(Uint32* pixels, int n, int i)
{
    pixels[(locationy+n) * 600 + (locationx+i)] = (0xFF << 24) | (0x80 << 16) | (0x80 << 8) | 0x80 ;
}

void Enemies::drawred(Uint32* pixels, int n, int i)
{
    pixels[(locationy+n) * 600 + (locationx+i)] = (0xFF << 24) | (0x80 << 16) | (0x00 << 8) | 0x00 ;
}

void Enemies::drawdgrey(Uint32* pixels, int n, int i)
{
    pixels[(locationy+n) * 600 + (locationx+i)] = (0xFF << 24) | (0x69 << 16) | (0x69 << 8) | 0x69 ;
}
void Enemies::drawyellow(Uint32* pixels, int n, int i)
{
    pixels[(locationy+n) * 600 + (locationx+i)] = (0xFF << 24) | (0xDA << 16) | (0xA5 << 8) | 0x20 ;
}