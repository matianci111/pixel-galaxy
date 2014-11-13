//
//  Gamedraw.cpp
//  FirstRPG
//
//  Created by Tianci on 07/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "Gamedraw.h"
Gamedraw::Gamedraw(Uint32* passed_pixels, Gameupdate* passed_update, SDL_Setup* passed_sdl_setup)
{
    sdl_setup = passed_sdl_setup;
    pixels = passed_pixels;
    update = passed_update;
}

Gamedraw::~Gamedraw(void)
{
    jets.clear();
    meteors.clear();
    bullets.clear();
    locations.clear();
}

void Gamedraw::drawenemy(Uint32* passed_pixels)
{
    jets = update->Getjets();
    meteors = update->Getmeteors();
    bullets = update->Getbullets();
    for(int i=0; i<bullets.size(); i++)
    {
        bullets[i]->draw(passed_pixels);
    }
    for(int i=0; i<jets.size(); i++)
    {
        jets[i]->draw(passed_pixels);
    }
    for(int i=0; i<meteors.size(); i++)
    {
        meteors[i]->draw(passed_pixels);
    }
}

void Gamedraw::drawscore(int x, int y, int size)
{
    score = update->Getscore();
    string str;
    str = to_string(score);
    Text = new text(sdl_setup, size, x, y, str);
    Text->writetext();
    delete Text;
    
}

void Gamedraw::drawexplosion(Uint32* passed_pixels)
{
    pixels = passed_pixels;
    locations = update->Getlocations();
    if(!locations.empty())
    {
        for(int i=0; i<locations.size();i++)
        {
            explosionx = locations[i]->GetX();
            explosiony = locations[i]->GetY();

            if(locations[i]->Getframe()==0)
            {
                locations[i]->settimecheck(SDL_GetTicks());
                locations[i]->incframe();
            }
            
            if(locations[i]->Getframe()==1)
            {
                for(int k=-5; k<5;k++)
                {
                    drawred(pixels, 0, k, explosionx, explosiony);
                    drawred(pixels, 30, k, explosionx, explosiony);
                }
                for(int k=-7; k<7;k++)
                {
                    drawred(pixels, 1, k, explosionx, explosiony);
                    drawred(pixels, 29, k, explosionx, explosiony);
                }
                for(int k=-9; k<9;k++)
                {
                    drawred(pixels, 2, k, explosionx, explosiony);
                    drawred(pixels, 28, k, explosionx, explosiony);
                }
                for(int k=-10; k<10;k++)
                {
                    drawred(pixels, 3, k, explosionx, explosiony);
                    drawred(pixels, 27, k, explosionx, explosiony);
                }
                for(int k=-11; k<11;k++)
                {
                    drawred(pixels, 4, k, explosionx, explosiony);
                    drawred(pixels, 26, k, explosionx, explosiony);
                }
                for(int k=-12; k<12;k++)
                {
                    drawred(pixels, 5, k, explosionx, explosiony);
                    drawred(pixels, 27, k, explosionx, explosiony);
                }
                for(int k=-13; k<13;k++)
                {
                    drawred(pixels, 6, k, explosionx, explosiony);
                    drawred(pixels, 7, k, explosionx, explosiony);
                    drawred(pixels, 26, k, explosionx, explosiony);
                    drawred(pixels, 25, k, explosionx, explosiony);
                }
                for(int k=-14; k<14;k++)
                {
                    drawred(pixels, 8, k, explosionx, explosiony);
                    drawred(pixels, 9, k, explosionx, explosiony);
                    drawred(pixels, 24, k, explosionx, explosiony);
                    drawred(pixels, 23, k, explosionx, explosiony);
                }
                for(int k=-15; k<15;k++)
                {
                    for(int j=10; j<=22; j++)
                    {
                        drawred(pixels, j, k, explosionx, explosiony);
                    }
                }
                if(locations[i]->gettimecheck()+150<SDL_GetTicks())
                {
                locations[i]->incframe();
                locations[i]->settimecheck(SDL_GetTicks());
                }
            }
            if(locations[i]->Getframe()==2)
            {
                for(int k=-8; k<8;k++)
                {
                    drawred(pixels, -3, k, explosionx, explosiony);
                    drawred(pixels, 33, k, explosionx, explosiony);
                }
                for(int k=-10; k<10;k++)
                {
                    drawred(pixels, -2, k, explosionx, explosiony);
                    drawred(pixels, 32, k, explosionx, explosiony);
                }
                for(int k=-12; k<12;k++)
                {
                    drawred(pixels, -1, k, explosionx, explosiony);
                    drawred(pixels, 31, k, explosionx, explosiony);
                }
                for(int k=-13; k<13;k++)
                {
                    drawred(pixels, 0, k, explosionx, explosiony);
                    drawred(pixels, 30, k, explosionx, explosiony);
                }
                for(int k=-14; k<14;k++)
                {
                    drawred(pixels, 1, k, explosionx, explosiony);
                    drawred(pixels, 29, k, explosionx, explosiony);
                }
                for(int k=-15; k<15;k++)
                {
                    drawred(pixels, 2, k, explosionx, explosiony);
                    drawred(pixels, 28, k, explosionx, explosiony);
                }
                for(int k=-16; k<16;k++)
                {
                    drawred(pixels, 3, k, explosionx, explosiony);
                    drawred(pixels, 4, k, explosionx, explosiony);
                    drawred(pixels, 27, k, explosionx, explosiony);
                    drawred(pixels, 26, k, explosionx, explosiony);
                }
                for(int k=-17; k<17;k++)
                {
                    drawred(pixels, 5, k, explosionx, explosiony);
                    drawred(pixels, 6, k, explosionx, explosiony);
                    drawred(pixels, 25, k, explosionx, explosiony);
                    drawred(pixels, 24, k, explosionx, explosiony);
                }
                for(int k=-18; k<18;k++)
                {
                    for(int j=7; j<=23; j++)
                    {
                        drawred(pixels, j, k, explosionx, explosiony);
                    }
                }

                if(locations[i]->gettimecheck()+150<SDL_GetTicks())
                {
                locations[i]->incframe();
                locations[i]->settimecheck(SDL_GetTicks());
                }
            }
            if(locations[i]->Getframe()==3)
            {
                for(int k=-5; k<5;k++)
                {
                    drawred(pixels, -8, k, explosionx, explosiony);
                    drawred(pixels, 37, k, explosionx, explosiony);
                }
                for(int k=-9; k<9;k++)
                {
                    drawred(pixels, -7, k, explosionx, explosiony);
                    drawred(pixels, 36, k, explosionx, explosiony);
                }
                for(int k=-11; k<11;k++)
                {
                    drawred(pixels, -6, k, explosionx, explosiony);
                    drawred(pixels, 35, k, explosionx, explosiony);
                }
                for(int k=-13; k<13;k++)
                {
                    drawred(pixels, -5, k, explosionx, explosiony);
                    drawred(pixels, 34, k, explosionx, explosiony);
                }
                for(int k=-15; k<15;k++)
                {
                    drawred(pixels, -4, k, explosionx, explosiony);
                    drawred(pixels, 33, k, explosionx, explosiony);
                }
                for(int k=-16; k<16;k++)
                {
                    drawred(pixels, -3, k, explosionx, explosiony);
                    drawred(pixels, 32, k, explosionx, explosiony);
                }
                for(int k=-17; k<17;k++)
                {
                    drawred(pixels, -2, k, explosionx, explosiony);
                    drawred(pixels, 31, k, explosionx, explosiony);
                }
                for(int k=-18; k<18;k++)
                {
                    drawred(pixels, -1, k, explosionx, explosiony);
                    drawred(pixels, 30, k, explosionx, explosiony);
                }
                for(int k=-19; k<19;k++)
                {
                    drawred(pixels, 0, k, explosionx, explosiony);
                    drawred(pixels, 29, k, explosionx, explosiony);
                }
                for(int k=-20; k<20;k++)
                {
                    drawred(pixels, 1, k, explosionx, explosiony);
                    drawred(pixels, 28, k, explosionx, explosiony);
                }
                for(int k=-21; k<21;k++)
                {
                    drawred(pixels, 2, k, explosionx, explosiony);
                    drawred(pixels, 27, k, explosionx, explosiony);
                    drawred(pixels, 3, k, explosionx, explosiony);
                    drawred(pixels, 26, k, explosionx, explosiony);
                }
                for(int k=-22; k<22;k++)
                {
                    drawred(pixels, 4, k, explosionx, explosiony);
                    drawred(pixels, 25, k, explosionx, explosiony);
                }
                for(int k=-23; k<23;k++)
                {
                    drawred(pixels, 5, k, explosionx, explosiony);
                    drawred(pixels, 6, k, explosionx, explosiony);
                    drawred(pixels, 24, k, explosionx, explosiony);
                    drawred(pixels, 23, k, explosionx, explosiony);
                }
                for(int k=-24; k<24;k++)
                {
                    drawred(pixels, 8, k, explosionx, explosiony);
                    drawred(pixels, 9, k, explosionx, explosiony);
                    drawred(pixels, 7, k, explosionx, explosiony);
                    drawred(pixels, 22, k, explosionx, explosiony);
                    drawred(pixels, 21, k, explosionx, explosiony);
                    drawred(pixels, 20, k, explosionx, explosiony);
                }
                for(int k=-25; k<25;k++)
                {
                    for(int j=10; j<=19; j++)
                    {
                        drawred(pixels, j, k, explosionx, explosiony);
                    }
                }
                if(locations[i]->gettimecheck()+150<SDL_GetTicks())
                {
                delete locations[i];
                locations.erase(locations.begin()+i);
                update->explosionfinish(i);
                
                }
            }
           
        }
    }
}

