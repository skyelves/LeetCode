//
// Created by 王柯 on 12/3/22.
//

#ifndef LEETCODE_1115_PRINTFOOBARALTERNATELY_H
#define LEETCODE_1115_PRINTFOOBARALTERNATELY_H


#include "solution.h"

class FooBar {
private:
    int n;
    mutex first, second;

public:
    FooBar(int n) {
        this->n = n;
        second.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            first.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            second.unlock();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            second.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            first.unlock();
        }
    }
};

#endif //LEETCODE_1115_PRINTFOOBARALTERNATELY_H
