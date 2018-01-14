/**
 * Jacob Landowski, CS132, Winter 2667, Section A
 * Assignment #2, 1/10/18
 * 
 * This is the primary initial file for
 * CS 132 Assignment #2.  The purpose of this file
 * is to create a simplistic encryption tool to store and
 * reload user names and passwords.   In doing so
 * the user will use stings and string manipulation.
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


void addToFile(string fname);
void checkFile(string fname);
bool meetsRequirements(const string &password);
bool issymbol(char c);
string encryptPassword(const string &password);
string toMorseCode(char c);
void savePassword(string &password);
void toLower(string &password);

    //  hashed chars, a - z % 26 
    //  0 => h  | 1 => i  | 2 => j  | 3 => k
    //  ...
    //  19 => a | 20 => b | 21 => c 
const string MORSE_ALPHA[] = {  
                                "****", "**", "*---", "-*-",
                                "*-**", "--", "-*", "---", 
                                "*--*", "--*-", "*-*", "***",
                                "-", "**-", "***-", "*--",
                                "-**-", "-*--", "--**", "*-",
                                "-***", "-*-*", "-**", "*", 
                                "**-*", "--*"  
                             };

    //  hashed numbers/punctuation, 0 - 9 | . | , | ? | space % 26
    //  18 => , | 20 => . | 11 => ? | 6 => space
    //  ...
    //  0 => '4' | 1 => '5' 
    //  ... 
    //  22 => '0' | 23 => '1'
    //  array size and modulo is 26 because this produced no collisions
    //  and I'm too lazy to deal with probing stuff or fancy formulas
    //  Bonus side effect : any odd symbols will probably become an empty string 
const string MORSE_NUM_PUNCT[] = { 
                                    "****-", "*****", "-****", "--***", // 3
                                    "---**", "----*", "/", "", // 7
                                    "", "", "", "**--**", // 11
                                    "", "", "", "", // 15e
                                    "", "", "--**--", "", // 19
                                    "*-*-*-", "", "", "*----", // 23
                                    "**---", "***--"  // 25
                                 };

const int MORSE_ALPHA_HASH = 26;
const int MORSE_NUM_PUNCT_HASH = 26;

 int main()
 {
     string userPassword;
     int option;

     cout << "***************************************************************" << endl;
     cout << "Hello and welcome to the CS132 ultra secure password generator." << endl;
     cout << "***************************************************************" << endl;

     while (true)
     {
        const string fileName = "masterFile.txt";

        do
        {
            cout << "Would you like to test a password, or add a password?" << endl;
            cout << "  1 : for test a password"<< endl;
            cout << "  2 : for add a password" << endl;
            cout << "  3 : to quit" << endl;
            cout << "  >>> ";

            cin >> option;
        } while (option < 1 || option > 3);


        if (option == 1)
        {
            checkFile(fileName);
        }
        else if (option == 2)
        {
            addToFile(fileName);
        }
        else if (option == 3)
        {
            cout << "Thank you, have a good day." << endl;
            return 0;
        }
        else
        {
         // This is an error state, this should never happen.
         cerr << "ERROR invalid option" << endl;
         return 99;

        }

     } // End of the while(true);

    // The program did not leave correctly.
    cerr << "ERROR illegal loop exit." << endl;
    return 100;

 }

void addToFile(string fname)
{
    ofstream file(fname.c_str(), ios::app);

    cin.ignore(); // erase leftover whitespace from menu

        // get password from user
    string userPassword; 
    getline(cin, userPassword);

        // check string for valid password requirements
    if(!meetsRequirements(userPassword))
    {
        cout << "Doesn't meet requirements" << endl;
        return;
    }

    toLower(userPassword);
    
    string encryptedPassword = encryptPassword(userPassword);
    
    savePassword(encryptedPassword);
}

void checkFile(string fname)
{
    ifstream file(fname.c_str());

    if(file.is_open())
    {
        cout << "Opened filed \"" << fname << "\"" << endl;
        string line;
        while(file >> line)
        {
                // check hashed password against each hashed line in this file
                // if match found break out
                // cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Failed to open file \"" << fname << "\"" << endl; 
    }
        // fname = filename given to us
        // get password from user
        // encrypt password
        // see if encrypted password exists in file
        // give user notification
}

bool meetsRequirements(const string &password)
{
    int letters = 0;
    int numbers = 0; 
    int symbols = 0;

    for(unsigned int i = 0; i < password.length(); i++)
    {
             if(isalpha(password[i]))  letters++;
        else if(isdigit(password[i]))  numbers++;
        else if(issymbol(password[i])) symbols++;
    }

    return letters >= 10 && numbers >= 2 && symbols >= 1;
}

bool issymbol(char c)
{
    return c == ' ' || c == '.' || c == ',' || c == '?';
}

void toLower(string &password)
{
    for(unsigned int i = 0; i < password.length(); i++)
    {
        if(password[i] >= 'A' || password[i] <= 'Z')
        { 
            password[i] += 32;
        }
    }
}

string encryptPassword(const string &password)
{
    string encrypted = "";
    unsigned int lastIndex = password.length() - 1;

    for(unsigned int i = 0; i < lastIndex; i++)
    {
        // encrypted += toMorseCode(password[i]) + ' ';
    }

        // fence post so no space at end
    encrypted += toMorseCode(password[lastIndex]);

    return encrypted;
}

string toMorseCode(char c)
{
        //  if not alphabetical, use num/punct hash table
    return c < 'a' ? MORSE_NUM_PUNCT[c % MORSE_NUM_PUNCT_HASH] 
                   : MORSE_ALPHA[c % MORSE_ALPHA_HASH]; 
}

void savePassword(string &password)
{
    cout << password << endl;
}

