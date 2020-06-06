#pragma once

#include<iostream>
using namespace std;

// #define NORMAL_WINDOW_HEIGHT 18

class Screen{

private:

    int _width,_height;
    int _StatusWidth, _StatusHeight;
    char **_screen;
    char **_status;
    bool StatusScreen; //if true print func will also prints status screen
    void _ResizeTerminal(); //resize terminal according to Width and height
    bool value_check(int h, int w); //check if width and height is in range for getters


public:
    Screen();
   
    Screen(int h,int w);
   
    void initScreen(); //initialize screen without status screen
    void initStatus(); //initialize screen with status screen

    
    void refreshScreen(); //fills the screen and status with ' '
    void refreshStatus(); //fills the status screen with ' '
    
    void print(); //prints the screen and ( status if its being used );
    
    void setStatus(int y, string Name, string Value);
    void setStatus(int y, string Name, char Value);
    void setStatus(int y, string Name, int Value);
    void setStatus(int y, string Name);
    
    
    void put_on_screen(int y,int x,char icon); //puts passed element to the x,y pos on screen
    void put_on_status(int y,int x,char icon); //puts passed element to the x,y pos on status
    
    char getScreenElement(int y, int x); 
    char getStatusElement(int y, int x);
    int getScreenWidth(){ return _width; }
    int getScreenHeight(){ return _height; }
    int getStatusWidth(){ return _width/2; }
    int getStatusHeight(){ return _height; }


};

