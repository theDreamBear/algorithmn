/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
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
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int findMatch(const string &s, int start) {
        int left = 0;
        int right = 0;
        for (int i = start; i < s.size(); ++i) {
            if (s[i] == '[') {
                ++left;
            }
            if (s[i] == ']') {
                ++right;
            }
            if (left == right) {
                return i;
            }
        }
        return 0;
    }

    NestedInteger deserializeHelper(const string &s, int low, int high) {
        NestedInteger ne;
        int sign = 0;
        int value = 0;
        for (int i = low; i <= high; ++i) {
            if (s[i] == ',') {
                if (sign) {
                    value *= sign;
                    NestedInteger temp;
                    temp.setInteger(value);
                    ne.add(temp);
                }
                sign = 0;
                value = 0;
                continue;
            }
            if (s[i] == '[') {
                int h = findMatch(s, i);
                ne.add(deserializeHelper(s, i + 1, h - 1));
                i = h;
                continue;
            }
            if (s[i] == '-') {
                sign = -1;
                continue;
            }
            if (sign == 0) {
                sign = 1;
            }
            value = value * 10 + (s[i] - '0');
            if (i == high) {
                value *= sign;
                NestedInteger temp;
                temp.setInteger(value);
                ne.add(temp);
            }
        }
        return ne;
    }

    NestedInteger deserialize1(string s) {
        if (s[0] == '[') {
            return deserializeHelper(s, 1, s.size() - 2);
        }
        return NestedInteger(stoi(s));
    }

    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> st;
        int value = 0;
        int sign = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                st.push(NestedInteger());
                continue;
            }
            if (s[i] == ',') {
                if (sign) {
                    value *= sign;
                    NestedInteger temp(value);
                    st.top().add(temp);
                    sign = 0;
                    value = 0;
                }
                continue;
            }
            if (s[i] == ']') {
                if (sign) {
                    value *= sign;
                    NestedInteger temp(value);
                    st.top().add(temp);
                    sign = 0;
                    value = 0;
                }
                if (st.size() > 1) {
                    auto item = st.top();
                    st.pop();
                    st.top().add(item);
                }
                continue;
            }
            if (s[i] == '-') {
                sign = -1;
                continue;
            }
            if (sign == 0) {
                sign = 1;
            }
            value = value * 10 + (s[i] - '0');
        }
        return st.top();
    }
};
// @lc code=end

