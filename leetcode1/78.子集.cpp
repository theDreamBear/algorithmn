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

class Solution1 {
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

////////////////////////////////////////// ++++++++++++++++++++++++++++++++++++++++++++++

// 第一种方案
void subsetsHelper1(const vector<int>& nums, vector<int>& cur, int pos, vector<vector<int>>& ans) {
    // 注意这个边界
    if (pos > nums.size()) {
        return;
    }
    ans.push_back(cur);
    for (int i = pos; i < nums.size(); i++) {
        // 回溯
        cur.push_back(nums[i]);
        subsetsHelper1(nums, cur, i + 1, ans);
        cur.pop_back();
    }
}

// 第二种方案
void subsetsHelper2(const vector<int>& nums, vector<int>& cur, int pos, vector<vector<int>>& ans) {
   // 边界
   if (pos > nums.size()) {
       return;
   }
   if (pos == nums.size()) {
       ans.push_back(cur);
       return;
   }
   // 不取
   subsetsHelper2(nums, cur, pos + 1, ans);

   // 取
   cur.push_back(nums[pos]);
   subsetsHelper2(nums, cur, pos + 1, ans);
   cur.pop_back();
}

auto nextValueIndex = [](int mask) {
    auto rightMostOne = [](int mask)  {
        if (mask == 0) {
            return -1;
        }
        int pos = __builtin_ctz(mask);

        return pos;
    };
    return [my_mask = mask, rightMostOne]() mutable -> int {
        int pos = rightMostOne(my_mask);
        if (pos != -1) {
            my_mask ^= (1 << pos);
        }
        return pos;
    };
};

// 第三种方案
void subsetsHelper3(const vector<int>& nums, vector<int>& cur, int pos, vector<vector<int>>& ans) {
    int n = nums.size();
    for (int i = 0; i < (1 << n); i++) {
        // 统计1的位置
        vector<int> temp;
        int p;
        auto gen = nextValueIndex(i);
        while ((p = gen()) != -1) {
            if (p == -1) {
                break;
            }
            temp.push_back(nums[p]);
        }
        ans.push_back(temp);
    }
}



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        //subsetsHelper1(nums, cur, 0, ans);
        // subsetsHelper2(nums, cur, 0, ans);
        subsetsHelper3(nums, cur, 0, ans);
        return ans;
    }
};

// @lc code=end

