/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */
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

// @lc code=start
const int MAX_N = 1e5;
int n = 1;

int buffer[MAX_N];

void init(int sz) {
    n = 1;
    while (n < sz) {
        n <<= 1;
    }
    for (int i = 0; i < (n << 1) ; ++i) {
        buffer[i] = 0;
    }
}

void push(int idx, int v) {
    int k = idx + n - 1;
    buffer[k] = v;
    while (k > 0) {
        k = (k - 1) >> 1;
        buffer[k] ^= v;
    }
}

int query(int l, int r, int k = 0, int low = 0, int high = n - 1) {
    if (l > high || r < low) {
        return 0;
    }
    if (l <= low && r >= high) {
        return buffer[k];
    }
    int mid = ((low + high) >> 1);
    int lv =  query(l, r, (k << 1) + 1, low, mid);
    int rv = query(l, r , (k << 1) + 2, mid + 1, high);
    return lv ^ rv;
}
class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        init(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            push(i, arr[i]);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = query(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};

// @lc code=end

