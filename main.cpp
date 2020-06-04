#include "headers/screen.h"
#include "headers/snake.h"
#include "headers/functions.h"


int main(){
    srand(time(NULL)); //to get fruits on random position
    //height and width of the screen
    int width = 50,height = 18;
    
    //initialization of screen
    Screen screen(height,width);
    screen.init();
    update_fruit(screen);
    //initialization of snake
    Snake snake(height/2, width/2);
    snake.add_length(screen);

    //var to determine move;
    int move;
    //actual game starts
    while(1){
        if(kbhit()){
            move = getch();
        } 
        if(move == 'w') snake.move_up(screen);
        else if(move == 's') snake.move_down(screen);
        else if(move == 'a') snake.move_left(screen);
        else if(move == 'd') snake.move_right(screen);
        else {}
        system("clear");
        screen.print();
        cout << "key pressed : " << (char)move << endl;
        if(move == 'a'|| move == 'd') system("sleep 0.1");
        else system("sleep 0.2");
    }
    return 0;
}