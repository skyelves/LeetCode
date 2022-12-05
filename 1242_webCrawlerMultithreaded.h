//
// Created by 王柯 on 12/4/22.
//

#ifndef LEETCODE_1242_WEBCRAWLERMULTITHREADED_H
#define LEETCODE_1242_WEBCRAWLERMULTITHREADED_H

#include "solution.h"

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class webCrawlerMultiThreaded {
public:
    class HtmlParser {
    public:
        vector<string> getUrls(string url);
    };

#define NUM_THREADS 5

    queue<string> qq;
    set<string> ss;
    string _startUrl;
    mutex m1, m2;
    condition_variable cv;
    vector<thread> workers;
    bool done;
    int working;

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

    void myCrawl(HtmlParser *htmlParser) {
        while (!qq.empty()) {
            unique_lock<mutex> lock1(m1);
            cv.wait(lock1, [=]() { return qq.size() > 0 || done; });
            if (done)
                return;
            ++working;
            string tmp = qq.front();
            qq.pop();
            lock1.unlock();
            auto strs = htmlParser->getUrls(tmp);
            for (auto &str : strs) {
                m2.lock();
                if (ss.find(str) == ss.end() && isSameHost(str, _startUrl)) {
                    ss.insert(str);
                    lock1.lock();
                    qq.push(str);
                    lock1.unlock();
                }
                m2.unlock();
            }
            --working;
            if (working == 0 && qq.size() == 0)
                done = true;
            lock1.lock();
            cv.notify_all();
        }
        return;
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        _startUrl = startUrl;
        qq = queue<string>();
        ss.clear();
        done = false;
        working = 0;
        qq.push(startUrl);
        ss.insert(startUrl);
        pthread_t tids[NUM_THREADS];
        for (int i = 0; i < NUM_THREADS; ++i) {
            workers.emplace_back(&webCrawlerMultiThreaded::myCrawl, this, &htmlParser);
        }
        for (auto &i : workers) {
            i.join();
        }
        return vector<string>(ss.begin(), ss.end());
    }
};

#endif //LEETCODE_1242_WEBCRAWLERMULTITHREADED_H
