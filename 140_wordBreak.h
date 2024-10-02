//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_140_WORDBREAK_H
#define LEETCODE_140_WORDBREAK_H

#include "solution.h"

class WordBreak : public solution {
public:
    void dfs(string &s, int start, string &breaked, vector<string> &wordDict, vector<string> &res) {
        for (int i = 0; i < wordDict.size(); ++i) {
            int len = wordDict[i].size();
            bool equal = (wordDict[i] == s.substr(start, len));
            if (equal) {
                if (s.size() == start + len) {
                    string newBreaked = breaked + wordDict[i];
                    res.push_back(newBreaked);
                } else {
                    string newBreaked = breaked + wordDict[i] + " ";
                    dfs(s, start + len, newBreaked, wordDict, res);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> res;
        string breaked;
        dfs(s, 0, breaked, wordDict, res);
        return res;
    }

    void check() {
        string s = "catsanddog";
        vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        auto res = wordBreak(s, wordDict);
        for (auto i : res) {
            cout << i << endl;
        }
    }

    vector<string> wordBreak1(string s, vector<string>& wordDict) {
        vector<string> res;
        for (string &word : wordDict) {
            if (word == s.substr(0, word.size())) {
                if (s.length() == word.length()) {
                    res.push_back(word);
                } else {
                    vector<string> nextRes = wordBreak1(s.substr(word.length(), s.length()), wordDict);
                    for (string &s: nextRes) {
                        res.push_back(word + " " + s);
                    }
                }
            }
        }

        return res;
    }
};

#endif //LEETCODE_140_WORDBREAK_H
