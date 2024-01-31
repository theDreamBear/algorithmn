/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30114
 *
 * [77] 组合
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
    /*
        1、 不可排序或者排序无用
        2、 子序列
        2、2 ^ n
        3、选择， 不选择
        4、每次入队之后进行校验

    */
    void dfs(int n, int k, int cur, vector<int>& tmp,  vector<vector<int>>& ans) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (n - cur + 1 + tmp.size() < k) {
            return;
        }
        // 不选
        dfs(n, k, cur + 1, tmp, ans);
        // 选择
        tmp.push_back(cur);
        dfs(n, k, cur + 1, tmp, ans);
        // 回溯
        tmp.pop_back();
    }


    vector<vector<int>> combine_binary(int n, int k) {
        vector<vector<int>> ans;
        if (n < k) {
            return ans;
        }
        vector<int> tmp;
        dfs(n, k, 1, tmp, ans);
        return ans;
    }

    void dfs_for(int n, int k, int cur, vector<int>& tmp,  vector<vector<int>>& ans) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (n - cur + 1 + tmp.size() < k) {
            return;
        }
        for (int pos = cur; pos <= n; pos++) {
            tmp.push_back(pos);
            dfs_for(n, k, pos + 1, tmp, ans);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (n < k) {
            return ans;
        }
        vector<int> tmp;
        dfs_for(n, k, 1, tmp, ans);
        return ans;
    }

    /*
        层次遍历
        问题是空间复杂度太高了
    */
    vector<vector<int>> combine2(int n, int k) {
        vector<vector<int>> ans;
        // 递归树的层次遍历
        vector<int> temp;
        queue<vector<int>> q;
        int cur = 0;
        q.push(temp);
        while (!q.empty()) {
            ++cur;
            if (cur > n) {
                break;
            }
            int sz = q.size();
            for (int i =0; i < sz; i++) {
                auto data = move(q.front());
                q.pop();
                if (data.size() > k) {
                    continue;
                }
                auto old = data;
                data.push_back(cur);
                if (data.size() == k) {
                    ans.push_back(move(data));
                } else if (cur < n) {
                    q.push(move(data));
                }
                if (cur < n) {
                    q.push(move(old));
                }
            }
        }
        return ans;
    }

    /*
        使用数组比队列好的地方是不用频繁出队列
    */
    vector<vector<int>> combine3(int n, int k) {
        vector<vector<int>> ans;
        // 递归树的层次遍历
        vector<vector<int>> cur;
        cur.push_back({});
        for (int i = 1; i <= n; i++) {
            int sz = cur.size();
            for (int j = 0; j < sz; j++) {
                auto temp = cur[j];
                temp.push_back(i);
                if (temp.size() == k) {
                    ans.push_back(temp);
                    // 最后一层不须要继续入队列
                } else if (i != n) {
                    cur.push_back(move(temp));
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

