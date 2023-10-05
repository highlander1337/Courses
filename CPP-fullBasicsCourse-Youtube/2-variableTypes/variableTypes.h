#include "integerTypes.h"
#include "fractionalTypes.h"
#include "boolTypes.h"
#include "autoTypes.h"

#pragma once

void integerTypes();
void fractionalTypes();
void boolTypes(bool red, bool green, bool yellow);
void autoTypes();


/*
    A namespace is a declarative region that provides a scope to the identifiers 
    (the names of types, functions, variables, etc) inside it. 
    Namespaces are used to organize code into logical groups and to prevent name collisions that can 
    occur especially when your code base includes multiple libraries. 
    All identifiers at namespace scope are visible to one another without qualification. 
    Identifiers outside the namespace can access the members by using the fully qualified name for each identifier

    Reference: https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170
*/
/*
namespace dataTypes
{
    
    //void integerTypes();
    //void fractionalTypes();
    

    class dataTypeMng
    {
        public:
            void printInt()
            {
                integerTypes();
            }
            void printFractional()
            {
                fractionalTypes();
            }
    };
}
*/