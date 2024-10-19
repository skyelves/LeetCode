//
// Created by Ke Wang on 10/19/24.
//

#ifndef INC_346_MOVINGAVERAGE_H
#define INC_346_MOVINGAVERAGE_H

#include "solution.h"

class MovingAverage : public solution {
private:
    int _size;
    int cnt;
    int sum;
    vector<int> data;

public:
    MovingAverage(int size) {
        cnt = 0;
        sum = 0;
        _size = size;
        data.resize(size);
    }

    double next(int val) {
        if (cnt < _size) {
            sum += val;
            data[cnt % _size] = val;
            ++cnt;
            return (double)sum / cnt;
        }

        sum += val;
        sum -= data[cnt % _size];
        data[cnt % _size] = val;
        ++cnt;
        return (double)sum / _size;
    }
};

#endif //INC_346_MOVINGAVERAGE_H
