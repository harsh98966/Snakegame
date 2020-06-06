#include "headers/snake.h"
#include "headers/functions.h"


Snake::Snake(int y, int x){
    _length = 2; 
    
    //for head 
    _Head_icon = '@';
    _x.push_back(x); 
    _y.push_back(y);
    // _icon.push_back('@');
 
    //for tail
    _tail_icon = '*';
    _x.push_back(x - 1);
    _y.push_back(y);
    // _icon.push_back('o');
}

//increases the length of snake by 1
void Snake::add_length(Screen& screen){

    if(screen.getScreenElement(_y[_length - 1] + 1, _x[_length - 1]) == ' '){ 
        _y.push_back(_y[_length - 1] + 1);
        _x.push_back(_x[_length - 1]);
    }
    else if(screen.getScreenElement(_y[_length - 1], _x[_length - 1] - 1) == ' '){
        _y.push_back(_y[_length - 1]);
        _x.push_back(_x[_length - 1] - 1);
    }
    else if(screen.getScreenElement(_y[_length - 1] - 1, _x[_length - 1]) == ' '){
        _y.push_back(_y[_length - 1] - 1);
        _x.push_back(_x[_length - 1]);
    }
    else if(screen.getScreenElement(_y[_length - 1], _x[_length - 1] + 1) == ' '){
        _y.push_back(_y[_length - 1]);
        _x.push_back(_x[_length - 1] + 1);
    }
    else {
        screen.setStatus(1,"Snake","CannotAddLength");
    }
    
    ++_length;
    
    update_snake(screen);


}

//adds ' ' on the position of snake
void Snake::clear_snake(Screen& screen){
    for(int i = 0; i < _length; i++){
        if(screen.getScreenElement(_y[i], _x[i]) == _Head_icon || screen.getScreenElement(_y[i], _x[i]) == _tail_icon){
            screen.put_on_screen(_y[i],_x[i],' ');
        }
    }

}

//adds snake to the screen
void Snake::update_snake(Screen& screen){
   
    clear_snake(screen);
    
    char icon = _Head_icon;
    
    for(int i = 0; i < _length; i++){
        if(i == 0) {
            screen.put_on_screen(_y[i],_x[i],icon);
            icon = _tail_icon;
        }
        else {
            screen.put_on_screen(_y[i],_x[i],icon);
        }
    }

}

char Snake::_MoveSnake(char side,Screen& screen){
    char element = ' ';
    switch (side) {
        case 'w':
            element = screen.getScreenElement(_y[0] - 1,_x[0]);
            break;
        case 'a':
            element = screen.getScreenElement(_y[0] ,_x[0] - 1);
            break;
    
        case 's':
            element = screen.getScreenElement(_y[0] + 1,_x[0]);
            
            break;
    
        case 'd':
            element = screen.getScreenElement(_y[0],_x[0] + 1);
            
            break;
            
        default:
            break;

    }



    clear_snake(screen);

    move_body();



    switch (side) {
        case 'w':
            --_y[0];
            break;
    
        case 'a':
            --_x[0];
            break;
    
        case 's':
            ++_y[0];
            break;
    
        case 'd':
            ++_x[0];
            break;
            
        default:
            break;

    }

    return element;
}

//moves body of snake one step forward
void Snake::move_body(){

    for(int i = _length - 1; i > 0; i--){
        _x[i] = _x[i - 1];
        _y[i] = _y[i - 1];
        
    }

}