void Gamedraw::drawred(Uint32* pixels, int n, int i, int expx, int expy)
{
    pixels[(expy+n) * 600 + (expx+i)] = (0xFF << 24) | (0xFF << 16) | (0x00 << 8) | 0x00 ;
}

void Gamedraw::draworange(Uint32* pixels, int n, int i, int expx, int expy)
{
    pixels[(expy+n) * 600 + (expx+i)] = (0xFF << 24) | (0xFF << 16) | (0xFF << 8) | 0xFF ;
}

void Gamedraw::drawrect(int x, int y, int h, int w, Uint32* passed_pixels)
{
    for(int i=0; i<w;i++)
    {
        draworange(passed_pixels, 0, i, x, y);
        draworange(passed_pixels, 1, i, x, y);
    }
    for(int i=0; i<h;i++)
    {
        draworange(passed_pixels, i, 0, x, y);
        draworange(passed_pixels, i, 1, x, y);
        draworange(passed_pixels, i, w-1, x, y);
        draworange(passed_pixels, i, w, x, y);
    }
    for(int i=0; i<w;i++)
    {
        draworange(passed_pixels, h, i, x, y);
        draworange(passed_pixels, h-1, i, x, y);
    }
}

void Gamedraw::fillrect(int x, int y, int h, int w, Uint32* passed_pixels)
{
    for(int j=2; j<h-1;j++)
    {
        for(int i=2; i<w-1;i++)
        {
            drawred(passed_pixels, j, i, x, y);
        }
    }
}