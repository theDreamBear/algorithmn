/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
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
    /*
        超出 long long 限制
    */
    vector<int> addToArrayForm1(vector<int>& A, int K) {
        long long sum = 0;
        for (auto v : A) {
            sum = sum * 10 + v;
        }
        sum += K;
        vector<int> ans;
        stack<int> st;

        do {
            int v = sum % 10;
            st.push(v);
            sum /= 10;
        } while (sum);

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    vector<int> numToVec(int K) {
        vector<int> ans;
        do {
            int v = K % 10;
            ans.push_back(v);
            K /= 10;
        } while (K);
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void vecAdd(vector<int>& left, vector<int>& right) {
        int sz = left.size();
        int i = 0;
        for (; i < sz; ++i) {
            left[sz - i - 1] += right[sz - i - 1];
            if (left[sz - i - 1] >= 10) {
                left[sz - i - 1] -= 10;
                ++left[sz - i - 2];
            }
        }
        return;
    }

    vector<int> addToArrayForm2(vector<int>& A, int K) {
        auto add = numToVec(K);
        int sz = max(add.size(), A.size()) + 1;
        for (int i = A.size(); i < sz; ++i) {
             A.insert(A.begin(), 0);
        }
        for (int i = add.size(); i < sz; ++i) {
            add.insert(add.begin(), 0);
        }
        vecAdd(A, add);
        for (auto it = A.begin(); it != A.end(); it++) {
            if (*it != 0) {
                return vector<int>(it, A.end());
            }
        }
        return vector<int>{0};
    }


    vector<int> addToArrayForm3(vector<int>& A, int K) {
        vector<int> res;
        int n = A.size() -1;
        for (; n >= 0; --n) {
            int sum = A[n] + K % 10;
            K /= 10;
            if (sum >= 10) {
                sum -= 10;
                ++K;
            }
            res.push_back(sum);
        }
        while (K) {
            int v = K % 10;
            res.push_back(v);
            K /= 10;
        }
        return vector<int>(res.rbegin(), res.rend());
    }

    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int n = A.size() -1;
        for (; n >= 0 || K > 0; --n, K /= 10) {
            if (n >= 0) {
                K += A[n];
            }
            res.push_back(K % 10);
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};
// @lc code=end

