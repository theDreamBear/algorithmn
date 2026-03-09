/*
 * @lc app=leetcode.cn id=1980 lang=cpp
 * @lcpr version=30204
 *
 * [1980] 找出不同的二进制字符串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <bitset>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int binStrToInt(const string& str) {
        int ans = 0;
        for (int i = str.size() - 1, add = 1; i >= 0; add *= 2, i--) {
            if (str[i] == '1') {
                ans += add;
            }
        }
        return ans;
    }

    string intToBinStr(int v) {
        string ans;
        while (v) {
            ans.push_back(v % 2 + '0');
            v /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string findDifferentBinaryString1(vector<string>& nums) {
        int n = nums[0].size();
        bitset<66000u> bs;
        for (auto& str: nums) {
            bs.set(binStrToInt(str));
        }
        int v = 0;
        for (; bs.test(v); v++) {}
        string ans = intToBinStr(v);
        if (ans.size() < n) ans = string(n - ans.size(), '0') + ans;
        return ans;
    }

    string findDifferentBinaryString2(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> bs;
        for (auto& str: nums) {
            bs.insert(stoi(str, nullptr, 2));
        }
        int v = 0;
        for (; bs.count(v); v++) {}
        return bitset<32>(v).to_string().substr(32 - n);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, 0);
        for (int i = 0; i < n; i++) ans[i] = nums[i][i] ^ 1;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["01","10"]\n
// @lcpr case=end

// @lcpr case=start
// ["00","01"]\n
// @lcpr case=end

// @lcpr case=start
// ["111","011","001"]\n
// @lcpr case=end

 */

