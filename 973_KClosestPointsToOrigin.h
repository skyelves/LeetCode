//
// Created by Ke Wang on 10/20/24.
//

#ifndef INC_973_KCLOSESTPOINTSTOORIGIN_H
#define INC_973_KCLOSESTPOINTSTOORIGIN_H

#include "solution.h"

class KClosestPointsToOrigin : public solution {
private:
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return getDistance(a) < getDistance(b);
        }
    };

    static int getDistance(vector<int> a) {
        return a[0] * a[0] + a[1] * a[1];
    }

public:

    vector<vector<int> > kClosest(vector<vector<int> > &points, int k) {
        priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
        for (vector<int> &point : points) {
            if (pq.empty() || pq.size() < k) {
                pq.push(point);
            } else {
                const vector<int> &tmp = pq.top();
                if (getDistance(point) < getDistance(tmp)) {
                    pq.pop();
                    pq.push(point);
                }
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

#endif //INC_973_KCLOSESTPOINTSTOORIGIN_H
