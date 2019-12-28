/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (47.43%)
 * Likes:    764
 * Dislikes: 0
 * Total Accepted:    115.2K
 * Total Submissions: 242.8K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */
#include <iostream>
#include<vector>
using namespace std;
// @lc code=start

//#define DEBUG 
ostream& operator << (ostream& os, vector<vector<int> >& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        // 循环要注意初始化, 结束以及迭代
        for (int j = 0; j < vec[i].size(); ++j) {
            os << vec[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

class Solution {
public:
    int climbStairs1(int n) {
        if (n <= 1) {
            return n;
        }
        if (n == 2) {
            return 2;
        }
        int now = 2, pri = 1;
        for (int i = 3; i <= n; ++i) {
            int ans = now + pri;
            pri = now;
            now = ans;
        }
        return now;
    }

    vector<vector<int> > maxtrixMulty(vector<vector<int> >& left, vector<vector<int> >& right) {
        vector<vector<int> > ans(2, vector<int>(2));
        for (int i = 0; i < left.size(); ++i) {
            for (int j = 0; j < right.size(); ++j) {
                ans[i][j] = 0;
                for (int l = 0; l < right.size(); ++l) {
                    ans[i][j] += (left[i][l] * right[l][j]);
                }
            }
        }
        return ans;
    }

    vector<vector<int> > fastMatrixMulty(vector<vector<int> >& base, int n) {
        // 初始化
        vector<vector<int> > ans(2, vector<int>(2));
        ans[0][0] = 1;
        ans[1][1] = 1;
        #ifdef DEBUG
        // 注意终止位置
        while(n != 0) {
            // n == 1 这个位置将终止
            if ((n & 1) == 1) {
                ans = maxtrixMulty(ans, base);
            }
            // 可能base的结果会出现越界, 这个位置要做出判断
            if( n > 1) {
                base = maxtrixMulty(base, base);
            }
            n = n >> 1;
        }
        #endif // DEBUG

        // 下面方法可以不用担心上面可能的越界
        if (n == 1) {
            return base;
        }
        while(n > 1) {
             // n == 1 这个位置将终止
            if ((n & 1) == 1) {
                ans = maxtrixMulty(ans, base);
            }
            base = maxtrixMulty(base, base);
            n = n >> 1;
        }
        return maxtrixMulty(ans, base);
    }

    int climbStairs(int n) {
        if (n <= 1) {
            return n;
        }
        if (n == 2) {
            return 2;
        }
        vector<vector<int> > base(2, vector<int>(2));
        base[0][0] = 1;
        base[0][1] = 1;
        base[1][0] = 1;
        base[1][1] = 0;
        auto ans = fastMatrixMulty(base, n - 2);
        return 2 * ans[0][0] + ans[1][0];
    }
};
// @lc code=end

int fastPowerRecursion(int base, int n) {
    if (n == 0) {
        return 1;
    }
    if ((n & 1) == 1) {
        return base * fastPowerRecursion(base * base, n >> 1);
    }
    return fastPowerRecursion(base * base, n >> 1);
}

int fastPower(int base, int n) {
    int ans = 1;
    while(n != 0) {
        // n == 1 时这个位置就是终止条件
        if ((n & 1) == 1) {
            ans *= base;
        }
        // 这个位置可能会出现越界问题
        if (n > 1) {
            base *= base;
        }
        n = n >> 1;
    }
    return ans;
}

int main() {
    Solution s;
    cout << s.climbStairs(35) << endl;
}