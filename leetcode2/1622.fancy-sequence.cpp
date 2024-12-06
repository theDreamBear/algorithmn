/*
 * @lc app=leetcode.cn id=1622 lang=cpp
 * @lcpr version=30204
 *
 * [1622] 奇妙序列
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
class Fancy {
public:
    class Tree {
    public:
        int n;
        vector<int> tree;
        

        Tree(int sz):tree(sz << 2), addTag(sz << 2), mulTag(sz << 2) {
            n = 0;
        }

        void multiAll(int o, int l, int r, int m) {

        }
    };

    Fancy() {
        
    }
    
    void append(int val) {
        
    }
    
    void addAll(int inc) {
        
    }
    
    void multAll(int m) {
        
    }
    
    int getIndex(int idx) {
        
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex","getIndex"][[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]\n
// @lcpr case=end

 */

