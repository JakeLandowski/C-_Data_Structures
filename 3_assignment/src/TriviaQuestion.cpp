#include <time.h>
#include <stdlib.h>

#include "TriviaQuestion.h"
#include "Utilities.h"

using namespace std;

TriviaQuestion::TriviaQuestion(string data)
{
    srand(time(0));
    setup(data);  
}

void TriviaQuestion::setup(string data)
{
    if(data.empty()) return;

    answerIndex = 0;

    vector<string> components = Utilities::split(data, " :: ", 5);

    question   = components[0];
    answers[0] = components[1];
    answers[1] = components[2];
    answers[2] = components[3];
    answers[3] = components[4];

    cout << "\"" << question   << "\"" << endl
         << "\"" << answers[0] << "\"" << endl
         << "\"" << answers[1] << "\"" << endl
         << "\"" << answers[2] << "\"" << endl
         << "\"" << answers[3] << "\"" << endl;
}

int TriviaQuestion::askQuestion()
{
    if(question.empty()) cerr << "Question not setup yet." << endl;

    int correctAnswer;



    // figure out random order
    // figure out correct answer number
    // ask question
    // get input
    // check answer
    // etc

    return 0; 
}

void shuffleQuestions()
{
    for()
}