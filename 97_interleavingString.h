//
// Created by 王柯 on 8/24/23.
//

#ifndef LEETCODE_97_INTERLEAVINGSTRING_H
#define LEETCODE_97_INTERLEAVINGSTRING_H

#include "solution.h"

class InterLeavingString : public solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<bool> visited(s2.size() + 1, false);
        visited[0] = true;
        for (int j = 1; j <= s2.size(); ++j) {
            visited[j] = visited[j - 1] & (s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= s1.size(); ++i) {
            visited[0] = (s1[i - 1] == s3[i - 1]) & visited[0];
            for (int j = 1; j <= s2.size(); ++j) {
                visited[j] = (visited[j] && s1[i - 1] == s3[i + j - 1]) | (visited[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return visited[s2.size()];
    }

    void check() {
        string s1 = "", s2 = "b", s3 = "b";
        cout << isInterleave(s1, s2, s3) << endl;
    }
};

#endif //LEETCODE_97_INTERLEAVINGSTRING_H
