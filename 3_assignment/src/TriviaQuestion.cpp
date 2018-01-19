#include "TriviaQuestion.h"

using namespace std;

TriviaQuestion::TriviaQuestion(string data)
{
    setup(data);  
}

void TriviaQuestion::setup(string data)
{
    if(data.empty()) return;

    string delimiter = " :: ";
    size_t start_pos = 0;
    size_t found_pos;

    if((found_pos = data.find(delimiter, start_pos)) != string::npos)
    {
            //  set question equal to string up til first delimiter
        question  = data.substr(start_pos, found_pos - start_pos);

            //  skip to the position AFTER this delimiter
        start_pos = found_pos + delimiter.length(); 
    }

    int index = 0;

    while((found_pos = data.find(delimiter, start_pos)) != string::npos)
    {
        if(index > 3) 
        {
            cerr << "Too many answer arguments given to TriviaQuestion setup()" << endl;
            break;
        }

            //  set answer equal to string up til first delimiter
        answers[index] = data.substr(start_pos, found_pos - start_pos);
        
            //  skip to the position AFTER this delimiter
        start_pos = found_pos + delimiter.length();
        index++;
    }

    answers[3] = data.substr(start_pos);

    cout << "\"" << question << "\""  << endl
         << "\""<< answers[0] << "\"" << endl
         << "\""<< answers[1] << "\"" << endl
         << "\""<< answers[2] << "\"" << endl
         << "\""<< answers[3] << "\"" << endl;
}

int TriviaQuestion::askQuestion()
{
    if(question.empty()) cerr << "Question not setup yet." << endl;

    // figure out random order
    // figure out correct answer number
    // ask question
    // get input
    // check answer
    // etc

    return 0; 
}