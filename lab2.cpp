//Imani Cage
//lab 2

#include <iostream>

using namespace std;

int main()
{
  string word;
  int num1, num2;
  double dnum1,dnum2;

  cout << endl<< endl;

  cout << "Please provide a word: ";
  cin >> word;

  cout << "Your word is " << word << endl;

  cout << "Please provide two integers: ";
  cin >> num1 >> num2;

  cout << "The division of " << num1 << " by " <<  num2 << " is " << num1/num2
       << endl;
  cout << "The modulus of " << num1 << " by " <<  num2 << " is " << num1%num2
       << endl;

  cout << "Please provide two decimal numbers: ";
  cin >> dnum1 >> dnum2;

  cout << "The division of " << dnum1 << " by "  << dnum2 << " is "
       << dnum1/dnum2 << endl;
  
  cout << endl << endl;
  
  return 0;
}
