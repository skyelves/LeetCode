//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_412_FIZZBUZZ_H
#define LEETCODE_412_FIZZBUZZ_H

#include "solution.h"

class FizzBuzz : public solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                res[i - 1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                res[i - 1] = "Fizz";
            } else if (i % 5 == 0) {
                res[i - 1] = "Buzz";
            } else {
                stringstream ss;
                ss << i;
                res[i - 1] = ss.str();
            }
        }
        return res;
    }
};

#endif //LEETCODE_412_FIZZBUZZ_H
