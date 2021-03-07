/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
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

using namespace std;

// @lc code=start
class Solution {
public:

    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size());
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum = ((sum << 1) + A[i]) % 5;
            if (sum % 5 == 0) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
// @lc code=end

