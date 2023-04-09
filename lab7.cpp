//Imani Cage
//lab7.cpp

#include <iostream>
#include <iomanip>

using namespace std;

const int MIN = 3;
const int MAX = 9;
const int COL_WIDTH = 3;
const char SPACE = ' ';

int main()
{

  int input = 0;

  cout << endl <<endl;
  while (input < MIN || input > MAX){
    cout << "Please provide a number between " << MIN
         << " and " << MAX << ": ";
    cin >> input;
    cin.get();
  }
  for(int i = 0; i < input; i++){
    cout << input;
  }
  
  cout << endl << endl;
  cout << "Press enter to continue. ";
  cin.ignore();
  cout << endl << endl;
  
  for(int i = 0; i < input; i++){
    cout << "1" << endl;
  }

  cout << endl << endl;
  cout << "Press enter to continue. ";
  cin.ignore();
  cout << endl << endl;

  for(int i = 1; i <= input; i++){
    cout << setw(COL_WIDTH) << i;
  }
  cout << endl;
  for(int r = 1; r <= input; r++){
    cout << r;
    for(int c = 1; c <= input; c++){
      cout << setw(COL_WIDTH) << c*r;
     
    }
    cout << endl;
  }
  cout << endl << endl;
  cout << "Press enter to continue. ";
  cin.ignore();
  cout << endl << endl;

  for(int i = 1; i <= input; i++){
    for(int n = 1; n <= i; n++){
      cout << i;
    }
    cout << endl;
  }
  cout << endl << endl;
  cout << "Press enter to continue. ";
  cin.ignore();
  cout << endl << endl;

  for(int i = 1; i <= input; i++){
    for(int n = 1; n <= i; n++){
      cout << i;
    }
    cout << endl;
  }
  for(int i = input; i > 1; i--){
    for(int n = 1; n < i; n++){
      cout << i-1;
    }
    cout << endl;
  }
  cout << endl << endl;
  cout << "Press enter to continue. ";
  cin.ignore();
  cout << endl << endl;

  for(int i = 1; i <= input; i++){
    for(int n = input; n > i; n--){
      cout << SPACE;
    }
    for(int j = 1; j <= i; j++){
      cout << i + SPACE;
    }
    cout << endl;
  }
  
   for(int i = input; i > 1; i--){
    for(int n = input; n > i; n--){
      cout << SPACE;
    }
    for(int j = i; j > 0; j--){
      cout << (i-1) + SPACE;
    }
    cout << endl;
  }

}
