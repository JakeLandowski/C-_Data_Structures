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

/**
 *  Scan through the file text and feed the map one sentence
 *  at a time to build a more diverse mapping. Stops at each
 *  period, exclaimation or question mark.
 * 
 *  @param string &fileContents     Reference to the string dump
 *                                  from a file
 *  @param int level                The level/order to parse text at
 *  @return TextMap map             The complete map ready to use       
*/
TextMap buildMap(string &fileContents, int level)
{
    cout << "Building map..." << endl;
 
    TextMap map = TextMap(level);

    size_t startPosition = 0;
    size_t foundPosition = 0;
    string sentence;
    
    while((foundPosition = fileContents.find_first_of(".!?", startPosition)) != string::npos)
    {
        sentence = fileContents.substr(startPosition, foundPosition - startPosition + 1);
        map.parseText(sentence);
        startPosition = foundPosition + 1; 
    }

    return map;
}

/**
 *  Print the intro to the program       
*/
void printWelcome()
{
    cout << "Welcome to the grand writing artificial intelligence" << endl
         << "How may we help you today?" << endl << endl;
}


/**
 *  Prompt the user continuously until an order between 1-10 is given.
 * 
 *  @return int level   The desired level the user chose       
*/
int getLevel()
{
    int level = 0;
    string clearBuffer;

    cout << "Please type in the level of search : ";
    cin >> level;

    while (level < 0 || level > 10)
    {
        if(!cin)
        {
            cin.clear();
            cin.ignore();
            getline(cin, clearBuffer);
        }
        cout << "Please enter a level between 0 and 10 : ";
        cin >> level;
    }

    cin.clear();
    cin.ignore();

    return level;
}

/**
 *  Prompt the user for a text file to read content from. Will append
 *  a .txt extension if it was omitted.
 * 
 *  @return string fileName           The name of the file given       
*/
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

/**
 *  Print the fancy text stuff that includes a generated sentence from the map.
 *  Will print atleast 20 characters, will continue until it reaches punctuation.       
*/
void generateSnippet(TextMap &map)
{
    cout << "*****************************************************" << endl
         << "After careful thought, I surmise that the " 
         <<  "next sentence to your opus should be :" << endl
         << "*****************************************************" << endl
         << ">>" << map.generate(20) << endl
         << "*****************************************************" << endl;
}

