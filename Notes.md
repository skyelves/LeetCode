## Rabin-Karp
Problem: Check whether a substr (len: m) exists in a string (len: n)

Naive solution: compare bit by bit, O(mn)

Rabin-Karp 's algorithm, O(n): using Rolling Hashing https://coolcao.com/2020/08/20/rabin-karp/

Examples: 1044: Longest Duplicate Substring



## Sparse Table

Problem: Range Maximum/Minimum Query (RMQ)  with $O(nlogn)$ preprocess and $O(1)$ query time. Don't support insert.

​	Given a array $A$ and two numbers $l$ and $r$, return $max_{i\in [l,r]} A_i$.

Sparse table $f[a][b]$ stores the $max_{i\in [a,a+2^b -1]} A_i$.

Preprocess: using dp, `f[j][i] = max(f[j][i-1], f[j+(1<<(i-1))][i-1])`

![img](https://pic4.zhimg.com/80/v2-22d8a24faea894fb8ddceae627093bbf_1440w.jpg)

Query: `return max(f[l][s], f[r-(1<<s) + 1][s])` , where $s=log_2(r-l+1)$

![img](https://pic4.zhimg.com/80/v2-9d09b3492f0c0cbaa7555a56b22c1693_1440w.jpg)

https://zhuanlan.zhihu.com/p/105439034

Examples: P2880 [USACO07JAN] Balanced Lineup




## Binary Indexed Tree / Fenwick tree





## Segment Tree

1. Support query the maximum/minimum/sum value in a range: $O(log n)$
2. Support point/range modification: $O(log n)$

In essense, it's a balanced binary search tree.

For array [1,2,3,4,5], the segment tree looks like follows:

![preview](https://pic1.zhimg.com/v2-5e9124a6147143e51cea46755e9a0398_r.jpg)



https://zhuanlan.zhihu.com/p/106118909

Examples: 307: Range Sum Query - Mutable


## Disjoint-set



## Floyd 
Problem: calculate the minimum distance between multiple node pairs

```$xslt
for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
```

How to calculate the path?
Record the path in the calculate process.
```$xslt
for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) {
            int tmp = d[i][k] + d[k][j];
            if (dp[i][j] > tmp) {
                dp[i][j] = tmp;
                path[i][j] = k;
            } 
        }
    }
}
```
The getPath function:
```$xslt
string getPath(int i, int j) {
    if (path[i][j] == -1)
        return " " + i + " " + j;
    else {
        int k = path[i][j];
        return getPath(i, k) + getPath(k, j);
    }
}
```
https://www.cnblogs.com/wangyuliang/p/9216365.html


## Dijkstra (greedy)

Problem: calculate the minimum distance from one node to other nodes

https://blog.51cto.com/u_15178976/2790840

Optimizations: use A* algorithm prune the search space, but may not find the exact optimal path.