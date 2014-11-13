//
//  savenload.cpp
//  FirstRPG
//
//  Created by Tianci on 13/04/2014.
//  Copyright (c) 2014 Tianci. All rights reserved.
//

#include "savenload.h"
#include <vector>

using namespace std;

savenload::savenload(Gameupdate* passed_update)
{
    update=NULL;
    update = passed_update;
    insertpoint = 0;
}

savenload::~savenload(void)
{
    delete scoretext;
}

void savenload::loadscore()
{
    int temp;
    
    ifstream infile;
    infile.open("data/scoreboard.txt");
    score = update->Getscore();
    
    while(infile >> temp)
    {
        tempo.push_back(temp);
    }
    infile.close();
    if(tempo.size()!=0)
    {
        for(int i=0; i<tempo.size();i++)
        {
            if(tempo[i]>score)
                insertpoint = i+1;
        }
        tempo.insert(tempo.begin()+insertpoint, score);
        insertpoint=0;
    }
    else
        tempo.push_back(score);
    
    ofstream outfile;
    outfile.open("data/scoreboard.txt");
    for(int i =0; i<tempo.size();i++)
    {
        if(i<10)
        {
            outfile << tempo[i] << endl;
        }
    }
    outfile.close();
    tempo.clear();
}

vector<int> savenload::displayscore()
{
    int temp;
    ifstream infile;
    infile.open("data/scoreboard.txt");
    score = update->Getscore();
    scores.clear();
    while(infile >> temp)
    {
        scores.push_back(temp);
    }
    infile.close();
    return scores;
}

void savenload::writezero()
{
    int temp;
    ofstream outfile;
    outfile.open("data/scoreboard.txt");
    temp = 10-scores.size();
    for(int i=0; i<temp; i++)
    {
        scores.push_back(0);
    }
    for(int i =0; i<scores.size();i++)
    {
        if(i<10)
        {
            outfile << scores[i] << endl;
        }
    }
    outfile.close();
}