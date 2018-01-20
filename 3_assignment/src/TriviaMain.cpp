/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #2, 1/10/18
 * 
 *  This program...
 */


#include <string> // in case iostream doesn't include
#include <iostream>
#include <fstream>
#include <cstdlib> // for random

#include "TriviaQuestion.h"

using namespace std;

int main()
{
    clock_t start = clock();
    srand(time(0)); // seed random

    ifstream triviaFile("TriviaData.txt");

    if(triviaFile.is_open())
    {
        int numQuestions, numRequested, numAsked, numCorrect;

        triviaFile >> numQuestions;
        triviaFile.ignore(); // clear whitespace
        triviaFile.ignore(); // need two for first line, not sure why

        TriviaQuestion questions[numQuestions];
        string data;

        cout << endl << "Loading trivia game... ";
        cout.flush();

            //  loop each line, pass to question objects
        for(int i = 0; i < numQuestions; i++)
        {
            getline(triviaFile, data);
            questions[i].setup(data); 
        }

        cout <<  "done." << endl << endl;

        triviaFile.close(); // done with file

        questions[0].askQuestion();
    }
    else
    {
        cerr << "Failed to open file : \"TriviaData.txt\"" << endl;  
    }

    if(triviaFile.is_open()) triviaFile.close();



    cout << "Finished in " << ((float) (clock() - start) / CLOCKS_PER_SEC) << endl;
    return 0;
}