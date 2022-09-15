/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution_violate(CustomFunction &customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 0; x <= 1000; x++) {
            for (int y = 1; y <= 1000; y++) {
                if (customfunction.f(x, y) == z) {
                    ans.push_back({x, y});
                }
            }
        }
        return ans;
    }

    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        vector<vector<int>> ans;
        struct Node {
            int left, right, top, bottom;
        };

        stack<Node> st;
        st.push({1, 1000, 1, 1000});
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (customfunction.f(node.left, node.top) > z || customfunction.f(node.right, node.bottom) < z) {
                continue;
            }
            int x = (node.right + node.left) / 2;
            int y = (node.bottom + node.top) / 2;
            int v = customfunction.f(x, y);
            if (v < z) {
                if (x + 1 <= node.right) {
                    st.push({x + 1, node.right, node.top, node.bottom});
                }
                if (y + 1 <= node.bottom) {
                    st.push({node.left, x, y + 1, node.bottom});
                }
            } else if (v > z) {
                if (node.left + 1 <= x) {
                    st.push({node.left, x - 1, node.top, node.bottom});
                }
                if (node.top + 1 <= y) {
                    st.push({x, node.right, node.top, y - 1});
                }
            } else {
                ans.push_back({x, y});
                if (x + 1 <= node.right && node.top + 1 <= y) {
                    st.push({x + 1, node.right, node.top, y - 1});
                }
                if (node.left + 1 <= x && y + 1 <= node.bottom) {
                    st.push({node.left, x - 1, y + 1, node.bottom});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

