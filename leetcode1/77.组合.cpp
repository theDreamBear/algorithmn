/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
// 最左的 1 的位置
int leftOneIndex(unsigned int val) {
    if (val == 0) {
        return -1;
    }
    return 31 - __builtin_clz(val);
}

// 最右1的位置
int rightOneIndex(unsigned int val) {
    if (val == 0) {
        return -1;
    }
    return __builtin_ffs(val) - 1;
}

// 二进制1的个数
int oneCount(unsigned int val) {
    return __builtin_popcount(val);
}

using func = function<int()>;

// 下一个1的位置, 从低位开始到高位
auto nextRightOneIndex(unsigned int val) -> func {
    return [value = val]() mutable -> int {
        int p = rightOneIndex(value);
        if (p != -1) {
            value ^= (1 << p);
        }
        return p;
    };
}

class Solution {
public:
    void combineHelper(int pos, int n, int k, vector<vector<int>>& ans, vector<int>& cur) {
       if (pos > n || cur.size() == k) {
           if (cur.size() == k) {
               ans.push_back(cur);
           }
           return;
       }
       for (int i = pos; i <= n; i++) {
           cur.push_back(i);
           combineHelper(i + 1, n, k, ans, cur);
           cur.pop_back();
       }

    }
    
    void combineHelper_binary(int pos, int n, int k, vector<vector<int>>& ans, vector<int>& cur) {
        if (pos > n || cur.size() == k) {
            if (cur.size() == k) {
                ans.push_back(cur);
            }
            return;
        }
        combineHelper(pos + 1, n, k, ans, cur);
        cur.push_back(pos);
        combineHelper(pos + 1, n, k, ans, cur);
        cur.pop_back();
    }

    vector<vector<int>> combine_1(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        combineHelper_binary(1, n, k, ans, cur);
        return ans;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for (int i = 1; i <= (1 << n) - 1; i++) {
            if (__builtin_popcount(i) == k) {
                auto v = nextRightOneIndex(i);
                vector<int> cur;
                int p;
                while ((p = v()) != -1) {
                    cur.push_back(p + 1);
                }
                ans.push_back(cur);
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        // 初始化
        // 将 temp 中 [0, k - 1] 每个位置 i 设置为 i + 1，即 [0, k - 1] 存 [1, k]
        // 末尾加一位 n + 1 作为哨兵
        for (int i = 1; i <= k; ++i) {
            temp.push_back(i);
        }
        temp.push_back(n + 1);
        
        int j = 0;
        while (j < k) {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            j = 0;
            // 寻找第一个 temp[j] + 1 != temp[j + 1] 的位置 t
            // 我们需要把 [0, t - 1] 区间内的每个位置重置成 [1, t]
            while (j < k && temp[j] + 1 == temp[j + 1]) {
                temp[j] = j + 1;
                ++j;
            }
            // j 是第一个 temp[j] + 1 != temp[j + 1] 的位置
            ++temp[j];
        }
        return ans;
    }
};
// @lc code=end

