#include "TextMap.h"
#include "iostream"

// #define printGrams
// #define printMap
// #define printWeighted

using namespace std;

TextMap::TextMap(int order)
{
    this->order = order > 0 ? order : 1;
};

void TextMap::parseText(string &text)
{
    if(!text.empty())
    {

        text += ' ';  // Add padding to separate end from start when wrapping
        string gram;            // The substring key to log "the" "he_", "e_r", etc... 
        char charAfter;         // The character to log for an N Gram
        int grabAmount = 0;     // Amt of text to grab for an N Gram, 0 up to Order level
        int offset = 0;         // When to start wrapping 
        int wrapAmount = 0;     // How much to wrap around to the start
        int len = text.length();

        for(int i = 0; i < len; i++)
        {
            offset = len - 1 - i;

            if(offset < grabAmount) // Near end of string, start wrapping
            {
                wrapAmount = grabAmount - offset - 1;
                gram = text.substr(i, grabAmount - wrapAmount); // Grab from end
                gram += text.substr(0, wrapAmount);     // Grab from start too
                charAfter = isGood(text[wrapAmount]);
                text[wrapAmount] = charAfter;       
            }
            else
            {
                gram = text.substr(i, grabAmount); // Grab N Gram key
                charAfter = isGood(text[i + grabAmount]);  // Grab char following it
                text[i + grabAmount] = charAfter;
            }

            if(grabAmount < order) // Scale grab amount from 0 up til Order level
            {
                i--;  // Hold loop position back until full order
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
}

/**
 * [
 *   'the' = 
 *          [
 *              c = 1,
 *              d = 3, 
 *            ' ' = 7,
 *              e = 2
 *          ]
 * ]
 * 
 * Will turn into weighted:
 * 
 * [
 *   'the' = 
 *          [
 *              probs = 
 *                      [
 *                          1 = c,
 *                          4 = d, 
 *                         11 = ' ',
 *                         13 = e
 *                      ],
 * 
 *              max = 13
 *          ]
 * ]
 * 
 *  Then pick a random number and find the first
 *  range it falls under for a weighted random choice.
 */
void TextMap::weighProbabilities()
{
    int acc;
           //  pair<gram, map<char, int>>
    for(const auto &gram_charMap : ngrams)
    {
        acc = 0;

        weighted[gram_charMap.first]; // create map at gram

               //  pair<char, int>
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

    string gram;    // Current substring key to lookup char probabilities
    char newChar;   // New char to append to our string
    int charIndex;  // Random number picked to find a char
    int i = 0 - order; // Start at negative order to start search at empty string

    while(i < size)
    {
        if(i < 0) gram = seed.substr(0); // while seed not big enough grab all
        else      gram = seed.substr(i, i + order); // grab order length and move;

        charIndex = rand() % (weighted.at(gram).max + 1);

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

        //  Don't stop generating til you hit punctuation.
        if((i == size && newChar == ' ') || 
           (i == size && 
            newChar != '.' && 
            newChar != '!' && 
            newChar != '?'))
        {
            size++;
        } 
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

char TextMap::isGood(const char &c) const
{
    if (c > 255 || c < 0) return '~';
    if (isprint(c))       return c;
    if (iscntrl(c))       return ' ';
    return '~';
}