//
// Created by 王柯 on 12/6/22.
//

#ifndef LEETCODE_1268_SUGGESTEDPRODUCTS_H
#define LEETCODE_1268_SUGGESTEDPRODUCTS_H

#include "solution.h"

class SuggestedProducts : public solution {
public:
    class Node {
    public:
        vector<string> suggest;
        Node *children[26] = {nullptr};

        void add(string &str) {
            suggest.push_back(str);
            sort(suggest.begin(), suggest.end());
            if (suggest.size() > 3) {
                suggest.resize(3);
            }
        }
    };

    Node *buildTrie(vector<string> &products) {
        Node *root = new Node;
        for (auto &product : products) {
            Node *tmp = root;
            for (auto &c : product) {
                if (tmp->children[c - 'a'] == nullptr) {
                    tmp->children[c - 'a'] = new Node;
                }
                tmp = tmp->children[c - 'a'];
                tmp->add(product);
            }
        }
        return root;
    }

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        vector<vector<string>> res;
        Node *root = buildTrie(products);
        for (auto &c : searchWord) {
            if (root != nullptr) {
                root = root->children[c - 'a'];
            }
            if (root != nullptr) {
                res.push_back(root->suggest);
            } else {
                res.push_back({});
            }
        }

        return res;
    }

    void check() {
        vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
        string searchWord = "mouse";
        auto res = suggestedProducts(products, searchWord);
        for (auto &i : res) {
            for (auto &j : i) {
                cout << j << endl;
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_1268_SUGGESTEDPRODUCTS_H
