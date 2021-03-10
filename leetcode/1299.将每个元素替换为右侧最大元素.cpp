/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> replaceElements1(vector<int>& arr) {
        /*
            最大栈, 直观解法
        */
        stack<int> maxStack;
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (maxStack.empty()) {
                maxStack.push(arr[i]);
            } else {
                int val = maxStack.top();
                if (val < arr[i]) {
                    val = arr[i];
                }
                maxStack.push(val);
            }
        }
        vector<int> ans(arr.size(), -1);
        maxStack.pop();
        for (int i = 0; i < arr.size() && !maxStack.empty(); ++i) {
            ans[i] = maxStack.top();
            maxStack.pop();
        }
        return ans;
    }

    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size(), -1);
        // 逆序操作保证每个位置下一位就是最大目标值, 类似冒泡
        for (int i = arr.size() - 2; i >= 0; --i) {
            if (i + 2 < arr.size() && arr[i + 1] < arr[i + 2]) {
               swap(arr[i + 1], arr[i + 2]);
            }
            ans[i] = arr[i + 1];
        }
        return ans;
    }
};
// @lc code=end

