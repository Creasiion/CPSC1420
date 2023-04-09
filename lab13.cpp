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
void tablePrint(int arr[ROWS][COLMS]);
int sumTotal(int arr[ROWS][COLMS]);

int main()
{
  int table[ROWS][COLMS] = {0};
  ifstream infile;
  
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

  tablePrint(table);

  cout << "The total is " << sumTotal(table);
  cout << endl << endl;
  
  return 0;
}

void tablePrint(int arr[ROWS][COLMS])
{
  int total = 0;
  cout << endl << endl;
  cout << "                                    Row total" << endl;
  for(int r = 0; r < ROWS; r++){
    total = 0;
    for(int c = 0; c < COLMS; c++){
      cout << setw(COLM_WIDTH) << arr[r][c];
      total += arr[r][c];
    }
    cout << " " << total << endl;
  }
  cout << endl << endl;
  total = 0;
  for(int c  = 0; c < COLMS; c++){
    total = 0;
    for(int r = 0; r < ROWS; r++){
      total += arr[r][c];
    }
    cout << setw(COLM_WIDTH) << total;
  }
  cout << endl << "  Column total " << endl;

  cout << endl << endl;
}

int sumTotal(int arr[ROWS][COLMS])
{
   int total = 0;
   
  for(int r  = 0; r < ROWS; r++){
    for(int c = 0; c < COLMS; c++){
      total += arr[r][c];
    }
  }
  return total;
}
