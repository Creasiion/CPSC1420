//Imani Cage
//lab11.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";
const int ROWS = 5;
const int COLMS = 8;
const int COLM_WIDTH = 5;

int main(){
  int table[ROWS][COLMS] = {0};
  ifstream infile;
  int total;
  
  infile.open(FILENAME);

  if(infile.fail()){
    cout << "Error: File did not open. Please try again";
    return 0;
  }
  
  for(int r = 0; r < ROWS; r++){
    for (int c = 0; c < COLMS; c++){
      infile >> table[r][c];
    }
  }
  
  infile.close();
  cout << endl << endl;
  cout << "                                    Row total" << endl;  
  for(int r = 0; r < ROWS; r++){
    total = 0;
    for(int c = 0; c < COLMS; c++){
      cout << setw(COLM_WIDTH) << table[r][c];
      total += table[r][c];
    }
    cout << " " << total << endl;
  }
  cout << endl << endl;
  total = 0;
  for(int c  = 0; c < COLMS; c++){
    total = 0;
    for(int r = 0; r < ROWS; r++){
      total += table[r][c];
    }
    cout << setw(COLM_WIDTH) << total;
  }
  cout << endl << "  Column total " << endl;
  
  cout << endl << endl;
  total = 0;

  for(int r  = 0; r < ROWS; r++){
    for(int c = 0; c < COLMS; c++){
      total += table[r][c];
    }
  }
  cout <<"The total is " << total << endl;
  cout << endl << endl;

  
  return 0;
}
