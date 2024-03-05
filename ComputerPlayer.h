#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player
{
public:
   
    //default and custom constructors
    ComputerPlayer();
    ComputerPlayer(string name, int wins = 0, int rngRange = 100, int rngStart = 0);

    //virtual functions, unique to ComputerPlayer derived class
    virtual int getGuess();
    virtual void wrongGuess(int guess, int answer);
    virtual void endRound(bool winYes);

    //other functions, in charge of modifying private member variables
    void resetRNG();
    void shiftRangeDown(int currentGuess);
    void shiftRangeUp(int currentGuess);
    
private:
    int rngStart;
    int rngRange;

};

#endif