//
// Created by 王柯 on 12/5/22.
//

#ifndef LEETCODE_772_BASICCALCULATORIII_H
#define LEETCODE_772_BASICCALCULATORIII_H

#include "solution.h"

class BasicCaculatorIII : public solution {
public:
    int calculate(string s) {
        int res = 0;


        return res;
    }

    void check() {
        string s = "2*(5+5*2)/3+(6/2+8)";
        int res = calculate(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_772_BASICCALCULATORIII_H
