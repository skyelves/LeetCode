//
// Created by 王柯 on 12/7/22.
//

#ifndef LEETCODE_642_AUTOCOMPLETESYSTEM_H
#define LEETCODE_642_AUTOCOMPLETESYSTEM_H

#include "solution.h"

class AutocompleteSystem {
public:
    class Node {
    public:
        map<string, int> hotness;
        Node *children[27] = {nullptr};

        vector<string> Suggest() {
            vector<string> res;
            vector<pair<string, int>> toSort;
            for (auto &i : hotness) {
                toSort.push_back(i);
            }
            sort(toSort.begin(), toSort.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                } else {
                    return a.first < b.first;
                }
            });
            for (int i = 0; i < min(3, (int)toSort.size()); ++i) {
                res.push_back(toSort[i].first);
            }
            return res;
        }
    };

    Node *root;
    Node *curr;
    string writing;

    Node *buildTrie(vector<string> &sentences, vector<int> &times) {
        Node *root = new Node;
        for (int i = 0; i < sentences.size(); ++i) {
            string sentence = sentences[i];
            int hot = times[i];
            Node *tmp = root;
            for (auto &c : sentence) {
                int idx = c - 'a';
                if (c == '#') break;
                if (c == ' ')
                    idx = 26;
                if (tmp->children[idx] == nullptr) {
                    tmp->children[idx] = new Node;
                }
                tmp = tmp->children[idx];
                tmp->hotness[sentence] = hot;
            }

        }
        return root;
    }

    void updateTrie() {
        Node *tmp = root;
        for (auto &c : writing) {
            int idx = c - 'a';
            if (c == '#') break;
            if (c == ' ')
                idx = 26;
            tmp = tmp->children[idx];
            ++tmp->hotness[writing];
        }
    }

    AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
        root = buildTrie(sentences, times);
        curr = root;
    }

    vector<string> input(char c) {
        if (c == '#') {
            updateTrie();
            writing = "";
            curr = root;
            return {};
        }
        writing += c;
        int idx = c - 'a';
        if (c == ' ')
            idx = 26;
        if (curr->children[idx] == nullptr) {
            curr->children[idx] = new Node;
            curr = curr->children[idx];
            return {};
        } else {
            curr = curr->children[idx];
            return curr->Suggest();
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

#endif //LEETCODE_642_AUTOCOMPLETESYSTEM_H
