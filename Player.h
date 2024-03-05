#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
        //default and custom constructors
        Player();
        Player(string userName, int wins);

        //mutator that sets the invoking object's name
        void setName(string new_name);

        //accessor that returns the invoking object's name
        string getName() const;

        //virtual functions, each with their own versions in one or both of the derived classes
        virtual int getGuess();
        virtual void wrongGuess(int guess, int answer);
        virtual void endRound(bool winYes);

        //overloaded operators, to allow for usage of these operators with objects of player class
        friend ostream& operator <<(ostream& outs, const Player& p);
        friend bool operator <(const Player& p1, const Player& p2);
    
    protected:
        int numWins;

    private:
        string playerName;
    

};

#endif //PLAYER_H

