/*
 * @lc app=leetcode.cn id=LCR 075 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 075] 数组的相对排序
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray_sort(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> pr;
        for (int i = 0; i < arr2.size(); i++) {
            pr[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](const int v, const int w) {
            if (pr.count(v) and pr.count(w)) {
                return pr[v] < pr[w];
            }
            if (pr.count(v)) {
                return true;
            }
            if (pr.count(w)) {
                return false;
            }
            return v < w;
        });
        return arr1;
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int upper = *max_element(arr1.begin(), arr1.end());
        vector<int> fre(upper + 1);
        for (auto v : arr1) {
            fre[v]++;
        }
        vector<int> ans;
        for (auto x : arr2) {
            for (int i = 0; i < fre[x]; i++) {
                ans.push_back(x);
            }
            fre[x] = 0;
        }
        for (int i = 0; i < fre.size(); i++) {
            for (int j = 0; j < fre[i]; j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]\n
// @lcpr case=end

 */

