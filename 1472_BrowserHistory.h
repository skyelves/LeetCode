//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1472_BROWSERHISTORY_H
#define LEETCODE_1472_BROWSERHISTORY_H

#include "solution.h"

class BrowserHistory {
public:
    vector<string> browser;
    int curr;

    BrowserHistory(string homepage) {
        browser.push_back(homepage);
        curr = 1;
    }

    void visit(string url) {
        if (browser.size() > curr) {
            browser[curr] = url;
            curr++;
            browser.erase(browser.begin() + curr, browser.end());
        } else {
            browser.push_back(url);
            curr++;
        }
    }

    string back(int steps) {
        curr = max(curr - steps, 1);
        return browser[curr - 1];
    }

    string forward(int steps) {
        int maxCurr = browser.size();
        curr = min(maxCurr, curr + steps);
        return browser[curr - 1];
    }
};


#endif //LEETCODE_1472_BROWSERHISTORY_H
