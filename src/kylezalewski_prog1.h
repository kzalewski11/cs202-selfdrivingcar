//Kyle Zalewski
//CS202
//Project 1
//kylezalewski_prog1.h
//class declarations and global variables

#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 4;
const int LIMIT = 35;
const int LENGTH = 20;

//node class
class node
{
    public:
        node();                              //default constructor
        node(bool occupied);                    //wrapper constructor with passed in occupied flag
        node(node * newNode);                //constructor with passed in node
        void display(node * toDisp);                    //display node function
        int add(node * & start, node * toAdd);        //add node function
        
    private:
        bool occupied;
        node * next;                //next pointer

};

//location base class
class location
{
    public:
        location();                          //location class constructor
        void dispSpeedLimit();               //function to display speed limit
        void display();                      //display array of LLL

    private:
        int speedLimit;                       //speed limit of street
        node * head[SIZE];
        bool manual;                          //driver manual control required
        
};

//car class derived from location
class car:public location
{
    public:
        car();
    private:
        bool me;                                //flag for user car
};

//class for empty space derived from location
class space:public location
{
    public: 
        space();                                //default space constructor
    private:
        bool safe;                              //flag for lane open
};

//derived class from empty space to represent bus lane
class busLane:public space
{
    public:
        busLane();                              //default busLane constructor
    private:
        bool carAllowed;                        //flag saying if bus lane allows cars to share

};

//derived class from empty space to represent bike lane
class bikeLane:public space
{
    public:
        bikeLane();                             //default bikeLane constructor
    private:
        bool shared;                            //flag saying if cars can share
        int toRight;                            //if lane is not shared, int represents
                                                //lane the bike lane sits to the right of.
                                                //if shared, toRight will equal zero.

};
