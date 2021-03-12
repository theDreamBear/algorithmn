/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
        问题分析
            1. nums[i] - nums[j] 会越界
            2. 时间复杂度, nk;
        思考: n 是变不了的, 怎么改变 k
            我们每次是在前面k 的元素里面找[nums[i] - t, nums[i] + t]
       范围内的元素 这种可以通过 set 配合二分来实现
    */
    bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = max(0, i - k); j < i; ++j) {
                if (abs(nums[i] - nums[j]) <= t) {
                    return true;
                }
            }
        }
        return false;
    }

    /*
        史上最坑的一道题
        约束条件一个不给
        + - 发会引发越界
        时间复杂度 nlgk
    */
    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
        if (k == 0) {
            return false;
        }
        long long diff = 0;
        if (k == 1) {
            for (int i = 1; i < nums.size(); ++i) {
                diff = abs((long long)nums[i - 1] - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            return false;
        }
        set<long long> s;
        for (int i = 0; i < nums.size(); ++i) {
            // 找第一个比自己小t的
            auto pos = s.lower_bound((long long)nums[i] - t);
            if (pos != s.end()) {
                diff = abs((long long)*pos - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            // 找第一个大于等于自己的
            pos = s.lower_bound(nums[i]);
            if (pos != s.end()) {
                diff = abs((long long)*pos - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }

    int getBucketId(int val, int width) {
        if (width == 0) {
            return val;
        }
        // 负数和正数分开出来
        if (val < 0) {
            if (val % width == 0) {
                return val / width;
            } else {
                return val / width - 1;
            }
        } else {
             if (val % width == 0) {
                return val / width;
            } else {
                return val / width + 1;
            }
        }
    }
    /*
        桶的思路
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) {
            return false;
        }
        long long diff = 0;
        if (k == 1) {
            for (int i = 1; i < nums.size(); ++i) {
                diff = abs((long long)nums[i - 1] - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            return false;
        }
        //           桶 id, 值
        unordered_map<int, int> bucket;
        for (int i = 0; i < nums.size(); ++i) {
            int id = getBucketId(nums[i], t);
            if (bucket.count(id) > 0) {
                return true;
            }
            if (bucket.count(id - 1) > 0 &&
                abs((long long)bucket[id - 1] - nums[i]) <= t) {
                return true;
            }
            if (bucket.count(id + 1) > 0 &&
                abs((long long)bucket[id + 1] - nums[i]) <= t) {
                return true;
            }
            bucket[id] = nums[i];
            if (bucket.size() > k) {
                bucket.erase(getBucketId(nums[i - k], t));
            }
        }
        return false;
    }
};
// @lc code=end
int main() {
    vector<int> data{-3,3};
    cout <<Solution{}.containsNearbyAlmostDuplicate(data, 2, 4);
}
