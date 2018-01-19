/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #2, 1/10/18
 * 
 *  This program...
 */


#include <string> // in case iostream doesn't include
#include <iostream>

#include "TriviaQuestion.h"

using namespace std;

int main()
{
    unsigned int timestamp = time(0);

    TriviaQuestion question("question here :: answer 1 here :: answer 2 here :: answer 3 here :: answer 4 here");

    cout << "Finished in " << timestamp << endl;
    return 0;
}