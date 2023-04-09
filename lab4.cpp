//Imani Cage
//lab4.cpp

#include <iostream>

using namespace std;

int main()
{
  int num1, num2, larger, smaller;

  cout << endl << endl;
  
  cout << "Please provide two whole numbers that are not zero: ";
  cin >> num1 >> num2;

  if (num1 > num2){
    larger = num1;
    smaller = num2;
  } else {
    larger = num2;
    smaller = num1;
  }

  
  if (larger%smaller != 0){
    
    cout << larger  << " is NOT a multiple of " << smaller;

  } else {

    cout << larger  << " is a multiple of " << smaller
         << " and the other factor is " << larger/smaller;
    
  }
  
  cout << endl << endl;
  
  return 0;

}
