//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1279_TRAFFICLIGHTCONTROLLEDINTERSECTION_H
#define LEETCODE_1279_TRAFFICLIGHTCONTROLLEDINTERSECTION_H

#include "solution.h"

class TrafficLight {
public:
    int greenID;
    mutex m1;

    TrafficLight() {
        greenID = 1;
    }

    void carArrived(
            int carId,                   // ID of the car
            int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
            int direction,               // Direction of the car
            function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
            function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        m1.lock();
        if (greenID != roadId) {
            greenID = roadId;
            turnGreen();
        }
        crossCar();
        m1.unlock();
    }
};

#endif //LEETCODE_1279_TRAFFICLIGHTCONTROLLEDINTERSECTION_H
