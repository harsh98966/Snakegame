#include "headers/game.h"
// #include "headers/screen.h"
// #include "headers/snake.h"
int main(){
    srand(time(NULL));
    Game game(19,55);
    game.Start();

//TODO : add play again

    return 0;
}