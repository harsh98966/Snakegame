#include "headers/game.h"
#include "headers/functions.h"




//Game Class

Game::Game(int height, int width){
    
    playAgain = false;
    _ScreenHeight = height;
    _ScreenWidth = width;
    screen = new Screen(height,width);
    snake = new Snake(height/2,width/2);
    cout << "Enter Your Name : ";
    getline(cin,_PlayerName);
    resetAll();

}

Game::~Game(){
    delete snake;
}

void Game::resetAll(){
    _Score = 0;
    _GameOver = false;
    PreviousMove = '0'; //invalid move
    _level = 1;
    _maxLevel = 10;
    _nextLevel = _Score + 30;
}

void Game::levelCheck(){
    if(_level != _maxLevel){
        if(_Score >= _nextLevel){
            _nextLevel = _Score + 10;
            _level += 1;
        }
    }
    else {
        _level = _maxLevel;
    }
}



//add fruit to the screen
void Game::_add_fruit(){
    while(1){
        _fruitX = rand() % _ScreenWidth;
        _fruitY = rand() % _ScreenHeight;
        if(screen->getScreenElement(_fruitY,_fruitX) == ' '){
            break;
        }
    }
    screen->put_on_screen(_fruitY,_fruitX,'f');
}

//add fruit to the screen
void Game::_add_Power(){
    while(1){
        _powerX = rand() % _ScreenWidth;
        _powerY = rand() % _ScreenHeight;
        if(screen->getScreenElement(_powerX,_powerY) == ' '){
            break;
        }
    }
    screen->put_on_screen(_powerX,_powerY,'$');
}


//initialize's screen and snake
void Game::init(){
    
}


//update StatusScreen
void Game::updateStatus(){
    
    screen->setStatus(1,"PlayerName",_PlayerName);
    screen->setStatus(3,"Score",_Score);
    if(_level == _maxLevel){
        // screen->setStatus(5,"CurrentLevel","MaxLevel");
        screen->setStatus(7," ");
    }
    else {
        screen->setStatus(7,"NextLevel",_nextLevel);
    }
    screen->setStatus(5,"CurrentLevel",_level);
    screen->setStatus(9,"MaxLevels",_maxLevel);


    //info about fruits and powerups
    screen->setStatus(_ScreenHeight - 2,"f"," +5");
    screen->setStatus(_ScreenHeight - 1,"$"," +10");

}


//Sets up everything and starts the actual game loop
void Game::Start(){
    system("clear");
    
    //initialize snake and screen
    if(!playAgain){
        screen->initStatus();
    } 
    snake->update_snake(*screen);
    playAgain = false;    _add_fruit();
    _add_Power();


    char move{'d'};


    //first time
    screen->setStatus(2,"Press any key to start");
    screen->print();
    getch();    
    screen->refreshStatus();
  

    //Game loop
    while(!_GameOver){
        
        levelCheck();
        if(move == 'd' || move == 'a'){
            switch (_level){
                case 1:
                    system("sleep 0.5");
                    break;
                case 2:
                    system("sleep 0.4");
                    break;
                case 3:
                    system("sleep 0.3");
                    break;
                case 4:
                    system("sleep 0.25");
                    break;
                case 5:
                    system("sleep 0.2");
                    break;
                case 6:
                    system("sleep 0.15");
                    break;
                case 7:
                    system("sleep 0.08");
                    break;
                case 8:
                    system("sleep 0.07");
                    break;
                case 9:
                    system("sleep 0.06");
                    break;
                case 10:
                    system("sleep 0.04");
                    break;
                default:
                    system("sleep 0.04");
                    break;
            }
        }
        else{

            switch (_level){
                case 1:
                    system("sleep 0.55");
                    break;
                case 2:
                    system("sleep 0.45");
                    break;
                case 3:
                    system("sleep 0.35");
                    break;
                case 4:
                    system("sleep 0.30");
                    break;
                case 5:
                    system("sleep 0.25");
                    break;
                case 6:
                    system("sleep 0.20");
                    break;
                case 7:
                    system("sleep 0.15");
                    break;
                case 8:
                    system("sleep 0.10");
                    break;
                case 9:
                    system("sleep 0.08");
                    break;
                case 10:
                    system("sleep 0.06");
                    break;
                default:
                    system("sleep 0.06");
                    break;
            }   

        } 
        system("clear");
       
        MakeMove(move);
        if(_GameOver){
            break;
        }

        snake->update_snake(*screen);
        updateStatus();
        screen->print();
        
        //loop for handling long keypress
        while(kbhit()){
            move = getch();
        }


    }

    GameOver(); //above loop will only exit if game is over

}



void Game::MakeMove(char &move){
    //to stop snake moving backward
    //we check if move is valid or not
    /*
        for example :  if previousMove = 'a' and user presses 'd' then the move is not valid
    */
    if(PreviousMove == '0'){
        PreviousMove = move;
    }
 
    char element; //stores element our snake eats(even ' ')

    if(move != 'w' && move != 'a' && move != 's' && move != 'd'){
        move = PreviousMove;
    }
    else {
        //invalid move's 
        if(PreviousMove == 'a' && move == 'd'){
            move = PreviousMove;
        }
        else if(PreviousMove == 'd' && move == 'a'){
            move = PreviousMove;
        }
        else if(PreviousMove == 'w' && move == 's'){
            move = PreviousMove;
        }
        else if(PreviousMove == 's' && move == 'w'){
            move = PreviousMove;
        }
        else { //valid move
            PreviousMove = move;   
        }
    }


    element = snake->_MoveSnake(move,*screen);
    //'f' denotes fruitlevel
    if(element == 'f'){
        snake->add_length(*screen);
        _add_fruit();
        _Score += 5;
    }
    else if(element == '#' || element == '*'){
        _GameOver = true;
    }
    else if(element == '$'){
        snake->add_length(*screen);
        snake->add_length(*screen);
        _add_Power();
        _Score += 10;
    }
    else {}
    
}




void Game::GameOver(){
    system("clear");
    screen->refreshStatus();
    screen->setStatus(1,"Score",_Score);
    screen->setStatus(3,"GameOver");
    screen->setStatus(5,"Do You Want");
    screen->setStatus(6," to play Again?");
    screen->setStatus(7," 'y' - Yes");

    screen->print();

    char choice;
    cin >> choice;
    cin.clear();
    cin.ignore(250,'\n');
    if(choice == 'y'){
        playAgain = true;
        screen->refreshScreen();
        screen->refreshStatus();
        snake->deleteSnake(_ScreenHeight/2,_ScreenWidth/2,*screen);
        resetAll();
        Start();
    }
    else {
        system("clear");
        screen->refreshStatus();
        screen->setStatus(5,"Bye!!!");
        screen->print();
    }
}

