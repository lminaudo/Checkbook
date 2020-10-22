//
// Created by Logan Minaudo on 10/21/20.
//

#ifndef HW2_CSC275_GIT_CHECKBOOK_H
#define HW2_CSC275_GIT_CHECKBOOK_H

#include <iostream>
#include "Check.h"


class CheckBook : public Check {//account that holds all the checks and balance
public:
    CheckBook() : balance(0), numofChecks(0), checkBookSize(4),
                  lastDeposit(0) { chkptr = new Check[checkBookSize]; }//initializing the checkbook
    CheckBook(float amount) : balance(amount), numofChecks(0), checkBookSize(2), lastDeposit(
            amount) { chkptr = new Check[checkBookSize]; }//initializing the checkbook with a balance
    ~CheckBook();

    CheckBook(const CheckBook &obj);

    void setBalance(float abal) {
        balance = abal;
        lastDeposit = abal;
    }

    void setLastDeposit(float ldeposit) { lastDeposit = ldeposit; }

    void setNumOfChecks(int nchecks) { numofChecks = nchecks; }

    void setCheckBookSize(int csize) { checkBookSize = csize; }

    const float getBalance() { return balance; }

    const float getLastDeposit() { return lastDeposit; }

    const int getNumOfChecks() { return numofChecks; }

    const int getCheckBookSize() { return checkBookSize; }

    CheckBook operator=(CheckBook &cb1);

    void deposit(float amount);

    bool writeCheck(Check c_amount);

    void displayChecks() const;

private:
    Check *chkptr;//array that will hold all the checks
    float balance, lastDeposit;
    int numofChecks, checkBookSize;
};

#endif //HW2_CSC275_GIT_CHECKBOOK_H
