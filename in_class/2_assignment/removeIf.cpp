#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool lessThanThree(const string &str);

void removeShortWords(vector<string> &v);

int main()
{
    vector<string> myList;
    myList.push_back("ABCDEF");
    myList.push_back("ABCDE");
    myList.push_back("AB");
    myList.push_back("A");
    myList.push_back("ABC");
    myList.push_back("ABCDEFGH");
    myList.push_back("ABCEDFGH");
    myList.push_back("123");
    myList.push_back("12");
    myList.push_back("1");
    myList.push_back("12345");

    // Print out the vector before the sort
    cout << "****" << endl;
    removeShortWords(myList);
    // Print out the vector after the modify

    for(const auto &str : myList)
    {
        cout << str << endl;
    }

    return 0;
}

bool lessThanThree(const string &str)
{
    return str.length() <= 3;
}

void removeShortWords(vector<string> &v)
{
    v.erase(remove_if(v.begin(), v.end(), lessThanThree), v.end());
}