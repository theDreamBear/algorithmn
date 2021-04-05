/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include <ranges.h>
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
        空间换时间
    */
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto val : nums) {
            ++hash[val];
        }
        for (auto& kv : hash) {
            if (kv.second == 1) {
                return kv.first;
            }
        }
        return 0;
    }


    /*
        能解决正整数，但是对于负数来说则不对
    */

    struct twobitCounter {
        long long ans;
        twobitCounter() { ans = 0; }

        void setBit(int pos, long long val) {
            ans ^= (val << pos);
        }

        void add(int val) {
            for (int i = 0; i < 32; ++i) {
                int flag = (val >> i) & 0x1;
                if (!flag) {
                    continue;
                }
                int old = (ans >> (2 * i)) & (0x3);
                switch (old) {
                    case 0: {
                        setBit(2 * i, 1);
                        break;
                    }
                    case 1: {
                        setBit(2 * i, 1);
                        setBit(2 * i + 1, 1);
                        break;
                    }
                    case 2: {
                        setBit(2 * i + 1, 1);
                        break;
                    }
                }
            }
        }

        int getAns() {
            long long temp = 0;
            for (int i = 0; i < 64; i += 2) {
                long long flag = ((ans >> i) & (0x1));
                if (flag == 1) {
                    temp |= (flag << (i / 2));
                }
            }
            return temp;
        }
    };

    /*
       
    */
    int singleNumber2(vector<int>& nums) {
        twobitCounter tc;
        for (auto val : nums)  {
            tc.add(val);
        }
        return tc.getAns();
    }

    /*
        解法2 用一个64 位的数来记录结果的， 可以用两个int 代替
        对于第 i 位， once[i] twice[i] 共同记录出现的次数
        if val[i] = 0, 不变
        if val[i] = 1, once[i] = 0, twice[i] = 0  => once[i] = 1, twice[i] = 0
                       once[i] = 1, twice[i] = 0  => once[i] = 0, twice[i] = 1
                       once[i] = 0, twice[i] = 1  => once[i] = 0, twice[i] = 0;
        once[i] = once[i] ^ val[i] & ~twice[i]
        twice[i] = twice[i] ^ val[i] & ~once[i]
    */
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (auto val : nums) {
            once = once ^ val & ~twice;
            twice = twice ^ val & ~once;
        }
        return once;
    }

};
// @lc code=end

int main() {
    vector<int> data = {-1, 2, 2, 2};
    cout << Solution{}.singleNumber(data);
}