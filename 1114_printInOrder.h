//
// Created by 王柯 on 12/3/22.
//

#ifndef LEETCODE_1114_PRINTINORDER_H
#define LEETCODE_1114_PRINTINORDER_H

#include <semaphore.h>
#include "solution.h"

class Foo {
public:
    sem_t firstDone, secondDone;

    Foo() {
        sem_init(&firstDone, 0, 0);
        sem_init(&secondDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstDone);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondDone);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

#endif //LEETCODE_1114_PRINTINORDER_H
