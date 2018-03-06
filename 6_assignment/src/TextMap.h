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
        struct WeightedNGram
        {
            std::map<int, char> probs; // This needs to be ordered so I can loop 
                                       // through in order and find first char
            int max;                   // range randomly
        };

        std::unordered_map<std::string, std::unordered_map<char, int>> ngrams;
        std::unordered_map<std::string, WeightedNGram> weighted;

        void weighProbabilities();
        char findFirstInRange(const int &num, const std::map<int, char> &charRange) const;
        char isGood(const char &c) const;
        int order;
};

#endif