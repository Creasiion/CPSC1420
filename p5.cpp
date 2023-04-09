//Imani Cage
//p5.cpp

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Gameboard
{
  string name;
  int owner;
  int buy;
  int rent;
};

struct Player
{
  string name;
  int money;
  int location;
};


void welcome();
int fillBoard(Gameboard board[]);
int rollDie(); //Returns number for the player which is how many places they moved on the board
int winner(Player list[], int numP); //Linear searches for the winner index
void checkLocation(Player list[], int playerNum, Gameboard board[]);
bool takeTurn(Player list[], int playerNum, Gameboard board[], int numPlaces); //Calls rollDie and checkLocation. Updates player location and returns if the game is finished or not
void property(Player list[], int playerNum, Gameboard board[]); //Checks if property is owned or not
void goodbye();

const int BOARD_SIZE = 45;
const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;
const int MIN_ROLL = 1;
const int MAX_ROLL = 6;
const int BEGINNING_CASH = 1500;
const int PASS_HOME_CASH = 200;
const int INCOME_REPAYMENT = 200;
const int CHANCE_ROLL = 3;
const int CHANCE_CASH = 50;
const string CHANCE = "Chance";
const string CHAPEL = "Chapel of St. Ignatius";
const string DEANS_OFFICE = "Dean of Students Office";
const string GO = "Go";
const string INCOME = "Income Tax";
const string FEES = "Fees";
const char YES = 'y';

int main()
{
  srand(time(0));
  Gameboard myGame[BOARD_SIZE];
  Player myPlayers[MAX_PLAYERS + 1];
  bool gameComplete = false;
  int numPlayers = 0;
  int currentPlayer = 1;
  int pWinner;
  int numProperties = 0;
  char ans = 'y';
  
  welcome();
  cin.ignore();

  numProperties = fillBoard(myGame);

  while(tolower(ans) == YES){
    //reset necessary variables here i.e. asking for amount of players
    cout << endl << endl;
    gameComplete = false;
    numPlayers = 0;
    while(numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS){
    cout << "How many players? Between " << MIN_PLAYERS << " and " << MAX_PLAYERS << ". ";
    cin >> numPlayers;
    cout << endl;
    }
    cin.ignore();
    for(int i = 1; i <= numPlayers; i++){
      cout << "Player " << i << ", what is your name? ";
      cin >> myPlayers[i].name;
      myPlayers[i].money = BEGINNING_CASH;
      myPlayers[i].location = 0;
    }
    cin.ignore();
    while(!gameComplete){
      cout << endl << endl;
        gameComplete = takeTurn(myPlayers, currentPlayer, myGame, numProperties);
        currentPlayer++;
        if(currentPlayer > numPlayers){
          currentPlayer = 1;
        }
    }
 
  pWinner = winner(myPlayers, numPlayers);
  cout << endl << endl;
  cout << "Congratulations, " << myPlayers[pWinner].name << "!!! You've won SU Monopoly!"
       << endl <<"You ended the game with $" << myPlayers[pWinner].money << "!!";
  cout << endl << endl;
  cout << "Would you like to play again? (y/n) ";
  cin >> ans;
}
  goodbye();

  return 0;
}

void welcome()
{
  cout << "Welcome to Seattle University Monopoly! ";
  cout << "Press enter to begin...";
}

void goodbye()
{
  cout << endl << endl;
  cout << "Thank you for playing!";
}

int fillBoard(Gameboard board[])
{
  ifstream inFile;
  int count = 0;
  inFile.open("/home/fac/sreeder/class/cs1420/p5input.dat");
  if (!inFile.fail()){
    while (count < BOARD_SIZE && getline(inFile, board[count].name)){
       inFile >> board[count].owner >> board[count].buy >> board[count].rent;
       inFile.ignore();
       count++;
   }
   inFile.close();
  }
  return count;
}

int rollDie()
{
  int dice1 = (rand()% ((MAX_ROLL - MIN_ROLL) + 1) + MIN_ROLL);
  int dice2 = (rand()% ((MAX_ROLL - MIN_ROLL) + 1) + MIN_ROLL);
  return dice1 + dice2;
}

int winner(Player list[], int numP)
{
  int winner = 1;
  for(int i = 2 ; i < numP; i++){
    if(list[i].money > list[winner].money){
      winner = i;
    }
  }
  return winner;
}

