#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "saving.h"
#include "checking.h"
#include "subAccount.h"
using namespace std;

static unsigned int savAccCount = 1000;
static unsigned int checkAccCount = 6000;

class BankAccount{
public:
  //function: DONE! (remember to come back and delete test input)
  void createAcc(unsigned int accNumber){
    cust.createCustomer();
    //cust.testCreateCustomer();//DELETE IN FINAL PRODUCT

    setAccNum(accNumber);

    cout <<"\t| A new bank account " << accNum << " was successfully created." << endl << endl;
  }

  //function: DONE!
  int accMenu(){
    cout << "Eligible services for Bank Account " << accNum << endl;

    cout << "\t(1) Open a Saving Sub-Account" << endl
    << "\t(2) Open a Checking Sub-Account" << endl
    << "\t(3) Modify a Sub-Account" << endl
    << "\t(4) Close a Sub-Account" << endl
    << "\t(5) Detailed Information of All Sub-Accounts" << endl //using its bank account number
    << "\t(6) Brief Account Information" << endl //See info & modify based on account number
    << "\t(7) Exit" << endl; //See detailed information of all accounts

    cout << "Please enter your selection: ";
    cin >> acctService;
    while (cin.fail() || !(acctService == 1 || acctService == 2 || acctService == 3 || acctService == 4 || acctService == 5 || acctService == 6 || acctService == 7)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\tThat is not a valid choice, please try again: ";
      cin >> acctService;
	  }

    cout << endl;

    return acctService;
  }

  void accMenuResult(){
    int accChoice = accMenu();
    Saving tempSav;
    Checking tempCheck;
    int numSavAcc, numCheckAcc;
    bool firstSav = false;
    
    while(accChoice != 7){

      switch(accChoice){
      //open saving acct - DONE
      case 1:
        if(saVec.size() > 0){
          tempSav.createSavAcc(savAccCount, false);
        }else{
          tempSav.createSavAcc(savAccCount, true);
        }
        saVec.push_back(tempSav);
        savAccCount++;
        break;

      //open checking acct - DONE
      case 2:
        tempCheck.createCheckAcc(checkAccCount);
        caVec.push_back(tempCheck);
        checkAccCount++;
        break;

      //modify sub acct - DONE
      case 3:
        modSubAcc(saVec, caVec);
        break;

      //close sub acct - DONE
      case 4:
        closeSubAcc(saVec, caVec);
        break;

      //detailed sub acct info
      case 5:
        displayDetailedAccInfo();
        break;

      //brief acct info
      case 6:
        displayBriefAccInfo();
        cout << endl;
        break;
      }

      accChoice = accMenu();

    }

    cout << "\t| End of service for bank-account " << accNum << endl << endl;

  }

  void modSubAcc(vector<Saving>& sAccVec, vector<Checking>& cAccVec){
    string modNum;
    bool found = false;

    if(sAccVec.size() == 0 && cAccVec.size()==0){
      cout <<"\tNo Sub Accounts have been created yet." << endl
      << "\tPlease create at least one sub account before trying this option again." << endl << endl;
    }else{
      cout << "\tEnter the bank account number to be modified: ";
      cin >> modNum;
      cout << endl;

      //find account to modify
      for(int i = 0; i < sAccVec.size(); i++){//if savings acct
        if(modNum == sAccVec.at(i).getSubAccNum()){
          found = true;
          sAccVec.at(i).savMenuResult();
          break;
        }
      }

      for(int i = 0; i < cAccVec.size(); i++){//if checking acct
        if(modNum == cAccVec.at(i).getSubAccNum()){
          found = true;
          cAccVec.at(i).checkMenuResult();
          break;
        }
      }

      if(!found){
        cout << "\t| Bank Account " << modNum << " does not exist," << endl
        << "\t| please use an existing account number next time" << endl << endl;
      }
    }
  }

