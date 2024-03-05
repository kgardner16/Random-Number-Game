#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include "Player.h"

using namespace std;

//default constructor
Player::Player() :playerName("no name yet"), numWins(0)
{
    //purposely left empty
}

//custom constructor, sets playerName and numWins to values entered by user
Player::Player(string userName, int wins) : playerName(userName), numWins(wins)
{
    //purposely left empty
}

//mutator
void Player::setName(string new_name)
{
    playerName = new_name;
}

//accessor
string Player::getName() const
{
    return playerName;
}

//precondition: getGuess has been called by a base class player object
//postcondition: value of zero has been returned
int Player::getGuess()
{
    int tempGuess = 0;
    return tempGuess;
}

//precondition: guess and answer are both integers between 0 and 99
//postcondition: a message has been printed for player's knowledge in game, depending on relationship between guess and answer
void Player::wrongGuess(int guess, int answer)
{
    if(guess > answer)
    {
        cout << "Your guess is too high!" << endl;
    }
    else if(guess < answer)
    {
        cout << "Your guess is too low!" << endl;
    }
}

//precondition: an variable with value true or false has been passed to function
//postcondition: if the invoking object won the game, i.e. if winYes = true, the invoking object's numWins is incremented by 1
void Player::endRound(bool winYes)
{
    if(winYes)
    {
        numWins += 1;
    }
}

//Precondition: If out is a file output stream, then out has already been connected to a file
ostream& operator <<(ostream& outs, const Player& p)
{
    cout << p.playerName << endl;
    cout << "Number of wins: " << p.numWins << endl;
    return outs;
}

//precondition p1 and p2 are two objects of player class with each their own values assigned to numWins
//postcondition: numWins of p1 and p2 have been compared, and a true or false answer has been returned accordingly
bool operator <(const Player& p1, const Player& p2)
{
    return p1.numWins < p2.numWins;
}