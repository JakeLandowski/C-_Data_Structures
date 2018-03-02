#include <iostream>
#include <string>

using namespace std;

bool didTheyAnswerYes(string str);

int main()
{
    int numStrings = 5;

    string testStrings[] = {
        "This is the way of the wild",
        "Yesterday is amazing",
        "I did it my way",
        "A banana is yellow",
        "My yam is yellow Yo!"
    };

    for(int i = 0; i < numStrings; i++)
    {
        cout << testStrings[i] << " : " 
                << (didTheyAnswerYes(testStrings[i]) ? "TRUE" : "FALSE") << endl;
    }

    return 0;
}

bool didTheyAnswerYes(string str)
{
    int yPos;

    while((yPos = str.find_first_of("yY")) != string::npos)
    {
        if(yPos == 0 || str[yPos - 1] == ' ') return true;

        str.erase(0, yPos + 1);
    }

    return false;
}