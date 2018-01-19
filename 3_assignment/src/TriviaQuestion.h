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
        std::string question;
        std::string answers[4];
        int answerIndex;

        int[] shuffleQuestions();
};

#endif