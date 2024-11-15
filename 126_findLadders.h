//
// Created by 王柯 on 8/14/22.
//

#ifndef LEETCODE_126_FINDLADDERS_H
#define LEETCODE_126_FINDLADDERS_H

#include "solution.h"

class FindLadders : public solution {
public:
    bool isAdjacent(string &s1, string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int begin = findWord(beginWord, wordList);
        if (begin == -1) {
            wordList.push_back(beginWord);
            begin = wordList.size() - 1;
        }
        int end = findWord(endWord, wordList);
        if (end == -1) {
            return {};
        }
        int n = wordList.size();
        vector<vector<int>> edge(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isAdjacent(wordList[i], wordList[j])) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        queue<pair<int, int>> curr;
        vector<int> dis(n, INT32_MAX);
        vector<vector<int>> parent(n);
        dis[begin] = 1;
        parent[begin] = {-1};
        curr.emplace(begin, 1);
        while (!curr.empty()) {
            auto tmp = curr.front();
            curr.pop();
            for (int i : edge[tmp.first]) {
                if (dis[i] > tmp.second + 1) {
                    dis[i] = tmp.second + 1;
                    parent[i].push_back(tmp.first);
                    curr.emplace(i, tmp.second + 1);
                } else if (dis[i] == tmp.second + 1) {
                    parent[i].push_back(tmp.first);
                }
            }
        }
        vector<vector<string>> res = {};
        vector<string> path;
        getPath(end, path, parent, wordList, res);
        for (auto &tmp : res) {
            reverse(tmp.begin(), tmp.end());
        }
        return res;
    }

    void getPath(int tmp, vector<string> &path, vector<vector<int>> &parent, vector<string>& wordList, vector<vector<string>> &res) {
        if (tmp == -1) {
            res.push_back(path);
            return;
        }
        path.push_back(wordList[tmp]);
        for (int i : parent[tmp]) {
            getPath(i, path, parent, wordList, res);
        }
        path.pop_back();
    }

    int findWord(string &endWord, vector<string>& wordList) {
        int n = wordList.size();
        int end = -1;
        for (int i = 0; i < n; ++i) {
            if (endWord == wordList[i]) {
                end = i;
                break;
            }
        }
        return end;
    }

    void check() {
        string beginWord = "hot", endWord = "dog";
        vector<string> wordList = {"hot", "dog"};
        auto res = findLadders(beginWord, endWord, wordList);
        for (auto i: res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_126_FINDLADDERS_H
