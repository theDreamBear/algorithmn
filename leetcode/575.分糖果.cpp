/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
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
    循环不变式
    [0, pos]  不存在重复元素区域
    (pos, i) 重复区域
    [i,j) 待处理区域
    循环不变式成立

    **/
    // 使用前需要排序
    int my_unique(vector<int>& candyType) {
        int i = 0;
        int j = candyType.size();
        int pos = 0;
        while (++i != j) {
            if (candyType[pos] != candyType[i]) {
                ++pos;
                swap(candyType[pos], candyType[i]);
            }
        }
        return ++pos;
    }

    /*
        排序后, 计算糖果种类
        若 糖果种类大于等于总糖果的一半, 那么妹妹必然可以得到总糖果一半类型的糖果
        若 种类少于总糖果一半, 那么妹妹必然可以得到所有类型的糖果
    */
    int distributeCandies(vector<int>& candyType) {
        int sz = candyType.size();
        sort(candyType.begin(), candyType.end());
       // auto po = unique(candyType.begin(), candyType.end());
        auto po = my_unique(candyType);
        int usz = po;
        if (usz * 2 >= sz) {
            return sz / 2;
        }
        return usz;
    }
};
// @lc code=end

