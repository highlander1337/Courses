#include <iostream>
#include <iomanip>


using namespace std;

void fractionalTypes()
{
    
    /*
        Fractional numbers
    */
   cout << setprecision(20); // control the precision from std::cout
   float float_number {1.1221673716371637167316f}; // the precision for a flot point number is 7 digits
   cout << "sizeof(float_number) : " << sizeof(float_number) << endl;
   cout << "float_number is : " << float_number << " << Precision: 7 digits >>  " << endl;
   double double_number {1.1221673716371637167316}; // the precision for a double point number is 15 digits
   cout << "sizeof(double_number) : " << sizeof(double_number) << endl;
   cout << "double_number is : " << double_number << " << Precision: 15 digits >> " << endl;
   long double long_double {1.1221673716371637167316L}; // the precision for a long double point number is 15+ digits
   cout << "sizeof(long_double) : " << sizeof(long_double) << endl;
   cout << "long_double is : " << long_double << " << Precision: 15+ digits >> " << endl;
   
   
}