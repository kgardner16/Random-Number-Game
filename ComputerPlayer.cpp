#include <iostream>
#include <string>
#include "ComputerPlayer.h"

using namespace std;

//default constructor, calls base class default constructor, and calls resetRNG
ComputerPlayer::ComputerPlayer():Player()
{
   resetRNG();
}

//custom constructor, calls base class custom constructor and calls resetRNG
ComputerPlayer::ComputerPlayer(string name, int wins, int rngRange, int rngStart) : 
   Player(name, wins), rngRange(rngRange), rngStart(rngStart)
{
   resetRNG();
}

//precondition: rngStart and rngRange are real member variables
//postcondition: values of rngStart and rngRange have been updated to 0 and 100, respectively
void ComputerPlayer::resetRNG()
{
   rngStart = 0;
   rngRange = 100;
}
 
//precondition: invoking object is a computer player
//postcondtion: computer player has guessed an integer between 0 and 99, and arithmetic errors have been avoided
int ComputerPlayer::getGuess()
{
   int guess;
   if(rngRange == 0)
   {
      rngRange += 1;
   }
   guess = rand() % rngRange + rngStart;
   return guess;
}

//precondition: currentGuess is an integer higher than the answer
//postcondtion: rngRange has been shifted downward; leaves rngStart untouched
void ComputerPlayer::shiftRangeDown(int currentGuess) 
{
   rngRange = (currentGuess - rngStart); 
}

//precondition: currentGuess is an integer lower than the answer
//postcondtion: rngRange has been modified accordingly, and rngStart has been moved upwards
void ComputerPlayer::shiftRangeUp(int currentGuess) 
{
   
      int temp;
      int oldRange;
      temp = currentGuess - rngStart + 1;
      oldRange = rngRange;
      rngRange = oldRange - temp;

      rngStart = currentGuess + 1;
}

//precondition: guess and answer are both integers between 0 and 99
//postcondtion: base class wrongGuess has been called, printing a message for player's knowledge in game and shiftRangeDown or shiftRangeUp have been called, depending on relationship between guess and answer
void ComputerPlayer::wrongGuess(int guess, int answer)
{
   Player::wrongGuess(guess, answer);

   if(guess > answer)
   {
      shiftRangeDown(guess);
   }
   else if(guess < answer)
   {
      shiftRangeUp(guess);
   }
   
}

//precondition: an variable with value true or false has been passed to function
//postcondition: based class endRound has been called, incrementing the invoking object's numWins by 1, and resetRNG has been called, so as to prepare for the game to be played again
void ComputerPlayer::endRound(bool winYes)
{
    Player::endRound(winYes);
    resetRNG();
}