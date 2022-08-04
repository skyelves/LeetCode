//
// Created by 王柯 on 8/4/22.
//

#ifndef LEETCODE_731_MYCALENDARTWO_H
#define LEETCODE_731_MYCALENDARTWO_H

#include "solution.h"

class MyCalendarTwo : public solution {
public:
    list<pair<int, int>> bookings;
    list<pair<int, int>> dup_bookings;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        bool flag = true;
        for (auto i : dup_bookings) {
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
            for (auto i : bookings) {
                if (start >= i.first) {
                    if (start < i.second) {
                        dup_bookings.push_back({start, min(end, i.second)});
                    }
                } else if (end > i.first) {
                    dup_bookings.push_back({i.first, min(end, i.second)});
                }

            }
            bookings.push_back({start, end});
        }
        return flag;
    }

    void check() {
        cout << book(10, 20) << endl;
        cout << book(50, 60) << endl;
        cout << book(10, 40) << endl;
        cout << book(5, 15) << endl;
        cout << book(5, 10) << endl;
        cout << book(25, 55) << endl;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

#endif //LEETCODE_731_MYCALENDARTWO_H
