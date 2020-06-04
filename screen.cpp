#include"headers/screen.h"
Screen::Screen(){
    _height = 18;
    _width = 50;
    // _screen = new char*[_height];   
}
Screen::Screen(int h, int w){
    _height = h;
    _width = w;
}
Screen::~Screen(){
    for(int y = 0; y < _height; y++){
        delete _screen[y];
        _screen[y] = nullptr;
    }
}
void Screen::init(){
    _screen = new char*[_height];
    for(int y = 0; y < _width; y++){
        _screen[y] = new char[_width + 1];
    }
    
    for(int y = 0; y < _height; y++){
        for(int x = 0; x <= _width; x++){
            if(y == 0 || y == _height - 1){
                _screen[y][x] = '#';
            }
            else{
                if(x == 0 || x == _width - 1) _screen[y][x] = '#';
                else _screen[y][x] = ' ';
            } 

            if(x == _width) _screen[y][x] = '\n';
        }
    }
}

void Screen::print(){
    for(int y = 0; y < _height; y++){
        for(int x = 0; x <= _width; x++){
            cout << _screen[y][x];
        }
    }
}

void Screen::put(int y,int x,char icon){
    _screen[y][x] = icon;
}


char Screen::get_icon(int y, int x){
    return _screen[y][x];
}