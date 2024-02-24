/*
 * @lc app=leetcode.cn id=LCR 157 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 157] 套餐内商品的排列顺序
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
class Solution1 {
    unordered_set<string> set;
    int n=0;
    void helper(string& s, int begin){
        if(begin==n){
            set.insert(s);
            return;
        }
        for(int i=begin;i<n;++i){
            swap(s[i],s[begin]);
            helper(s,begin+1);
            swap(s[i],s[begin]);
        }
    }
public:
    vector<string> goodsOrder(string s) {
        n=s.size();
        helper(s,0);
        return vector<string>(set.begin(),set.end());
    }
};

class Solution {
public:
    void goodsOrder(string& goods, vector<string>& ans, int pos) {
        if (pos >= goods.size()) {
            ans.push_back(goods);
            return;
        }
        vector<int> ct(26);
        for (int i = pos; i < goods.size(); i++) {
            if (ct[goods[i] - 'a'] > 0) {
                continue;
            }
            ct[goods[i] - 'a']++;
            swap(goods[i], goods[pos]);
            goodsOrder(goods, ans, pos + 1);
            swap(goods[i], goods[pos]);
        }
    }

    vector<string> goodsOrder(string goods) {
        sort(goods.begin(), goods.end());
        vector<string> ans;
        goodsOrder(goods, ans, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "agew"\n
// @lcpr case=end

 */

