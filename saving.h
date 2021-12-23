//this class is done!
#ifndef SAVING_H
#define SAVING_H

#include <iostream>
#include <string>
#include "subAccount.h"
using namespace std;

//child of subAccount
class Saving : public SubAccount{
public:
  Saving(){
    balance = -9999;
    subAccNum = "N/A";
  }

  void createSavAcc(int savAccNum, bool isFirstSavAcc){
    int initialAmt;

    cout << "\tEnter the initial balance: ";
    cin >> initialAmt;

    if(isFirstSavAcc){
      balance = initialAmt + 100;
    }else{
      balance = initialAmt;
    }

    subAccNum = "SAV" + to_string(savAccNum);

    cout <<"\t| A new Saving Sub Account " << subAccNum << " was successfully created." << endl << endl;
  }

  int savAccMenu(){
    int SavAcctService;

    cout << "Eligible services for Sub-Account " << getSubAccNum() << endl;

    cout << "\t(1) Deposit" << endl
    << "\t(2) Withdraw" << endl
    << "\t(3) Exit" << endl;

    cout << "Please enter your selection: ";
    cin >> SavAcctService;
    while (cin.fail() || !(SavAcctService == 1 || SavAcctService == 2 || SavAcctService == 3)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\tThat is not a valid choice, please try again: ";
      cin >> SavAcctService;
	  }

    cout << endl;

    return SavAcctService;
  }

  void savMenuResult(){
    int savChoice = savAccMenu();
    
    while(savChoice != 3){

      switch(savChoice){
      //deposit
      case 1:
        deposit();
        break;

      //withdraw
      case 2:
        withdraw();
        break;
      }

      savChoice = savAccMenu();

    }

    cout << "\t| End of service for sub-account " << getSubAccNum() << endl << endl;
  }
};

#endif
