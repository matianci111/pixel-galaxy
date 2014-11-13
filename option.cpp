//
//  option.cpp
//  FirstRPG
//
//  Created by Tianci on 13/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "option.h"

option::option(SDL_Setup* passed_sdl_setup, Gameupdate* passed_update, Uint32* passed_pixels)
{
    sdl_setup = passed_sdl_setup;
    update = passed_update;
    pixels = passed_pixels;
    draw = new Gamedraw(pixels, update, sdl_setup);
    mousepressed = false;

}

option::~option(void)
{
    
}

void option::drawblocks(int passed_mousex, int passed_mousey, int xoff, int yoff, int h, int w, Uint32* passed_pixels)
{
    mousex = passed_mousex;
    mousey = passed_mousey;
    
    draw->drawrect(xoff, yoff, h, w, pixels);
    
    if(mousex < xoff+w && mousex > xoff && mousey > yoff && mousey < yoff+h)
    {
        draw->fillrect(xoff, yoff, h, w, pixels);
    }
}

void option::drawtexts(int h, int xoff, int yoff, string str)
{
    Text = new text(sdl_setup, h, xoff, yoff, str);
    Text->writetext();
    delete Text;
}

bool option::mousecheck(int passed_mousex, int passed_mousey, int x_w, int xoff, int yoff, int y_h)
{
    mousex = passed_mousex;
    mousey = passed_mousey;
    if(sdl_setup->GetEvent()->type == SDL_MOUSEBUTTONDOWN)
    {
        if(sdl_setup->GetEvent()->button.button == SDL_BUTTON_LEFT)
        {
            mousepressed = true;
        }
    }
    
    if(sdl_setup->GetEvent()->type == SDL_MOUSEBUTTONUP && mousepressed == true)
    {
        if(mousex < x_w && mousex > xoff && mousey > yoff && mousey < y_h)
        {
            mousepressed = false;
            return true;
        }
    }
    return false;
}

void option::drawscores(vector<int> passed_scores)
{
    for(int i = 0; i<passed_scores.size();i++)
    {
        int score;
        score = passed_scores[i];
        string str;
        switch(i)
        {
            case 0:str = "First place: "; break;
            case 1:str = "Second place: "; break;
            case 2:str = "Thrid place: "; break;
            case 3:str = "Forth place: "; break;
            case 4:str = "Fifth place: "; break;
            case 5:str = "Sixth place: "; break;
            case 6:str = "Seventh place: "; break;
            case 7:str = "Eighth place: "; break;
            case 8:str = "Ninth place: "; break;
            case 9:str = "Tenth place: "; break;
                

        }
        str += to_string(score);
        drawtexts(40, 40+270*(i/5), 160+50*(i), str);
    }
}
