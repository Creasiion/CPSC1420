//Imani Cage
//p3.cpp
//Description: Recreation of the chutes and ladders game for two players.
//Game goes back and forth between the two players to "spin" and progress through the game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcome();
void goodbye();
int spin();
int checkLocation(int position);
int takeTurn(int position, string name);
const int MIN_SPIN = 1;
const int MAX_SPIN = 6;
const int STARTING_POSITION = 1;
const int WINNING_POSITION = 100;
int main()
{
  srand(time(0));
  const char YES = 'y';
  char ans = 'Y';
  int p1Position;
  int p2Position;
  string p1Name;
  string p2Name;
  bool p1Turn = true;
  
  welcome();
  cout << "Player 1, Please enter your name: ";
  cin >> p1Name;
  cout << endl;
  cout << "Player 2, Please enter your name: ";
  cin >> p2Name;
  cin.ignore();
  
  while (tolower(ans) == YES){
    p1Position = STARTING_POSITION;
    p2Position = STARTING_POSITION;
    while(p1Position != WINNING_POSITION && p2Position != WINNING_POSITION){
      if(p1Turn){
        p1Position = takeTurn(p1Position, p1Name);
        p1Turn = false;
      }else{
        p2Position = takeTurn(p2Position, p2Name);
        p1Turn = true;
      }
    }
    
    if(p1Position == WINNING_POSITION){
      cout << endl << endl;
      cout << "Congrats " << p1Name << ", you've won Chutes and Ladders against " << p2Name << "!";
    }else{
      cout << endl << endl;
      cout << "Congrats " << p2Name << ", you've won Chutes and Ladders against " << p1Name << "!";
    }
    cout << endl << endl;
    cout << "Play again? y/n ";
    cin >> ans;
  }
  goodbye();
  return 0;
}


void welcome(){
  cout << endl << endl;
  cout << "Welcome to Chutes and Ladders!" << endl;
  cout << "In this game the first player to reach " << WINNING_POSITION
       << " wins! But be careful! Certain positions will either:";
  cout << endl << "1. Take you up a ladder, and closer to the finish line!"
       << endl << "2. Take you down a chute, and will move you further away from winning.";
  cout << endl << "Are you ready! Let's begin!";
  cout << endl << endl;
}

void goodbye(){
  cout << endl << endl;
  cout << "Thank you for playing!";
  cout << endl << endl;
}

int spin(){
  return rand()% ((MAX_SPIN - MIN_SPIN) + 1) + MIN_SPIN;
}

int checkLocation(int position){
    if(position == 1){
      return 37;
    }else if(position == 4){
      return 10;
    }else if(position == 9){
      return 12;
    }else if(position == 23){
      return 21;
    }else if(position == 28){
      return 56;
    }else if(position == 36){
      return 8;
    }else if(position == 51){
      return 15;
    }else if(position == 71){
      return 19;
    }else if(position == 80){
      return 20;
    }else if(position == 98){
      return -20;
    }else if(position == 95){
      return -20;
    }else if(position == 93){
      return -20;
    }else if(position == 87){
      return -63;
    }else if(position == 64){
      return -4;
    }else if(position == 62){
      return -43;
    }else if(position == 56){
      return -3;
    }else if(position == 49){
      return -38;
    }else if(position == 48){
      return -22;
    }else if(position == 16){
      return -10;
    }
      return 0;
  }

  int takeTurn(int position, string name){
    int chuteLadder;
    int playerSpin;

    cout << endl << endl;
    cout << name << ", it's your turn to spin! You are currently on "
         << position << ". Press enter to spin! ";
    cin.ignore();
    playerSpin = spin();
    cout << endl << name << " has spinned " << playerSpin << "!" << endl;
    cout << endl;
    if(position + playerSpin <= WINNING_POSITION){
      position += playerSpin;
      cout << "You are now at " << position;
    }else{
      cout << endl;
      cout << "Sorry! You can't go past " << WINNING_POSITION << "!"
           << " Looks like you have to try again next turn!";
    }
    chuteLadder = checkLocation(position);
    if(chuteLadder > 0){
      cout << endl << "Oh, wait a minute. What is this? A ladder!";
      position += chuteLadder;
      cout << endl << name << " is now at " << position << "!";
    }else if (chuteLadder < 0){
      cout << endl << "Oh? What is this- oh no a chute! You're sliding down!";
      position += chuteLadder;
      cout << endl;
      cout << endl << name << " is now at " << position << ". Be careful!";
        }
    return position;
  }
