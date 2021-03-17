/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> dfs = [&](int pos, int left) {
            if (left == 0) {
                ans.push_back(temp);
                return;
            }
            if (pos >= candidates.size()) {
                return;
            }
            for (int i = pos; i < candidates.size(); ++i) {
                if (left < candidates[i]) {
                    return;
                }
                if (i != pos && candidates[i - 1] == candidates[i]) {
                    continue;
                }
                left -= candidates[i];
                temp.push_back(candidates[i]);
                dfs(i + 1, left);
                left += candidates[i];
                temp.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> data{1, 1, 2, 5 ,6 ,7, 10};
    auto ans = Solution{}.combinationSum2(data, 8);
}