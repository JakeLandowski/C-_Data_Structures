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

// HELPERS
string getUserPassword();
bool meetsRequirements(const string &password);
bool issymbol(char c);
string encryptPassword(const string &password);
string toMorseCode(char c);
void savePassword(string &password, string fname);
void toLowerCase(string &password);

    //  hashed chars, a - z % 26 
    //  0 => h  | 1 => i  | 2 => j  | 3 => k
    //  ...
    //  19 => a | 20 => b | 21 => c 
const string MORSE_ALPHA[] = {  
                                "****",   "**",    "*---",  "-*-",
                                "*-**",   "--",    "-*",    "---", 
                                "*--*",   "--*-",  "*-*",   "***",
                                "-",      "**-",   "***-",  "*--",
                                "-**-",   "-*--",  "--**",  "*-",
                                "-***",   "-*-*",  "-**",   "*", 
                                "**-*",   "--*"  
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
const string MORSE_NUM_PUNCT[] = {                                            // last index 
                                    "****-",    "*****", "-****",   "--***",  // 3
                                    "---**",    "----*", "/",       "",       // 7
                                    "",         "",      "",        "**--**", // 11
                                    "",         "",      "",        "",       // 15
                                    "",         "",      "--**--",  "",       // 19
                                    "*-*-*-",   "",      "",        "*----",  // 23
                                    "**---",    "***--"                       // 25
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

        //  Initial menu prompt, continue grabbing tokens
        //  and printing menu until user enters 1-3
        do
        {
            cout << "Would you like to test a password, or add a password?" << endl;
            cout << "  1 : for test a password"<< endl;
            cout << "  2 : for add a password" << endl;
            cout << "  3 : to quit" << endl;
            cout << "  >>> ";

            cin >> option;
        } while (option < 1 || option > 3);

            //  1 : Check file for a password
            //  2 : Add a password to the file
            //  3 : Exit program
            //  D : Error
        switch(option)
        {
            case 1: checkFile(fileName); break;
            case 2: addToFile(fileName); break;
            
            case 3: 
                cout << "Thank you, have a good day." << endl;
                return 0;
            
            default: // This is an error state, this should never happen.
                cerr << "ERROR invalid option" << endl;
                return 99;
        }

     } // End of the while(true);

    // The program did not leave correctly.
    cerr << "ERROR illegal loop exit." << endl;
    return 100;
 }

/**
 *  Prompt the user for a new password.
 *  Check if it meets the password requirements, if not return to the menu.
 *  Lowercase the entered password.
 *  Encrypt the password into morse code.
 *  Save the encrypted password to the file.
*/
void addToFile(string fname)
{
    string userPassword = getUserPassword(); 

        // check string for valid password requirements
    if(!meetsRequirements(userPassword))
    {
        cout << "Doesn't meet requirements" << endl;
        return;
    }

    toLowerCase(userPassword);

    string encryptedPassword = encryptPassword(userPassword);

    savePassword(encryptedPassword, fname);
}

/**
 *  Open the masterFile for reading.
 *  If file succesfully opened continue.
 *  Prompt user for a password.
 *  Lower case the given password.
 *  Encrypt given password.
 *  Begin scanning each line in the file.
 *  If a match was found, mark boolean as true and break out of loop.
 *  Close the file.
 *  Inform user if password was valid or not.
*/
void checkFile(string fname)
{
    ifstream file(fname.c_str());

    if(file.is_open())
    {
        string userPassword;
            
            //  clear remaining whitespace from menu  
        cin.ignore();       
        getline(cin, userPassword);
            
        toLowerCase(userPassword);
        userPassword = encryptPassword(userPassword);

        cout << "Checking \"" << fname << "\" for your password..." << endl;
        
        string line;
        bool found = false;
        
        while(getline(file, line))
        {
            if(userPassword == line) 
            {
                found = true;
                break;
            }
        }

        file.close();

        cout << "You password is " << (found ? "valid!" : "invalid!") << endl << endl;
    }
    else
    {
        cout << "Failed to open file \"" << fname << "\"" << endl; 
    }
}          

  //==============================================================//
 //                          HELPERS                             // 
//==============================================================//

string getUserPassword()
{
    string userPassword;
    cin.ignore();
    getline(cin, userPassword);

    return userPassword;
}

/**
 *  Count each instance of letter, number, symbol found.
 *  Return true if minimum number of each was found. 
*/
bool meetsRequirements(const string &password)
{
    int total   = 0;
    int letters = 0;
    int numbers = 0; 
    int symbols = 0;

    for(unsigned int i = 0; i < password.length(); i++)
    {
             if(isalpha(password[i]))  letters++;
        else if(isdigit(password[i]))  numbers++;
        else if(issymbol(password[i])) symbols++;

        total++;
    }

    bool onlyValidChars = total == (letters + numbers + symbols);
    bool minLetters = letters >= 10;
    bool minNumbers = numbers >= 2;
    bool minSymbols = symbols >= 1;

    return onlyValidChars && minLetters && minNumbers && minSymbols;
}

bool issymbol(char c)
{
    return c == ' ' || c == '.' || c == ',' || c == '?';
}

/**
 *  If letter is A - Z, add 32 to make it lowercase
*/
void toLowerCase(string &password)
{
    for(unsigned int i = 0; i < password.length(); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        { 
            password[i] += 32;
        }
    }
}

/**
 *  Store last index of string for fenceposting.
 *  Loop through each character and set to its morse code equivalent.
 *  Fencepost the last character to morse code without adding a space.
 *  Return the now encrypted password.
*/
string encryptPassword(const string &password)
{
    string encrypted = "";
    unsigned int lastIndex = password.length() - 1;

    for(unsigned int i = 0; i < lastIndex; i++)
    {
        encrypted += toMorseCode(password[i]) + ' ';
    }

        // fence post so no space at end
    encrypted += toMorseCode(password[lastIndex]);

    return encrypted;
}

/**
 *  If character is less than 'a' then it is either number or symbol.
 *  If not alphabetical retrieve the morse code from NUM_PUNCT hash table.
 *  Otherwise retreive the morse code from ALPHA hash table.
 *  HASH const is 26.
 *  Character code % 26 for index in both tables.
*/
string toMorseCode(char c)
{
    return c < 'a' ? MORSE_NUM_PUNCT[c % MORSE_NUM_PUNCT_HASH] 
                   : MORSE_ALPHA[c % MORSE_ALPHA_HASH]; 
}

void savePassword(string &password, string fname)
{
        //  need to pass C String version of fname
        //  ios::app = append to file
    ofstream file(fname.c_str(), ios::app);

    file << password << endl;

    cout << "Password saved to \"" << fname << "\"!" << endl;
}

