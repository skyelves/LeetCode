//
// Created by 王柯 on 8/3/22.
//

#ifndef LEETCODE_729_MYCALENDAR_H
#define LEETCODE_729_MYCALENDAR_H

#include "solution.h"

class MyCalendar : public solution {
public:
    list<pair<int, int>> bookings;

    MyCalendar() {

    }

    bool book(int start, int end) {
        bool flag = true;
        for (auto i : bookings) {
            if (start >= i.first) {
                if (start < i.second) {
                    flag = false;
                    break;
                }
            } else if (end > i.first) {
                flag = false;
                break;
            }
        }
        if (flag) {
            bookings.push_back({start, end});
        }
        return flag;
    }

    void check() {
        cout << book(10, 20) << endl;
        cout << book(15, 25) << endl;
        cout << book(20, 30) << endl;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

#endif //LEETCODE_729_MYCALENDAR_H
