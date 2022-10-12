//
// Created by 王柯 on 10/12/22.
//

#ifndef LEETCODE_1507_REFORMATDATE_H
#define LEETCODE_1507_REFORMATDATE_H

#include "solution.h"

class ReformatDate : public solution {
public:
    string reformatDate(string date) {
        map<string, string> mm;
        vector<string> mon{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        vector<string> monNum{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
        for (int i = 0; i < 12; ++i) {
            mm.insert({mon[i], monNum[i]});
        }
        istringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;
        if (day[1] >= 'a' && day[1] <= 'z') {
            // example: 1st
            day = "0" + day;
        }
        day = day.substr(0, 2);
        return year + "-" + mm[month] + "-" + day;
    }

    void check() {

    }
};

#endif //LEETCODE_1507_REFORMATDATE_H
