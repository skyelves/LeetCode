//
// Created by 王柯 on 10/27/22.
//

#ifndef LEETCODE_212_FINDWORDS_H
#define LEETCODE_212_FINDWORDS_H

#include "solution.h"

class FindWords : public solution {
public:
    int dir[4][2] = {{-1, 0},
                     {1,  0},
                     {0,  -1},
                     {0,  1}};

    class Node {
    public:
        char key;
        bool isLeaf = false;
        bool visited = false;
        Node *child[26] = {nullptr};

        Node() {}

        Node(char c) : key(c) {}

        ~Node() {}
    };

    void insertTrie(Node *root, string word, int idx) {
        if (idx == word.size()) {
            root->isLeaf = true;
            return;
        }
        char c = word[idx];
        if (root->child[c - 'a'] == nullptr) {
            Node *tmp = new Node(c);
            root->child[c - 'a'] = tmp;
        }
        insertTrie(root->child[c - 'a'], word, idx + 1);
    }

    void
    dfs(vector<vector<char>> &board, int x, int y, Node *root, string curr, vector<vector<bool>> &visited,
        vector<string> &res) {
        if (root->isLeaf && !root->visited) {
            root->visited = true;
            res.push_back(curr);
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny]) {
                char c = board[nx][ny];
                Node *tmp = root->child[c - 'a'];
                if (tmp != nullptr) {
                    visited[nx][ny] = true;
                    dfs(board, nx, ny, tmp, curr + c, visited, res);
                    visited[nx][ny] = false;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> res;
        int len = board.size(), width = board[0].size();
        Node *root = new Node;
        for (auto &word : words) {
            insertTrie(root, word, 0);
        }
        vector<vector<bool>> visited(len, vector<bool>(width, false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                char c = board[i][j];
                string cStr(1, c);
                Node *tmp = root->child[c - 'a'];
                if (tmp != nullptr) {
                    visited[i][j] = true;
                    dfs(board, i, j, tmp, cStr, visited, res);
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_212_FINDWORDS_H
