#include <iostream>
#include <iomanip>


using namespace std;

void integerTypes()
{
    /*
        Integer numbers
        Those modifiers only apply to integral types
    */
    short short_var {-32768}; // 2 bytes
    cout << "sizeof(short) : " << sizeof(short_var) << endl;
    short int short_int {455}; //
    cout << "sizeof(short_int) : " << sizeof(short_int) << endl;
    signed short signed_short {122}; //
    cout << "sizeof(signed_short) : " << sizeof(signed_short) << endl;
    unsigned short int unsigned_short_int {456};
    cout << "sizeof(unsigned_short_int) : " << sizeof(unsigned_short_int) << endl;

    int int_var {55}; // 4 bytes
    cout << "sizeof(int_var) : " << sizeof(int_var) << endl;
    signed signed_var {66}; //
    cout << "sizeof(signed_var) : " << sizeof(signed_var) << endl;
    signed int signed_int {77}; //
    cout << "sizeof(signed_int) : " << sizeof(signed_int) << endl;
    unsigned int unsigned_int{77};
    cout << "sizeof(unsigned_int) : " << sizeof(unsigned_int) << endl;

    long long_var {88}; // 4 OR 8 Bytes
    cout << "sizeof(long_var) : " << sizeof(long_var) << endl;
    long int long_int {33};
    cout << "sizeof(long_int) : " << sizeof(long_int) << endl;
    signed long signed_long {44};
    cout << "sizeof(signed_long) : " << sizeof(signed_long) << endl;
    signed long int signed_long_int {44};
    cout << "sizeof(signed_long_int) : " << sizeof(signed_long_int) << endl;
    unsigned long int unsigned_long_int {44};
    cout << "sizeof(unsigned_long_int) : " << sizeof(unsigned_long_int) << endl;
    
    long long long_long {888}; // 8 Bytes
    cout << "sizeof(long_long) : " << sizeof(long_long) << endl;
    long long int long_long_int {999};
    cout << "sizeof(long_long_int) : " << sizeof(long_long_int) << endl;
    signed long long signed_long_long {444};
    cout << "sizeof(signed_long_long) : " << sizeof(signed_long_long) << endl;
    signed long long int signed_long_long_int {1234};
    cout << "sizeof(signed_long_long_int) : " << sizeof(signed_long_long_int) << endl;
    unsigned long long int unsigned_long_long_int {1234};
    cout << "sizeof(unsigned_long_long_int) : " << sizeof(unsigned_long_long_int) << endl;


}