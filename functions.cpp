#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "headers/screen.h"

bool kbhit(){
    termios term;
    tcgetattr(0, &term);
    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    tcsetattr(0, TCSANOW, &term);
    return byteswaiting > 0;
}

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void update_fruit(Screen& screen){
    int _x = rand() % screen.get_width() + 1;
    int _y = rand() % screen.get_height() + 1;
    while(1){
        if(screen.get_icon(_y,_x) == ' ') break;
        else{
            _x = rand() % screen.get_width() + 2;
            _y = rand() % screen.get_height() + 2;
        }
    }
    screen.put(_y,_x,'f');
}