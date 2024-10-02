//
// Created by Admin on 10/1/2024.
//

#ifndef LEETCODE_269_ALIENDICTIONARY_H
#define LEETCODE_269_ALIENDICTIONARY_H

#include "solution.h"

class AlienDictionary : public solution {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        map<char, set<char>> preMap;
        for (string &word : words) {
            for (char c : word) {
                preMap[c] = {};
            }
        }
        preMap.insert({words[0][0], {}});
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                bool claim = getPreCursor(words[i], words[j], preMap);
                if (!claim) {
                    return "";
                }
            }
        }
        while (!preMap.empty()) {
            bool noPre = false;
            for (auto &tmp: preMap) {
                if (tmp.second.empty()) {
                    noPre = true;
                    res.push_back(tmp.first);
                    for(auto &pre : preMap) {
                        if (pre.second.find(tmp.first) != pre.second.end()) {
                            pre.second.erase(tmp.first);
                        }
                    }
                    preMap.erase(tmp.first);
                    break;
                }
            }
            if (!noPre) {
                return "";
            }
        }

        return res;
    }

    bool getPreCursor(string &a, string &b, map<char, set<char>> &preMap) {
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                preMap[b[j]].insert(a[i]);
                return true;
            }
            ++i;
            ++j;
        }
        if (a.size() > b.size()) {
            return false;
        }
        return true;
    }

    void check() {
        vector<string> words{"wrt","wrtkj"};
        cout << alienOrder(words) << endl;
    }
};

#endif //LEETCODE_269_ALIENDICTIONARY_H
