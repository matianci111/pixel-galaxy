//
//  Playerjet.cpp
//  FirstRPG
//
//  Created by Tianci on 06/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "Playerjet.h"
Playerjet::Playerjet(int Passed_MousedX, int Passed_MouseY, Uint32* passed_pixel)
{
    MouseX = Passed_MousedX;
    MouseY = Passed_MouseY;
    pixels = new Uint32[600 * 750];
    pixels = passed_pixel;
    locationx = 300;
    locationy = 600;
}

Playerjet::~Playerjet(void)
{
}

void Playerjet::Drawjet(int Passed_MouseX, int Passed_MouseY)
{
            if(!(Passed_MouseY <= 0 || Passed_MouseY+70 >= 750 || Passed_MouseX-21 <= 0 || Passed_MouseX+21 >= 600))
            {
                for(int i=-20; i<20; i++)
                {
                    for(int j=36; j<=40; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                }
                for(int i=-18; i<18; i++)
                {
                    for(int j=41; j<=43; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    for(int j=32; j<=35; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                }
                for(int i=-16; i<16; i++)
                {
                    for(int j=29; j<=31; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                }
                for(int i=-14; i<14; i++)
                {
                    for(int j=44; j<=47; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    for(int j=24; j<=28; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-12; i<12; i++)
                {
                    for(int j=48; j<=51; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    for(int j=20; j<=23; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-10; i<10; i++)
                {
                    for(int j=52; j<=53; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    for(int j=15; j<=19; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-8; i<8; i++)
                {
                    for(int j=10; j<=14; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-5; i<5; i++)
                {
                    
                    for(int j=7; j<=10; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-3; i<3; i++)
                {
                    
                    for(int j=4; j<=7; j++)
                        drawgrey(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                //below draw glass
                for(int i=-8; i<8; i++)
                {
                    
                    for(int j=17; j<=28; j++)
                        drawred(pixels, j, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-7; i<7; i++)
                {
                    drawred(pixels, 16, i, Passed_MouseX, Passed_MouseY);
                    drawred(pixels, 29, i, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-6; i<6; i++)
                {
                    
                    drawred(pixels, 30, i, Passed_MouseX, Passed_MouseY);
                    drawred(pixels, 15, i, Passed_MouseX, Passed_MouseY);
                }
                //draw rear
                for(int n=43; n<=54;n++)
                {
                    drawdgrey(pixels, n, -11, Passed_MouseX, Passed_MouseY);
                    drawdgrey(pixels, n, -3, Passed_MouseX, Passed_MouseY);
                    drawdgrey(pixels, n, 10, Passed_MouseX, Passed_MouseY);
                    drawdgrey(pixels, n, 2, Passed_MouseX, Passed_MouseY);
                    for(int j=-10; j<=-4; j++)
                        drawyellow(pixels, n, j, Passed_MouseX, Passed_MouseY);
                    for(int j=3; j<=9; j++)
                        drawyellow(pixels, n, j, Passed_MouseX, Passed_MouseY);
                    
                }
                for(int i=-10;i<-4;i++)
                    drawdgrey(pixels, 55, i, Passed_MouseX, Passed_MouseY);
                for(int i=3;i<9;i++)
                    drawdgrey(pixels, 55, i, Passed_MouseX, Passed_MouseY);
                for(int i=3;i<9;i++)
                    drawdgrey(pixels, 42, i, Passed_MouseX, Passed_MouseY);
                for(int i=-10;i<-4;i++)
                    drawdgrey(pixels, 42, i, Passed_MouseX, Passed_MouseY);
                locationx=Passed_MouseX;
                locationy=Passed_MouseY;
                
            }
            else
            {
                for(int i=-20; i<20; i++)
                {
                    for(int j=36; j<=40; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                }
                for(int i=-18; i<18; i++)
                {
                    for(int j=41; j<=43; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    for(int j=32; j<=35; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                }
                for(int i=-16; i<16; i++)
                {
                    for(int j=29; j<=31; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                }
                for(int i=-14; i<14; i++)
                {
                    for(int j=44; j<=47; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    for(int j=24; j<=28; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    
                }
                for(int i=-12; i<12; i++)
                {
                    for(int j=48; j<=51; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    for(int j=20; j<=23; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    
                }
                for(int i=-10; i<10; i++)
                {
                    for(int j=52; j<=53; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    for(int j=15; j<=19; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    
                }
                for(int i=-8; i<8; i++)
                {
                    for(int j=10; j<=14; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    
                }
                for(int i=-5; i<5; i++)
                {
                    
                    for(int j=7; j<=10; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    
                }
                for(int i=-3; i<3; i++)
                {
                    
                    for(int j=4; j<=7; j++)
                        drawgrey(pixels, j, i, locationx, locationy);
                    
                }
                //below draw glass
                for(int i=-8; i<8; i++)
                {
                    
                    for(int j=17; j<=28; j++)
                        drawred(pixels, j, i, locationx, locationy);
                    
                }
                for(int i=-7; i<7; i++)
                {
                    drawred(pixels, 16, i, locationx, locationy);
                    drawred(pixels, 29, i, locationx, locationy);
                    
                }
                for(int i=-6; i<6; i++)
                {
                    
                    drawred(pixels, 30, i, locationx, locationy);
                    drawred(pixels, 15, i, locationx, locationy);
                }
                //draw rear
                for(int n=43; n<=54;n++)
                {
                    drawdgrey(pixels, n, -11, locationx, locationy);
                    drawdgrey(pixels, n, -3, locationx, locationy);
                    drawdgrey(pixels, n, 10, locationx, locationy);
                    drawdgrey(pixels, n, 2, locationx, locationy);
                    for(int j=-10; j<=-4; j++)
                        drawyellow(pixels, n, j, locationx, locationy);
                    for(int j=3; j<=9; j++)
                        drawyellow(pixels, n, j, locationx, locationy);
                    
                }
                for(int i=-10;i<-4;i++)
                    drawdgrey(pixels, 55, i, locationx, locationy);
                for(int i=3;i<9;i++)
                    drawdgrey(pixels, 55, i, locationx, locationy);
                for(int i=3;i<9;i++)
                    drawdgrey(pixels, 42, i, locationx, locationy);
                for(int i=-10;i<-4;i++)
                    drawdgrey(pixels, 42, i, locationx, locationy);

            }
}

void Playerjet::drawgrey(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY)
{
//    pixels[(Passed_MouseY+n) * 600 + (Passed_MouseX+i)] = (0xFF << 24) | (0xDB << 16) | (0x70 << 8) | 0x93 ;
    pixels[(Passed_MouseY+n) * 600 + (Passed_MouseX+i)] = (0xFF << 24) | (0xFF << 16) | (0x00 << 8) | 0x00 ;
}

void Playerjet::drawred(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY)
{
    pixels[(Passed_MouseY+n) * 600 + (Passed_MouseX+i)] = (0xFF << 24) | (0xF5 << 16) | (0xF5 << 8) | 0xF5 ;
}

void Playerjet::drawdgrey(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY)
{
    pixels[(Passed_MouseY+n) * 600 + (Passed_MouseX+i)] = (0xFF << 24) | (0xF5 << 16) | (0xDE << 8) | 0xB3 ;
}
void Playerjet::drawyellow(Uint32* pixels, int n, int i, int Passed_MouseX, int Passed_MouseY)
{
    pixels[(Passed_MouseY+n) * 600 + (Passed_MouseX+i)] = (0xFF << 24) | (0x00 << 16) | (0xBF << 8) | 0xFF ;
}