//Imani Cage
//lab9.cpp

#include <iostream>

using namespace std;

void input(string& str1, string& str2);
void swapStr(string& str1, string& str2);
void output(string str1, string str2);

int main()
{
  string str1, str2;
  input(str1, str2);
  
  output(str1, str2);
  
  swapStr(str1, str2);
  
  output(str1, str2);
  
  return 0;
}

void input(string& str1, string& str2){
  cout << "Please provide two single words: ";
  cin >> str1;
  cin >> str2;
}

void swapStr(string& str1, string& str2){
  string temp = str1;
  str1  = str2;
  str2 = temp;
}

void output(string str1, string str2){
  cout << "String 1 is " << str1
       << ". String 2 is " << str2;
  cout << endl << endl;
}
