//This program adds money of two different people
#include <iostream>
#include <cstdlib>

using namespace std;

class AltMoney{

public:
  AltMoney();
  AltMoney(int d, int c);
  void read_money(int& d, int& c);

  friend void add(AltMoney m1, AltMoney m2, AltMoney& sum);
  friend void subtract(AltMoney m1, AltMoney m2, AltMoney& subRes);
  void display_money();

private:
  int dollars;
  int cents;
};

int main(){

  int d, c;
  AltMoney m1, m2, sum, subRes;

  sum = AltMoney(0,0);
  subRes = AltMoney(0,0);

  m1.read_money(d,c);
  m1 = AltMoney(d,c);
  cout << "The first money is: ";
  m1.display_money();

  m2.read_money(d,c);
  m2 = AltMoney(d,c);
  cout << "The second money is: ";
  m2.display_money();

  add(m1, m2, sum);
  cout << "The sum is: ";
  sum.display_money();

  subtract(m1, m2, subRes);
  cout << "The result of subtraction is: ";
  subRes.display_money();

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

void add(AltMoney m1, AltMoney m2, AltMoney& sum){

  int extra = 0;
  sum.cents = m1.cents + m2.cents;

  if(sum.cents >= 100){
    sum.cents = sum.cents - 100;
    extra = 1;
  }

  sum.dollars = m1.dollars + m2.dollars + extra;


}

void subtract(AltMoney m1, AltMoney m2, AltMoney& subRes){

  int extra = 0;

  if(m1.cents <= m2.cents){
    subRes.cents = m2.cents - m1.cents;
  } else{
    subRes.cents = m1.cents - m2.cents;
  }


  if(subRes.cents >= 100){
    subRes.cents = subRes.cents - 100;
    extra = 1;
  }

  if(m1.dollars <= m2.dollars){
    subRes.dollars = m2.dollars - m1.dollars;
  } else{
    subRes.dollars = m1.dollars - m2.dollars - extra;
  }

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
