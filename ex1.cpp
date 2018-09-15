//This program adds money of two different people
#include <iostream>
#include <cstdlib>

using namespace std;

class AltMoney{

public:
  AltMoney();
  AltMoney(int d, int c);
  void read_money(int& d, int& c);

  friend AltMoney add(AltMoney m1, AltMoney m2);
  friend AltMoney subtract(AltMoney m1, AltMoney m2);
  void display_money();

private:
  int dollars;
  int cents;
};

int main(){

  int d, c;
  AltMoney m1, m2, sum, sub;

  m1.read_money(d,c);
  m1 = AltMoney(d,c);
  cout << "The first money is: ";
  m1.display_money();

  m2.read_money(d,c);
  m2 = AltMoney(d,c);
  cout << "The second money is: ";
  m2.display_money();

  sum = add(m1, m2);
  cout << "The sum is: ";
  sum.display_money();

  sub = subtract(m1, m2);
  cout << "The result of subtraction is: ";
  sub.display_money();

  return 0;
}

AltMoney::AltMoney(){

}

AltMoney::AltMoney(int d, int c){

  dollars = d;
  cents = c;
}

void AltMoney::display_money(){

  cout << "$" << dollars << ".";

  if (cents <= 9){
    cout << "0"; //To display a 0 in the left for numbers less than 10
  }

  cout << cents << endl;
}

AltMoney add(AltMoney m1, AltMoney m2){

  AltMoney temp;
  int extra = 0;
  temp.cents = m1.cents + m2.cents;

  if(temp.cents >= 100){
    temp.cents = temp.cents - 100;
    extra = 1;
  }

  temp.dollars = m1.dollars + m2.dollars + extra;

  return temp;
}

AltMoney subtract(AltMoney m1, AltMoney m2){

  AltMoney temp;

  int extra = 0;

  if(m1.cents <= m2.cents){
    temp.cents = m2.cents - m1.cents;
  } else{
    temp.cents = m1.cents - m2.cents;
  }


  if(temp.cents >= 100){
    temp.cents = temp.cents - 100;
    extra = 1;
  }

  if(m1.dollars <= m2.dollars){
    temp.dollars = m2.dollars - m1.dollars;
  } else{
    temp.dollars = m1.dollars - m2.dollars - extra;
  }

  return temp;
}

void AltMoney::read_money(int& d, int& c){

  cout << "Enter dollar \n";
  cin >> d;
  cout << "Enter cents \n";
  cin >> c;

  if (d < 0 || c < 0){
    cout << "Invalid dollars and cents, negative values \n";
    exit(1);
  }

}
