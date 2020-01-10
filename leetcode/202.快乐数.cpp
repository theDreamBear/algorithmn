/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (56.30%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    40.3K
 * Total Submissions: 71.2K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */
#include <set>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int bitSquare(int n) {
        int ans = 0;
        while(n != 0) {
            int x = n % 10;
            n /= 10;
            ans += (x * x);
        }
        return ans;
    }
    bool isHappy(int n) {
        // trick
        #ifdef DEBUG
        int maxtimes = 10000;
        while(maxtimes > 0) {
            int ans = 0;
            while(n != 0) {
                int x = n % 10;
                n /= 10;
                ans += (x * x);
            }
            if (ans == 1) {
                return true;
            }
            --maxtimes;
            n = ans;
        }
        return false;
         #endif // DEBUG

        // 什么时候回无线循环, 不快乐
        // 答 重复了
        #ifdef DEBUG
        set<int> set;
        set.insert(n);
        while(true) {
            int ans = 0;
            while(n != 0) {
                int x = n % 10;
                n /= 10;
                ans += (x * x);
            }
            if (ans == 1) {
                return true;
            }
            if (set.find(ans) != set.end()) {
                return false;
            }
            set.insert(ans);
            n = ans;
        }
        return false;
        #endif // DEBUG
        
        // 快慢指针破循环
        if (n == 1) {
            return true;
        }
        int slow = bitSquare(n);
        int fast = bitSquare(bitSquare(n));
        if (fast == 1) {
            return true;
        }
        while(slow != fast) {
            slow = bitSquare(slow);
            fast = bitSquare(bitSquare(fast));
            if (slow == 1 || fast == 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    for(int i = 0; i < 1000; ++i) {
        if (s.isHappy(i)) {
            cout << i << " ";
        }
    }
}

