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

        static std::vector<std::string> const split(const std::string &splitting, 
                                                    const std::string &delimiter,
                                                    int estimatedCapacity = 10);
};

#endif