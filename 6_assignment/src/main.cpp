#include "TextMap.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
        // START
    clock_t start = clock();
    srand(time(0));

    ifstream file("Moby Dick.txt");

    string contents;
    contents.assign(istreambuf_iterator<char>(file),
                    istreambuf_iterator<char>());;

    TextMap map(contents, 5);
    cout << map.generate(500) << endl;

    cout << "Finished in " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
         << " seconds." << endl;

    return 0;
}
