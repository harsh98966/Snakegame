#pragma once
#include "screen.h"
#include "snake.h"

class Game{

private:
    int _ScreenWidth,_ScreenHeight;
    Screen* screen;
    Snake* snake;
    int _fruitX, _fruitY;
    int _powerX, _powerY;
    int _Score;
    bool _GameOver;
    string _PlayerName;
    char PreviousMove; //to check if move is valid or not (check MakeMove function for more info);
    bool playAgain;
    int _level;
    int _maxLevel; 
    int _nextLevel;


    //functions 
    void _add_fruit();
    void _add_Power();
    void init();
    void updateStatus(); //updates various value on status screen
    void MakeMove(char &move); //Moves snake and also checks for invalid input
    void GameOver();
    void levelCheck();
    void resetAll();

public :

    Game(int height, int width);
    ~Game();
    void Start();
    
};