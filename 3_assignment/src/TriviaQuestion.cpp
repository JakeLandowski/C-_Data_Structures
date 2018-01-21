#include <stdlib.h>

#include "TriviaQuestion.h"
#include "Utilities.h"

using namespace std;

TriviaQuestion::TriviaQuestion(string data)
{
    setup(data);  
}
            
void TriviaQuestion::setup(string data)
{
    if(data.empty()) return;

    answerIndex = 0;

        // java-esque split()
    vector<string> components = Utilities::split(data, " :: ", 5);

    question   = components[0];
    answers[0] = components[1];
    answers[1] = components[2];
    answers[2] = components[3];
    answers[3] = components[4];
}

int TriviaQuestion::askQuestion()
{
    if(question.empty()) cerr << "Question not setup yet." << endl;


    //====== PRINT SHUFLED QUESTION/ANSWERS ======//
    shuffleQuestions();
    
    cout << question << endl;

    for(int i = 0; i < NUM_ANSWERS; i++)
    {
        cout << '\t' << i + 1 << ". " << answers[i] << endl;
    }


    //====== GET USER ANSWER ======//
    cout << endl << "Your Answer >> ";
    cout.flush(); // force print

    int userAnswer = 0;

    cin >> userAnswer;
    cin.ignore(); // ignore remaining whitespace 


    //====== CHECK ANSWER, INFORM USER, RETURN RESULT ======//
    bool incorrect = userAnswer - 1 != answerIndex;

    if(incorrect)
    {
        cout << endl << "~~ Incorrect! ~~" << endl
             << "Answer : " << answers[answerIndex] << endl << endl;
        return 0;
    }

    cout << endl << "~~ Correct! ~~" << endl << endl;
    return 1; 
}

/**
 *  Linear in-place fisher yates shuffle
 *  Random index 0 => 3 | Swap picked with 3
 *  Random index 0 => 2 | Swap picked with 2
 *  Random index 0 => 1 | Swap picked with 1
*/
void TriviaQuestion::shuffleQuestions()
{
    int picked;
    string temp;

    for(int i = NUM_ANSWERS; i > 0; i--)
    {
        picked = rand() % i; 
        temp   = answers[picked];
        answers[picked] = answers[i - 1];
        answers[i - 1] = temp;
        
        if(picked == answerIndex)
        {
            answerIndex = i - 1;
        } 
    }
}