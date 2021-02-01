/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
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
    // 空间换时间
    int findShortestSubArray1(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto val : nums) {
            ++hash[val];
        }
        int max_ct = 0;
        vector<int> max_vec;

        for (auto& kv : hash) {
            if (kv.second > max_ct) {
                max_ct = kv.second;
            }
        }

        for (auto& kv : hash) {
            if (kv.second == max_ct) {
                max_vec.push_back(kv.first);
            }
        }
        int min_len = INT_MAX;
        for (auto val : max_vec) {
            int i, j;
            for (i = 0; i < nums.size() && nums[i] != val; ++i)
                ;

            for (j = nums.size() - 1; j >= 0 && nums[j] != val; --j)
                ;
            if (j - i + 1 < min_len) {
                min_len = j - i + 1;
            }
        }
        return min_len;
    }

    struct AA {
     public:
        int times;
        int left;
        int right;

        AA() {
            times = 0;
            left = -1;
            right = -1;
        }

        void update(int i) {
            ++times;
            if (left == -1) {
                left = i;
                right = i;
            } else {
                right = i;
            }
        }

        int count() { return times; }

        int getLen() { return right - left + 1; }
    };

    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        unordered_map<int, AA> hash;
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]].update(i);
        }

        int max_times = 0;
        int min_len = INT_MAX;
        for (auto& kv : hash) {
            if (kv.second.count() > max_times) {
                max_times = kv.second.count();
                min_len = kv.second.getLen();

            } else if (kv.second.count() == max_times &&
                       kv.second.getLen() < min_len) {
                min_len = kv.second.getLen();
            }
        }
        return min_len;
    }
};
// @lc code=end

int main() {
    vector<int> ss = {1, 2, 2, 3, 1};
    cout << Solution{}.findShortestSubArray(ss);
}
