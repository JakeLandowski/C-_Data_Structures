#include "Purse.h"

using namespace std;

int main()
{
    Purse purse(50, 10, 1);

    purse = purse + 10;

    purse.print();

    Purse purse2(1, 1, 1);

    purse2.print();

    Purse purse3 = purse + purse2;   

    purse3.print();

    cout << endl << purse3 << endl;

    return 0;
}