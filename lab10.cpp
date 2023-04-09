//Imani Cage
//lab10.cpp

#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";

int main()
{
  ifstream infile;
  int num;
  int eCount = 0;
  int oCount = 0;
  int nCount = 0;
  const int SIZE = 30;
  int evenNum[SIZE];
  int oddNum[SIZE];
  int negNum[SIZE];
  
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "File failure... exiting program: please press enter";
    cin.get();
    return 0;
  }
  
  while (infile >> num){
    if(num < 0){
      negNum[nCount] = num;
      nCount++;
    }else if (num%2 == 0 && num!= 0){
      evenNum[eCount] = num;
      eCount++;
    }else if(num != 0){
      oddNum[oCount] = num;
      oCount++;
    }
  }
  
  cout << endl << endl;
  cout << "Negative numbers" << endl;
  cout << "Index" << " " << "Output" << endl;
  for(int i = 0; i < nCount; i++){
    cout << i << " " << negNum[i] << endl;
  }
  
  cout << endl << endl;
  cout << "Even numbers" << endl;
  cout << "Index" << " " << "Output" << endl;
  for(int i = 0; i < eCount; i++){
    cout << i << " " << evenNum[i] << endl;
  }
  
  cout << endl << endl;
  cout << "Odd  numbers" << endl;
  cout << "Index" << " " << "Output" << endl;
  for(int i = 0; i < oCount; i++){
    cout << i << " " << oddNum[i] << endl;
  }
  infile.close();
  
  return 0;
}
