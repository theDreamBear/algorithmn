/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    struct decreaseStack : public stack<int> {
        const vector<int>& _data;
        int total;

        decreaseStack(const vector<int>& nums):_data(nums) {
            total = 0;
        }

        int getValue(int idx) {
            if (idx >= 0) {
                return _data[idx];
            }
            return 0;
        }

        bool conflict(int idx) {
            return getValue(idx) >= getValue(top());
        }

        bool push(int idx) {
            if (empty() || !conflict(idx)) {
                stack<int>::push(idx);
                return true;
            }
            return false;
        }

        void addTotal(int v) {
            total += v;
        }

        int getTotal() {
            return total;
        }
        void calculate(int idx) {
            int calIdx = top();
            pop();
            int right = idx;
            int left = -1;
            if (!empty()) {
                left = top();
            }
            int height = min(getValue(left), getValue(idx)) - getValue(calIdx);
            if (height > 0) {
                int width = right - left - 1;
                addTotal(height * width);
            }
        }
    };

    int trap(vector<int>& height) {
        decreaseStack ds(height);
        for (int i = 0; i < height.size(); ++i) {
            while(!ds.push(i)) {
                ds.calculate(i);
            }
        }
        return ds.getTotal();
    }
};
// @lc code=end

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution{}.trap(nums);
}