bool takeTurn(Player list[], int playerNum, Gameboard board[], int numPlaces)
{
  string playerName = list[playerNum].name;
  int location = list[playerNum].location;
  cout << "It is " << playerName << "'s turn. You currently have $" << list[playerNum].money; 
  cout << endl << "Press enter to roll the dices!";
  cin.ignore();
  int rollTotal = rollDie();
  int newLocation = location + rollTotal; 
  location = newLocation;
  cout << endl << endl;
  cout << "You rolled a total of " << rollTotal << " moves! ";
  cout << endl << "You are now at space " << newLocation;
  if(newLocation >= numPlaces){
    newLocation = newLocation - numPlaces;
    cout << endl << endl;
    cout << playerName << " passed " << GO << " and collected $" << PASS_HOME_CASH << "!!";
  }
  list[playerNum].location = newLocation;
  checkLocation(list, playerNum, board);
  if(list[playerNum].money < 0){
    cout << playerName << " is now in debt! They pay it off, but they're done playing now.";
    list[playerNum].money = 0;

    return true;

  }else if(list[playerNum].money == 0){
    cout << playerName << " has no more money to spend! The games have come to an end!";
    return true;
  } else {
    cout << endl << playerName << " now has $" << list[playerNum].money;
    return false;
  }
  
}

void checkLocation(Player list[], int playerNum, Gameboard board[])
{
  int chanceRoll = 0;
  int findChapel = 0;

  cout << endl << "Now at " << board[list[playerNum].location].name;

  if(board[list[playerNum].location].name  == GO){
    cout << endl << "Here's your paycheck!";
    cout << endl;
    list[playerNum].money += PASS_HOME_CASH;
  } else if(board[list[playerNum].location].name  == INCOME){
    cout << endl << "You landed on income tax! You have to pay the bank!";
    cout << endl;
    if(list[playerNum].money < INCOME_REPAYMENT){
      list[playerNum].money = 0;
    }else{
      list[playerNum].money -= INCOME_REPAYMENT;
    }
  }else if(board[list[playerNum].location].name == CHAPEL){
    cout << endl << "You're in the Chapel of St. Ignatius. Relax and Rest!";
    cout << endl;
  }else if(board[list[playerNum].location].name == DEANS_OFFICE){
    cout << endl << "You made it into the Dean's Office. Talk about your classes!";
    cout << endl;
    }else if(board[list[playerNum].location].name  == CHANCE){
    cout << endl << "Oh wow! You landed on a chance to get $" << CHANCE_CASH << "!";
    cout << endl << endl << "Press enter to roll for your chances...";
    cin.ignore();
    chanceRoll = rollDie();
    if(chanceRoll <= CHANCE_ROLL){
      cout << endl <<"Congratulations! You rolled a " << chanceRoll << " AND WON $" << CHANCE_CASH << "!!";
      list[playerNum].money += CHANCE_CASH;
    }else{
      cout << endl << "You rolled a " << chanceRoll << ". You didn't get any money and it made you exhausted."
           << endl << "You walk in sadness to the Chapel of St. Ignatius to take a nap.";
           list[playerNum].location = findChapel;
    }
  }else if (board[list[playerNum].location].name == FEES){
    cout << endl << "Looks like you forgot to pay some fees earlier... pay them now! ";
    if(list[playerNum].money < board[list[playerNum].location].rent){
      list[playerNum].money = 0;
    }else{
      list[playerNum].money -= board[list[playerNum].location].rent;
    }
  } else {
    property(list, playerNum, board);
  }
}


void property(Player list[], int playerNum, Gameboard board[])
{
  char buyAns;
  Player owner = list[board[list[playerNum].location].owner];
  if(board[list[playerNum].location].owner == 0){
    cout << endl;
    cout << board[list[playerNum].location].name << " is unowned, so consider buying it!"
         << " The place costs $" << board[list[playerNum].location].buy;
    cout << ". You currently have $" << list[playerNum].money << ". Would you like to purchase? (y/n) ";
    cin >> buyAns;
    cin.ignore();
    if(tolower(buyAns) == YES){
      cout << endl << endl;
      cout << list[playerNum].name << " has bought the space!";
      list[playerNum].money -= board[list[playerNum].location].buy;
      board[list[playerNum].location].owner = playerNum;
    }else{
      cout << endl << board[list[playerNum].location].name << " was not bought and still up for grabs!";
    }
  }else if (board[list[playerNum].location].owner != playerNum){
    cout << endl <<"This space is owned by " << owner.name << "!";
    cout << endl << "You must pay the rent of $" << board[list[playerNum].location].rent << " to " << owner.name;
    list[playerNum].money -= board[list[playerNum].location].rent;
    list[board[list[playerNum].location].owner].money += board[list[playerNum].location].rent; //gives rent money to house owner
  }else{
    cout << endl <<"You own this building! You decide to walk around and inspect.";
  }
}