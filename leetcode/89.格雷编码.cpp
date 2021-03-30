/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
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
    int countOne(int val) {
        int ct = 0;
        while (val) {
            val = val & (val - 1);
            ++ct;
        }
        return ct;
    }

    /*
        理解错题目意思的解法
    */
    vector<int> grayCode_bad(int n) {
        vector<vector<int>> temp(n + 1, vector<int>());
        int ma = pow(2, n) - 1;
        for (int i = 0; i <= ma; ++i) {
            int ct = countOne(i);
            temp[ct].push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            int val = temp[i].back();
            temp[i].pop_back();
            ans.push_back(val);
        }
        int i = n - 1;
        bool flag = true;
        while (flag && i > 0 && i < n) {
            for (; flag && i > 0 && i < n; --i) {
                if (temp[i].empty()) {
                    flag = false;
                    break;
                }
                int val = temp[i].back();
                temp[i].pop_back();
                ans.push_back(val);
            }
            i = 2;
            for (; flag && i < n && i > 0; ++i) {
                if (temp[i].empty()) {
                    flag = false;
                    break;
                }
                int val = temp[i].back();
                temp[i].pop_back();
                ans.push_back(val);
            }
        }
        return ans;
    }

    bool grayCompare(int left, int right) {
        if (abs(countOne(left) - countOne(right)) != 1) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i <= 31; ++i) {
            if (((left >> i) & 0x1) != ((right >> i) & 0x1)) {
                ++diff;
            }
        }
        return diff == 1;
    }

    bool grayValid(vector<int>& data) {
        if (data.empty()) {
            return true;
        }
        int left = data[0];
        for (int i = 1; i < data.size(); ++i) {
            if (!grayCompare(data[i], left)) {
                return false;
            }
            left = data[i];
        }
        return true;
    }
    /*
        回溯
        选择全排列
    */
    void backtracking1(vector<vector<int>>& result, vector<int>& ans, vector<bool>& used) {
        if (!result.empty()) {
            return;
        }
        if (!grayValid(ans)) {
            return;
        }
        if (ans.size() == used.size()) {
            result.push_back(ans);
            return;
        }
        for (int i = 1; i < used.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                ans.push_back(i);
                backtracking1(result, ans, used);
                used[i] = false;
                ans.pop_back();
            }
        }
    }

    void backtracking(vector<vector<int>>& result, vector<int>& ans, int pos) {
         if (!result.empty()) {
            return;
        }
        if (!grayValid(ans)) {
            return;
        }
        if (pos == ans.size()) {
            result.push_back(ans);
            return;
        }
        for (int i = pos; i < ans.size(); ++i) {
            swap(ans[i], ans[pos]);
            backtracking(result, ans, pos + 1);
            swap(ans[i], ans[pos]);
        }
    }

    vector<int> recursion(vector<int> temp, int pos) {
        if (pos < 0) {
            return temp;
        }
        vector<int> data(temp.size() * 2);
        int index = 0;
        for (int i = 0; i < temp.size(); i += 2) {
            data[index++] = temp[i];
            data[index++] = temp[i]  ^ (0x1 << pos);
            data[index++] = temp[i + 1] ^ (0x1 << pos);
            data[index++] = temp[i + 1];
        }
        return recursion(data, pos - 1);
    }

    vector<int> grayCode(int n) {
        if (n == 0) {
            return {0};
        }
        if (n == 1) {
            return {0, 1};
        }
        vector<int> temp{0, 0 ^ (0x1 << n - 1)};
        return recursion(temp, n - 2);
    }
};
// @lc code=end

int main() {
    auto data = Solution{}.grayCode(4);
    for (auto v : data) {
        cout << v << " ";
    }
    cout << endl;
}
