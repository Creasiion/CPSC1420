//Imani Cage
//p4.cpp
//This code recreated the popular card game in the attempts to get
//two of the same card.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const char BEG = 'b';
const char EXP = 'e';
const int BEG_SECONDS = 5;
const int EXP_SECONDS = 3;
const int SCREEN_SIZE = 40;
const int WIN = 6;
const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";
const int COLS = 3;
const int ROWS = 4;
const char YES = 'y';
const char LEFT_BRACKET = '[';
const char RIGHT_BRACKET = ']';
const char SPACE = ' ';
const char ASTERISK = '*';
const char UNDERSCORE = '_';
const int PROBABILITY = 2;
const int BOARD_ONE = 1;
const int INVALID = -1;

void welcome(char& ans);
void wait(int seconds);
bool readFile(char board[][COLS], string fileName);
void display(const char board[][COLS], int c1Row = -1, int c1Col = -1, 
             int c2Row = -1, int c2Col = -1); //Displays board
void getFirstCard(char board[][COLS], int& c1Row, int& c1Col); //Requests first card choice from user
void getSecondCard(char board[][COLS], int& c2Row, int& c2Col, //Requests second card choice from user
                    int c1Row, int c1Col);
void clrScreen();
void goodbye();


int main()
{
  srand(time(0));
  char board[ROWS][COLS]; //Card set-up
  char ans;
  char expAns;
  int time; //Varying time based off of beginner or expert
  int turns; //Keeps track of how many turns the player has done
  bool errorCheck = false;
  int fileChange = rand()% PROBABILITY;
  int foundPairs;
  string fileName; 
  int currentC1R, currentC1C, currentC2R, currentC2C = INVALID;
  
  welcome(ans);
  
  clrScreen();
  
  //while loop to ask them to continue playing
  while(tolower(ans) == YES){
    turns = 0;
    foundPairs = 0;
    //Asks player if they are a beginner or expert.
    cout << "Are you a BEGINNER (b)? or an EXPERT(e)? b/e ";
    cin >> expAns;
    while(tolower(expAns)!= BEG && tolower(expAns) != EXP){
      cout << endl << "Invalid option. Please try again ";
      cin >> expAns;
    }
    if(expAns == BEG){
      time = BEG_SECONDS;
    }else{
      time = EXP_SECONDS;
    }

    // Beginning of file reading

    if(fileChange == BOARD_ONE) {    //Radomizes board
      fileName = FILE1;
    } else {
      fileName = FILE2;
    } 

    errorCheck = readFile(board, fileName);
    if(!errorCheck)
      {
        cout << "Error with file. Exiting program.";
        ans = 'n';
      }
    
  
    while(foundPairs != WIN){
      clrScreen();
      display(board);
      getFirstCard(board, currentC1R, currentC1C);
      clrScreen();
      display(board, currentC1R, currentC1C);
      getSecondCard(board, currentC2R, currentC2C, currentC1R, currentC1C);

      if(board[currentC1R][currentC1C] == board[currentC2R][currentC2C])
      {
        foundPairs++;
         board[currentC1R][currentC1C] = UNDERSCORE;
         board[currentC2R][currentC2C] = UNDERSCORE;
         clrScreen();
         display(board);
        cout << "Congrats! You found a matched pair!";
        cout << endl << endl;
        cout << "Press enter to continue";
        cin.ignore();
        cin.ignore();
    }else
    {
      clrScreen();
      display(board, currentC1R, currentC1C, currentC2R, currentC2C);
      cout << endl << endl;
      cout << "Sorry! It wasn't a match";
      cout << endl << endl;
      wait(time);
    }
turns++;
    }
    cout << endl << endl << "Congratulations!";
    if(turns == WIN)
    {
      cout << endl;
      cout << "Wow! You for a perfect score of " << turns << "!";
    } else 
    {
cout << endl;
cout << "You got a score of " << turns;
    }
    cout << endl << endl;
    cout << "Would you like to play again? y/n " ;
    cin >> ans;
    fileChange = rand()% PROBABILITY;
  } // end of while loop
  goodbye();
  //Close file
  return 0;
}

