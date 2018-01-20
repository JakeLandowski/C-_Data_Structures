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
    clock_t start = clock();

    // TriviaQuestion question("question here :: answer 1 here :: answer 2 here :: answer 3 here :: answer 4 here");
    TriviaQuestion question("x :: a :: b :: c :: d");

    // open file
    // get num questions from line 1
    // 



    cout << "Finished in " << ((float) (clock() - start) / CLOCKS_PER_SEC) << endl;
    return 0;
}