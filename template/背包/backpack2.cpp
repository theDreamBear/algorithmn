#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;


// lintcode 92 · 背包问题

// 用位图进行状态压缩
constexpr int MAX_N = 102400;
class Solution {
public:
    int backPack(int m, vector<int> &A) {
        bitset<MAX_N> bs;
        bs[0] = true;
        for (int i = 0; i < A.size(); i++) {
            bs = bs | bs << A[i];
        }
        for (int i = m; i >= 0; i--) {
            if (bs[i]) {
                return i;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int backPack(int m, vector<int> &A) {
        bitset<MAX_N> bs;
        bs[0] = true;
        for (int i = 0; i < A.size(); i++) {
            bs = bs | bs << A[i];
        }
        for (int i = m; i >= 0; i--) {
            if (bs[i]) {
                return i;
            }
        }
        return 0;
    }
};