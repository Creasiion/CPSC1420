//Imani Cage
//lab12.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printList(const double arr[], int numE);
double total(const double arr[], int numE);

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";

int main()
{
  const int MAX_LENGTH = 50;
  double list[MAX_LENGTH] = {0};
  int count = 0;
  double num;
  ifstream infile;
  infile.open(FILENAME);
  
  if(infile.fail())
    {
      cout << "Error: File did not open. Please try again";
      return 0;
    }
  
  while (infile >> num)
    {
      list[count] = num;
      count++;
    }
   
  printList(list, count);
  cout << endl << endl;
  cout << "The total is: " << total(list, count);
  cout << endl << endl;
  
  return 0;
}

void printList(const double arr[], int numE)
{
  const int INDEX_COLM = 5;
  const int NUM_COLM = 8;
  const int DIGITS = 3;

  cout << setw(INDEX_COLM) << "Index" << setw(NUM_COLM)
       << "Value:" << endl;
  for(int i = 0; i < numE; i++){
    cout << setw(INDEX_COLM) << i << setw(NUM_COLM)
         << fixed << showpoint << setprecision(DIGITS)
         << arr[i] << endl;
  }
}

double total(const double arr[], int numE)
{
  double sum = 0;
  for(int i = 0; i < numE; i++){
    sum += arr[i];
  }
  return sum;
}
