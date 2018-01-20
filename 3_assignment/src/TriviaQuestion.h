#ifndef H_TriviaQuestion_H
#define H_TriviaQuestion_H

#include <string> // in case iostream doesn't include
#include <iostream>
#include <vector>

class TriviaQuestion
{
    public:
        TriviaQuestion(std::string data = "");
        void setup(std::string data); 
        int askQuestion();

    private:
        static const int NUM_ANSWERS = 4;
        std::string question;
        std::string answers[NUM_ANSWERS];
        int answerIndex;

        void shuffleQuestions();
};

#endif