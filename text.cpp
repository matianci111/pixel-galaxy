//
//  text.cpp
//  FirstRPG
//
//  Created by Tianci on 09/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "text.h"

text::text(SDL_Setup* passed_sdl_setup, int h, int passed_x, int passed_y, string passed_string)
{
    x=passed_x;
    y=passed_y;
    sdl_setup = passed_sdl_setup;
    finaltext = passed_string;
    
    message = NULL;
    font =NULL;
    textColor.r=255; textColor.g=255;textColor.b=255;
    font = TTF_OpenFont( "SIXTY.ttf", h);
    if(font == NULL)
    {
        cout << "false" << endl;
    }
    message = TTF_RenderText_Solid(font, finaltext.c_str(), textColor);
    if(message == NULL)
    {
        
    }
    Texture_text = SDL_CreateTextureFromSurface(sdl_setup->GetRenderer(), message);
    SDL_QueryTexture(Texture_text, NULL, NULL, &w, &h);
    textRect.x=x;textRect.y=y; textRect.w = w; textRect.h=h;
}
text::~text(void)
{
    SDL_FreeSurface(message);
    SDL_DestroyTexture(Texture_text);
    TTF_CloseFont(font);
}

void text::writetext()
{
    SDL_RenderCopy(sdl_setup->GetRenderer(), Texture_text, NULL, &textRect);
}
