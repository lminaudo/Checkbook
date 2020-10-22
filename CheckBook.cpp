//
// Created by Logan Minaudo on 10/21/20.
//

#include "CheckBook.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::string;

CheckBook::~CheckBook() {
    delete[] chkptr;//deconstructor to free memory after the program is terminated.
}

CheckBook::CheckBook(const CheckBook &obj) {//copy constructor
    checkBookSize = obj.checkBookSize;
    numofChecks = obj.numofChecks;
    chkptr = new Check[checkBookSize];
    for (int i = 0; i < numofChecks; i++)
        chkptr[i] = obj.chkptr[i];

}

CheckBook CheckBook::operator=(
        CheckBook &cb1) {//this is a set operator that will allow to set a checkbook equal to another checkbook.
    if (this == &cb1)
        return *this;
    delete[] chkptr;
    checkBookSize = cb1.checkBookSize * 2;
    numofChecks = cb1.numofChecks;
    chkptr = new Check[checkBookSize];
    for (int i = 0; i < numofChecks; i++)
        chkptr[i] = cb1.chkptr[i];
    return *this;
}

void CheckBook::deposit(float amount) {//deposits money into an account
    balance += amount;
    lastDeposit = amount;
}

bool CheckBook::writeCheck(Check c_amount) {//c_amount=(1,'',50), start with 4 checks
    if (c_amount < balance or balance == 0)
        return false;
    if (checkBookSize / 2 == numofChecks) {
        //if half of the checkbook is used then this will double the size of the array
        //and tell the user another checkbook has been ordered
        checkBookSize *= 2;
        Check *newArray = new Check[checkBookSize];
        for (int i = 0; i < numofChecks; i++)
            newArray[i] = chkptr[i];
        delete[] chkptr;
        chkptr = newArray;
        cout << "New checkbook ordered" << endl;
    }
    string memo[11] = {"hello", "whats up?", "hours", "wedding", "baby shower", "pizza", "children's hospital",
                       "barber shop", "plumber", "hobbit", "true"};
    chkptr[numofChecks] = c_amount;
    chkptr[numofChecks].setCheckNum(numofChecks + 1);
    balance -= c_amount.getCheckAmount();
    chkptr[numofChecks].setMemo(memo[rand() % 11]);
    numofChecks++;
    //cout<<chkptr[numofChecks-1]<<endl;//this is for printing the check directly after writing the check.
    c_amount.setCheckNum(c_amount.getCheckNum() + 1);
    return true;
}

void CheckBook::displayChecks() const {//Displays the checks written within the checkbook.
    cout << "--------------------------" << endl;
    for (int i = numofChecks; i > 0; i--)
        cout << chkptr[i - 1];
}

bool Check::operator<(float amount) const {//checks to see if the chek amount is greater than the amount.
    if (amount < CheckAmount)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &output,
                         Check &c1) {//this allows the code to print out a whole check object with the overloaded operator.
    output << c1.CheckNum << " " << c1.CheckAmount << " " << c1.CheckMemo << std::endl;
    return output;
}


