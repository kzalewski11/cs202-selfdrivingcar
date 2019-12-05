//Kyle Zalewski
//CS202
//Project 1
//main.cpp
//main program file

#include "kylezalewski_prog1.h"

int main (){
    int begin = 0; 
    location street;                                               //create street object
    
    cout << "Hello. Welcome to AutoDrive." << endl;             //greet user and begin program
    street.dispSpeedLimit();                                    //display street speed limit
    // display map to begin program
    street.display();    

    //user start menu
    cout << "Please press 1 to begin driving. " << endl;
    cin >> begin;
    cin.ignore(100, '\n');

    //check if input from user is correct and exit program if not
    if(begin != 1)
    {
        cout << "Begin has not been selected. " << endl
            << "Exiting program and returning manual control. " << endl;
        return 0;
    }
    
    //begin driving
    cout << "You have turned right into the rightmost lane. " << endl;

    return 0;
}

