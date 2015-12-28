//
//  game.hpp
//  2048
//
//  Created by Jason on 12/18/15.
//  Copyright © 2015 Jason. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>

#include "util.h"
#include "stdlib.h"

class Game{
    
    
public:
    Game();
    
   
    
    void setPieces(Screen& screen);
    
    void ifSame();
    
    void randomG();
    
    void Up();
    void Down();
    void Left();
    void Right();
    
    void clearScreen();
    
    void process(char ch);
    void play();
    bool checkEnd();
    bool checkLose();
    
private:
    
    int m_container[bound][bound];
    Screen m_screen;
    int seed;
    
    bool lose;
    
    
    
    
};



#endif /* game_hpp */
