//
// Created by 王柯 on 12/12/22.
//

#ifndef LEETCODE_679_JUDGEPOINT24_H
#define LEETCODE_679_JUDGEPOINT24_H

#include "solution.h"

class JudgePoint24 : public solution {
public:
    bool Point24(vector<double> &cards) {
        if (cards.size() == 1) {
            if (abs(cards[0] - 24) < 0.00001)
                return true;
            else
                return false;
        }
        for (int i = cards.size() - 1; i > 0; --i) {
            double n1 = cards[i];
            cards.erase(cards.begin() + i);
            for (int j = i - 1; j >= 0; --j) {
                double n2 = cards[j];
                cards.erase(cards.begin() + j);
                cards.push_back(n1 + n2);
                bool tmp = Point24(cards);
                if (tmp)
                    return true;
                cards.pop_back();

                cards.push_back(n1 - n2);
                tmp = Point24(cards);
                if (tmp)
                    return true;
                cards.pop_back();

                cards.push_back(n1 * n2);
                tmp = Point24(cards);
                if (tmp)
                    return true;
                cards.pop_back();

                cards.push_back(n1 / n2);
                tmp = Point24(cards);
                if (tmp)
                    return true;
                cards.pop_back();

                cards.push_back(n2 - n1);
                tmp = Point24(cards);
                if (tmp)
                    return true;
                cards.pop_back();

                cards.push_back(n2 / n1);
                tmp = Point24(cards);
                if (tmp)
                    return true;
                cards.pop_back();

                cards.insert(cards.begin() + j, n2);
            }
            cards.insert(cards.begin() + i, n1);
        }
        return false;
    }

    bool judgePoint24(vector<int> &cards) {
        vector<double> myCards;
        for (auto &i : cards)
            myCards.push_back(i);
        return Point24(myCards);
    }

    void check() {
        vector<int> cards{4, 1, 8, 7};
        cout << judgePoint24(cards) << endl;
    }
};

#endif //LEETCODE_679_JUDGEPOINT24_H
