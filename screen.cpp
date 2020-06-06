#include"headers/screen.h"


Screen::Screen(){
    _height = 18;
    _width = 50;
    StatusScreen = false;
    
}

Screen::Screen(int h, int w){
    _height = h;
    _width = w;
    StatusScreen = false;
}


void Screen::initScreen(){   
    //resizing terminal to get desired height and width
    _ResizeTerminal();

    //allocating memory for screen
    _screen = new char*[_height];
    for(int y = 0; y < _height; y++){
        _screen[y] = new char[_width];
    }
    


    //filling all pos with ' '
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width; x++){
            _screen[y][x] = ' ';
        }
    }


}


void Screen::initStatus(){
    StatusScreen = true;
    _StatusHeight = _height;
    _StatusWidth = _StatusWidth/2;

    //allocates memory for status
    _status = new char*[_height];
    for(int y = 0; y < _height; y++){
        _status[y] = new char[_width/2];
    }

    //filling status with spaces
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width / 2; x++){
            _status[y][x] = ' ';
        }
    }
    initScreen();


}



//SetStatus

void Screen::setStatus(int y, string Name){
    if(StatusScreen){

        for(int i = 0; i < _StatusWidth; i++){
            put_on_status(y,i,' ');
        }
        //checks if the Name can fit in our status screen
        //if not then "TooBig" will be printed instead of passed strings
        if(Name.size() < _width/2 - 2){
            
            
            for(int x = 0; x < Name.size(); x++){
                put_on_status(y,x + 2,Name[x]);
            }   
            
        }
        else {
            string TooBig = "TooBig!";
            for(int x = 0; x < TooBig.size(); x++){
                put_on_status(y,x+1,TooBig[x]);
            }
        }
    }

}

void Screen::setStatus(int y, string Name, char Value){
    if(StatusScreen){
        //combining both values 
        //so it's easy to put it on status screen
        Name += ": "; //seperator
        Name += Value; 
        for(int i = 0; i < _StatusWidth; i++){
            put_on_status(y,i,' ');
        }

        //checks if the Name and value can fit in our status screen
        //if not then "TooBig" will be printed instead of passed strings
        if(Name.size() < _width/2 - 2){
            
           
          
            for(int x = 0; x < Name.size(); x++){
                put_on_status(y,x + 2,Name[x]);
            }   

        }
        else {
            string TooBig = "TooBig!";
            for(int x = 0; x < TooBig.size(); x++){
                put_on_status(y,x+1,TooBig[x]);
            }
        }
    }

}

void Screen::setStatus(int y, string Name, string Value){
    if(StatusScreen){
           //combining both values 
        //so it's easy to put it on status screen
        Name += ": "; //seperator
        Name += Value; 
        for(int i = 0; i < _StatusWidth; i++){
            put_on_status(y,i,' ');
        }

        //checks if the Name and value can fit in our status screen
        //if not then "TooBig" will be printed instead of passed strings
        if(Name.size() < _width/2 - 2){
            
           
            for(int x = 0; x < Name.size(); x++){
                put_on_status(y,x + 2,Name[x]);
            }
            
        }
        else {
            string TooBig = "TooBig!";
            for(int x = 0; x < TooBig.size(); x++){
                put_on_status(y,x+1,TooBig[x]);
            }
        }

    }

}


void Screen::setStatus(int y, string Name, int Value){
    if(StatusScreen){
        //converts int to string
        //as we can only set char values to status screen
        //so we need to convert our score or any other int value to string
        //so that we can print it on status screen
    
        std::string temp;
        std::string ActualValue = "";
        int t;
        do{
            t = Value % 10;  
            Value /= 10;
            temp += char(t +'0');
            ActualValue += '0';
        }while(Value != 0);
        int size = temp.size() - 1;
        for(int i = size; i >= 0; i--){
            ActualValue[size - i] = temp[i];
        }
      
        
        //combining both values 
        //so it's easy to put it on status screen
        Name += ": "; //seperator
        Name += ActualValue; 
        for(int i = 0; i < _StatusWidth; i++){
            put_on_status(y,i,' ');
        }
        //checks if the Name and value can fit in our status screen
        //if not then "TooBig" will be printed instead of passed strings
        if(Name.size() < _width/2 - 2){

            for(int x = 0; x < Name.size(); x++){
                put_on_status(y,x + 2,Name[x]);
            }
            
        }
        else {
            string TooBig = "TooBig!";
            for(int x = 0; x < TooBig.size(); x++){
                put_on_status(y,x+1,TooBig[x]);
            }
        }

    }

}



//fills the whole screen with spaces ' '
void Screen::refreshScreen(){
    
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width; x++){
            _screen[y][x] = ' ';
        }
    }

}


//fills the whole status screen with spaces ' '
void Screen::refreshStatus(){
   
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width / 2; x++){
            _status[y][x] = ' ';
        }
    }

}


//prints upper and lower border
void upLowBorder(int width){
    
    for(int i = 0; i < width + 2; i++){
        cout << "#";
    }

}


void Screen::print(){
    //prints upper border
    upLowBorder(_width);
    
    cout << ' '; //screen and status seperator

    if(StatusScreen) upLowBorder(_width / 2); //prints bottom border for status
    cout << '\n';


    for(int y = 0; y < _height; y++){
        cout << "#"; //left border;
        for(int x = 0; x < _width; x++){
            cout << _screen[y][x]; //data
        }
        cout << '#'; //end of screen border 

        cout << ' '; //to seperate screen and status


        if(StatusScreen){
       

            cout << '#'; //Status border starts
            for(int x = 0; x < _width/2; x++){
                cout << _status[y][x]; //Status data
            }
            cout << '#'; //Status border ends


        }
        
        cout << endl; //border ends
    }



    //prints lower border for screen
    upLowBorder(_width);
    cout << ' '; //screen and status seperator

    if(StatusScreen){

    //prints bottom border for status
    upLowBorder(_width / 2);

    }
    cout << '\n';

}

bool Screen::value_check(int h, int w){
    if(w < _width && h < _height && w >= 0 && h >= 0) return true;

    return false;
}

void Screen::put_on_screen(int y,int x,char icon){
    if(value_check(y,x)) _screen[y][x] = icon;
}

void Screen::put_on_status(int y, int x, char icon){
    if(y < _width/2 && y < _height && x >= 0 && y >= 0) _status[y][x] = icon;
} 

char Screen::getScreenElement(int y, int x){
    if(value_check(y,x)) return _screen[y][x];
    else return '#';
}

char Screen::getStatusElement(int y, int x){
    if(y < _width/2 && y < _height && x >= 0 && y >= 0) return _status[y][x];
    else return '#';
}


void Screen::_ResizeTerminal(){
    int w = _width;
    int h = _height + 10; // + 10 to get some extra space
    if(StatusScreen){
        w = _width + (_width + 2); //as we also need to print status screen 
    }
    w += 10;
    cout << "\033[8;" << h << ";" << w << "t"; //To resize terminal
}

