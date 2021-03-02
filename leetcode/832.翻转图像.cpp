/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); ++i) {
            for (int m = 0, n = image[i].size() - 1; m <= n; ++m, --n) {
                if (image[i][m] == image[i][n]) {
                    image[i][n] = !image[i][n];
                    if (m != n) {
                        image[i][m] = !image[i][m];
                    }
                }
            }
        }
        return image;
    }
};
// @lc code=end

