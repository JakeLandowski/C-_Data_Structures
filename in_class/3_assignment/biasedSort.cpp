#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool biasedCompare(const string &str1, const string &str2);

void BiasedSort(vector<string> &v);

int main()
{
    vector<string> myList;
    myList.push_back("Song 1");
    myList.push_back("Song 5");
    myList.push_back("A Song 2");
    myList.push_back("Song 2");
    myList.push_back("Song 3");
    myList.push_back("Me First Song 3");
    myList.push_back("Song 7");
    myList.push_back("Song 8");
    myList.push_back("Me First Song 1");
    myList.push_back("Song 4");
    myList.push_back("Song 6");
    myList.push_back("A Song 1");
    myList.push_back("Me First Song 2");

    // Print out the vector before the sort
    cout << "****" << endl;
    BiasedSort(myList);
    // Print out the vector after the sort

    for(const auto &str : myList)
    {
        cout << str << endl;
    }

    return 0;
}

bool biasedCompare(const string &str1, const string &str2)
{
         if(str1.find("Me First") != string::npos &&
            str2.find("Me First") == string::npos) return true;
    else if(str2.find("Me First") != string::npos &&
            str1.find("Me First") == string::npos) return false;
    return str1 < str2;
}

void BiasedSort(vector<string> &v)
{   
    sort(v.begin(), v.end(), biasedCompare);
}