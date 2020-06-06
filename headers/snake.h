#ifndef SNAKE_H
#define SNAKE_H
#include "screen.h"
#include <vector>
using namespace std;
//contains position of one block
class Snake{

private: 

    vector<int> _x; 
    vector<int> _y;
    char _Head_icon;
    char _tail_icon;
    int _length; //snake length
    void move_body();
    void clear_snake(Screen& screen); //clears snake from the screen and add ' ' on their position.

public:

    Snake(int y, int x);
    void add_length(Screen& screen);
    void update_snake(Screen& screen); //adds snake on the screen.
    char _MoveSnake(char side, Screen& sreen ); // 'w', 'a', 's', 'd' moves the snake
    void deleteSnake(int y, int x,Screen& screen){
        clear_snake(screen);
        _length = 2;
        _x.clear();
        _y.clear();
        _x.push_back(x);
        _y.push_back(y);
        _x.push_back(x - 1);
        _y.push_back(y);
        update_snake(screen);
    }
    
};

#endif
