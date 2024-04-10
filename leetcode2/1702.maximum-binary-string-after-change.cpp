// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 * @lcpr version=30121
 *
 * [1702] 修改后的最大二进制字符串
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
class Solution {
public:
    string maximumBinaryString_bad(string binary) {
        for (int j = binary.size() - 1; j > 0; ) {
            if (binary[j] == '1' || binary[j - 1] == '0') {
                j--;
                continue;
            }
            int k = j - 1;
            while (k >= 0 and binary[k] == '1') {
                --k;
            }
            if (k < 0) {
                break;
            }
            for (int m = k + 2; m <= j; m++) {
                binary[m] = '1';
            }
            binary[k + 1] = '0';
            j = k;
        }
        for (int i = 0; i + 1 < binary.size(); i++) {
            if (binary[i] == '0' and binary[i + 1] == '0') {
                binary[i] = '1';
            }
        }
        return binary;
    }

    string maximumBinaryString_1(string binary) {
        int start = 0;
        while (start < binary.size() and binary[start] == '1') {
            ++start;
        }
        if (start == binary.size()) {
            return binary;
        }
        int ct = count(binary.begin() + start, binary.end(), '0');
        for (int i = start; i < binary.size(); i++) {
            if (i + 1 != ct + start) {
                binary[i] = '1';
            } else {
                binary[i] = '0';
            }
        }
        return binary;
    }

    string maximumBinaryString_2(string binary) {
        int j = 0;
        int n = binary.size();
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                while (j <= i || (j < n and binary[j] == '1')) {
                    j++;
                }
                if (j < n) {
                    binary[i] = '1';
                    binary[j] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }

    string maximumBinaryString(string binary) {
        int pz = binary.find('0');
        if (pz == string::npos) {
            return binary;
        }
        int cz = count(binary.begin(), binary.end(), '0');
        string s(binary.size(), '1');
        s[pz + cz  - 1] = '0';
        return s;
    }

};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=000110
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "000110"\n
// @lcpr case=end

// @lcpr case=start
// "01"\n
// @lcpr case=end

 */

