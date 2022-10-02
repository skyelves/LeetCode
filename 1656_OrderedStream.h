//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1656_ORDEREDSTREAM_H
#define LEETCODE_1656_ORDEREDSTREAM_H

#include "solution.h"

class OrderedStream {
public:
    int num;
    bool *visited = NULL;
    vector<string> str;

    OrderedStream(int n) {
        num = 1;
        visited = new bool[n + 2];
        memset(visited, false, sizeof(bool) * (n + 2));
        str.resize(n + 2);
        visited[0] = true;
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res{};
        visited[idKey] = true;
        str[idKey] = value;
        if (idKey == num) {
            int i = idKey;
            while (visited[i]) {
                res.push_back(str[i]);
                i++;
                num++;
            }
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

#endif //LEETCODE_1656_ORDEREDSTREAM_H
