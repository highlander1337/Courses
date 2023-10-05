#include <iostream>
#include "Calculator.h"

using namespace std;


int main()
{
    double x {0.0};
    double y {0.0};
    double result {0.0};
    char oper {'+'};

    cout << "Calculadora" << endl << endl;
    cout << "Por favor, entre com a operação. Ex: x+y | x-y | x*y | x/y" << endl;

    Calculator c;

    while(true)
    {
        cin >> x >> oper >> y;
        if (oper == '/' && y == 0)
        {
            cout << "Não se pode dividir por zero!" << endl;
            continue;
        }
        else
        {
            result = c.Calculate(x, oper, y);
            cout << "Resultado " << "de " << x << oper << y << " é: " << result << endl;
        }
    }

    return 0;
}

