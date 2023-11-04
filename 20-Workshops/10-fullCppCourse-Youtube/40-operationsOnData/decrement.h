#include <iostream>

using namespace std;


int prefixDecrement(int n)
{
    return --n;
}

int postfixDecrement(int n)
{
    // it will not work properly because n is return first
    // return n--;
    // the proper solution, but not quite the behavior expected therefore do not return a postfix decrement
    n--;
    return n;

}