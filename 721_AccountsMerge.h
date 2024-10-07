//
// Created by Admin on 10/5/2024.
//

#ifndef LEETCODE_721_ACCOUNTSMERGE_H
#define LEETCODE_721_ACCOUNTSMERGE_H

#include "solution.h"

class AccountsMerge : public solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, string> emailToName;
    unordered_map<string, set<string> > parentToSets;

    void merge(string email0, string email1) {
        string parent0 = find(email0), parent1 = find(email1);
        if (parent0 != parent1) {
            parent[parent1] = parent0;
        }
    }

    string find(string email) {
        if (parent[email] == email) {
            return email;
        } else {
            string res = find(parent[email]);
            parent[email] = res;
            return res;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto &account : accounts) {
            emailToName[account[1]] = account[0];
            for (int i = 1; i < account.size(); ++i) {
                parent[account[i]] = account[i];
            }
        }

        for (auto &account : accounts) {
            for (int i = 2; i < account.size(); ++i) {
                merge(account[1], account[i]);
            }
        }

        for (auto &item : parent) {
            parentToSets[find(item.first)].insert(item.first);
        }

        vector<vector<string> > res;
        for (auto &currPair : parentToSets) {
            vector<string> tmp;
            tmp.push_back(emailToName[currPair.first]);
            for (const string &email : currPair.second) {
                tmp.push_back(email);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

#endif //LEETCODE_721_ACCOUNTSMERGE_H