  void closeSubAcc(vector<Saving>& sAccVec, vector<Checking>& cAccVec){
    string closeAccNum;
    bool found = false;

    if(sAccVec.size() == 0 && cAccVec.size()==0){
      cout <<"\tNo Sub Accounts have been created yet." << endl
      << "\tPlease create at least one sub account before trying this option again." << endl << endl;
    }else{
      cout << "\tEnter the bank account number to be closed: ";
      cin >> closeAccNum;

      //find account to modify
      for(int i = 0; i < sAccVec.size(); i++){//if savings acct
        if(closeAccNum == sAccVec.at(i).getSubAccNum()){
          found = true;
          sAccVec.erase(sAccVec.begin() + i);
        }
      }

      for(int i = 0; i < cAccVec.size(); i++){//if checking acct
        if(closeAccNum == cAccVec.at(i).getSubAccNum()){
          found = true;
          cAccVec.erase(cAccVec.begin() + i);
        }
      }

      if(found){
        cout << "\t| Bank Account " << closeAccNum << " successfully closed" << endl << endl;
      }else{
        cout << "\t| Bank Account " << closeAccNum << " does not exist," << endl
        << "\t| please use an existing account number next time" << endl << endl;
      }
    }
  }

  void displayDetailedAccInfo(){
    //QuickSort(saVec, int i, int k);
    //QuickSort(caVec, int i, int k);

    for(Saving savAcc : saVec){
      savAcc.printSubAccInfo();
      cout << endl;
    }

    cout << endl;

    for(Checking checkAcc : caVec){
      checkAcc.printSubAccInfo();
      cout << endl;
    }
    cout << endl;
  }

  void displayBriefAccInfo(){
    cout << "\t| Aggregated Balance of the bank account : " << accNum << " with " << getSubAccTot() << " Sub Accounts is $" << getSubAccBalance() << endl;
    //<< getTotalBal() << endl;
  }

/*
  //sorting Algorithm
  template <typename t>
  int Partition(vector<t> &vec, int i, int k){
    int midpoint = i+(k -i)/2;
    t pivot = vec.at(midpoint);
    int l = i;
    int h = k;
    bool done = false;

    while(!done){
      while(vec.at(l).getSubAccBalance() < pivot.getSubAccBalance()){
        ++l;
      }

      while(pivot.getSubAccBalance() < vec.at(h).getSubAccBalance()){
        --h;
      }

      if(l >=h){
        done =true;
      }else{
        t temp = vec.at(l);
        vec.at(l) = vec.at(h);
        vec.at(h) = temp;
        ++l;
        --h;
      }
    }

    return h;
  }
  template <typename t>
  void QuickSort(vector<t> &vec, int i, int k){
    int j;

    if(i>=k){
      return;
    }

    j = Partition(vec,i,k);
    QuickSort(vec,i,j);  
    QuickSort(vec,j +1,k);
  }
*/

  //use in main.cpp closeAcc function
  void closeAllSubAcc(){
    caVec.clear();
    saVec.clear();
  }

  void setAccNum(unsigned int accNumber){
    accNum = "BNK" + to_string(accNumber);
  }

  int getSubAccBalance(){
    int total = 0;

    for(Saving savAcc : saVec){
      total += savAcc.getBalance();
    }

    for(Checking checkAcc : caVec){
      total += checkAcc.getBalance();
    }

    return total;
  }

  string getAccNum(){
    return accNum;
  }
  int getSavAccTot(){
    return saVec.size();
  }
  int getCheckAccTot(){
    return caVec.size();
  }
  int getSubAccTot(){
    return (saVec.size()+caVec.size());
  }


private:
  Customer cust;
  string accNum;
  int acctService;

  vector<Checking> caVec;
  vector<Saving> saVec;
};

#endif

/*
FUNCTIONS:
accountNum()
customerInfo() - first name, last name, SSN
savingAcct()
CheckingAcct()

AVAILABLE SERVICES:
(1) Open saving sub-account
(2) Open checking sub-account
(3) Modify a sub-account
(4) Close a sub-account
(5) Detailed bank account info with its sub-accounts sorted based on their balances
(6) Brief bank account info
*/