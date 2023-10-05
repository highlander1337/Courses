#include <iostream>
#include "variableTypes.h"


//using namespace dataTypes; 

int main()
{
    //dataTypeMng dataTypeManager;

    cout << " \n\n " << endl;
    cout << " ------------------------------------------------ " << endl;
    cout << "Integer number types: " << endl;
    cout << " ------------------------------------------------ " << endl;
    //dataTypeManager.printInt();
    integerTypes();
    
    cout << " \n\n " << endl;

    cout << " ------------------------------------------------ " << endl;
    cout << "Fractional number types: " << endl;
    cout << " ------------------------------------------------ " << endl;
    //dataTypeManager.printFractional();
    fractionalTypes();

    cout << " \n\n" << endl;

    cout << " ------------------------------------------------ " << endl;
    cout << "Bool types: " << endl;
    cout << " ------------------------------------------------ " << endl;
    //dataTypeManager.printFractional();
    boolTypes(false, false, true);
    
    cout << " \n\n" << endl;

    cout << " ------------------------------------------------ " << endl;
    cout << "Auto types: " << endl;
    cout << " ------------------------------------------------ " << endl;
    //dataTypeManager.printFractional();
    autoTypes();

    return 0;

}