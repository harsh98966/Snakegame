#ifndef SNAKE_H
#define SNAKE_H
#include "screen.h"
#include <vector>
using namespace std;
//contains position of one block
class Snake{
    vector<int> _x; 
    vector<int> _y;
    vector<char> _icon;
    int _length;
    void copy_previous_data(Screen& screen);
public:
    Snake(int y, int x);
    void update_screen(Screen& screen);
    void add_length(Screen& screen);
    void move_left(Screen& screen);
    void move_right(Screen& screen);
    void move_down(Screen& screen);
    void move_up(Screen& screen);
};
#endif