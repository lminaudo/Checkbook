/*************************************************************************
 ** Author : Logan Minaudo
** Program : HW2, Q1 For upload
** Date Created : Oct 16, 2020
** Date Last Modified : Oct 21, 2020
** Usage : No command line arguments
**
** Problem :
Creates a Checkbook from the Checkbook class made up of individual checks (structs).
 From there the program take a preset amount of money per check and writes checks while
 subtracting the amount from the checkbook balance.
 Commented out code also allows for users to designate the balance of the account
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include "CheckBook.h"

using std::string;
using std::cout;
using std::endl;

void TestCheck(CheckBook &cb, float Bal) {
    //this checks to see if the code is running correctly
    if (cb.getBalance() <= 0)//This checks to see if there needs to be a change in the balance of the account.
        cb.setBalance(Bal);
    Check check1(50, 1);//tesk check. A constant value.
    for (int i = 0; i < cb.getCheckBookSize(); i++) {
//        if(cb.getNumOfChecks()==4)
//            cb.deposit(600);//just here to check if deposit function works.
        cb.writeCheck(check1);
    }
    cb.displayChecks();//takes you to the displayChecks function to print out the checks from most recent.
}

int main() {
    CheckBook cb1, cb2(500);//comment this out to enable the second checkbook.
    float balance = 1000;
//    cout<<"Enter the balance of CheckBook 1: ";
//    std::cin>>balance;//allows user to designate balance of the checkbook before writing checks.
    TestCheck(cb1, balance);
    TestCheck(cb2, NULL);//this was used to try two checkbooks being tested one after the other.
}



