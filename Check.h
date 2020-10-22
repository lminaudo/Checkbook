//
// Created by Logan Minaudo on 10/21/20.
//

#ifndef HW2_CSC275_GIT_CHECK_H
#define HW2_CSC275_GIT_CHECK_H

#include <iostream>

class Check {//checks for the checkbook
public:
    Check() : CheckNum(0), CheckAmount(0), CheckMemo("") {}

    Check(float amount, int cnum) : CheckNum(cnum), CheckAmount(amount), CheckMemo("") {}

    bool operator<(float amount) const;

    friend std::ostream &operator<<(std::ostream &output, Check &c1);

    void setCheckNum(int cnum) { CheckNum = cnum; }

    void setMemo(std::string umemo) { CheckMemo = umemo; }

    void setCheckAmount(float amount) { CheckAmount = amount; }

    int getCheckNum() { return CheckNum; }

    std::string getMemo() { return CheckMemo; }

    float getCheckAmount() { return CheckAmount; }

private:
    int CheckNum;
    std::string CheckMemo;
    float CheckAmount;

};


#endif //HW2_CSC275_GIT_CHECK_H
