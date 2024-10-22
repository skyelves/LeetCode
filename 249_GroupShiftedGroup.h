//
// Created by Ke Wang on 10/21/24.
//

#ifndef INC_249_GROUPSHIFTEDGROUP_H
#define INC_249_GROUPSHIFTEDGROUP_H

#include "solution.h"

class GroupShiftedGroup : public solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        vector<vector<string>> res;
        vector<vector<int>> diff(n);
        for (int i = 0; i < n; ++i) {
            string &s = strings[i];
            vector<int> tmpDiff(s.size() - 1, 0);
            for (int j = 1; j < s.size(); ++j) {
                tmpDiff[j - 1] = getDiff(s[j], s[j - 1]);
            }
            diff[i] = tmpDiff;
        }

        map<vector<int>, int> groupMap;
        for (int i = 0; i < n; ++i) {
            auto iter = groupMap.find(diff[i]);
            if (iter != groupMap.end()) {
                res[iter->second].push_back(strings[i]);
            } else {
                vector<string> newGroup{strings[i]};
                res.push_back(newGroup);
                groupMap.insert({diff[i], res.size() - 1});
            }
        }
        return res;
    }

    inline int getDiff(char a, char b) {
        return a - b < 0 ? a - b + 26 : a - b;
    }

};

#endif //INC_249_GROUPSHIFTEDGROUP_H
