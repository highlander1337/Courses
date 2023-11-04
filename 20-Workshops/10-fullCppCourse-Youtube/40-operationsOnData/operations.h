#include "addition.h"
#include "compound.h"
#include "decrement.h"
#include "division.h"
#include "increment.h"
#include "modulus.h"
#include "multiplication.h"
#include "relational.h"
#include "subtraction.h"
#include <iostream>


/*
    Basic operations
*/
float addition(auto, auto);
float subtraction(auto, auto);
float multiplication(auto, auto);
float division(auto, auto);
int myModulus(int, int);

/*
    Increment operations
*/

int prefixIncrement(int);
int postfixIncrement(int);

/*
    Decrement operations
*/
int prefixDecrement(int);
int postfixDecrement(int);

/*
    Compound operators
*/
int compound(int, char);

/*
    Relational operators
*/

void relational(int, int, int);