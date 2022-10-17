//
// Created by 王柯 on 10/16/22.
//

#ifndef LEETCODE_488_FINDMINSTEP_H
#define LEETCODE_488_FINDMINSTEP_H

#include "solution.h"

class FindMinStep : public solution {
public:
    void remove(string &board, int idx) {
        int left = idx, right = idx;
        while (left > 0 && board[left] == board[left - 1]) --left;
        while (right < board.length() && board[right] == board[right + 1]) ++right;
        if (right - left >= 2) {
            board = board.substr(0, left) + board.substr(right + 1);
            remove(board, left - 1);
        }
    }

    int findMinStep(string board, string hand) {
        int res = 0, totalNum = hand.length();
        sort(hand.begin(), hand.end());
        queue<pair<string, string>> qq;
        unordered_set<string> ss;
        qq.push({board, hand});
        while (!qq.empty()) {
            auto tmp = qq.front();
            qq.pop();
            for (int i = 0; i < tmp.second.length(); ++i) {
                char ball = tmp.second[i];
                if (i > 0 && tmp.second[i] == tmp.second[i - 1]) continue;
                for (int j = 0; j <= tmp.first.length(); ++j) {
                    if (j > 0 && tmp.first[j] == tmp.first[j - 1] && tmp.first[j] == ball) continue;
                    bool worthTry = false;
                    if (tmp.second[i] == tmp.first[j])
                        worthTry = true;
                    else if (j > 0 && tmp.first[j] == tmp.first[j - 1] && tmp.first[j] != tmp.second[i])
                        worthTry = true;
                    if (worthTry) {
                        // create a new board
                        string newBoard = tmp.first.substr(0, j) + ball + tmp.first.substr(j, tmp.first.length() - j);
//                        newBoard = remove(newBoard);
                        remove(newBoard, j);
                        if (newBoard.length() == 0) {
                            return totalNum - tmp.second.length() + 1;
                        } else {
                            string newHand =
                                    tmp.second.substr(0, i) + tmp.second.substr(i + 1, tmp.second.length() - i - 1);
                            string memory = newBoard + " " + newHand;
                            if (ss.find(memory) == ss.end()) {
                                qq.push({newBoard, newHand});
                                ss.insert(memory);
                            }
                        }
                    }
                }
            }
        }

        return -1;
    }

    void check() {
        string board = "RRWWRRBBRR", hand = "WB";
        int res = findMinStep(board, hand);
        cout << res << endl;
    }
};

#endif //LEETCODE_488_FINDMINSTEP_H
