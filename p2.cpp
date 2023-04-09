//Imani Cage
//p2.cpp
/*A program where you and another player have to make your "bucket" have
  all 10 "cherries" from a "tree", via spinning a wheel */


#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(){

  srand(time(0));
  const int MAX_SPIN = 7;
  const int oneCherry = 1;
  const int twoCherry = 2;
  const int threeCherry = 3;
  const int fourCherry = 4;
  const int spilledBucket = 0;
  const int dog = 2;
  const int bird = 2;
  const char yes = 'y';
  int p1Bucket = 0;
  int p2Bucket = 0;
  string p1Name, p2Name;
  bool p1Turn = true;
  char ans = 'y';
  int spin = (rand()%MAX_SPIN)+ 1; 

  cout << endl << "Welcome to Hi-Ho Cherry O!";
  cout << endl << "The goal is to pick 10 cherries from"
       << " your tree before your opponent!";
  cout << endl << endl;
  
  cout << "Player one, what is your name? ";
  cin >> p1Name;

  cout << endl;
  
  cout << "Player two, what is your name? ";
  cin >> p2Name;
  cin.ignore();

  cout << endl << endl;
  
  cout << "Excellent! Let's begin!";
  
  while(tolower(ans) == yes){
  while(p1Bucket < 10 &&  p2Bucket < 10){
    if(p1Turn){
      cout << endl << endl;
      cout << p1Name << ", it's your turn to spin!"
           << endl << "Press enter to spin!";
      cin.ignore();

      spin = (rand()%MAX_SPIN)+ 1;
      
      cout << endl << endl;
      
      switch(spin){
      case 1:
        cout << "You've picked one cherry from the tree."
             << endl << "You now have " << p1Bucket + oneCherry
             << " cherries in your bucket!";
          p1Bucket = p1Bucket + oneCherry;
          break;
      case 2:
        cout << "You've picked two cherries from the tree."
             << endl << "You now have " << p1Bucket + twoCherry
             << " cherries in your bucket!";
          p1Bucket = p1Bucket + twoCherry;
        break;
      case 3:
        cout << "You've picked three cherries from the tree."
             << endl << "You now have " << p1Bucket + threeCherry
             << " cherries in your bucket!";
          p1Bucket = p1Bucket + threeCherry;
        break;
      case 4:
        cout << "You've picked four cherries from the tree."
             << endl << "You now have " << p1Bucket + fourCherry
             << " cherries in your bucket!";
          p1Bucket = p1Bucket + fourCherry;
        break;
      case 5:
        if (p1Bucket == 0){
          cout << "Oh! You spilled your bucket!"
               << endl << "Good thing you had no cherries!";
        }else{
        cout << "Oh no! You spilled your bucket!" << endl
             << "You have no more cherries in your bucket.";
        p1Bucket = spilledBucket;
        }
        break;
      case 6:
        if (p1Bucket == 1 || p1Bucket == 2){
          cout << "Oh no! A dog has taken your cherry!"
               << endl << "You now have no more cherries in "
               << "your bucket.";
          p1Bucket = p1Bucket - dog;
        }else if(p1Bucket == 0){
          cout << "Oh! A dog is sniffing around your bucket! "
               << "Good thing there are no cherries!";
        }else{
        cout << "Oh no! A dog has taken your cherries!"
             << endl << "You now have " << p1Bucket - dog
             << " cherries!";
          p1Bucket = p1Bucket - dog;
        }
        break;
      case 7:
         if (p1Bucket == 1 || p1Bucket == 2){
          cout << "Oh no! A bird  has taken your cherry!"
               << endl << "You now have no more cherries in "
               << "your bucket.";
          p1Bucket = p1Bucket - bird;
        }else if(p1Bucket == 0){
          cout << "Oh! A bird is pecking around your bucket! "
               << "Good thing there are no cherries!";
        }else{
        cout << "Oh no! A bird has taken your cherries!"
             << endl << "You now have " << p1Bucket - bird
             << " cherries!";
          p1Bucket = p1Bucket - bird;
         }
         break;
      }
      if(p1Bucket < 0){
        p1Bucket = 0;
      }
      p1Turn = false;
    }else{
      cout << endl << endl;
      
      cout << p2Name << ", it's your turn to spin!";
      cout << endl << "Press enter to spin! ";
      cin.ignore();
      
      spin = (rand()%MAX_SPIN)+ 1;
      
      cout << endl << endl;
      
      switch(spin){
      case 1:
        cout << "You've picked one cherry from the tree."
             << endl << "You now have " << p2Bucket + oneCherry
             << " cherries in your bucket!";
        p2Bucket = p2Bucket + oneCherry;
        break;
      case 2:
        cout << "You've picked two cherries from the tree."
             << endl << "You now have " << p2Bucket + twoCherry
             << " cherries in your bucket!";
        p2Bucket = p2Bucket + twoCherry;
        break;
      case 3:
        cout << "You've picked three cherries from the tree."
             << endl << "You now have " << p2Bucket + threeCherry
             << " cherries in your bucket!";
        p2Bucket = p2Bucket + threeCherry;
        break;
      case 4:
        cout << "You've picked four cherries from the tree."
             << endl << "You now have " << p2Bucket + fourCherry
             << " cherries in your bucket!";
        p2Bucket = p2Bucket + fourCherry;
        break;
      case 5:
        if (p2Bucket == 0){
          cout << "Oh! You spilled your bucket!"
               << endl << "Good thing you had no cherries!";
            }else{
        cout << "Oh no! You spilled your bucket!" << endl
             << "You have no more cherries in your bucket.";
        p2Bucket = spilledBucket;
        }
        break;
      case 6:
        if (p2Bucket == 1 || p2Bucket == 2){
          cout << "Oh no! A dog has taken your cherry!"
               << endl << "You now have no more cherries in "
               << "your bucket.";
          p2Bucket = p2Bucket - dog;
        }else if(p2Bucket == 0){
          cout << "Oh! A dog is sniffing around your bucket! "
               << "Good thing there are no cherries!";
        }else{
          cout << "Oh no! A dog has taken your cherries!"
               << endl << "You now have " << p2Bucket - dog
               << " cherries!";
          p2Bucket = p2Bucket - dog;
        }
        break;
      case 7:
         if (p2Bucket == 1 || p2Bucket == 2){
           cout << "Oh no! A bird  has taken your cherry!"
               << endl << "You now have no more cherries in "
               << "your bucket.";
          p2Bucket = p2Bucket - bird;
        }else if(p2Bucket == 0){
           cout << "Oh! A bird is pecking around your bucket! "
               << "Good thing there are no cherries!";
        }else{
           cout << "Oh no! A bird has taken your cherries!"
                << endl << "You now have " << p2Bucket - bird
                << " cherries!";
          p2Bucket = p2Bucket - bird;
         }
         break;
      }
      if(p2Bucket < 0){
        p2Bucket = 0;
      }
      p1Turn = true;
    }

  }
  if(p1Bucket >= 10){
    cout << endl << endl;
    cout << "CONGRATULATIONS " << p1Name << "!!"
         << " You've won Hi-Ho Cherry-O!";
  }else{
    cout << endl << endl;
    cout << "CONGRATULATIONS " << p2Name << "!!"
         << " You've won Hi-Ho Cherry-O!";
  }
  cout << endl << endl;
  cout << "Would you like to play again? ";
  cin >> ans;
  }
  cout << endl << endl;
  cout << "Thank you for playing!";
  return 0;
}
