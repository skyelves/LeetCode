//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1169_INVALIDTRANSACTIONS_H
#define LEETCODE_1169_INVALIDTRANSACTIONS_H

#include "solution.h"

class InvalidTransactions {
public:
    class transaction {
    public:
        string name;
        string city;
        int time;
        int amount;
        transaction(string _name, string _city, int _time, int _amount) : name(_name), city(_city), time(_time), amount(_amount) {}
    };

    vector<string> invalidTransactions(vector<string> &transactions) {
        int len = transactions.size();
        vector<string> res;
        unordered_map<string, vector<transaction>> mm;
        vector<transaction> vv;
        for (int i = 0; i < len; ++i) {
            stringstream ss(transactions[i]);
            string name, city, timeStr, amountStr;
            getline(ss, name, ',');
            getline(ss, timeStr, ',');
            getline(ss, amountStr, ',');
            getline(ss, city, ',');
            int t = stoi(timeStr);
            int a = stoi(amountStr);
            auto tmp = transaction(name, city, t, a);
            mm[name].push_back(tmp);
            vv.emplace_back(tmp);
        }
        for (int i = 0; i < len; ++i) {
            if (vv[i].amount > 1000) {
                res.push_back(transactions[i]);
                continue;
            }
            for (auto &j : mm[vv[i].name]) {
                if (vv[i].city != j.city && abs(vv[i].time - j.time) <= 60) {
                    res.push_back(transactions[i]);
                    break;
                }
            }
        }
        return res;
    }
};

#endif //LEETCODE_1169_INVALIDTRANSACTIONS_H
