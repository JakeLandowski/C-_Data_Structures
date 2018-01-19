#ifndef H_TriviaQuestion_H
#define H_TriviaQuestion_H

#include <string> // in case iostream doesn't include
#include <iostream>

class TriviaQuestion
{
    private:
        std::string question;
        std::string answers[4];

    public:
        TriviaQuestion(std::string data = "");
        void setup(std::string data); 
        int askQuestion();
};

#endif