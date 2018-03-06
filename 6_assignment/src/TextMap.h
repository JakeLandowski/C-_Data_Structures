#ifndef H_TextMap_H
#define H_TextMap_H

#include <map>
#include <unordered_map>
#include <string>

class TextMap
{
    public:
        TextMap(int order = 5);
        void parseText(std::string &text);
        std::string generate(const int size = 200);

    private:
            //  Used to associate a max value 
            //  with the map of weighted probabilities
        struct WeightedNGram
        {
            std::map<int, char> probs; // This needs to be ordered so I can loop 
                                       // through in order and find first char
            int max;                   // range from a random number
        };

            //  Holds mapping of NGram keys to the
            //  count of characters following it
        std::unordered_map<std::string, std::unordered_map<char, int>> ngrams;
            
            //  Holds mapping of NGram keys to a 
            //  weighted probability of characters following it
        std::unordered_map<std::string, WeightedNGram> weighted;

        void weighProbabilities();
        char findFirstInRange(const int &num, const std::map<int, char> &charRange) const;
        char isGood(const char &c) const;
        int order;
};

#endif