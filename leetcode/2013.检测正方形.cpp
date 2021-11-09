/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
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
class DetectSquares {
 private:
    map<pair<int, int>, int> data;
    map<int, vector<int>> rowEqualData;
 public:
    DetectSquares() {
    }

    void add(vector<int> point) {
        auto p = make_pair(point[0], point[1]);
        ++data[p];
        rowEqualData[point[0]].push_back(point[1]);
    }

    int countHelper(int x, int y, int y1) {
        int d = abs(y - y1);
        int ans = 0;
        auto r1 = make_pair(x + d, y);
        auto r2 = make_pair(x + d, y1);
        if (data.count(r1) && data.count(r2)) {
            ans += data[r1] * data[r2];
        }
        auto l1 = make_pair(x - d, y);
        auto l2 = make_pair(x - d, y1);
        if (data.count(l1) && data.count(l2)) {
            ans += data[l1] * data[l2];
        }
        return ans;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        // 找x 相同的值
        if (rowEqualData.count(x) == 0) {
            return 0;
        }
        int ans = 0;
        for (auto & y1 : rowEqualData[x]) {
            if (y1 == y) {
                continue;
            }
            ans += countHelper(x, y, y1);
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

