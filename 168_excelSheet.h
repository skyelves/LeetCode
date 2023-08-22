//
// Created by 王柯 on 8/22/23.
//

#ifndef LEETCODE_168_EXCELSHEET_H
#define LEETCODE_168_EXCELSHEET_H

#endif //LEETCODE_168_EXCELSHEET_H

#include "solution.h"

class ExcelSheet : public solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0) {
            columnNumber -= 1;
            res = (char)('A' + columnNumber % 26) + res;
            columnNumber /= 26;
        }
        return res;
    }

    void check() {
        cout << convertToTitle(701) << endl;
    }
};