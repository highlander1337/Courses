#include <iostream>
#include <iomanip>

using namespace std;


void charTypes()
{
    char character_1 {'T'};
    char character_2 {'A'};
    char character_3 {'S'};
    char character_4 {'S'};
    char character_5 {'I'};
    char character_6 {'O'};


    cout << character_1 << endl;
    cout << character_2 << endl;
    cout << character_3 << endl;
    cout << character_4 << endl;
    cout << character_5 << endl;
    cout << character_6 << endl;

    cout << endl;

    char value = 65; // ASCII character code for 'A'
    cout << "value: " << value << endl;
    cout << "value(int): " << static_cast<int>(value) << endl;
}