//
//  Gameupdate.cpp
//  FirstRPG
//
//  Created by Tianci on 07/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "Gameupdate.h"
Gameupdate::Gameupdate(SDL_Setup* passed_sdl_setup)
{
    srand((unsigned)time(0));
    enemymax = 20;
    enemycurrent = 0;
    animationdelay = SDL_GetTicks();
    timecheck = SDL_GetTicks();
    difficultycheck = SDL_GetTicks();
    sdl_setup = passed_sdl_setup;
    pressed = false;
    score = 0;
    Gamelose = false;
    explosionlose = false;
    laser=NULL;
    laser = Mix_LoadWAV("liser.wav");
    blast = Mix_LoadWAV("blast.wav");
    Mix_VolumeChunk(laser, 20);
    Mix_VolumeChunk(blast, 20);
    if(laser == NULL)
        cout << "fail" << endl;
    spawnspeed =5;
    divisionspawn = SDL_GetTicks();
    divisionline = 0;
}

Gameupdate::~Gameupdate(void)
{
    jets.clear();
    meteors.clear();
    bullets.clear();
    locations.clear();
}

void Gameupdate::enemyspawn()
{
    if(divisionspawn + 10000 < SDL_GetTicks() && divisionline ==0)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 1;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==1)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 2;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==2)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 3;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==3)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 4;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==4)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 5;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==5)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 6;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==6)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 7;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==7)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 8;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==8)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 9;
    }
    if(divisionspawn + 10000+divisionline*50 < SDL_GetTicks() && divisionline ==9)
    {
        enemy = new Enemies(80+50*divisionline, 10, 0);
        jets.push_back(enemy);
        enemycurrent++;
        divisionline = 0;
        divisionspawn = SDL_GetTicks();
    }
    if(enemymax < 50)
    {
    spawnspeed = enemymax;
    }
    
    if(enemycurrent<enemymax && timecheck+((rand() % (6000-(spawnspeed*100))) + (200-(spawnspeed*4))) < SDL_GetTicks())
    {
        type = ((rand() % 2) + 1)-1;
        startingx = ((rand() % 560) + 20);
        
        enemy = new Enemies(startingx, 10, type);
        if(type==0)
            jets.push_back(enemy);
        if(type==1)
            meteors.push_back(enemy);
        enemycurrent++;
        timecheck = SDL_GetTicks();
    }
}

void Gameupdate::enemyupdate()
{
    if(animationdelay+50 < SDL_GetTicks())
    {
        for(int i=0; i<jets.size(); i++)
        {
            jets[i]->move(5+(enemymax/2));
        }
        for(int i=0; i<meteors.size(); i++)
        {
            meteors[i]->move(5+enemymax);
        }
        for(int i=0; i<bullets.size(); i++)
        {
            bullets[i]->move();
        }
        animationdelay = SDL_GetTicks();
    }
}

void Gameupdate::enemydespawn()
{
    for(int i=0; i<jets.size(); i++)
    {
        if(jets[i]->GetY() > 680)
        {
            jets.erase(jets.begin()+i);
            enemycurrent--;
        }
    }
    for(int i=0; i<meteors.size(); i++)
    {
        if(meteors[i]->GetY() > 680)
        {
            meteors.erase(meteors.begin()+i);
            enemycurrent--;
        }
    }
    for(int i=0; i<bullets.size(); i++)
    {
        if(bullets[i]->GetY() < 20)
        {
            bullets.erase(bullets.begin()+i);
        }
    }
}

void Gameupdate::bulletspawn(int Passed_MousedX, int Passed_MouseY)
{
    if(sdl_setup->GetEvent()->type == SDL_KEYDOWN)
    {

        if(!pressed && sdl_setup->GetEvent()->key.keysym.sym == SDLK_SPACE)
        {
            bul = new bullet(Passed_MousedX, Passed_MouseY);
            bullets.push_back(bul);
            Mix_PlayChannel(-1, laser, 0);
            pressed = true;
        }
    }
    if(sdl_setup->GetEvent()->type == SDL_KEYUP)
    {
            pressed = false;
       
    }
    
}

void Gameupdate::collision(int passed_x, int passed_y)
{
    for(int i=0; i<bullets.size(); i++)
    {
        for(int j=0; j<jets.size(); j++)
        {
            if(abs(bullets[i]->GetX()-jets[j]->GetX())<23 && abs(bullets[i]->GetY() - jets[j]->GetY()) < 20 )
            {
                locations.push_back(jets[j]);
                bullets.erase(bullets.begin()+i);
                jets.erase(jets.begin()+j);
                enemycurrent--;
                Mix_PlayChannel(-1, blast, 0);
                score++;
            }
        }
    }
    for(int i=0; i<bullets.size(); i++)
    {
        for(int j=0; j<meteors.size(); j++)
        {
            if(abs(bullets[i]->GetX()-meteors[j]->GetX())<30 && abs(bullets[i]->GetY() - meteors[j]->GetY()) < 20 )
            {
                bullets.erase(bullets.begin()+i);
            }
        }
    }
    for(int j=0; j<meteors.size(); j++)
    {
        if(abs(passed_x-meteors[j]->GetX())<40 && abs(passed_y - meteors[j]->GetY()) < 40 &&!explosionlose)
        {
            player = new Enemies(passed_x, passed_y, 0);
            locations.push_back(player);
            explosionlose = true;
            Mix_PlayChannel(-1, blast, 0);
        }
    }
    for(int j=0; j<jets.size(); j++)
    {
        if(abs(passed_x-jets[j]->GetX())<40 && abs(passed_y - jets[j]->GetY()) < 40 &&!explosionlose)
        {
            player = new Enemies(passed_x, passed_y, 0);

            locations.push_back(player);
            locations.push_back(jets[j]);
            jets.erase(jets.begin()+j);
            enemycurrent--;
            score++;
            explosionlose = true;
            Mix_PlayChannel(-1, blast, 0);
        }
    }

}

bool Gameupdate::checklose(int passed_locationx, int passed_locationy)
{
    return explosionlose;
}

void Gameupdate::difficulty()
{
    if(difficultycheck+10000 < SDL_GetTicks())
    {
    enemymax++;
    difficultycheck=SDL_GetTicks();
    }
}

void Gameupdate::explosionfinish(int i)
{
    locations.erase(locations.begin()+i);
}

void Gameupdate::initialize()
{
    jets.clear();
    meteors.clear();
    bullets.clear();
    locations.clear();
    enemymax = 20;
    spawnspeed = enemymax;
    enemycurrent = 0;
    score = 0;
    explosionlose = false;
    
}