/*
 * @lc app=leetcode.cn id=133 lang=cpp
 * @lcpr version=30113
 *
 * [133] 克隆图
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

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        unordered_map<int, Node*> g;
        queue<Node*> q;

        g[node->val] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                auto nn = g[node->val];
                for (auto nei : node->neighbors) {
                    if (!g.count(nei->val)) {
                        g[nei->val] = new Node(nei->val);
                        q.push(nei);
                    }
                    nn->neighbors.push_back(g[nei->val]);
                }
            }
        }
        return g[node->val];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4],[1,3],[2,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[2],[1]]\n
// @lcpr case=end

 */

