//
// Created by 王柯 on 12/2/22.
//

#ifndef LEETCODE_158_READNCHARACTERSGIVENREAD4II_H
#define LEETCODE_158_READNCHARACTERSGIVENREAD4II_H

#include "solution.h"

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class ReadNCharactersGivenRead4II : public solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char myBuf[4] = {0};
    int idx = 0;
    int len = 0;
    bool eof = false;

    int read4(char *buf4);

    int read(char *buf, int n) {
        int res = 0;
        if (n <= len - idx) {
            memcpy(buf, myBuf+idx, n);
            idx += n;
            return n;
        }
        memcpy(buf, myBuf+idx, len - idx);
        idx = len;
        res += len - idx;
        if (eof)
            return res;
        len = read4(myBuf);
        while (res < n && len == 4) {
            if (res + 4 <= n) {
                memcpy(buf + res, myBuf, 4);
                res += 4;
                len = read4(myBuf);
            } else {
                memcpy(buf + res, myBuf, n - res);
                idx = n - res;
                return n;
            }
        }
        eof = true;
        if (res + len <= n) {
            memcpy(buf + res, myBuf, len);
            res += len;
        } else {
            memcpy(buf + res, myBuf, n - res);
            idx += n - res;
            return n;
        }

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_158_READNCHARACTERSGIVENREAD4II_H
