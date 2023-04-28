/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern_violate(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        //
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] <= nums[i]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] <= nums[i] || nums[k] >= nums[j]) {
                        continue;
                    }
                    return true;
                }
            }
        }
        return false;
    }

    // 分治 失败
    bool find132pattern_bad(vector<int> &nums, int low, int high) {
        if (low + 2 > high) {
            return false;
        }
        int mid = (low + high) >> 1;
        // 在左边
        bool left = find132pattern_bad(nums, low, mid);
        if (left) {
            return true;
        }
        // 在右边
        bool right = find132pattern_bad(nums, mid, high);
        if (right) {
            return true;
        }
        // 有一个点在异端

        return false;
    }

    // 错误的单调栈
    bool find132pattern_bad2(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        // 严格单调递增栈
        stack<int> st;
        for (auto v: nums) {
            if (st.empty() || st.top() < v) {
                st.push(v);
                continue;
            }
            if (st.top() == v) {
                continue;
            }
            while (!st.empty() && st.top() >= v) {
                st.pop();
            }
            if (!st.empty()) {
                return true;
            }
            st.push(v);
        }
        return false;
    }

    // 枚举3
    // 思考的时候想到了类似的解法， 但是没找到对应的数据结构
    bool find132pattern_multiset(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        // 枚举3
        int mm = nums[0];
        multiset<int> right;
        for (int i = 1; i < n; i++) {
            right.insert(nums[i]);
        }
        // i为3
        for (int i = 1; i < n - 1; i++) {
            right.erase(right.find(nums[i]));
            if (nums[i] <= mm) {
                mm = nums[i];
                continue;
            }
            auto it = right.upper_bound(mm);
            if (it != right.end() && *it < nums[i]) {
                return true;
            }
        }
        return false;
    }

    // 枚举1
    // 逆序
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int m2 = INT_MIN;
        // 单调递减
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < m2) {
                return true;
            }
            if (st.empty() || st.top() > nums[i]) {
                st.push(nums[i]);
                continue;
            }
            if (st.top() == nums[i]) {
                continue;
            }
            while (!st.empty() && nums[i] > st.top()) {
                m2 = max(m2, st.top());
                st.pop();
            }
            if (nums[i] > m2) {
                st.push(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end

