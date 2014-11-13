//
//  Mainloop.cpp
//  FirstRPG
//
//  Created by Tianci on 06/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "Mainloop.h"

Mainloop::Mainloop(void)
{
    gamequit = false;
    sdl_setup = new SDL_Setup;
    TTF_Init();
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    pixels = sdl_setup->GetPixels();
    texture = sdl_setup->GetTexture();
    background = NULL;
    background = IMG_LoadTexture(sdl_setup->GetRenderer(), "galaxy.png");
    if(background == NULL)
    {
        cout << "can't load galaxy" << endl;
    }
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.h = 750;
    rect.w = 600;
    pitch = 600;
    galaxy = new Uint32[600 * 750];
  
    Player = new Playerjet(MouseX, MouseY, pixels);
    update = new Gameupdate(sdl_setup);
    draw = new Gamedraw(pixels, update, sdl_setup);
    gamelose = false;
    atoption = true;
    
    currenttype = 0;
    
    entergame = new option(sdl_setup, update, pixels);
    scoreboard = new option(sdl_setup, update, pixels);
    creditboard = new option(sdl_setup, update, pixels);
    gamepause = new option(sdl_setup, update, pixels);
    timecheck = SDL_GetTicks();
    n = 650;
    
    load = new savenload(update);
    scores = load->displayscore();
    if(scores.size()<=10)
    {
        load->writezero();
        scores = load->displayscore();
    }
    
    music = Mix_LoadMUS("winter.mp3");
    Mix_VolumeMusic(128);
    playmusic = 1;
}
Mainloop::~Mainloop(void)
{
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    delete sdl_setup;
    SDL_DestroyTexture(texture);
    delete Player;
    delete update;
    delete draw;
}

void Mainloop::MainGame()
{
    while (!(sdl_setup->GetEvent()->type == SDL_QUIT || (gamequit)))
    {
        SDL_PollEvent(sdl_setup->GetEvent());
        if(playmusic == 1)
        {
            Mix_PlayMusic(music, -1);
            Mix_VolumeMusic(128);
            playmusic = 0;
        }
        SDL_RenderClear(sdl_setup->GetRenderer());
        SDL_GetMouseState(&MouseX, &MouseY);
        if(!gamelose&&atoption)
        {
            showoption();
            SDL_ShowCursor(1);
        }
        if(!gamelose&&!atoption)
        {
            Gaming();
        }
        if(gamelose&&!atoption){
            Gamelose();
            if(timecheck+1000<SDL_GetTicks())
            {
               
                entergame->drawtexts(180, 40, 200, "You lose");
                entergame->drawtexts(50, 190, 420, "Your score:");
                draw->drawscore(400, 420, 50);
            }
            if(timecheck+4000<SDL_GetTicks())
            {
              
            gamelose = false;
            currenttype = 0;
            }
            if(!gamelose)
            {
    
                load->loadscore();
                scores = load->displayscore();
                update->initialize();
                atoption = true;
            }
        }
        SDL_RenderPresent(sdl_setup->GetRenderer());
        for(int i=0; i<(600*750);i++)
        {
            pixels[i] = galaxy[i];
        }

    }
}



void Mainloop::Gaming()
{
    draw->drawenemy(pixels);
    Player->Drawjet(MouseX, MouseY);
    draw->drawexplosion(pixels);
    update->enemydespawn();
    update->collision(Player->GetX(), Player->GetY());
    gamelose = update->checklose(Player->GetX(), Player->GetY());
    if(gamelose)
        timecheck = SDL_GetTicks();
    update->enemyupdate();
    update->difficulty();
    update->enemyspawn();
    update->bulletspawn(Player->GetX(), Player->GetY());
    SDL_UpdateTexture(texture, NULL, pixels, 600 * sizeof(Uint32));
    SDL_RenderCopy(sdl_setup->GetRenderer(), texture, NULL, NULL);
    draw->drawscore(570, 20, 40);
    SDL_ShowCursor(0);
}

