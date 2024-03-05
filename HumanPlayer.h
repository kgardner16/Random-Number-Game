#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{
public:

    //default and custom constructors
    HumanPlayer();
    HumanPlayer(string name, int wins = 0);

    //virtual function, unique to HumanPlayer derived class
    virtual int getGuess();

};

#endif