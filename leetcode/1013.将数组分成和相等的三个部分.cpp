/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */
#include <string.h>

#include <algorithm>
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
    /*
        想清楚终止条件
        0 .... i, ... j .... end
        i + 1 < j
    */
    bool canThreePartsEqualSum1(vector<int>& arr) {
        int total = 0;
        for (auto v : arr) {
            total += v;
        }
        if (total % 3 != 0) {
            return false;
        }
        int i = 0;
        int sum = 0;
        int onePart = total / 3;
        do {
            sum += arr[i];
            if (sum != onePart) {
                ++i;
            }
        } while (i < arr.size() && sum != onePart);
        if (sum != onePart) {
            return false;
        }
        int j = arr.size() - 1;
        sum = 0;
        do {
            sum += arr[j];
            if (sum != onePart) {
                --j;
            }
        } while (j >= 0 && sum != onePart);
        if (sum != onePart) {
            return false;
        }
        return i + 1 < j;
    }

    bool canThreePartsEqualSum2(vector<int>& arr) {
        int total = 0;
        for (auto v : arr) {
            total += v;
        }
        if (total % 3 != 0) {
            return false;
        }
        int i = 0;
        int sum = 0;
        int onePart = total / 3;
        // 为了防止 onePart == 0
        // 所以需要使用 do while, 不然可以 sum 初始值不能为零,
        // 不能使用会产生干扰的值
        do {
            sum += arr[i];
            ++i;
        } while (i < arr.size() && sum != onePart);
        if (sum != onePart) {
            return false;
        }
        int j = arr.size() - 1;
        sum = 0;
        do {
            sum += arr[j];
            --j;
        } while (j >= 0 && sum != onePart);
        if (sum != onePart) {
            return false;
        }
        return i - 1 < j;
    }

    bool canGetOnePart(const vector<int>& arr, int& i, int onePart,
                       function<bool(int)> func, function<void(int&)> op) {
        int sum = 0;
        while (func(i)) {
            sum += arr[i];
            if (sum == onePart) {
                break;
            }
            op(i);
        }
        return sum == onePart;
    }

    /*
        虚假的函数式编程
    */
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) {
            return false;
        }
        int onePart = total / 3;

        int i = 0;
        if (!canGetOnePart(
                arr, i, onePart, [&](int index) { return index < arr.size(); },
                [&](int& v) { ++v; })) {
            return false;
        }

        int j = arr.size() - 1;
        if (!canGetOnePart(
                arr, j, onePart, [&](int index) { return index >= 0; },
                [&](int& v) { --v; })) {
            return false;
        }
        return i + 1 < j;
    }
};
// @lc code=end

int main() {
    vector<int> data = {1, -1, 1, -1};
    cout << Solution{}.canThreePartsEqualSum(data);
}
