/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    struct slidingWindows {
        int _windows_size;
        // 从左到右依次递减
        deque<int> _q;
        const vector<int> &nums;

        slidingWindows(const vector<int> &nums, int sz)
            : nums(nums), _windows_size(sz) {}

        bool full(int i) {
            if (_q.empty()) {
                return false;
            }
            return (i - _q.front()) >= _windows_size;
        }

        void add(int i) {
            if (full(i)) {
                // 左侧出栈
                _q.pop_front();
            }
            while (!_q.empty() && nums[_q.back()] <= nums[i]) {
                _q.pop_back();
            }
            _q.push_back(i);
        }

        int max() { return nums[_q.front()]; }
    };

    vector<int> maxSlidingWindow_1(vector<int> &nums, int k) {
        vector<int> res;
        slidingWindows sw(nums, k);
        for (int i = 0; i < min(k, int(nums.size())); ++i) {
            sw.add(i);
        }
        res.push_back(sw.max());
        for (int i = k; i < nums.size(); ++i) {
            sw.add(i);
            res.push_back(sw.max());
        }
        return res;
    }

    // 窗口区间
    /*
    时间复杂度 O(n);
    空间复杂度O(n);
    整体效果不如滑动窗口
    */
    struct rangeMax {
        const vector<int> &_nums;
        int _windows_size;
        int *left;
        int *right;

        rangeMax(const vector<int> &nums, int sz)
            : _nums(nums), _windows_size(sz) {
            left = new int[_nums.size()];
            right = new int[_nums.size()];
            fill(left, left + _windows_size, 0);
            fill(right, right + _windows_size, 0);
            init();
        }

        ~rangeMax() {
            delete[] left;
            delete[] right;
        }

        void initLeft() {
            for (int i = 0; i < _nums.size(); ++i) {
                if (i % _windows_size == 0) {
                    left[i] = _nums[i];
                } else {
                    left[i] = max(left[i - 1], _nums[i]);
                }
            }
        }

        void init() {
            int sz = _nums.size();
            left[0] = _nums[0];
            right[sz - 1] = _nums[sz - 1];
            for (int i = 1; i < _nums.size(); ++i) {
                // left;
                if (i % _windows_size == 0) {
                    left[i] = _nums[i];
                } else {
                    left[i] = max(left[i - 1], _nums[i]);
                }
                // right;
                if ((sz - i) % _windows_size == 0) {
                    right[sz - i - 1] = _nums[sz - i - 1];
                } else {
                    right[sz - i - 1] = max(right[sz - i], _nums[sz - i - 1]);
                }
            }
        }
        void print() {
            cout << "left:  ";
            for (int i = 0; i < _nums.size(); ++i) {
                cout << left[i] << " ";
            }
            cout << endl;
            cout << "right: ";
            for (int i = 0; i < _nums.size(); ++i) {
                cout << right[i] << " ";
            }
            cout << endl;
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        rangeMax r(nums, k);
        res.push_back(r.left[k - 1]);
        for (int i = k; i < nums.size(); ++i) {
            int m = max(r.left[i], r.right[i - k + 1]);
            res.push_back(m);
        }
        return res;
    }
};
// @lc code=end
