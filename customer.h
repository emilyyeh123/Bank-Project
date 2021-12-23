//this class is done!
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer{
public:
  Customer(){
    cFirst = "Bill";
    cLast = "Stevenson";
    cSSN = "000-00-0000";
  }

  Customer(string first, string last, string ssn){
    cFirst = first;
    cLast = last;
    cSSN = ssn;
  }

  void createCustomer(){
    cout << "\tEnter the first name of the account holder: ";
    cin >> cFirst;
    cout << "\tEnter the last name of the account holder: ";
    cin >> cLast;
    cout << "\tEnter the SSN of the account holder: ";
    cin >> cSSN;
    cout << endl;
  }

/*
  void testCreateCustomer(){
    cout << "\tEnter the first name of the account holder: " << cFirst << endl
    << "\tEnter the last name of the account holder: " << cLast << endl
    << "\tEnter the SSN of the account holder: " << cSSN << endl << endl;
  }
*/

  void setCFirst(string first){
    cFirst = first;
  }
  void setCLast(string last){
    cLast = last;
  }
  void setCSSN(string ssn){
    cSSN = ssn;
  }

  string getCFirst(){
    return cFirst;
  }
  string getCLast(){
    return cLast;
  }
  string getCSSN(){
    return cSSN;
  }

private:
  string cFirst;//customer first name
  string cLast;//customer last name
  string cSSN;//customer holder SSN
};

#endif