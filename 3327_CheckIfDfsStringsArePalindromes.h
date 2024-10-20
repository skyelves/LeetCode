//
// Created by Ke Wang on 10/19/24.
//

#ifndef INC_3327_CHECKIFDFSSTRINGSAREPALINDROMES_H
#define INC_3327_CHECKIFDFSSTRINGSAREPALINDROMES_H

#include "solution.h"

class CheckIfDfsStringsArePalindroms : public solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        // construct children
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }

        // construct dfsStr
        vector<pair<int, int>> range(n);
        string tmp = "";
        dfs(0, s, tmp, children, range);

        // find all the palindromes (d1 and d2) using manacher
        vector<int> d1(tmp.size(), 0), d2(tmp.size(), 0);
        manacher(tmp, d1, d2);

        // set res according to the d1 and d2
        vector<bool> res(n, false);
        for (int i = 0; i < n; ++i) {
            int l = range[i].first, r = range[i].second, mid = (l + r) / 2;
            int len = r - l;
            if (len % 2 == 1) {
                res[i] = d1[mid] >= len / 2 + 1;
            } else {
                res[i] = d2[mid] >= len / 2;
            }
        }
        return res;
    }

    void dfs(int root, string &s, string &tmp, vector<vector<int>> &children, vector<pair<int, int>> &range) {
        int idx = tmp.size();
        for (auto child : children[root]) {
            dfs(child, s, tmp, children, range);
        }

        tmp += s[root];
        range[root] = {idx, tmp.size()};
    }

    void manacher(string &s, vector<int> &d1, vector<int> &d2) {
        int n = s.size();
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
    }
};

#endif //INC_3327_CHECKIFDFSSTRINGSAREPALINDROMES_H
