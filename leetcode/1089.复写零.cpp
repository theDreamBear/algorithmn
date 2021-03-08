/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    void duplicateZeros1(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0) {
                for (int j = arr.size() - 1; j >= i + 1; --j) {
                    arr[j] = arr[j - 1];
                }
                ++i;
            }
        }
    }

    void duplicateZeros2(vector<int>& arr) {
        int pz = 0;
        int high = arr.size() - 1;
        for (int i = 0; i <= high - pz; ++i) {
            if (arr[i] == 0) {
                // 最后一个0
                if (i == high - pz) {
                    // 不复制的 0 下面的很关键
                    arr[high] = 0;
                    --high;
                    break;
                }
                ++pz;
            }
        }
        int last = high - pz;
        for (int i = high; i >= 0; --i) {
            if (arr[last] == 0) {
                arr[i] = 0;
                if (pz-- > 0) {
                    --i;
                    arr[i] = 0;
                }
            } else {
                arr[i] = arr[last];
            }
            --last;
        }
    }

    void duplicateZeros(vector<int>& arr) {
       // 快慢指针
       int i = 0, j = 0;
       while (j < arr.size()) {
           if (arr[i] == 0) {
               ++j;
           }
           ++j;
           ++i;
       }
       --i;
       --j;
       while (j >= 0) {
           if (j < arr.size()) {
             arr[j] = arr[i];
           }
           if (arr[i] == 0) {
               arr[--j] = 0;
           }
           --j;
           --i;
       }
    }
};
// @lc code=end

int main() {
    vector<int> arr{1,0,2,3,0,4,5,0};
    Solution{}.duplicateZeros(arr);
}

