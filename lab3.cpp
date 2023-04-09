//Imani Cage
//Lab 3

#include <iostream>

using namespace std;

int main()
{
  int num1, num2;

  cout << endl << endl;
  
  cout << "Please provide two whole numbers that are not zero: ";
  cin >> num1 >> num2;

  if (num1%num2 != 0){
    
    cout << num1 << " is NOT a multiple of " << num2;

  } else {

    cout << num1 << " is a multiple of " << num2
         << " and the other factor is " << num1/num2;
    
  }
  
  cout << endl << endl;
  
  return 0;

}
