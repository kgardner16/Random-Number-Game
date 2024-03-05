# Random-Number-Game
Project was completed at the end of 2023. This project was a cumulation of all of the c++ knowledge and skills I had gained up until that point.

For this project, I created a 2 player game from scratch, allowing for either 2 human players, 2 computer players, or 1 of each, to play against each other. In the game, the two players compete to see who can guess the random number, between 1 and 99, first. They take turns guessing until someone guesses the number correctly.
Additionally, the computer player is programmed with a small amount of artificial intelligence, allowing it to slowly refine and improve its guesses so as to serve as a more challenging opponent. 

These files contain a parent class, the Player class, which holds all of the data and functions for any kind of player, and two derived classes: HumanPlayer and ComputerPlayer, each including different functions specific to the type of player.

USAGE:
Run main.cpp in order to begin the game. Follow the prompts to decide how many human and computer players will be playing the game. The code will randomly generate a number, and then the game will begin. If 1 or 2 human players are present, the players will be prompted to enter their guesses and play the game. If 2 computer players are present, the user can simply watch as they carry out the game themselves. 
