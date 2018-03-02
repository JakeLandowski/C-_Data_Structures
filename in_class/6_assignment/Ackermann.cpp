/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  2-23-18
 *  In-Class Assignment #6
 * 
 *  Demonstration of the Ackermann recursive algorithm.
*/

#include <iostream>
#include <string>
#include <ctime> // Just in case

using namespace std;

int ack(int, int);

int main()
{
        // START
    clock_t start = clock();

    try
    {
        cout << "Ackermann(0, 0) = "   << ack(0, 0) 
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;

        cout << "Ackermann(0, 1) = "   << ack(0, 1)
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
        
        cout << "Ackermann(1, 1) = "   << ack(1, 1)
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
        
        cout << "Ackermann(2, 2) = "   << ack(2, 2)
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
        
        cout << "Ackermann(3, 3) = "   << ack(3, 3)   
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
        
        cout << "Ackermann(3, 9) = "   << ack(3, 9)   
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
        
        cout << "Ackermann(3, 10) = "  << ack(3, 10)  
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
        
        cout << "Attemping to print Ackermann(-1, -1)... ";

        cout << "Ackermann(-1, -1) = " << ack(-1, -1) 
             << " and it took " << ((double) (clock() - start) / CLOCKS_PER_SEC) 
             << " seconds."<< endl;
    }
    catch(const char *err)
    {
        cerr << err << endl;
    }

    return 0;
}

int ack(int m, int n)
{
    if(m < 0 || n < 0) throw "Error! M or N was negative.";
    if(m == 0) return n + 1;
    if(n == 0) return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}