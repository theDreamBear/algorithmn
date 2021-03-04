/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
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
    /*
        c++ stl
    */
    vector<int> sortArrayByParity1(vector<int>& A) {
        vector<int> ans;
        copy_if(A.begin(), A.end(), back_insert_iterator(ans), [](int x) {
            return x % 2 == 0;
        });
        copy_if(A.begin(), A.end(), back_insert_iterator(ans), [](int x) {
            return x % 2 != 0;
        });
        return ans;
    }

     vector<int> sortArrayByParity2(vector<int>& A) {
        partition(A.begin(), A.end(), [](int val) {
            return val % 2 == 0;
        });
        return A;
    }

    /*
        [0, d] 为偶数区
        [d + 1, i) 为奇数区
        [i, sz) 待定区
    */
    void mypartition(vector<int>& A) {
        int d =  -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] % 2 == 0) {
                ++d;
                if (d != i) {
                    swap(A[i], A[d]);
                }
            }
        }
    }

    vector<int> sortArrayByParity(vector<int>& A) {
        mypartition(A);
        return A;
    }

};
// @lc code=end

