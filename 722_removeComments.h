//
// Created by 王柯 on 12/10/22.
//

#ifndef LEETCODE_722_REMOVECOMMENTS_H
#define LEETCODE_722_REMOVECOMMENTS_H

#include "solution.h"

class RemoveComments : public solution {
public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> res;
        int status = 0; //0: normal, 1: /* */
        string tmp;
        for (auto &line : source) {
            if (status == 0)
                tmp.clear();
            for (int i = 0; i < line.size(); ++i) {
                if (status == 0) {
                    if (line[i] == '/') {
                        if (line[i + 1] == '/') {
                            break;
                        } else if (line[i + 1] == '*') {
                            status = 1;
                            ++i;
                        } else {
                            tmp.push_back(line[i]);
                        }
                    } else {
                        tmp.push_back(line[i]);
                    }
                } else if (status == 1) {
                    if (line[i] == '*' && (i + 1) < line.size() && line[i + 1] == '/') {
                        status = 0;
                        ++i;
                    }
                }
            }
            if (status == 0 && tmp.length() != 0) {
                res.push_back(tmp);
            }
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_722_REMOVECOMMENTS_H
