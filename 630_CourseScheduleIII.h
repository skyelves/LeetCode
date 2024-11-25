//
// Created by Ke Wang on 11/24/24.
//

#ifndef INC_630_COURSESCHEDULEIII_H
#define INC_630_COURSESCHEDULEIII_H

#include "solution.h"

class CourseScheduleIII : public solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int sum = 0;
        priority_queue<int> pq;
        for (auto &tmp : courses) {
            sum += tmp[0];
            pq.push(tmp[0]);
            if (sum > tmp[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }

    void check() {
        vector<vector<int>> courses{{5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19}};
        cout << scheduleCourse(courses) << endl;
    }
};

#endif //INC_630_COURSESCHEDULEIII_H
