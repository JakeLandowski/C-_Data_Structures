#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <fstream>

using namespace std;

bool byValue(const pair<string,double> &left, const pair<string,double> &right);
set<string> criticsPick(map<string,double> m);
void doP(const string &str);

int main()
{
    map<string,double> movieList;

    string fname = "Movies.txt";
    ifstream myfile;
    myfile.open(fname);

    if(myfile.is_open())
    { 
        cout << "File Opened" << endl; 
    }
    else
    {
        cout << "BAD : " +fname<< endl;
        return -99;
    }

    string nameString, scoreString;

    while (myfile)
    {
        getline(myfile,nameString);
        getline(myfile,scoreString);

        movieList[nameString]= atof(scoreString.c_str());
    }

    // map<string,double>::iterator it = movieList.begin();

    // while(it != movieList.end())
    // {
    //     std::cout<<it->first<<" :: "<<it->second<<std::endl;
    //     it++;
    // }


    cout << endl << endl;

    set<string> results;
    results = criticsPick(movieList);

    for_each(results.begin(),results.end(),doP);

    return 0;
}

bool byValue(const pair<string,double> &left, const pair<string,double> &right)
{
    return left.second < right.second;
}


set<string> criticsPick(map<string,double> m)
{
    set<string> topTenMovies;

    map<string,double>::iterator max;

    for(int i = 0; i < 10 && !m.empty(); i++)
    {
        max = max_element(m.begin(), m.end(), byValue);
        topTenMovies.insert(max->first);
        m.erase(max);
    }

    return topTenMovies;
}

void doP(const string &str)
{
    cout << str << endl;
}