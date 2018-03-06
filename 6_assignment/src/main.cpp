#include "TextMap.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

TextMap buildMap(string &fileContents, int level);
void printWelcome();
int getLevel();
string getFileName();
void generateSnippet(TextMap &map);

int main()
{
        // START
    clock_t start = clock();
    srand(time(0));

    int level = getLevel();

    string fileName = getFileName();
    ifstream file(fileName);

    if(file.is_open())
    { 
        cout << "File Opened Successfully : " << fileName << endl; 
    }
    else
    {
        cout << "BAD : " << fileName << endl;
        return -99;
    }

    string fileContents; // Dump file to string
    fileContents.assign(istreambuf_iterator<char>(file),
                    istreambuf_iterator<char>());

    TextMap map = buildMap(fileContents, level);

    bool keepGoing = true;
    string input;

    do
    {
        generateSnippet(map);
        cout << "Do you want another? Press enter to quit, anything else to repeat." << endl;
        getline(cin, input);
        keepGoing = !input.empty();
    } 
    while (keepGoing);

    cout << "Finished in " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
         << " seconds." << endl;

    return 0;
}

TextMap buildMap(string &fileContents, int level)
{
    cout << "Building map..." << endl;
 
    TextMap map = TextMap(level);

    int startPosition = 0;
    int foundPosition = 0;
    string sentence;
    
    while((foundPosition = fileContents.find_first_of(".!?", startPosition)) != string::npos)
    {
        sentence = fileContents.substr(startPosition, foundPosition - startPosition + 1);
        map.parseText(sentence);
        startPosition = foundPosition + 1; 
    }

    return map;
}

void printWelcome()
{
    cout << "Welcome to the grand writing artificial intelligence" << endl
         << "How may we help you today?" << endl << endl;
}

int getLevel()
{
    int level = 0;
    string clearBuffer;

    cout << "Please type in the level of search : ";
    cin >> level;

    while (level < 1 || level > 10)
    {
        if(!cin)
        {
            cin.clear();
            cin.ignore();
            getline(cin, clearBuffer);
        }
        cout << "Please enter a level between 1 and 10 : ";
        cin >> level;
    }

    cin.clear();
    cin.ignore();

    return level;
}

string getFileName()
{
    string fileName;

    cout << "Please type in the file name you would like your opus based on : ";
    getline(cin, fileName);

    if(fileName.find(".txt") == string::npos || 
       fileName[fileName.length()-1] != 't')
    {
        fileName.append(".txt");
    }

    return fileName;
}

void generateSnippet(TextMap &map)
{
    cout << "*****************************************************" << endl
         << "After careful thought, I surmise that the " 
         <<  "next sentence to your opus should be :" << endl
         << "*****************************************************" << endl
         << ">>" << map.generate(20) << endl
         << "*****************************************************" << endl;
}

