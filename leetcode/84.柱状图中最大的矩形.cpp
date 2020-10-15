/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
 public:
    struct increaseStack : public stack<int> {
        //stack<int> st;
        const vector<int>& nums;

        int getV(int idx) {
            if (idx >= 0) {
                return nums[idx];
            }
            return INT_MIN;
        }

        bool conflict(int idx) {
            return getV(idx) < getV(top());
        }

        bool push(int idx) {
            if (empty() || !conflict(idx)) {
                stack<int>::push(idx);
                return true;
            }
            return false;
        }

        increaseStack(const vector<int>& nums): nums(nums) {
            // 哨兵
            stack<int>::push(-1);
        }
    };

    struct recTangleHelper : public increaseStack {
        int maxArea;
        recTangleHelper(const vector<int>& nums):increaseStack(nums){
            maxArea = 0;
        }

        void calculate(int idx) {
            int calIndex = top();
            pop();
            int right = idx;
            int left = -1;
            if(!empty()) {
                left = top();
            }
            int newArea = getV(calIndex) * (right - left - 1);
            if (newArea > maxArea) {
                maxArea = newArea;
            }
        }
    };

    // 单调递增栈
    int largestRectangleArea1(vector<int>& heights) {
        stack<int> increaseStack;
        // 哨兵
        // 能让所有的都出栈
        heights.push_back(-1);
        int maxRectanglesize = 0;
        for (size_t index = 0; index < heights.size(); ++index) {
            if (increaseStack.empty() || heights[index] > heights[increaseStack.top()]) {
                increaseStack.push(index);
            } else {
                while (!increaseStack.empty()) {
                    // 计算
                    int right = index;
                    int preIndex = increaseStack.top();
                    int left = -1;
                    increaseStack.pop();
                    if (!increaseStack.empty()) {
                        left = increaseStack.top();
                    }
                    int width = right - left - 1;
                    if (width * heights[preIndex] > maxRectanglesize) {
                        maxRectanglesize = width * heights[preIndex];
                    }
                    if (increaseStack.empty() ||
                        heights[index] > heights[increaseStack.top()]) {
                        increaseStack.push(index);
                        break;
                    }
                }
            }
        }
        return maxRectanglesize;
    }

    int largestRectangleArea(vector<int>& heights) {
        // 哨兵
        // 能让所有的都出栈
        heights.push_back(-1);
        recTangleHelper rt(heights);
        for (size_t index = 0; index < heights.size(); ++index) {
            while (!rt.push(index)) {
                rt.calculate(index);
            }
        }
        return rt.maxArea;
    }
};
// @lc code=end

int main() {
    vector<int> h{2, 1, 5, 6, 2, 3};
    cout << Solution{}.largestRectangleArea(h);
}
