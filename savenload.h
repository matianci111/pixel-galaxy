//
//  savenload.h
//  FirstRPG
//
//  Created by Tianci on 13/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//
#pragma once
#ifndef __FirstRPG__savenload__
#define __FirstRPG__savenload__


#include <iostream>
#include <fstream>
#include "Gameupdate.h"
#include <sstream>
#include <vector>
#include "option.h"

using namespace std;


#endif /* defined(__FirstRPG__savenload__) */
class savenload
{
public:
    savenload(Gameupdate* passed_update);
    ~savenload(void);
    void loadscore();
    vector<int> displayscore();
    void writezero();
    
private:
    Gameupdate* update;
    int score;
    vector<int> tempo;
    vector<int> scores;
    int insertpoint;
    option* scoretext;
};