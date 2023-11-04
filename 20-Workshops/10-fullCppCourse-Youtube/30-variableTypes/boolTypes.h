#include <iostream>
#include <iomanip>

using namespace std;


void boolTypes(bool red, bool green, bool yellow)
{
    bool red_light {red};
    bool green_light {green};
    bool yellow_light {yellow};

    if(red_light && ~green_light)
    {
        cout << "Stop !!" << endl;
        cout << "   The light is NOT green!" << endl;
    }
    else if (green_light & ~yellow_light)
    {
        cout << "Go through!" << endl;
        cout << "   The light is green! " << endl;
        
    }
    else if(yellow_light)
    {
        cout << "Slow down!" << endl;
        cout << "   The light is yellow!" << endl;
    }

    // print out a bool 1 or 0
    cout << "red_light : " << red_light << endl;
    cout << "yellow_light : " << yellow_light << endl;
    cout << "green_light : " << green_light << endl;

    // print out a bool true or false
    cout << boolalpha;
    cout << "red_light : " << red_light << endl;
    cout << "yellow_light : " << yellow_light << endl;
    cout << "green_light : " << green_light << endl;


}