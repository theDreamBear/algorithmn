/*
 * @lc app=leetcode.cn id=2874 lang=cpp
 * @lcpr version=30204
 *
 * [2874] 有序三元组中的最大值 II
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
// @lcpr-template-end
// @lc code=start
class ZKWMAX {
public:
    vector<int> tr;
    int n = 1;

    ZKWMAX(int sz) {
        while (n < sz + 2) n <<= 1;
        tr.resize(n << 1, INT_MIN);
        n++;
    }

    void add(int i, int v) {
        for (tr[i += n] = v, i >>= 1; i; i >>= 1) {
            tr[i] = max(tr[i << 1], tr[i << 1 |1]);
        }
    }

    int query(int L, int R) {
        if (L > R) {
            return INT_MIN;
        }
        int ans = INT_MIN;
        for (L += (n - 1), R += (n + 1); L ^ R ^ 1; L >>= 1, R >>= 1) {
            if (~L & 1) ans = max(ans, tr[L ^ 1]);
            if (R & 1) ans = max(ans, tr[R ^ 1]);
        }
        return ans;
    }

    void reset(int i) {
        tr[i += n] = INT_MIN;
    }
};

class ZKWMIN {
public:
    vector<int> tr;
    int n = 1;

    ZKWMIN(int sz) {
        while (n < sz + 2) n <<= 1;
        tr.resize(n << 1, INT_MAX);
        n++;
    }

    void add(int i, int v) {
        for (tr[i += n] = v, i >>= 1; i; i >>= 1) {
            tr[i] = min(tr[i << 1], tr[i << 1 |1]);
        }
    }

    int query(int L, int R) {
        if (L > R) return INT_MAX;
        int ans = INT_MAX;
        for (L += (n - 1), R += (n + 1); L ^ R ^ 1; L >>= 1, R >>= 1) {
            if (~L & 1) ans = min(ans, tr[L ^ 1]);
            if (R & 1) ans = min(ans, tr[R ^ 1]);
        }
        return ans;
    }

    void reset(int i) {
        tr[i += n] = INT_MAX;
    }
};


class Solution {
public:
    //数据范围都是正数, 不需要考虑负数的问题
    long long maximumTripletValue1(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        ZKWMAX lma(n), rma(n);
        //ZKWMIN lmm(n), rmm(n);
        for (int i = 0; i < nums.size(); i++) {
            lma.add(i, nums[i]);
            //lmm.add(i, nums[i]);
            rma.add(i, nums[i]);
            //rmm.add(i, nums[i]);
        }
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            long long left_ma = lma.query(0, i - 1);
            long long right_ma = rma.query(i + 1, n - 1);
            // if (left_mm != INT_MAX) {
            //     if (right_ma != INT_MIN) {
            //         ans = max(ans, (left_mm - v) * right_ma);
            //     }
            //     if (right_mm != INT_MAX) {
            //         ans = max(ans, (left_mm - v) * right_mm);
            //     }
            // }
            if (left_ma != INT_MIN) {
                // if (right_mm != INT_MAX) {
                //     ans = max(ans, (left_ma - v) * right_mm);
                // }
                if (right_ma != INT_MIN) {
                    ans = max(ans, (left_ma - v) * right_ma);
                }
            }
        }
        return ans;
    }

    long long maximumTripletValue2(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> sufMAX(n + 1);
        for (int i = n - 1; i >= 0; i--) sufMAX[i] = max(sufMAX[i + 1], nums[i]);
        int preMAx = nums[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, (long long)(preMAx - nums[i]) * sufMAX[i + 1]);
            preMAx = max(preMAx, nums[i]);
        }
        return ans;
    }

    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int preMaxDiff = 0;
        int preMAx = nums[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, (long long)nums[i] * preMaxDiff);
            preMaxDiff = max(preMaxDiff, preMAx - nums[i]);
            preMAx = max(preMAx, nums[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,6,1,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,3,4,19]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

