//
// Created by 王柯 on 8/25/22.
//

#ifndef LEETCODE_691_MINSTICKERS_H
#define LEETCODE_691_MINSTICKERS_H

#include "solution.h"

class MinStickers : public solution {
public:
    vector<vector<int>> sbags;
    int sbag_len;
    int stickersNum = 0;
    int minS;

    void dfs(vector<int> &target, int start = 0, int curr = 0) {
        if (curr + 1 >= minS)
            return;
        for (; start < sbag_len; ++start) {
            if (target[start] > 0)
                break;
        }
        for (int j = 0; j < stickersNum; ++j) {
            if (sbags[j][start] > 0) {
                vector<int> tmp = target;
                bool flag = true;
                for (int k = start; k < sbag_len; ++k) {
                    tmp[k] = max(0, tmp[k] - sbags[j][k]);
                    if (tmp[k] != 0) {
                        flag = false;
                    }
                }
                if (flag) {
                    minS = min(minS, curr + 1);
                    return;
                }
                dfs(tmp, start, curr + 1);
            }
        }
    }

    int minStickers(vector<string> &stickers, string target) {
        bool stickersContains[26] = {false};
        map<int, int> mm;
        vector<int> t;
        for (int i = 0; i < target.size(); ++i) {
            if (mm.find(target[i] - 'a') != mm.end())
                mm[target[i] - 'a']++;
            else
                mm[target[i] - 'a'] = 1;
        }
        for (auto i: mm) {
            t.push_back(i.second);
        }
        sbag_len = t.size();

        stickersNum = stickers.size();
        for (int i = 0; i < stickersNum; ++i) {
            vector<int> tmp;
            map<int, int> tmp_mm;
            int tmpLen = stickers[i].size();
            for (int j = 0; j < tmpLen; ++j) {
                stickersContains[stickers[i][j] - 'a'] = true;
                if (tmp_mm.find(stickers[i][j] - 'a') != tmp_mm.end())
                    tmp_mm[stickers[i][j] - 'a']++;
                else
                    tmp_mm[stickers[i][j] - 'a'] = 1;
            }
            for (auto j : mm) {
                auto iter = tmp_mm.find(j.first);
                if (iter != tmp_mm.end())
                    tmp.push_back(iter->second);
                else
                    tmp.push_back(0);
            }
            sbags.push_back(tmp);
        }
        for (auto i : mm) {
            if (!stickersContains[i.first])
                return -1;
        }
        minS = 16;
        dfs(t);
        return minS == 16 ? -1 : minS;
    }

    void check() {
        vector<string> stickers{"heart", "seven", "consider", "just", "less", "back", "an", "four", "cost", "kill",
                                "skin", "happen", "depend", "broad", "caught", "fast", "fig", "way", "under", "print",
                                "white", "war", "sent", "locate", "be", "noise", "door", "get", "burn", "quite",
                                "eight", "press", "eye", "wave", "bread", "wont", "short", "cow", "plain", "who",
                                "well", "drive", "fact", "chief", "store", "night", "operate", "page", "south", "once"};
        string target = "simpleexample";
        int res = minStickers(stickers, target);
        cout << res << endl;
    }

};

#endif //LEETCODE_691_MINSTICKERS_H
