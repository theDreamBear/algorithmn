/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
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
    /*
        暴力解法 nklgk, 超时
    */
    vector<double> medianSlidingWindow_violate(vector<int>& nums, int k) {
        vector<double> ans;
        deque<int> temp;
        for (int i = 0; i < nums.size() && i < k; ++i) {
            temp.push_back(nums[i]);
        }
        vector<int> tV(temp.begin(), temp.end());
        sort(tV.begin(), tV.end());
        double mid = tV[tV.size() / 2];
        if (k % 2 == 0) {
            mid = (mid + tV[tV.size() / 2 - 1]) / 2;
        }
        ans.push_back(mid);
        for (int i = k; i < nums.size(); ++i) {
            temp.pop_front();
            temp.push_back(nums[i]);
            vector<int> tV(temp.begin(), temp.end());
            sort(tV.begin(), tV.end());
            double mid = tV[tV.size() / 2];
            if (k % 2 == 0) {
                mid = (mid + tV[tV.size() / 2 - 1]) / 2;
            }
            ans.push_back(mid);
        }
        return ans;
    }

    class hashHeap {
     private:
        const vector<int>& _data;
        // 存每个元素在_data 里面的下标
        vector<int> _indexes;
        int _sz;

        // 外部下标映射内部下标, 方面删除
        unordered_map<int, int> outInner;

        // _data 下标对应 _indexes 下标
        function<bool(int, int)> _comparator;

        void update(int innerIndex) {}

        int size() { return _sz; }

        int getValue(int innerIndex) { return _data[_indexes[innerIndex]]; }

        void heapUp(int innerIndex) {
            int vOuter = _indexes[innerIndex];
            int pos = innerIndex;
            while (pos > 0) {
                int pInner = (pos - 1) / 2;
                if (_comparator(getValue(pInner), getValue(pos))) {
                    break;
                }
                _indexes[pos] = _indexes[pInner];
                outInner[_indexes[pInner]] = pos;
                pos = pInner;

            }
            _indexes[pos] = vOuter;
            outInner[vOuter] = pos;
        }

        void headDown(int innerIndex) {
            int vOuter = _indexes[innerIndex];
            int pos = innerIndex;
            while (pos * 2 < _sz) {
                int mm = 2 * pos;
                int ma = mm + 1;
                if (ma < size() && _comparator(getValue(ma), getValue(mm))) {
                    mm = ma;
                }
                if (_comparator(pos, mm)) {
                    break;
                }
                _indexes[pos] = _indexes[mm];
                outInner[_indexes[pos]] = pos;
            }
            _indexes[pos] = vOuter;
            outInner[vOuter] = pos;
        }

        int lastIndex() {
            return size() - 1;
        }

        void shrink() { --_sz; }

        void expand() {
            ++_sz;
        }
     public:
        hashHeap(const vector<int>& nums) : _data(nums) {
            _sz = 0;
        }

        void push(int outIndex) {
            if (_sz == _indexes.size()) {
                _indexes.push_back(outIndex);
            } else {
                _indexes[_sz] = outIndex;
            }
            expand();
            heapUp(lastIndex());
        }

        void deletePos(int outerIndex) {
            int inner = outInner[outerIndex];
            _indexes[inner] = _indexes[lastIndex()];
            shrink();
            headDown(inner);
        }

        void print() {
            while (size() > 0) {
                
            }
        }
    };

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {}
};
// @lc code=end
