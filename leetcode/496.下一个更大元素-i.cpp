/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
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

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement_violate(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            bool found = false;
            for (int j = 0; j < nums2.size(); ++j) {
                if (!found) {
                    if (nums1[i] == nums2[j]) {
                        found = true;
                    }
                    continue;
                }
                if (nums2[j] > nums1[i]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }

    vector<int> nextGreaterElement_violate_optimize(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums2.size(); ++i) {
            hashMap[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            int j = hashMap[nums1[i]] + 1;
            for (; j < nums2.size(); ++j) {
                if (nums2[j] > nums1[i]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }

    /*
        预处理找到nums2 右边每一个比自己大的元素  单调栈, 存 map

    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums2.size(); ++i) {
            if (st.empty() || st.top() > nums2[i]) {
                st.push(nums2[i]);
            } else {
                while (!st.empty() && st.top() < nums2[i]) {
                    int v = st.top();
                    st.pop();
                    hashMap[v] = nums2[i];
                }
                st.push(nums2[i]);
            }
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (hashMap.count(nums1[i]) != 0) {
                ans[i] = hashMap[nums1[i]];
            }
        }
        return ans;
    }
};
// @lc code=end

