/* This is the primary initial file for
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

    //  hashed numbers/punctuation, 0 - 9 | . | , | ? | ' ' % 26
    //  array size and modulo is 26 because this produced no collisions
    //  and I'm too lazy to deal with probing stuff
    // , = > 18 | . => 20 | 
const string MORSE_NUM_PUNCT[] = { 
                                    "****-", "*****", "-****", "--***", // 3
                                    "---**", "----*", " ", "", // 7
                                    "", "", "", "**--**", // 11
                                    "", "", "", "", // 15
                                    "", "", "--**--", "", // 19
                                    "*-*-*-", "", "", "*----", // 23
                                    "**---", "***--"  // 25
                                 };



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
    // fname = filename given to us
    // get password from user
    // check string for valid password requirements
    // if not valid exit function and return to caller
    // encrypt password
    // add password to file
}
 
void checkFile(string fname)
{
    // fname = filename given to us
    // get password from user
    // encrypt password
    // see if encrypted password exists in file
    // give user notification
}