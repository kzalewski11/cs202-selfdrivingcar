//Kyle Zalewski
//CS202
//Project 1
//kylezalewski_prog1.cpp
//function implementations

#include "kylezalewski_prog1.h"

//node default constructor
//no arguments
node::node()
{
    occupied = false;
    next = NULL;
}

//node constructor wrapper with passed in occupied arg
node::node(bool occupied)
{
    this->occupied = occupied;
    this->next = NULL;
}

//node constructor with passed in node
//requires node pointer as arg
node::node(node * toAdd)
{
    node * newNode = new node;
    newNode->occupied = toAdd->occupied;
    newNode->next = toAdd->next;
}

//display node //arg is node type
//need to edit to display entire LLL not just single node
void node::display(node * toDisp)
{
    if(!toDisp)
        return;
    if(toDisp->occupied)
        cout << " <CAR> ";
    else
        cout << " <   > ";
    if(toDisp->next)
        display(toDisp->next);
    return;    
}

//add node to LLL
int node::add(node * & start, node * toAdd)
{ 
    //traverse the list starting at lane
    if(!start)
        return 0;
    //stop when node->next = NULL
    if(!start->next)
    {
        node * adding = new node;                 //create new node
        adding->occupied = toAdd->occupied;     //copy occupied from passed in node
        start->next = adding;                   //link adding to end of LLL
        return 1;
    }
    return add(start->next, toAdd) + 1;
}

//location default constructor
//no args
location::location()
{
    speedLimit = LIMIT;
    manual = false;
    for(int i = 0; i < SIZE; i++)
    {
        node * newNode = new node;              //create node to be added to array
        head[i] = newNode;                      //call constructor for node in ith array element
        //add LENGTH additional nodes to each lane
        for(int j=0; j<LENGTH; j++)
        {
            int rn = rand();
            if(rn%2 == 0)
            {   
                node * occNode = new node(true);
                head[i]->add(head[i], occNode);
            }
            else
            {
                node * addNode = new node;
                head[i]->add(head[i], addNode);
            }
        }
    }
}

//speed limit display function
//no args
void location::dispSpeedLimit()
{
    cout << "The current speed limit is " << location::speedLimit << "." << endl << endl;
}

//display all elements of the array and all elements of each LLL
//no args
void location::display()
{
    //control structure to move through array elements
    for(int i=0;i<SIZE; i++)
    {
        //print lane labels
        cout << "Lane " << i + 1 << ": ";
        //print each lane's LLL content
        head[i]->display(head[i]);
        cout << endl << endl;
    }
}

//default constructor for car class
//no args
car::car()
{
    me = false;
}

//default constructor for space class
//no args
space::space()
{
    safe = false;
}

//default constructor for busLane class
//no args
busLane::busLane()
{
    carAllowed = false;
}

//default constructor for bikeLane class
//no args
bikeLane::bikeLane()
{
    shared = false;
    toRight = 0;
}

