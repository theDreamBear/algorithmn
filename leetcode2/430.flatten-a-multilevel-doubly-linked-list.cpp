/*
 * @lc app=leetcode.cn id=430 lang=cpp
 * @lcpr version=30204
 *
 * [430] 扁平化多级双向链表
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // 不是环形链表
    Node* flatten(Node* head) {
        if (!head) return head;
        auto dfs = [&](auto&& dfs, Node* h)->Node* {
            Node* cur = h;
            Node* tail = nullptr;
            while (cur) {
                Node* nxt = cur->next;
                if (cur->child) {
                    auto nt = dfs(dfs, cur->child);
                    if (cur->next) {
                        nt->next = cur->next;
                        cur->next->prev = nt;
                    }
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    tail = nt;
                    cur->child = nullptr;
                } else {
                    tail = cur;
                }
                cur = nxt;
            }
            return tail;
        };
        dfs(dfs, head);
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

