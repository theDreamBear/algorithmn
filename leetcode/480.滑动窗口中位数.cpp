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
class Solution1 {
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


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {}
};
// @lc code=end


int main() {
    vector<int> data= {1,3,2};
    hashHeap hd(data);
    for (int i = 0; i < data.size(); ++i) {
        hd.push(i);
    }
    hd.deletePos(1);
    hd.print();
    cout << "hello world" << endl;
}
