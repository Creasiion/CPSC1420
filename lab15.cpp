//Imani Cage
//lab15.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int linearSearch(const string list[], int numE, string target);

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";
const int MAX = 75;
const char YES = 'y';

int main()
{
  int results;
  int count = 0;
  ifstream infile;
  string words[MAX];
  string playerWord;
  char ans = 'y';
  string wordOptions;
  
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "File has failed to open. Please try again.";
  }
  
  while(infile >> wordOptions){
    words[count] = wordOptions ;
    count++;
  }
  infile.close();
  
  while(tolower(ans) == YES){ 
    cout << "Please type in a word you would like to search for. ";
    cin >> playerWord;
    
    results = linearSearch(words, count, playerWord);
    
    if(results == -1){
      cout << endl << endl;
      cout << "Sorry, " << playerWord << " was not found.";
      cout << endl << endl;
    } else {
      cout << endl << endl;
      cout << playerWord << " was found in index "
           << results << "!";
      cout << endl << endl;
    }
    cout << "Try again? (y/n) ";
    cin >> ans;
  }
  cout << endl << endl;
  cout << "Thank you for playing!";
  cout << endl << endl;
  
  return 0;
}

int linearSearch(const string list[], int numE, string target)
{
  int index = 0;
  while(index < numE && list[index] != target){
    index++;
      }
  if(index < numE){
    return index;
  }else{
    return -1;
  }
}
