#include <time.h>
#include <stdlib.h>

#include "TriviaQuestion.h"

using namespace std;

TriviaQuestion::TriviaQuestion(string data)
{
    srand(time(0));
    setup(data);  
}

void TriviaQuestion::setup(string data)
{
    if(data.empty()) return;

    vector<string> components = split(data, " :: ", 5);

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

    rand();
    // figure out random order
    // figure out correct answer number
    // ask question
    // get input
    // check answer
    // etc

    return 0; 
}

vector<string> const TriviaQuestion::split(const string &splitting, 
                                           const string &delimiter,
                                           int estimatedCapacity)
{
    vector<string> tokens;
    tokens.reserve(estimatedCapacity);
    
    size_t start_pos = 0;
    size_t found_pos;

    while((found_pos = splitting.find(delimiter, start_pos)) != string::npos)
    {
            //  push string up til first delimiter
        tokens.push_back(splitting.substr(start_pos, found_pos - start_pos));
        
            //  skip to the position AFTER this delimiter
        start_pos = found_pos + delimiter.length();
    }

        //  fence post last token
    tokens.push_back(splitting.substr(start_pos));

    return tokens;
}