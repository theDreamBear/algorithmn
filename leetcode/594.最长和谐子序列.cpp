/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
        题意是最大最小值恰好等于 1
        暴力枚举最大值, 超时
    */
    int findLHS_pick(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        vector<int> ted = nums;
        int max_len = 0;
        for (auto val : ted) {
            int len = 0;
            int ct_max = 0;
            int ct_min = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] > val || nums[i] < val - 1) {
                    continue;
                }
                if (nums[i] == val) {
                    ++ct_max;
                } else {
                    ++ct_min;
                }
                ++len;
            }
            if (ct_min > 0 && ct_max > 0 && len > max_len) {
                max_len = len;
            }
        }
        return max_len;
    }

    struct DD {
        DD() = default;

        DD(bool mm, bool ma) {
            min_exist = mm;
            max_exist = ma;
            len = 1;
        }

        void update(int& max_len) {
            if (min_exist && max_exist && len > max_len) {
                max_len = len;
            }
        }

        void increase() { ++len; }

        void setMinExist() { min_exist = true; }

        void setMaxExist() { max_exist = true; }
        bool max_exist;
        bool min_exist;
        int len;
    };

    int findLHS_stupid(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int max_len = 0;
        map<int, DD> hash;
        for (auto val : nums) {
            // 添加当前最大值
            if (hash.count(val) == 0) {
                hash[val] = DD(false, true);
            } else {
                hash[val].increase();
                hash[val].setMaxExist();
            }
            if (hash.count(val + 1) == 0) {
                hash[val + 1] = DD(true, false);
            } else {
                hash[val + 1].increase();
                hash[val + 1].setMinExist();
            }
        }
        for (auto& kv : hash) {
            kv.second.update(max_len);
        }
        return max_len;
    }

    /*
        计算每个数的个数, 若是比他小1的数存在, 则 update
    */
    int findLHS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int max_len = 0;
        unordered_map<int, int> hash;
        for (auto& val : nums) {
            ++hash[val];
        }
        for (auto& kv : hash) {
            if (hash.count(kv.first - 1) > 0) {
                int len = kv.second + hash[kv.first - 1];
                if (len > max_len) {
                    max_len = len;
                }
            }
        }
        return max_len;
    }
};
// @lc code=end
