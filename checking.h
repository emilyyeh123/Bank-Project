#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <string>
#include "subAccount.h"
using namespace std;

//child of subAccount
class Checking : public SubAccount{
public:
  Checking(){
    balance = -9999;
    subAccNum = "N/A";
    maxCap = 0;
    lock = false;
  }

  void createCheckAcc(int checkAccNum){
    int bal, cap;
    char isLock;
    
    cout << "\tEnter the initial balance: ";
    cin >> bal;
    cout << "\tEnter the desired maximum capacity: ";
    cin >> cap;
    cout << "\tDefine initial state (L - Locked, Otherwise - Unlocked): ";
    cin >> isLock;
    cout << endl;
    
    balance = bal;
    maxCap = cap;
    lock = isLock;

    subAccNum = "CHK" + to_string(checkAccNum);

    cout << "\t| A new Checking Sub Account " << subAccNum << " was successfully created." << endl << endl;
  }
  
  //DONE
  int checkAccMenu(){
    int CheckAcctService;

    cout << "Eligible services for Sub-Account " << getSubAccNum() << endl;

    cout << "\t(1) Deposit" << endl
    << "\t(2) Withdraw" << endl
    << "\t(3) Max Capacity" << endl
    << "\t(4) Lock Sub-Account" << endl
    << "\t(5) Unlock Sub-Account" << endl
    << "\t(6) Exit" << endl;

    cout << "Please enter your selection: ";
    cin >> CheckAcctService;
    while (cin.fail() || !(CheckAcctService == 1 || CheckAcctService == 2 || CheckAcctService == 3 || CheckAcctService == 4 || CheckAcctService == 5 || CheckAcctService == 6)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\tThat is not a valid choice, please try again: ";
      cin >> CheckAcctService;
	  }

    cout << endl;

    return CheckAcctService;
  }

  //DONE
  void checkMenuResult(){
    int checkChoice = checkAccMenu();
    int cap;

    while(checkChoice != 6){

      switch(checkChoice){
      ///deposit
      case 1:
        if(lock == 'l' || lock == 'L'){
          cout << "\t| The account is currently locked!" << endl;
          cout << "\t| Deposit unsuccessful." << endl << endl;
        }else{
          int depositAmt;

          cout << "\tEnter the amount to deposit: ";
          cin >> depositAmt;

          if((balance + depositAmt) > maxCap){
            cout << "\t| The account exceeds max capacity!" << endl;
            cout << "\t| Deposit unsuccessful." << endl << endl;
          }else{
            balance += depositAmt;
            cout << "\t| Deposit was successful." << endl;
            cout << "\t| The current balance is: " << balance << endl << endl;
          }
        }
        break;

      //withdraw
      case 2:
        if(lock == 'l' || lock == 'L'){
          cout << "\t| The account is currently locked!" << endl;
          cout << "\t| Withdrawl unsuccessful." << endl << endl;
        }else{
          withdraw();
        }
        break;

      //Max Capacity
      case 3:
        cout << "Enter the new maximum capacity: ";
        cin >> cap;

        if(cap >= balance){
          maxCap = cap;
          cout << "\t| Max capacity successfully changed.";
        }else{
          cout << "\t| Max capacity entered is less than current balance." << endl;
          cout << "\t| Max capacity failed to be changed.";
        }
        
        cout << endl << endl;
        break;

      //Lock Sub-Account
      case 4:
        lock = 'l';
        cout << "\t| Sub-account " << subAccNum << " is now locked!" << endl << endl;
        break;

      //Unlock Sub-Account
      case 5:
        lock = 'u';
        cout << "\t| Sub-account " << subAccNum << " is unlocked now!" << endl << endl;
        break;
      }
      
      checkChoice = checkAccMenu();
      
    }
  }

  void printSubAccInfo(){
    SubAccount::printSubAccInfo();

    cout << "\t| The Maximum capacity is: " << maxCap << endl
    << "\t| The sub-account is ";

    if(lock == 'l' || lock == 'L'){
      cout << "locked."<< endl;
    }else{
      cout << "not locked."<< endl;
    }
  }

  /*
  bool depositExceedsCap(){
    int depositAmt;

    cout << "\tEnter the amount to deposit: ";
    cin >> depositAmt;

    if((balance + depositAmt) > maxCap){
      return true;
    }

    return false;
  }
  */

private:
  int maxCap;
  char lock;
};

#endif