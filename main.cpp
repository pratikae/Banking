#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

#include "AccountSystem.h"
using namespace std;

// prints header
void DisplayHeader() {
  cout << "+----------------------------------------------+" << endl;
  cout << "|       Computer Science and Engineering       |" << endl;
  cout << "|        CSCE 1040 - Computer Science II       |" << endl;
  cout << "|  Pratika Eswaran pve0005 pve0005@my.unt.edu  |" << endl;
  cout << "+----------------------------------------------+" << endl;
  cout << endl;
}

// prints menu
void DisplayMenu() {
  cout << "+--------------------------------------+" << endl;
  cout << "| Enter account selection              |" << endl;
  cout << "| 1 : Add new account                  |" << endl;
  cout << "| 2 : Deposit into account             |" << endl;
  cout << "| 3 : Withdraw from account            |" << endl;
  cout << "| 4 : Transfer into account            |" << endl;
  cout << "| 5 : Print a list of all accounts     |" << endl;
  cout << "| 6 : End transaction (Exit)           |" << endl;
  cout << "+--------------------------------------+" << endl;
}

int main() {
  DisplayHeader(); // prints out the header

  // creates new account system object called transaction
  // AccountSystem transaction = new AccountSystem();
  AccountSystem transaction; 
  // calls store account system
  transaction.LoadAccountSystem(); 
 
  int choice; // int var for user choice
  bool quit = false; // bool var for if user wants to quit the program
  DisplayMenu(); // displays the initial menu
  cin >> choice; // gets users first choice
  
  while (!quit) { // while user doesnt want to quit
    switch(choice) {
      case 1:
        transaction.AddAccount(); // calls AddAccount for transaction
        cout << endl;
        break;
      case 2:
        transaction.Deposit(); // calls AddAccount for transaction
        cout << endl;
        break;
      case 3:
        transaction.Withdraw(); // callls Withdraw for transaction
        cout << endl;
        break;
      case 4:
        transaction.Transfer(); // calls Transfer for transaction
        cout << endl;
        break;
      case 5:
        transaction.PrintAccounts(); // calls PrintAccounts for transaction
        cout << endl;
        break;
      case 6:
        quit = true; // sets quit to true is user enters 6
        cout << "Thank you for running the program. Goodbye!" << endl;
        break;
      default:
        cout << "Error: Invalid selection. Enter a value between 1-6." << endl; // error message
    }
    
    if (!quit) {
      DisplayMenu(); // continues printing menu is user doesn't quit
      cin >> choice;
    }
  }

  transaction.StoreAccountSystem(); // loads transaction data into the file
  return 0;
}