void welcome(char& ans)
{
  cout << endl << endl;
  cout << "Welcome to the Memory Game!"<< endl 
       << "In this game match all cards with their pair." 
       << endl << "Your score is the amount of turns you take, so the less turns the better!"
       << endl << "Are you ready to begin? y/n ";
  cin >> ans;
}

bool readFile(char board[][COLS], string fileName)
{
  ifstream inFile;
  
  inFile.open(fileName);
  if(inFile.fail()) 
  {
    return false;
  }
  
  for(int r = 0; r < ROWS; r++) 
  {
    for(int c = 0; c < COLS; c++) 
    {
      inFile >> board[r][c];
    }
  }
  inFile.close();
  return true;
}

void clrScreen()
{
  for(int i = 0; i <= SCREEN_SIZE; i++)
  {
    cout << endl;
  }
}

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}

void display(const char board[][COLS], int c1Row, 
             int c1Col, int c2Row, int c2Col)
{
  for(int i = 0; i < COLS; i++) 
  {
    cout << setw(ROWS) << i;
  }
  cout << endl;

  for(int row = 0; row < ROWS; row++) 
  {
    cout << row << SPACE;
    for(int col = 0; col < COLS; col++) 
    {
      cout << LEFT_BRACKET;
      
      if(row == c1Row && col == c1Col) 
      {
        cout << board[c1Row][c1Col];
      } else if (row == c2Row && col == c2Col)
       {
        cout << board[c2Row][c2Col];
      } else if(board[row][col] == UNDERSCORE)
      {
        cout << board[row][col];
      } else 
      {
        cout << ASTERISK;
      }
      
      cout << RIGHT_BRACKET << SPACE;
    }
    cout << endl;
  }
}

void getFirstCard(char board[][COLS], int& c1Row, int& c1Col)
{
  cout << "Your first card: " << endl;
  int cardRow = INVALID;
  int cardCol = INVALID;

  while(cardRow == INVALID && cardCol == INVALID)
   {
    while (cardRow < 0 || cardRow > ROWS - 1) 
    {
      cout << "Row? ";
      cin >> cardRow;
    }

    c1Row = cardRow;

    while (cardCol < 0 || cardCol > COLS - 1) 
    {
      cout << "Col? ";
      cin >> cardCol;
    }

    c1Col = cardCol;

    if(board[c1Row][c1Col] == UNDERSCORE) 
    {
      cout << "This card is unavailable! Please pick again..." << endl;
      cardRow = INVALID;
      cardCol = INVALID;
    }
  }
}

void getSecondCard(char board[][COLS], int& c2Row, int& c2Col,
                    int c1Row, int c1Col)
{
  int cardRow = INVALID;
  int cardCol = INVALID;

  cout << "Your second card: " << endl;

  while(cardRow == INVALID && cardCol == INVALID)
   {
    while (cardRow < 0 || cardRow > ROWS - 1) 
    {
      cout << "Row? ";
      cin >> cardRow;
    }

    c2Row = cardRow;

    while (cardCol < 0 || cardCol > COLS - 1) 
    {
      cout << "Col? ";
      cin >> cardCol;
    }

    c2Col = cardCol;

    if(board[c2Row][c2Col] == UNDERSCORE) 
    {
      cout << "This card is unavailable! Please pick again..." << endl;
      cardRow = INVALID;
      cardCol = INVALID;
    } else if(cardRow == c1Row && cardCol == c1Col)
    {
      cout << "You've already picked this card! Please pick again...";
      cardRow = INVALID;
      cardCol = INVALID;
    }
  }
}

void goodbye()
{
  cout << endl << endl;
  cout << "Thanks for playing!";
  cout << endl << endl;
}
