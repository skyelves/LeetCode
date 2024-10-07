//
// Created by Admin on 10/6/2024.
//

#ifndef LEETCODE_752_OPENTHELOCK_H
#define LEETCODE_752_OPENTHELOCK_H

#include "solution.h"

class OpenTheLock : public solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res = 0;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> curr;
        curr.push("0000");
        while(!curr.empty()) {
            queue<string> next;
            while(!curr.empty()) {
                string password = curr.front();
                curr.pop();
                if (password == target) {
                    return res;
                } else if (visited.find(password) != visited.end()) {
                    continue;
                } else {
                    visited.insert(password);
                    for (int i = 0; i < 4; ++i) {
                        string nextPassword = password;
                        if (password[i] == '0') {
                            nextPassword[i] = '1';
                            next.push(nextPassword);
                            nextPassword[i] = '9';
                            next.push(nextPassword);
                        } else if (password[i] == '9') {
                            nextPassword[i] = '0';
                            next.push(nextPassword);
                            nextPassword[i] = '8';
                            next.push(nextPassword);
                        } else {
                            nextPassword[i] = password[i] + 1;
                            next.push(nextPassword);
                            nextPassword[i] = password[i] - 1;
                            next.push(nextPassword);
                        }
                    }
                }
            }
            curr = next;
            ++res;
        }
        return -1;
    }
};

#endif //LEETCODE_752_OPENTHELOCK_H
