#include "TextMap.h"
#include "iostream"

// #define printGrams
// #define printMap
// #define printWeighted

using namespace std;

TextMap::TextMap(string text, int order)
{
    this->order = order > 0 ? order : 1;
    if(!text.empty()) parseText(text);
};

void TextMap::parseText(string &text)
{
    text += ' ';
    string gram;
    char charAfter;
    int grabAmount = 0;
    int offset = 0;
    int wrapAmount = 0;
    int len = text.length();

    for(int i = 0; i < len; i++)
    {
        offset = len - 1 - i;

        if(offset < grabAmount)
        {
            wrapAmount = grabAmount - offset - 1;
            gram = text.substr(i, grabAmount - wrapAmount);
            gram += text.substr(0, wrapAmount);
            charAfter = text[wrapAmount];
            if(charAfter == '\n')
            {
                charAfter = ' ';
                text[wrapAmount] = ' ';
            }
        }
        else
        {
            gram = text.substr(i, grabAmount);
            charAfter = text[i + grabAmount];
            if(charAfter == '\n')
            {
                charAfter = ' ';
                text[i + grabAmount] = ' ';
            }
        }

        if(grabAmount < order) 
        {
            i--;
            grabAmount++;
        }



#ifdef printGrams //==============================================//
cout << '\'' << gram << "\' => \'" << charAfter << '\'' << endl;
#endif //=========================================================//



        if(ngrams.count(gram) <= 0) // if gram doesn't exist
            ngrams[gram]; // create char map at this gram 

        auto charCount = ngrams.at(gram).find(charAfter);

        if(charCount == ngrams.at(gram).end()) // if char not found 
            ngrams.at(gram)[charAfter] = 1;    // create char at 1  
        else
            ngrams.at(gram).at(charAfter)++; // else increment that char count
    }



#ifdef printMap //===============================================//
for(const auto &gram_charMap : ngrams)
{
    cout << '\"' << gram_charMap.first << '\"' << endl << '[' << endl;

    for(const auto &char_count : gram_charMap.second)
    {
        cout << "\t" << char_count.first << " => \'" << char_count.second << '\'' << endl;
    }

    cout << "]" << endl << endl;
}
#endif //=========================================================//





}

void TextMap::weighProbabilities()
{
    int acc;

    for(const auto &gram_charMap : ngrams)
    {
        acc = 0;

        weighted[gram_charMap.first]; // create map at gram

        for(const auto &char_count : gram_charMap.second)
        {
            acc += char_count.second; // accumulate

                // set accumulated int to char
            weighted.at(gram_charMap.first).probs[acc] = char_count.first;
        }
            // assign max to final accumulation
        weighted.at(gram_charMap.first).max = acc;
    }






#ifdef printWeighted //===============================================//
for(const auto &gram_struct : weighted)
{
    cout << '\"' << gram_struct.first << '\"' << endl << '[' << endl;

    cout << "\t" << "max => \'" << gram_struct.second.max << endl;

    for(const auto &int_chars : gram_struct.second.probs)
    {
        cout << "\t" << int_chars.first << " => \'" << int_chars.second << '\'' << endl;
    }

    cout << "]" << endl << endl;
}
#endif //=========================================================//






}

string TextMap::generate(int size)
{
    if(ngrams.empty()) return "No text parsed yet.";

    weighProbabilities();

    string seed;
    seed.reserve(size);

    string gram;
    char newChar;
    int charIndex;
    int i = 0 - order;

    while(i < size)
    {
        if(i < 0) gram = seed.substr(0); // while seed not big enough grab all
        else      gram = seed.substr(i, i + order); // grab order length and move;

        charIndex = rand() % weighted.at(gram).max;

        try
        {
            newChar = findFirstInRange(charIndex, weighted.at(gram).probs);
            seed.append(1, newChar);
        }
        catch(const string &err)
        {
            cout << err << endl;
            break;
        }

        i++;

        if((i == size && newChar == ' ') || (i == size && newChar != '.' && newChar != '!' && newChar != '?')) size++;
    }
    
    return seed;
}

char TextMap::findFirstInRange(const int &num, const map<int, char> &charRange) const
{
    for(const auto &int_char : charRange)
    {
        if(num <= int_char.first) return int_char.second;
    }

    string err = "Failed to find char with index: " + num;

    throw err;
}