/*
 * @lc app=leetcode.cn id=985 lang=cpp
 *
 * [985] 查询后的偶数和
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
#include <numeric>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = accumulate(A.begin(), A.end(), 0, [](int val, int newVal) {
            if (newVal % 2 == 0) {
                return val + newVal;
            }
            return val;
        });
        for (auto& p : queries) {
            int val = p[0];
            int index = p[1];
            int oldVal = A[index];
            if (oldVal % 2 == 0) {
                sum -= oldVal;
            }
            A[index] += val;
            if (A[index] % 2 == 0) {
                sum += A[index];
            }
            ans.emplace_back(sum);
        }
        return ans;
    }
};
// @lc code=end

