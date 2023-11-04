#include <iostream>

using namespace std;

enum { GT, LT, EQ, GQT, LQT, DIF };

void relational(int a, int b, int op) {

  switch (op) {
  case GT:
    if (a > b) {
      cout << boolalpha;
      cout << a << " > " << b << "? " << true << endl;
    } else {
      cout << a << " > " << b << "? " << false << endl;
    }
    break;
  case LT:
    if (a < b) {
      cout << boolalpha;
      cout << a << " < " << b << "? " << true << endl;
    } else {
      cout << a << " < " << b << "? " << false << endl;
    }
    break;
  case EQ:
    if (a == b) {
      cout << boolalpha;
      cout << a << " == " << b << "? " << true << endl;
    } else {
      cout << a << " == " << b << "? " << false << endl;
    }
    break;
  case GQT:
    if (a >= b) {
      cout << boolalpha;
      cout << a << " >= " << b << "? " << true << endl;
    } else {
      cout << a << " >= " << b << "? " << false << endl;
    }
    break;
  case LQT:
    if (a <= b) {
      cout << boolalpha;
      cout << a << " <= " << b << "? " << true << endl;
    } else {
      cout << a << " <= " << b << "? " << false << endl;
    }
    break;
  case DIF:
    if (a != b) {
      cout << boolalpha;
      cout << a << " != " << b << "? " << true << endl;
    } else {
      cout << a << " != " << b << "? " << false << endl;
    }
    break;

  default:
    break;
  }
}