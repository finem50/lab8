//Rules for calculation will be:
// a/b + c/d = (a*d + b*c) / (b*d)
// a/b - c/d = (a*d - b*c) / (b*d)
// (a/b) * (c/d) = (a*c) / (b*d)
// (a/b) / (c/d) = (a*d) * (c*b)

#include <iostream>
#include <cmath>

using namespace std;

class Rational{

public:
  Rational();
  Rational(int a, int b, int c, int d); //Four variables, for each quarter of the equation
  void set();
  friend Rational operator +(int a, int b, int c, int d);
  friend Rational operator -(int a, int b, int c, int d);
  friend Rational operator *(int a, int b, int c, int d);
  friend Rational operator /(int a, int b, int c, int d);

private:
  int a, b, c, d, total; //These will be used to construct the fractions

};

Rational operator +(int a, int b, int c, int d);
Rational operator -(int a, int b, int c, int d);
Rational operator *(int a, int b, int c, int d);
Rational operator /(int a, int b, int c, int d);

int main(){

  int a, b, c, d;
  char oper;

  Rational rational;
  cout << "Please enter stuff: ";
  rational.set();

  cout << "Which operator would you like to perform? i.e. +, -, *, / " << endl;
  cin >> oper;

  switch(oper){
      case '+':
        a + b + c + d;
        break;

      case '-':
        a - b - c - d;
        break;

      case '*':
        a * b * c * d;
        break;

      case '/':
        a / b / c / d;
        break;

      default:
        cout << "Invalid input\n";
        break;
  }

}

Rational::Rational(){

  //Default constructor
}

Rational::Rational(int numA, int denA, int numB, int denB){

  a = numA;
  b = denA;

  c = numB;
  d = denB;
}

void Rational::set(){

  cout << "Please enter the first numerator: ";
  cin >> a;

  cout << "Please enter the first denominator: ";
  cin >> b;

  cout << "Please enter the second numerator: ";
  cin >> c;

  cout << "Please enter the second denominator: ";
  cin >> d;
}

Rational operator +(int a, int b, int c, int d){

  Rational temp;
  int total;

  temp.total = (temp.a * temp.d + temp.b * temp.c) / (temp.b * temp.d);

  return temp;
}

Rational operator -(int a, int b, int c, int d){

  int total;

  total = (a * d - b * c) / (b * d);
  cout << a << " / " << b << " - " << c << " / " << d << " = " << total << endl;

  temp.total = (temp.a * temp.d + temp.b * temp.c) / (temp.b * temp.d);

  return temp;
}

Rational operator *(int a, int b, int c, int d){

  int total;

  total = (a * c) / (b * d);
  cout << a << " / " << b << " * " << c << " / " << d << " = " << total << endl;

  temp.total = (temp.a * temp.d + temp.b * temp.c) / (temp.b * temp.d);

  return temp;
}

Rational operator /(int a, int b, int c, int d){

  int total;

  total = (a * d) * (c * b);
  cout << a << " / " << b << " / " << c << " / " << d << " = " << total << endl;

  temp.total = (temp.a * temp.d + temp.b * temp.c) / (temp.b * temp.d);

  return temp;
}
