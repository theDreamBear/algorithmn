/*
 * @lc app=leetcode.cn id=1304 lang=cpp
 *
 * [1304] 和为零的N个唯一整数
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
class Solution {
public:
    /*
        0 对称
    */
    vector<int> sumZero1(int n) {
        vector<int> ans(n);
        int k = 1;
        if (n % 2 != 0) {
            --n;
        }
        int sz = n;
        for (int i = sz - 1; i >= 0; --i) {
            ans[i] = k;
            k = ~(k - 1);
            --n;
            if (k > 0) {
                ++k;
            }
        }
        return ans;
    }

    vector<int> sumZero(int n) {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans.emplace_back(i + 1);
            sum += (i + 1);
        }
        ans.emplace_back(-sum);
        return ans;
    }

};
// @lc code=end