void Mainloop::Gamelose()
{
    update->enemydespawn();
    update->collision(Player->GetX(), Player->GetY());
    update->enemyupdate();
    draw->drawexplosion(pixels);
    draw->drawenemy(pixels);
    SDL_UpdateTexture(texture, NULL, pixels, 600 * sizeof(Uint32));
    SDL_RenderCopy(sdl_setup->GetRenderer(), texture, NULL, NULL);
    draw->drawscore(570, 20, 40);
    SDL_ShowCursor(0);
}

void Mainloop::showoption()
{
    switch (currenttype)
    {
        case 0:
            entergame->drawblocks(MouseX, MouseY, 120, 170, 75, 360, pixels);
            entergame->drawblocks(MouseX, MouseY, 120, 300, 75, 360, pixels);
            entergame->drawblocks(MouseX, MouseY, 120, 426, 75, 360, pixels);
            entergame->drawblocks(MouseX, MouseY, 120, 554, 75, 360, pixels);

            SDL_UpdateTexture(texture, NULL, pixels, 600 * sizeof(Uint32));
            SDL_RenderCopy(sdl_setup->GetRenderer(), texture, NULL, NULL);
            entergame->drawtexts(100, 80, 30, "Pixel Galaxy");
            entergame->drawtexts(40, 225, 190, "New game");
            entergame->drawtexts(40, 260, 321, "Score");
            entergame->drawtexts(40, 250, 447, "Credit");
            entergame->drawtexts(40, 266, 573, "Quit");
            
            if(entergame->mousecheck(MouseX, MouseY, 480, 120, 170, 170+75))
            {
                currenttype = 1;
                break;
            }
            if(entergame->mousecheck(MouseX, MouseY, 480, 120, 300, 300+75))
            {
                currenttype = 2;
                break;
            }
            if(entergame->mousecheck(MouseX, MouseY, 480, 120, 426, 426+75))
            {
                currenttype = 3;
                n=650;
                break;
            }
            if(entergame->mousecheck(MouseX, MouseY, 480, 120, 554, 554+75))
            {
                currenttype = 4;
                break;
            }
            break;
        case 1:
            atoption = false;
        
            break;
        case 2:
            scoreboard->drawblocks(MouseX, MouseY, 480, 680, 40, 100, pixels);
            SDL_UpdateTexture(texture, NULL, pixels, 600 * sizeof(Uint32));
            SDL_RenderCopy(sdl_setup->GetRenderer(), texture, NULL, NULL);
            creditboard->drawtexts(35, 485, 685, "Return");
            creditboard->drawtexts(100, 80, 40, "High Scores");
            creditboard->drawscores(scores);
            if(entergame->mousecheck(MouseX, MouseY, 480+100, 500, 680, 680+40))
            {
                currenttype = 0;
                break;
            }
            break;
        case 3:
            creditboard->drawblocks(MouseX, MouseY, 480, 680, 40, 100, pixels);
            SDL_UpdateTexture(texture, NULL, pixels, 600 * sizeof(Uint32));
            SDL_RenderCopy(sdl_setup->GetRenderer(), texture, NULL, NULL);
            creditboard->drawtexts(35, 485, 685, "Return");
            creditboard->drawtexts(70, 140, 100+n, "Pixel Galaxy");
            creditboard->drawtexts(30, 60, 200+n, "Designed and developed solely by Tianci Ma");
            creditboard->drawtexts(35, 120, 300+n, "Game design            Tianci");
            creditboard->drawtexts(35, 120, 350+n, "Programming           Tianci");
            creditboard->drawtexts(35, 120, 400+n, "Graphics                 Tianci");
            creditboard->drawtexts(35, 120, 450+n, "Artwork                   Tianci");
            creditboard->drawtexts(35, 120, 500+n, "Sounds & musics      Tianci");
            if(timecheck+8<SDL_GetTicks() && n>0)
            {
                n = n-1;
                timecheck = SDL_GetTicks();
            }
            if(entergame->mousecheck(MouseX, MouseY, 480+100, 500, 680, 680+40))
            {
                currenttype = 0;
                break;
            }
            break;
        case 4:
            gamequit = true;
    }
}