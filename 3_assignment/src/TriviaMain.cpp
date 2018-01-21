/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #2, 1/10/18
 * 
 *  This program reads 250 questions from the file "TriviaData.txt"
 *  and wraps them in TriviaQuestion objects. It then prompts the user
 *  for a number of questions to ask, then begins quizzing them with
 *  random question selections. Afterwards it calculates their score.
 */


#include <string> // in case iostream doesn't include
#include <iostream>
#include <fstream>
#include <cstdlib> // for random

#include "TriviaQuestion.h"

using namespace std;

int main()
{
    //  timer for reference
    //clock_t start = clock();

    srand(time(0)); // seed random

    ifstream triviaFile("TriviaData.txt");

    if(triviaFile.is_open()) 
    {
        int numQuestions,  numAsked,  numCorrect;
            numQuestions = numAsked = numCorrect = 0;

        //====== CREATE QUESTIONS ARRAY ======//
        triviaFile >> numQuestions;
        triviaFile.ignore(); // clear whitespace
        triviaFile.ignore(); // need two for first line, not sure why

        TriviaQuestion questions[numQuestions];


        //====== SETUP EACH QUESTION OBJECT ======//
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


        //====== ASK HOW MANY AND BEGIN QUIZ ======//
        cout << "How many questions would you like to try?" << endl
             << ">> ";
        cout.flush();

        cin >> numAsked;

        for(int i = 0; i < numAsked; i++)
        {
            numCorrect += questions[rand() % 250].askQuestion(); 
        }

        cout << "Your score was " << numCorrect << " out of " 
             << numAsked << " for " 
             << ((double) numCorrect / numAsked) * 100 << "%." << endl;
    }
    else // file error
    {
        cerr << "Failed to open file : \"TriviaData.txt\"" << endl;  
    }

    if(triviaFile.is_open()) triviaFile.close();


    //  timer for reference
    //cout << "Finished in " << ((float) (clock() - start) / CLOCKS_PER_SEC) << endl;
    
    return 0;
}