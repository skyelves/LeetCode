//
// Created by 王柯 on 8/4/22.
//

#ifndef LEETCODE_732_MYCALENDARTHREE_H
#define LEETCODE_732_MYCALENDARTHREE_H

#include "solution.h"

class MyCalendarThree : public solution {
public:
    map<pair<int, int>, int> bookings;
    int maximum_intersec = 1;

    MyCalendarThree() {
    }

    int book(int start, int end) {
        bool flag = true;
        auto iter = bookings.begin();
        auto next_iter = iter;
        while (iter != bookings.end()) {
            next_iter = next(iter);
            auto booking = iter->first;
            int curr_intersec = iter->second;
            if (start >= booking.first) {
                if (start < booking.second) {
                    if (start > booking.first) {
                        bookings.insert({{booking.first, start}, curr_intersec});
                    }
                    flag = false;
                    if (curr_intersec + 1 > maximum_intersec) {
                        maximum_intersec = curr_intersec + 1;
                    }
                    bookings.erase(iter);
                    if (end < booking.second) {
                        bookings.insert({{end, booking.second}, curr_intersec});
                        bookings.insert({{start, end}, curr_intersec + 1});
                    } else if (end == booking.second) {
                        bookings.insert({{start, end}, curr_intersec + 1});
                    } else {
                        // end > booking.second
                        bookings.insert({{start, booking.second}, curr_intersec + 1});
                        book(booking.second, end);
                        break;
                    }
                }
            } else {
                // start < booking.first
                if (end > booking.first) {
                    flag = false;
                    if (curr_intersec + 1 > maximum_intersec) {
                        maximum_intersec = curr_intersec + 1;
                    }
                    bookings.erase(iter);
                    if (end > booking.second) {
                        bookings.insert({booking, curr_intersec + 1});
                        book(start, booking.first);
                        book(booking.second, end);
                        break;
                    } else if (end == booking.second) {
                        bookings.insert({booking, curr_intersec + 1});
                        book(start, booking.first);
                        break;
                    } else {
                        // end in [booking.first, booking.second)
                        bookings.insert({{booking.first, end}, curr_intersec + 1});
                        bookings.insert({{end, booking.second}, curr_intersec});
                        book(start, booking.first);
                        break;
                    }
                }
            }
            iter = next_iter;
        }

        if (flag) {
            bookings.insert({{start, end}, 1});
        }
        return maximum_intersec;
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
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

#endif //LEETCODE_732_MYCALENDARTHREE_H
