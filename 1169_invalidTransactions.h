//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1169_INVALIDTRANSACTIONS_H
#define LEETCODE_1169_INVALIDTRANSACTIONS_H

#include "solution.h"

class InvalidTransactions {
public:
    vector<string> invalidTransactions(vector<string> &transactions) {
        int len = transactions.size();
        vector<string> res;
        vector<string> name, city;
        vector<int> time, amount;
        vector<bool> visited(len, false);
        for (int i = 0; i < len; ++i) {
            int idx1 = transactions[i].find(',');
            int idx2 = transactions[i].find(',', idx1 + 1);
            int idx3 = transactions[i].find(',', idx2 + 1);
            int t = stoi(transactions[i].substr(idx1 + 1, idx2));
            int a = stoi(transactions[i].substr(idx2 + 1, idx3));
            if (a > 1000) {
                visited[i] = true;
                res.push_back(transactions[i]);
            }
            name.push_back(transactions[i].substr(0, idx1));
            time.push_back(t);
            amount.push_back(a);
            city.push_back(transactions[i].substr(idx3, transactions[i].size()));
        }
        for (int i = 0; i < len; ++i) {
            if (visited[i]) continue;
            for (int j = 0; j < len; ++j) {
                if (i != j && name[i] == name[j] && city[i] != city[j] && abs(time[i] - time[j]) <= 60) {
                    if (!visited[i]) {
                        visited[i] = true;
                        res.push_back(transactions[i]);
                    }
                    if (!visited[j]) {
                        visited[j] = true;
                        res.push_back(transactions[j]);
                    }
                }
            }
        }
        return res;
    }
};

#endif //LEETCODE_1169_INVALIDTRANSACTIONS_H
