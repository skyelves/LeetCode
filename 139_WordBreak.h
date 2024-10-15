//
// Created by Admin on 10/14/2024.
//

#ifndef LEETCODE_139_WORDBREAK_H
#define LEETCODE_139_WORDBREAK_H

#include "solution.h"

class WordBreak : public solution {
    vector<int> visited;

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        visited.resize(s.size(), -1);
        return dfs(s, wordDict, 0);
    }

    bool dfs(string &s, vector<string> &wordDict, int idx) {
        if (idx == s.size()) {
            return true;
        }
        if (visited[idx] != -1) {
            return visited[idx];
        }
        for (string &word: wordDict) {
            if (word == s.substr(idx, word.size())) {
                if (dfs(s, wordDict, idx + word.size())) {
                    visited[idx] = 1;
                    return true;
                }
            }
        }
        visited[idx] = 0;
        return false;
    }
};

#endif //LEETCODE_139_WORDBREAK_H
