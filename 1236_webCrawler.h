//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_1236_WEBCRAWLER_H
#define LEETCODE_1236_WEBCRAWLER_H

#include "solution.h"

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class webCrawler : public solution {
public:
    class HtmlParser {
    public:
        vector<string> getUrls(string url);
    };

    bool isSameHost(string &a, string &b) {
        int len = min(a.length(), b.length());
        for (int i = 7; i < len; ++i) {
            if (a[i] != b[i]) {
                return false;
            } else if (a[i] == '/') {
                break;
            }
        }
        return true;
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> res;
        set<string> ss;
        queue<string> qq;
        res.push_back(startUrl);
        qq.push(startUrl);
        ss.insert(startUrl);
        while (!qq.empty()) {
            string tmp = qq.front();
            qq.pop();
            auto strs = htmlParser.getUrls(tmp);
            for (auto &str : strs) {
                if (ss.find(str) == ss.end() && isSameHost(str, startUrl)) {
                    ss.insert(str);
                    qq.push(str);
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};

#endif //LEETCODE_1236_WEBCRAWLER_H
