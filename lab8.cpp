//Imani Cage
//lab8.cpp

#include <iostream>

using namespace std;

void welcome();

int input();

int summation(int num);

void goodbye();
const char YES = 'y';
const int MIN = 5;
const int MAX = 25;


int main()
{
  int num;
  char ans = 'y';
  welcome();
  while(tolower(ans) == YES){
    num = input();
    cout << endl << "The summation of " << num << " is "
    << summation(num);
    cout << endl << endl;
    cout << "Would you like to go again? y/n ";
    cin >> ans;
    cout << endl << endl;
  }
  goodbye();
  return 0;
}


void welcome()
{
  cout << "Welcome!";
  cout << endl << endl;
}
int input()
{
  int num;
  cout << "Please insert a number between " << MIN
       << " and " << MAX << ". ";
  cin >> num;
  while(num < MIN || num > MAX){
    cout << "Number invalid. Please try again. ";
    cin >> num;
  }
  return num;
}

int summation(int num)
{
  int sum;
  for(int i = 0; i <= num; i++){
    sum += i;
  }
  return sum;
}
void goodbye()
{
  cout << "Thanks for playing!";
  cout << endl << endl;
}
