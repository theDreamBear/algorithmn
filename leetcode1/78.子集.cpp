/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int i)> dfs = [&](int pos) {
            ans.push_back(temp);
            if (pos >= nums.size()) {
                return;
            }
            for (int i = pos; i < nums.size(); i ++) {
                temp.push_back(nums[i]);
                dfs(i + 1);
                temp.pop_back();
            }
        };
        dfs(0);
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i ++) {
            auto gen = nextRightOneIndex(i);
            vector<int> temp;
            int p;
            while ((p = gen()) != -1) {
                temp.push_back(nums[p]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

