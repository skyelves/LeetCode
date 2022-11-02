//
// Created by 王柯 on 11/2/22.
//

#ifndef LEETCODE_2115_FINDALLRECIPES_H
#define LEETCODE_2115_FINDALLRECIPES_H

#include "solution.h"

class FindAllRecipes : public solution {
public:
    class Node {
    public:
        string name;
        vector<Node *> child;
        bool exist = false;
        bool visited = false;

        Node(string _name) : name(std::move(_name)), exist(false) {}

        void addChild(Node *c) {
            child.push_back(c);
        }
    };

    bool dfs(Node *root) {
        if (root->child.size() == 0) return root->exist;
        bool res = true;
        if (root->visited) {
            return root->exist;
        }
        root->visited = true;
        for (auto &i : root->child) {
            bool tmp = dfs(i);
            if (!tmp) {
                res = false;
                break;
            }
        }
        root->exist = res;
        return res;
    }

    vector<string>
    findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
        vector<string> res;
        map<string, Node *> mm;
        int len = recipes.size();
        for (int i = 0; i < len; ++i) {
            Node *curr = nullptr;
            if (mm.find(recipes[i]) == mm.end()) {
                curr = new Node(recipes[i]);
                mm[recipes[i]] = curr;
            } else {
                curr = mm[recipes[i]];
            }
            for (auto &j : ingredients[i]) {
                if (mm.find(j) == mm.end()) {
                    Node *tmp = new Node(j);
                    mm[j] = tmp;
                    curr->addChild(tmp);
                } else {
                    curr->addChild(mm[j]);
                }
            }
        }
        for (auto &i : supplies) {
            if (mm.find(i) != mm.end())
                mm[i]->exist = true;
        }
        for (auto &i : recipes) {
            auto root = mm[i];
            if (dfs(root)) {
                res.push_back(i);
            }
        }
        return res;
    }

    void check() {
        vector<string> recipes{"bread"}, supplies{"yeast"};
        vector<vector<string>> ingredients{{"yeast", "flour"}};
        auto res = findAllRecipes(recipes, ingredients, supplies);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_2115_FINDALLRECIPES_H
