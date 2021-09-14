/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] 好子数组的最大分数
 */

// @lc code=start


constexpr int MAX_N = 3e5;
int n;

int tree[MAX_N];

void init(int _n) {
    n = 1;
    while (n < _n) {
        n <<= 1;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        tree[i] = INT_MAX;
    }
}

void update(int index, int value) {
    int k = index + n - 1;
    tree[k] = min(tree[k], value);
    while (k) {
        int p = (k - 1) >> 1;
        tree[p] = min(tree[(p << 1) + 1], tree[(p << 1) + 2]);
        k = p;
    }
}

int query(int l, int r, int node = 0, int left = 0, int right = n - 1) {
    if (l > right || r < left) {
        return INT_MAX;
    }
    if (l <= left && r >= right) {
        return tree[node];
    } else {
        int lv = query(l, r, 2 * node + 1, left, (left + right) / 2);
        int rv = query(l, r, 2 * node + 2, (left + right) / 2 + 1, right);
        return min(lv, rv);
    }
}


class Solution {
 public:
    int maximumScore(vector<int> &nums, int k) {
        int ans = INT_MIN;
        // 对于每一种情况最小值是固定
        // 枚举最小值
        // 接雨水问题
        // 找左右两把第一个比自己小的
        // 单调递增栈
        stack<int> st;
#ifdef VI
        init(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
        // 增加哨兵
        nums.insert(nums.begin(), INT_MIN);
        nums.insert(nums.end(), INT_MIN);
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                int node = st.top();
                st.pop();
                if (k >= st.top() && k <= i - 2) {
                    int width = i - st.top() - 1;
                    ans = max(ans, width * query(st.top(), i - 2));
                }
            }
            if (st.empty() || nums[st.top()] <= nums[i]) {
                st.push(i);
            }
        }
#else
        int i = 0;
        for (; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                int node = st.top();
                st.pop();
                if (st.empty()) {
                    if (i > k) {
                        int width = i;
                        ans = max(ans, width * nums[node]);
                    }
                    break;
                }
                if (k > st.top() && k < i) {
                    int width = i - st.top() - 1;
                    ans = max(ans, width * nums[node]);
                }
            }
            if (st.empty() || nums[st.top()] < nums[i]) {
                st.push(i);
            }
        }
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (st.empty()) {
                int width = i;
                ans = max(ans, width * nums[node]);
                continue;
            }
            if (k > st.top() && k < i) {
                int width = i - st.top() - 1;
                ans = max(ans, width * nums[node]);
            }
        }
#endif
        return ans;
    }
};
// @lc code=end

