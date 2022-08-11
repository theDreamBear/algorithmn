/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int sz = pow(2, n);
        vector<int> visited(sz);
        function<bool(int)> backtrack = [&](int cur)->bool {
            // 终止条件
            if (ans.size() == sz) {
                return true;
            }
            for (int i = 0; i < n; i++) {
                auto val = cur ^ (1 << i);
                if (visited[val]) {
                    continue;
                }
                visited[val] = 1;
                ans.push_back(val);
                if (backtrack(val)){
                    return true;
                }
                visited[val] = 0;
                ans.pop_back();
            }
            return false;
        };
        visited[0] = 1;
        ans.push_back(0);
        backtrack(0);
        return ans;
    }
};
// @lc code=end

