/*
 * @lc app=leetcode.cn id=997 lang=cpp
 * @lcpr version=30114
 *
 * [997] 找到小镇的法官
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
    int findJudge1(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n + 1);
        vector<int> inDegree(n + 1);
        for (auto vec : trust) {
            outDegree[vec[0]]++;
            inDegree[vec[1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (outDegree[i] == 0 and inDegree[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }

    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1);
        for (auto vec : trust) {
           degree[vec[0]] += 2000;
           degree[vec[1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (degree[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,3],[2,3],[3,1]]\n
// @lcpr case=end

 */

