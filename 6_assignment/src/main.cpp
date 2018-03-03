#include "TextMap.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
        // START
    clock_t start = clock();




    TextMap map("This is a sentence! This is another sentence!!");
    map.generate();



    cout << "Finished in " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
         << " seconds." << endl;

    return 0;
}
