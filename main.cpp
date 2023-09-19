/*
Name: Jack Knapp, 302.1
Purpose: Linked List, Stack Review
Description: Program to play Accordian card game
Input: Deck of cards from text file
What to do?:  Play a game of Accordian with the provided
    deck using a circular doubly linked list of stacks
Output: The formatted results of the card game
*/

#include "LL.h"
#include "LL.cpp"
#include "myStack.h"
#include "myStack.cpp"
#include <iostream>
#include <string>
using namespace std;


int main()
{   
    LL<myStack<string>> accordian;
    LL<myStack<string>>::iterator i,j,itt;

    //loop to read in cards, create stcks, and push to linked list
    for (int i=0; i<52; i++) {
        string card;
        cin >> card;
        myStack<string> temp;
        temp.push(card);
        accordian.tailInsert(temp);  
    }

    //After cards are read in begin main loop;
    //Also define some variables
    bool outofB = false;
    bool cardFound = false;
    i = accordian.begin();
    j = i;
    while (i != accordian.end()) {

        while (!cardFound) {
            
            //three check + out of bounds check
            outofB = false;
            j=i;
            j--;
            if (j == accordian.end()) {outofB = true;}
            j--;
            if (j == accordian.end()) {outofB = true;}
            j--;
            if (j == accordian.end()) {outofB = true;}

            //If checks are passed, look for a match
            if (outofB != true) {
                if ((*i).peek()[0] == (*j).peek()[0] || (*i).peek()[1] == (*j).peek()[1]) {
                    string item = (*i).pop();   //pop i
                    (*j).push(item);            //push i onto j
                    if ((*i).isEmpty()) {       //check for empty node/remove
                        accordian.removeAtPosition(i);
                    }

                    i = j;  //reset i to new stack
                    break;  //restart loop
                }
            }
            
            //one check + out of bounds check
            outofB = false;
            j=i;
            j--;
            if (j == accordian.end()) {outofB = true;}

            //If checks are passed, look for a match
            if (outofB != true) {
                if ((*i).peek()[0] == (*j).peek()[0] || (*i).peek()[1] == (*j).peek()[1]) {
                    string item = (*i).pop();   //pop i
                    (*j).push(item);            //push i onto j
                    if ((*i).isEmpty()) {       //check for empty node/remove
                        accordian.removeAtPosition(i);
                    }

                    i = j;  //reset i to new stack
                    break;  //restart loop
                }
            }

            i++;    //move to the next stack

            //for (itt = accordian.begin (); itt != accordian.end (); itt++) {
            //    cout << (*itt).peek() << " " ;
            //}
            //cout << endl << endl;
                
            //condition to break inner loop
            if (i == accordian.end()) {
                cardFound = true;
            }
        }
    }

    //reset iterators and define a counter
    i = accordian.begin();
    j = accordian.end();
    int count = 0;

    //count the number of stacks
    while (i!=j) {
        i++;
        count++;
    }

    //print the results of the game, formatted
    i = accordian.begin();
    cout << count << " Stacks: ";
    for (int b=0; b<count; b++) {
        cout<< (*i).peek() << ":";
        cout << (*i).getSize() << " ";
        i++;
    }
    cout << endl;

    return 0;
}