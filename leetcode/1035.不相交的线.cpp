/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
#include <ranges.h>
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
        第一版直接回溯， 超时

    */
    int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
        function<int(int, int, int, int)> backtrack =
            [&](int l1, int h1, int l2, int h2) -> int {
            int times = 0;
            for (int i = l1; i <= h1; ++i) {
                int num = nums1[i];
                for (int j = l2; j <= h2; ++j) {
                    if (nums2[j] == num) {
                        int left = 1 + backtrack(i + 1, h1, j + 1, h2);
                        if (left > times) {
                            times = left;
                        }
                    }
                }
            }
            return times;
        };
        return backtrack(0, nums1.size() - 1, 0, nums2.size() - 1);
    }

    void prepare(unordered_map<int, vector<int>>& hash,
                 const vector<int>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            hash[vec[i]].push_back(i);
        }
    }

    /*
        1 <= nums1.length <= 500
        1 <= nums2.length <= 500
        1 <= nums1[i], nums2[i] <= 2000

        500字符回溯法时间复杂度太高了
    */
    int maxUncrossedLines2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> hash;
        bool flag = nums1.size() < nums2.size();
        vector<int>*n1, *n2;
        if (flag) {
            n1 = &nums1;
            n2 = &nums2;
        } else {
            n1 = &nums2;
            n2 = &nums1;
        }
        prepare(hash, *n2);
        function<int(int, int, int, int)> backtrack =
            [&](int l1, int h1, int l2, int h2) -> int {
            if (l1 > h1 || l2 > h2) {
                return 0;
            }
            int times = 0;
            for (int i = l1; i <= h1; ++i) {
                int num = (*n1)[i];
                if (hash.count(num) > 0) {
                    auto j = lower_bound(hash[num].begin(), hash[num].end(), l2) - hash[num].begin();
                    if (j >= hash[num].size()) {
                        continue;
                    }
                    int left = 1 + backtrack(i + 1, h1, hash[num][j] + 1, h2);
                    if (left > times) {
                        times = left;
                    }
                }
            }
            return times;
        };
        return backtrack(0, n1->size() - 1, 0, n2->size() - 1);
    }
};
// @lc code=end

int main() {
    vector<int> n1 = {2,3,4,1,3,3,2,4,2,2,1,5,2,4,3,4,4,5,1,5,1,5,4,3,1,2,5,2,4,4};
    vector<int> n2 = {2,2,4,2,4,1,1,5,5,3,2,1,1,1,3,1,2,5,2,4,3,4,5,5,3,3,5,1,4,3};
    cout << Solution{}.maxUncrossedLines(n1, n2);
}