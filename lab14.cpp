//Imani Cage
//lab14.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Person
{
    string name;
    int age;
    int coffee;
};

const int MAX = 150;
const int NAME_FIELD = 15;
const int AGE_FIELD = 4;
const int COFFEE_FIELD = 4;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";

void printOne(Person p);
double averageAge(const Person list[], int numE);
int totalCoffee(const Person list[], int numE);

int main()
{
  Person clients[MAX];
  int count = 0; //keeps track of the array size number
  ifstream infile;

  cout << endl << endl;
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "File error: exiting program. Please try again.";
  }
  while (infile >> clients[count].name){
    infile >> clients[count].age >> clients[count].coffee;
    count++;
  }

  cout << left << setw(NAME_FIELD) << "Name"
       << right << setw(AGE_FIELD) << "Age " << setw(COFFEE_FIELD) << "Coffee";
  cout << endl << endl;
  
  for(int i = 0; i < count; i++){
      printOne(clients[i]);
      cout << endl;
    }

  cout << endl << endl;
  cout << "Average age: " << averageAge(clients, count);
  cout << endl;
  cout << "Total coffee: " << totalCoffee(clients, count);
  cout<< endl << endl;
  
  infile.close();
  return 0;
}

void printOne(Person p)
{
  cout << left << setw(NAME_FIELD) <<  p.name
       << right << setw(AGE_FIELD) << p.age << setw(COFFEE_FIELD) << p.coffee;
}
double averageAge(const Person list[], int numE)
{
  double sum = 0.0;
  double avg = 0.0;
  for(int i = 0; i < numE ; i++){
      sum += list[i].age;
    }
  avg = sum/numE;
  return avg;
}

int totalCoffee(const Person list[], int numE)
{
  int sum = 0;
  for(int i  = 0; i < numE; i++){
      sum += list[i].coffee;
    }
  return sum;
}



