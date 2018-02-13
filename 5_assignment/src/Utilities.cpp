#include "Utilities.h"

using namespace std;

vector<string> Utilities::split(const string &splitting, 
                                const string &delimiter,
                                int estimatedCapacity)
{
    vector<string> tokens;
    tokens.reserve(estimatedCapacity);
    
    size_t start_pos = 0;
    size_t found_pos;

        //  find position of first delimiter, if found continue
    while((found_pos = splitting.find(delimiter, start_pos)) != string::npos)
    {
            //  push string up til first delimiter
        tokens.push_back(splitting.substr(start_pos, found_pos - start_pos));
        
            //  skip to the position AFTER this delimiter
        start_pos = found_pos + delimiter.length();
    }

        //  fence post last token
    tokens.push_back(splitting.substr(start_pos));

    return tokens;
}

bool Utilities::isNumeric(const string &str)
{
    for(unsigned int i = 0; i < str.length(); i++)
        if(!isdigit(str[i])) return false;

    return true;
}