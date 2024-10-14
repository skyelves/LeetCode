//
// Created by Admin on 10/13/2024.
//

#ifndef LEETCODE_71_SIMPLIFYPATH_H
#define LEETCODE_71_SIMPLIFYPATH_H

#include "solution.h"

class SimplifyPath : public solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string> ss;
        convertPathToStack(path, ss);
        while(!ss.empty()) {
            res = "/" + ss.top() + res;
            ss.pop();
        }
        if (res.empty()) {
            return "/";
        }
        return res;
    }

    void convertPathToStack(string &path, stack<string> &ss) {
        int i = 0, n = path.size();
        while (i < n) {
            string tmp = readNext(path, i);
            if (tmp == ".") {
                continue;
            } else if (tmp == "..") {
                if (!ss.empty()) {
                    ss.pop();
                }
            } else if (!tmp.empty()){
                ss.push(tmp);
            }
        }
    }

    string readNext(string &path, int &i) {
        int n = path.size();
        string res;
        while (i < n && path[i] == '/') {
            ++i;
        }
        while (i < n && path[i] != '/') {
            res.push_back(path[i]);
            ++i;
        }
        return res;
    }
};

#endif //LEETCODE_71_SIMPLIFYPATH_H
