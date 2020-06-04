#include "headers/snake.h"
#include "headers/functions.h"
Snake::Snake(int y, int x){
    _length = 1;
    _x.push_back(x);
    _y.push_back(y);
    _icon.push_back('@');
}
void Snake::update_screen(Screen& screen){
    for(int i = 0; i < _length; i++){
        screen.put(_y[i],_x[i],_icon[i]);
    }
}
void Snake::add_length(Screen& screen){
    _x.push_back(_x[_length - 1] - 1);
    _y.push_back(_y[_length - 1]);
    _icon.push_back('o');
    ++_length;
    update_screen(screen);
}

// Snake moves
void Snake::copy_previous_data(Screen& screen){
    for(int i = _length - 1; i > 0; i--){
        screen.put(_y[i],_x[i],' ');
        _x[i] = _x[i - 1];
        _y[i] = _y[i - 1];
    }
}

void Snake::move_left(Screen& screen){
    if(screen.get_icon(_y[0],_x[0] - 1) == ' '){
        copy_previous_data(screen);
        --_x[0];
        update_screen(screen);
    }
    else if(screen.get_icon(_y[0],_x[0] - 1) == 'f'){
        add_length(screen);
        screen.put(_y[0],_x[0] - 1,' ');
        move_left(screen);
        update_fruit(screen);
    }
    else if(screen.get_icon(_y[0],_x[0] - 1) == '#'){
        copy_previous_data(screen);
        if(screen.get_icon(_y[0],screen.get_width() - 2) == 'f') {
            add_length(screen);
            update_fruit(screen);
        }
        _x[0] = screen.get_width() - 2; //as this func will only execute when snake hits left wall
        update_screen(screen);
    }
    else if(screen.get_icon(_y[0],_x[0] - 1) == 'o'){
        
    }
    else{}
}

void Snake::move_right(Screen& screen){
    if(screen.get_icon(_y[0],_x[0] + 1) == ' '){
        copy_previous_data(screen);
        ++_x[0];
        update_screen(screen);
    }
    else if(screen.get_icon(_y[0],_x[0] + 1) == 'f'){
        add_length(screen);
        screen.put(_y[0],_x[0] + 1,' ');
        move_right(screen);
        update_fruit(screen);
    }
    else if(screen.get_icon(_y[0],_x[0] + 1) == '#'){
        copy_previous_data(screen);
        if(screen.get_icon(_y[0],1) == 'f') {
            add_length(screen);
            update_fruit(screen);
        }
        _x[0] = 1; //as this func will only execute when snake hits right wall
        update_screen(screen);
    }
    else{}
}

void Snake::move_up(Screen& screen){
    if(screen.get_icon(_y[0] - 1,_x[0]) == ' '){
        copy_previous_data(screen);
        --_y[0];
        update_screen(screen);
    } 
    else if(screen.get_icon(_y[0] - 1,_x[0]) == 'f'){
        add_length(screen);
        screen.put(_y[0] - 1,_x[0],' ');
        move_up(screen);
        update_fruit(screen);
    }
    else if(screen.get_icon(_y[0] - 1,_x[0]) == '#'){
        copy_previous_data(screen);
        if(screen.get_icon(screen.get_height() - 2,_x[0]) == 'f') {
            add_length(screen);
            update_fruit(screen);
        }
        _y[0] = screen.get_height() - 2; //as this func will only execute when snake hits upper wall
        update_screen(screen);
    }
    else{}
}

void Snake::move_down(Screen& screen){
    if(screen.get_icon(_y[0] + 1,_x[0]) == ' '){
        copy_previous_data(screen);
        ++_y[0];
        update_screen(screen);
    } 
    else if(screen.get_icon(_y[0] + 1,_x[0]) == 'f'){
        add_length(screen);
        screen.put(_y[0] + 1,_x[0],' ');
        move_down(screen);
        update_fruit(screen);
    }
    else if(screen.get_icon(_y[0] + 1,_x[0]) == '#'){
        copy_previous_data(screen);
        if(screen.get_icon(1,_x[0]) == 'f') {
            add_length(screen);
            update_fruit(screen);
        }
        _y[0] = 1; //as this func will only execute when snake hits bottom wall
        update_screen(screen);
    }
    else{}
}