#include "TriviaQuestion.h"

using namespace std;

TriviaQuestion::TriviaQuestion(string data)
{
    setup(data);  
}

void TriviaQuestion::setup(string data)
{
    if(data.empty()) return;


    // parse question
}

int TriviaQuestion::askQuestion()
{
    if(question.empty()) cerr << "Question not setup yet." << endl; 
}