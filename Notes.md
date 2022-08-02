## Rabin-Karp
Problem: Check whether a substr (len: m) exists in a string (len: n)

Naive solution: compare bit by bit, O(mn)

Rabin-Karp 's algorithm, O(n): using Rolling Hashing https://coolcao.com/2020/08/20/rabin-karp/

Examples: 1044: Longest Duplicate Substring



## Segment Tree

1. Support query the maximum/minimum/sum value in a range: $O(log n)$
2. Support point/range modification: $O(log n)$

In essense, it's a balanced binary search tree.

For array [1,2,3,4,5], the segment tree looks like follows:

![preview](https://pic1.zhimg.com/v2-5e9124a6147143e51cea46755e9a0398_r.jpg)



https://zhuanlan.zhihu.com/p/106118909

Examples: 307: Range Sum Query - Mutable