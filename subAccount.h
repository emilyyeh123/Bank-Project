#ifndef SUBACCOUNT_H
#define SUBACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

//parent class
class SubAccount{
public:
  //default constructor
  SubAccount(){
    balance = -9999;
    subAccNum = "N/A";
  }

  //constructor
	SubAccount(string accNum, int bal){
    balance = bal;
    subAccNum = accNum;
  }

  void printSubAccInfo(){
    cout << "\t| Sub-account number: " << subAccNum << endl
    << "\t| Balance: " << balance << endl;
  }

  void deposit(){
    int depositAmt;

    cout << "\tEnter the amount to deposit: ";
    cin >> depositAmt;

    balance += depositAmt;
    cout << "\t| Deposit was successful." << endl;
    cout << "\t| The current balance is: " << balance << endl << endl;
  }

  void withdraw(){
    int withdrawAmt;

    cout << "\tEnter the amount to withdraw: ";
    cin >> withdrawAmt;

    balance -= withdrawAmt;
    if(balance < 0){
      balance = 0;
    }
    cout << "\t| Withdraw was successful." << endl;
    cout << "\t| The current balance is: " << balance << endl << endl;
  }

  //getters & setters
  void setBalance(int bal){
    balance = bal;
  }
  void setSubAccNum(string accNum){
    subAccNum = accNum;
  }

  int getBalance(){
    return balance;
  }
  string getSubAccNum(){
    return subAccNum;
  }

protected:
	int balance;
  string subAccNum;
};

#endif