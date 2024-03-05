//Kaitlin Gardner
//Prof. Hernandez
//Final Project - RNG Game
//12-14-23

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

void play(Player& player1, Player& player2);
bool checkForWin(Player& player, int answer);
void displayStats(const Player player1, const Player player2);


int main()
{
    // Set the Random Seed!
    int rand(unsigned int seed);
    int numPlayers;
    Player* p1, * p2;
    

    // Determine the number of players via user input and looping.
    cout << "How many human players? (0, 1, or 2): ";
    cin >> numPlayers;
    while(numPlayers < 0 || numPlayers > 2) //input validation; ensures that user must enter 0, 1, or 2
    {
        cout << "Please re-enter the number of players. (0, 1, or 2): ";
        cin >> numPlayers;
    }

    //creates two objects of each type of derived class
    HumanPlayer h1("Player 1"), h2("Player 2"); 
    ComputerPlayer c1("CPU 1"), c2("CPU 2");
    
    // Set up player pointers.
    string tempName;
    if(numPlayers == 0)
    {
        p1 = &c1;
        p2 = &c2;
    }
    else if(numPlayers == 1)
    {
        cout << "What is the human player's name? ";
        cin >> tempName;
        h1.setName(tempName);
        
        p1 = &h1;
        p2 = &c2;
    }
    else if(numPlayers == 2)
    {

        cout << "What is the first player's name? ";
        cin >> tempName;
        h1.setName(tempName);

        cout << "What is the second player's name? ";
        cin >> tempName;
        h2.setName(tempName);

        p1 = &h1;
        p2 = &h2;
    }

    //Game loop:
    char playAgain;
    do
    {
        play(*p1, *p2); //passes two player object pointers to play function, which handles the actual game code

        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;
        while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain && 'N')
        {
            cout << "Please re-enter your answer. (Y/N): ";
            cin >> playAgain;
        }

    } while(playAgain == 'y' || playAgain == 'Y');
    

    cout << endl;

    // Call the output game stats functions you wrote!
    displayStats(*p1, *p2);
    

    return 0;
}

//precondition: parameters take two real objects/pointers of any type of player class, allowing for any combination of human or computer players
//postcondition: a random answer has been generated, and the game has been carried out until one player wins
void play(Player& player1, Player& player2) 
{
    int answer = rand() % 100; 
    bool win = false;
    while (!win)
    {
        win = checkForWin(player1, answer);
        if (win)
        {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win)
        {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

//precondition: player is a real defined object of player class, and answer is a random integer which has been filled in via play function
//postcondition: player has been asked to enter a guess, and a result message has been printed, depending on correctness of guess
bool checkForWin(Player& player, int answer)
{
    bool win = false;
    cout << player.getName() << "'s turn to guess." << endl;
    int guess = player.getGuess(); //calls proper getGuess function depending on what type of class object called it
    cout << "You guessed " << guess << ". ";
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        win = true;
    }
    else
        player.wrongGuess(guess, answer);
    return win;
}


//precondition: player1 and player2 are both real, defined objects of any type of Player class, whether base or derived;
//function can only be utilized with files in which operator < is overloaded for objects of player class
//postcondition: game results are printed, and a congrats message is displayed for player with more wins (or a tie message if necessary)
void displayStats(const Player player1, const Player player2) 
{
    cout << "Final Results: " << endl;
    cout << player1;
    cout << player2;

    bool p2Win;
    bool p1Win;

    p2Win = player1 < player2;
    p1Win = player2 < player1;

    if(p2Win)
    {
        cout << "Congratulations, " << player2.getName() << "!";
    }
    else if(p1Win)
    {
        cout << "Congratulations, " << player1.getName() << "!";
    }
    else
    {
        cout << "We have a tie!";
    }

}