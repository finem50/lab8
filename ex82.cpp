//This program adds money of two different people
#include <iostream>
#include <cstdlib>

using namespace std;

class AltMoney{

public:
  AltMoney();
  AltMoney(int d, int c);

  friend AltMoney operator +(AltMoney m1, AltMoney m2);
  void display_money();

private:
  int dollars;
  int cents;
};

void read_money(int& d, int& c);

int main(){

  int d, c;
  AltMoney m1, m2, sum;

  sum = AltMoney(0,0);

  read_money(d, c);
  m1 = AltMoney(d, c);
  cout << "The first money is: ";
  m1.display_money();

  read_money(d, c);
  m2 = AltMoney(d, c);
  cout << "The second money is: ";
  m2.display_money();

  sum = m1 + m2;
  cout << "The sum is: ";
  sum.display_money();

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

  if(cents <= 9){
    cout << "0"; //To display a 0 on the left for numbers less than 10
  }

  cout << cents << endl;
}

AltMoney operator +(AltMoney m1, AltMoney m2){

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

void read_money(int& d, int& c){

  cout << "Enter dollar \n";
  cin >> d;
  cout << "Enter cents \n";
  cin >> c;
  if (d < 0 || c < 0){
    cout << "Invalid dollars and cents, negative values \n";
    exit(1);
  }
}
