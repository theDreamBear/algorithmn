/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
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

    int thirdMax(vector<int>& nums) {
        long long s = INT64_MIN;
        long long m = s, b = s;
        for (int i = 0; i < nums.size(); ++i) {
            long long temp = nums[i];
            if (temp > b) {
                swap(b, temp);
            }
            if (temp != b && temp > m) {
                swap(m, temp);
            }
            if (temp != b && temp != m && temp > s) {
                swap(temp, s);
            }
        }
        if (s == INT64_MIN) {
            return b;
        }
        return s;
    }

};
// @lc code=end

int main() {
    vector<int> x = {2,2,3};
    cout << Solution{}.thirdMax(x);
}