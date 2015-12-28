//
//  game.cpp
//  2048
//
//  Created by Jason on 12/18/15.
//  Copyright © 2015 Jason. All rights reserved.
//

#include "game.hpp"
#include <iostream>
#include "time.h"

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;



Game::Game()
: m_screen(SCREEN_WIDTH, SCREEN_HEIGHT)
{
    
    
    seed=0;
    
    
    for(int x=0; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
           
            m_container[x][y]=0;
            
            
            
            
        }

        
    }
    

    
    
}

void Game::clearScreen()
{
    //clear the screen except edges.
    for (int k=0 ; k<bound; k++)
    {
        for (int i=0; i<bound; i++)
        {
            
            m_container[k][i]=0;
            string d="   ";
            
            m_screen.gotoXY(k*5,i);
            m_screen.printString(d);
            
        }
        
    }
    
    
}

void Game::setPieces(Screen &screen){
    
    int a;
    int l=0;
    std::string c;
    std::string d;
    
    for(int x=0; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
            a=m_container[x][y];
            screen.gotoXY(x*5, y);  //for the space 
            c=std::to_string(a);
            d="";
            //screen.printString(d);   //to reset the space
            
            if(c.length()<4)
            {
                l=4-(int)c.length();
                
            }
            
            for(int k=0;k<l;k++)
                d=d+" ";
            
            c.append(d);
        
                
            screen.printString(c); //could still be problem here
            
            
            
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    
}

bool Game::checkLose(){
    
    int a,b,c,d,e;
    
    for(int x=0; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
            a=m_container[x][y];
            b=m_container[x-1][y];
            c=m_container[x+1][y];
            d=m_container[x][y-1];
            e=m_container[x][y+1];
            
            if((x-1)>0)
            {
                if(a==b)
                    return false;
                
            }
            
            
            if ((y-1)>0) {
                if(a==d)
                    return false;
                
            }
            
            
            if((x+1)<bound)
                if (a==c) {
                    return false;
                }
            
            if((y+1)<bound)
                if(a==e)
                    return false;
            
            
            
        }
        
        
        
        
    }
    
    return true;
    
    
    
    
    
}


void Game::randomG(){
    
    int a,b;
    
    srand( static_cast<unsigned int>(time(NULL)));

    
    for(int x=0; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
           

            b=rand()%6;
            
            
            m_screen.gotoXY(x, y+10);
            m_screen.printChar(b+'0');  //testing
            
            
            
            
            a=m_container[x][y];
            if(a==0){
                
                if(b==0 || b==1)
                    m_container[x][y]=1;
                
                else if(b==2)
                    m_container[x][y]=0;
                
                
                else
                    m_container[x][y]=0;
                
                
                
                
            }
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    
}



void Game::Up(){
    
    int a,b;
    
    for(int x=0; x<bound; x++)
    {
        for(int y=1;  y<bound; y++)
        {
         
            
            a=m_container[x][y];
            b=m_container[x][y-1];
            
            if(a==b)
            {
                m_container[x][y]=0;
                m_container[x][y-1]*=2;
            }
            else if(b==0)
            {
                
                m_container[x][y-1]=a;
                m_container[x][y]=0;
                
            }
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    
    
    
}








void Game::Down(){
    
    int a,b;
    
    for(int x=0; x<bound; x++)
    {
        for(int y=1;  y<bound; y++)
        {
            
            a=m_container[x][y];
            b=m_container[x][y-1];
            
            if(a==b)
            {
                m_container[x][y]=0;
                m_container[x][y-1]*=2;
            }
            else if (a==0)
            {
                m_container[x][y]=b;
                m_container[x][y-1]=0;
                
            }
            
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    
    
    
}




void Game::Left(){
    
    int a,b;
    
    for(int x=1; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
            
            
            a=m_container[x][y];
            b=m_container[x-1][y];
            
            if(a==b)
            {
                m_container[x][y]=0;
                m_container[x-1][y]*=2;
            }
            else if (b==0)
            {
                m_container[x-1][y]=a;
                m_container[x][y]=0;
                
            }
            
            
            
            
        }
        
        
        
        
    }
 
    
}




void Game::Right(){
    
    
    
    int a,b;
    for(int x=1; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
            
            a=m_container[x][y];
            b=m_container[x-1][y];
            
            if(a==b)
            {
                m_container[x-1][y]=0;
                m_container[x][y]*=2;
            }
            else if (a==0)
            {
                m_container[x][y]=b;
                m_container[x-1][y]=0;
                
            }
            
            
            
            
        }
        
        
        
        
    }
    
    
    
    
    
    
    
}



bool Game::checkEnd(){
    
    int a;
    
    for(int x=0; x<bound; x++)
    {
        for(int y=0;  y<bound; y++)
        {
            
            a=m_container[x][y];
            
            
            
            if(a>=2048)
                return true;
            
            
            
            
            
                
        }
        
        
        
        
    }
    
    return false;
    
    
    
}


void Game::process(char ch){
    
    
    switch (ch) {
        case ARROW_LEFT:
            Left();
            break;
        
        case ARROW_RIGHT:
            Right();
            break;
        case ARROW_UP:
            Up();
            break;
            
        case ARROW_DOWN:
            Down();
            break;

            
        default:
            break;
    }
    
    
    
    
    
}


void Game::play(){
    
    char ch;
    clearScreen();
    
    while(!checkEnd()){
        
        
       
        if(getCharIfAny(ch))
        {
            randomG();
            process(ch);
            
        }
       
        
        setPieces(m_screen);
        
        
        
        if (checkLose())
        {
            lose=true;
            break;
        
        }
        
        
    }
    
    
  

    
    
    clearScreen();
    m_screen.gotoXY(0,0);
    
    if(lose){
        m_screen.printString("You Lost!");
    }
    else{
    m_screen.printString("You won!");
    
    }
    
    
}




