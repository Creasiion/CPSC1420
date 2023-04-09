
//Imani Cage
//p1x.cpp
//A word game that'll make a short story based off of user's answers 

#include <iostream>

using namespace std;

int main()
{
  string name, school, occupation, animal;
  int age, gradYear, yearsLater;
  char ans;
  
  cout << endl << endl;
  cout << endl << endl;

  cout << "WELCOME! To Word Game MadLibs!" << endl ;
  cout << "Would you like to start? y/n ";
  cin >> ans;
    
  cout << endl << endl;

  while(ans == 'y'){
  cout << "What is your name? ";
  cin >> name;

  cout << "Pick a number: ";
  cin >> age;
  
  cout << "Name a school: ";
  cin >> school;

  cout << "What year do you graduate this school? ";
  cin >> gradYear;

  cout << "How many years have gone by? ";
  cin >> yearsLater;
  
  cout << "Name an occupation: ";
  cin >> occupation;

  cout << "Name an animal: ";
  cin >> animal;

  cout << endl << endl;
  
  cout << name << " began going to school when they were " << age
       << " years old. They went to "<< school  << " and graduated in "
       << gradYear << ". " << yearsLater  << " years later, they're now a "
       << occupation << " and have a pet " << animal;
  
  cout << endl << endl;

  cout << "Would you like to go again? y/n ";
  cin >> ans;
  
  cout << endl << endl;
  }
  cout << "Thank you for playing!";
  return 0;

}
