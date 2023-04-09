//Imani Cage
//lab6.cpp

#include <iostream>
#include <cctype>

using namespace std;

const char YES = 'y';

int main()
{
  int num1, num2, larger, smaller;
  char ans = YES;
  
  cout << endl << endl;

  cout << "This program will calculate two whole numbers and "
       << "whether or not they're" << endl << "multiples, will then "
       <<  "find the other factor.";
  
  cout << endl << endl << "Would you like to start? y/n  ";
  cin >> ans;

  while(tolower(ans) == YES){
  cout << "Please provide two whole numbers that are not zero: ";
  cin >> num1 >> num2;
  
  while (num1%num2 != 0 && num2%num1 !=0){
    
    cout << "These are NOT multiples of each other." <<
      "Please try again. ";
    cin >> num1 >> num2;
  }

  if(num1>num2){
    larger = num1;
    smaller = num2;
  }else{
    larger = num2;
    smaller = num1;
  }
  
  cout << larger  << " is a multiple of " << smaller
         << " and the other factor is " << larger/smaller;
    
  cout << endl << endl <<  "Would you like to go again? y/n ";
  cin >> ans;
  }
  cout << endl << endl;
  
  cout << "Thank you!";
  
  cout << endl << endl;
  
  return 0;

}
