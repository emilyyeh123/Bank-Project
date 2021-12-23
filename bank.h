//this class is done!
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
using namespace std;

class Bank{
public:
  void createBank(){
    cout << "Enter the name of the bank: ";
    cin >> bankName;
    cout << "Enter the address of the bank: ";
    cin >> address;
    cout << "Enter the working hours: ";
    cin >> hoursOfOp;
    cout << endl;
  }

  /*
  void testCreateBank(){
    cout << "Enter the name of the bank: ";
    bankName = "Student Bank Co.";
    cout << bankName << endl;
    cout << "Enter the address of the bank: ";
    address = "1 Main St., Stockton, CA 95201";
    cout << address << endl;
    cout << "Enter the working hours: ";
    hoursOfOp = "Mon - Fri 8:00am - 5:00am";
    cout << hoursOfOp << endl;
    cout << endl;
  }
  */

  int menu(){
    cout << "Eligible services for " << bankName << endl;

    cout << "\t(1) See Number of Bank Accounts" << endl
    << "\t(2) See Number of Saving Accounts" << endl
    << "\t(3) See Number of Checking Accounts" << endl
    << "\t(4) Open a Bank Account" << endl
    << "\t(5) Close a Bank account" << endl //using its bank account number
    << "\t(6) Modify a Bank Account" << endl //See info & modify based on account number
    << "\t(7) Detailed Information of All Bank Accounts" << endl //See detailed information of all accounts
    << "\t(8) Brief Account Information" << endl
    << "\t(9) Exit" << endl;

    cout << "Please enter your selection: ";
    cin >> service;
    while (cin.fail() || !(service == 1 || service == 2 || service == 3 || service == 4 || service == 5 || service == 6 || service == 7 || service == 8 || service == 9)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "That is not a valid choice, please try again: ";
      cin >> service;
	  }

    cout << endl;

    return service;
  }

  string getBankName(){
    return bankName;
  }

  void displayBankInfo(int totBalance, int numBankAccts){
    cout << "\t| Bank Name: " << bankName << endl
    << "\t| Bank Address: " << address << endl
    << "\t| Bank Working Hours: " << hoursOfOp << endl
    << "\t| Aggregated Balance: $" << totBalance << endl
    << "\t| Consists of " << numBankAccts << " Bank Accounts" << endl << endl;
  }

private:
  string bankName;
  string address;
  string hoursOfOp;
  int service;
};

#endif
