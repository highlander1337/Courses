#include <iostream>

using namespace std;

float division(auto n1, auto n2)
{
    if (n2 <= 0)
    {
        cout << "Division by zero!!"  << endl; 
        return 0;
    }
        
    
    return n1 / n2; 
}