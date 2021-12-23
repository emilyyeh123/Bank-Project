//Emily Yeh

#include <iostream>
#include <string>
#include <vector>
//#include <Windows.h>

#include "bank.h"
#include "bankAccount.h"
#include "customer.h"
#include "checking.h"
#include "saving.h"
#include "subAccount.h"

using namespace std;

//global variables:
static unsigned int bankAccNum = 10000;

void openAcc(vector<BankAccount> &bAccVec){
  BankAccount tempAccount;

  tempAccount.createAcc(bankAccNum);//create new acct
  bAccVec.push_back(tempAccount);//add new account to vector
  bankAccNum++;//increment num of accts

  //account.accMenuResult();
  bAccVec.back().accMenuResult();
}

void closeAcc(vector<BankAccount> &bAccVec){
  string closeAccNum;
  bool found = false;

  if(bAccVec.size() == 0){
    cout <<"\tNo Bank Accounts have been created yet." << endl
    << "\tPlease create at least one account before trying this option again." << endl << endl;
  }else{
    cout << "\tEnter the bank account number to be closed: ";
    cin >> closeAccNum;
    for(int i = 0; i < bAccVec.size(); i++){
      if(closeAccNum == bAccVec.at(i).getAccNum()){
        found = true;
        bAccVec.at(i).closeAllSubAcc();
        bAccVec.erase(bAccVec.begin() + i);
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

void modifyAcc(vector<BankAccount> &bAccVec){
  string modNum;
  bool found = false;

  if(bAccVec.size() == 0){
    cout <<"\tNo Bank Accounts have been created yet." << endl
    << "\tPlease create at least one account before trying this option again." << endl << endl;
  }else{
    cout << "\tEnter the bank account number to be modified: ";
    cin >> modNum;
    cout << endl;

    for(int i = 0; i < bAccVec.size(); i++){
      if(modNum == bAccVec.at(i).getAccNum()){
        found = true;
        bAccVec.at(i).accMenuResult();
        break;
      }
    }

    if(!found){
      cout << "\t| Bank Account " << modNum << " does not exist," << endl
      << "\t| please use an existing account number next time" << endl << endl;
    }
  }
}

/*
int Partition(vector<BankAccount> &vec, int i, int k){
  int midpoint = i+(k -i)/2;
  BankAccount pivot = vec.at(midpoint);
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
      BankAccount temp = vec.at(l);
      vec.at(l) = vec.at(h);
      vec.at(h) = temp;
      ++l;
      --h;
    }
  }

  return h;
}

void QuickSort(vector<BankAccount> &vec, int i, int k){
  int j;

  if(i>=k){
    return;
  }

  j = Partition(vec,i,k);
  QuickSort(vec,i,j);  
  QuickSort(vec,j +1,k);
}
*/

int main(){
  Bank bank;
  int menuOption;
  int numSavAcc;
  int numCheckAcc;
  vector<BankAccount> baVec;
  unsigned int totBalance;

  bank.createBank();
  //bank.testCreateBank();//DELETE IN FINAL PRODUCT
  menuOption = bank.menu();
  //cout << "The chosen menu option is: " << menuOption;

  while(menuOption != 9){

    switch(menuOption){

    case 1:
      cout << "\t| The Number of Bank Accounts is " << baVec.size() << endl << endl;
      //DONE
      break;

    case 2:
      numSavAcc = 0;
      for(BankAccount i : baVec){
        numSavAcc += i.getSavAccTot();
        //cout << "\tadding: " << i.getSavAccTot() << endl;//to be DELETED
      }
      cout << "\t| The Number of Saving Accounts is " << numSavAcc << endl << endl;
      //DONE
      break;
    
    case 3:
      numCheckAcc = 0;
      for(BankAccount i : baVec){
        numCheckAcc += i.getCheckAccTot();
      }
      cout << "\t| The Number of Saving Accounts is " << numCheckAcc << endl << endl;
      //DONE
      break;
    
    case 4:
      openAcc(baVec);
      //DONE!
      break;
    
    case 5:
      closeAcc(baVec);
      //DONE
      break;
    
    case 6:
      modifyAcc(baVec);
      //DONE!
      break;
    
    case 7:
      totBalance = 0;
      for(BankAccount totAccBalance : baVec){
        totBalance += totAccBalance.getSubAccBalance();
      }
      bank.displayBankInfo(totBalance, baVec.size());
      break;
    
    case 8:
      totBalance = 0;
      for(BankAccount totAccBalance : baVec){
        totBalance += totAccBalance.getSubAccBalance();
      }
      bank.displayBankInfo(totBalance, baVec.size());
      cout << endl;

      //QuickSort(baVec, 0, (baVec.size()-1));
      
      for(BankAccount print : baVec){
        print.displayBriefAccInfo();
      }
      
      cout << endl;
      break;
      
    }

    menuOption = bank.menu();

  }

  cout << "\t| End of service for bank " << bank.getBankName();

  //system("pause");
  return 0;
}