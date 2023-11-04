
int compound(int value, char op) {

  switch (op) {
  case '+':
    return value += value;
    break;
  case '-':
    return value -= value;
    break;
  case '/':
    return value /= value;
    break;
  case '*':
    return value *= value;
    break;

  default:
    return value;
    break;
  }
}