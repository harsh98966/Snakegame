#pragma once

#include<iostream>
using namespace std;

class Screen{
private:
   int _width,_height;
    char **_screen;
public:
    Screen();
    Screen(int h,int w);
    ~Screen();
    void init();
    void print(); 
    void put(int y,int x,char icon);
    char get_icon(int y, int x);
    int get_width(){ return _width; }
    int get_height(){ return _height; }
};

