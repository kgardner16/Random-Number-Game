#include "HumanPlayer.h"

//default constructor, calls base class default constructor
HumanPlayer::HumanPlayer():Player()
{
   //left empty
}

//custom constructor, calls base class custom constructor
HumanPlayer::HumanPlayer(string name, int wins) : 
   Player(name, wins)
{
   //left empty
}


//precondition: invoking object is a human player
//postcondtion: human player has guessed an integer between 0 and 99
int HumanPlayer::getGuess()
{
   int guess;
   cout << "Please enter a guess between 0 and 99: ";
   cin >> guess;
   while(guess < 0 || guess > 99)
   {
      cout << "Please re-enter guess: ";
      cin >> guess;
   }
   return guess;
}
 
