//
// Created by Ke Wang on 11/26/24.
//

#ifndef INC_825_FRIENDSOFAPPROPRIATEAGES_H
#define INC_825_FRIENDSOFAPPROPRIATEAGES_H

#include "solution.h"

class FriendsOfAppropriateAges : public solution {
public:
    int numFriendRequests(vector<int> &ages) {
        int res = 0, n = ages.size();
        vector<int> cnt(125, 0), presum(125, 0);
        for (auto i: ages) {
            ++cnt[i];
        }
        for (int i = 1; i < 125; ++i) {
            presum[i] = presum[i - 1] + cnt[i];
        }
        for (int i = 0; i < 125; ++i) {
            if (cnt[i] != 0) {
                int low = i / 2 + 7;
                int high = i - 1;
                if (low > high) {
                    continue;
                }
                int tmp = presum[high] - presum[low];
                res += tmp * cnt[i] + cnt[i] * (cnt[i] - 1);
            }
        }
        return res;
    }

    void check() {
        vector<int> ages{108, 115, 5, 24, 82};
        cout << numFriendRequests(ages) << endl;
    }
};

#endif //INC_825_FRIENDSOFAPPROPRIATEAGES_H
