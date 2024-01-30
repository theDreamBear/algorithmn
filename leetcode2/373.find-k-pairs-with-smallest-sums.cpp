/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30114
 *
 * [373] 查找和最小的 K 对数字
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
/*
1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 和 nums2 均为 升序排列
1 <= k <= 10^4
k <= nums1.length * nums2.length
*/
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    struct Node {
        int l, r;

        bool operator<(const Node& parent) const {
            return l + r > parent.l + parent.r;
        }

        int sum() const {
            return l + r;
        }
    };

    static bool sCmp(const Node& lhs, const Node& rhs) {
        return lhs.sum() < rhs.sum();
    }

    /*
        暴力解法
        1 <= nums1.length, nums2.length <= 10^5
        -10^9 <= nums1[i], nums2[i] <= 10^9
        nums1 和 nums2 均为 升序排列
        1 <= k <= 10^4
        k <= nums1.length * nums2.length

        时间复杂度 O(m * n  * lg(m * n)) 太大了
        空间复杂度O(m * n)

        还有个问题是，我们其实只需要部分的数据， 而不是全部数据
    */
    vector<vector<int>> kSmallestPairs_violatile(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> ans;
        vector<Node> tmp;
        for (auto l : nums1) {
            for (auto r : nums2) {
                tmp.push_back({l, r});
            }
        }
        sort(tmp.begin(), tmp.end(), sCmp);
        for (int i = 0; i < k && i < tmp.size(); i++) {
            ans.push_back({tmp[i].l, tmp[i].r});
        }
        return ans;
    }

    vector<vector<int>> kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int ct = k;
        vector<vector<int>> ans;
        priority_queue<Node, vector<Node>> priority;
        for (int i = 0; i <= m && ct > 0; ) {
            if (priority.empty() || (i < m && priority.top().sum() > nums1[i] + nums2.front())) {
                for (int j = 0; j < n; j++) {
                    priority.push({nums1[i], nums2[j]});
                }
                i++;
            }
            if (!priority.empty()) {
                ans.push_back({priority.top().l, priority.top().r});
                priority.pop();
                --ct;
            } else {
                break;
            }
        }
        return ans;
    }

    /*
        时间复杂度
        nk = 10^5 * 10^ 4 = 10^ 9 超时
    */
    vector<vector<int>> kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> ans;
        unordered_map<int, int> pos;
        for (int i = 0; i < m; i++) {
            pos[i] = 0;
        }
        for (int i = 0; i < k && !pos.empty(); i++) {
            auto tmp = pos.end();
            for (auto it = pos.begin(); it != pos.end(); it++) {
                if (tmp == pos.end()) {
                    tmp = it;
                    continue;
                }
                if (nums1[it->first] + nums2[it->second] < nums1[tmp->first] + nums2[tmp->second]) {
                    tmp = it;
                }
            }
            if (tmp == pos.end()) {
                break;
            }
            ans.push_back({nums1[tmp->first], nums2[tmp->second]});
            if (++tmp->second == n) {
                pos.erase(tmp);
            }
        }
        return ans;
    }

    /*
        优先队列存储直接是下标对
    */
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int ct = k;
        vector<vector<int>> ans;
        auto cmp = [&](const Node& lhs, const Node& rhs) {
            return nums1[lhs.l] + nums2[lhs.r] > nums1[rhs.l] + nums2[rhs.r];
        };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.push({i, 0});
        }
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.push({x, y + 1});
            }
        }
        return ans;
    }

    // 还有个二分法，能用二分法的前提是， 存在二分边界
    /*
        在解决算法题时，判断是否可以使用二分查找法（二分枚举法）通常依赖于以下几个关键因素：
        有序性：二分查找法适用于有序序列。如果问题涉及到已排序的数组或可排序的序列，则可能适合使用二分查找。
        目标函数的单调性：如果你可以定义一个单调的目标函数（即函数值随着输入的增加或减少而单调增加或减少），那么二分查找可能是个好选择。例如，在最大化或最小化某个目标时，如果可以证明目标函数是单调的，则可以使用二分查找来确定最优点。
        存在上下界：如果问题的解决方案存在明确的上下界限，并且你可以根据这些边界进行猜测和调整，那么二分查找可以有效应用。
        快速验证中间解：二分查找的一个关键是能够快速验证“中间”解。如果你可以快速确定当前猜测的解是否过高、过低或足够好，那么二分查找可能适合该问题。

    */
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3]\n3\n
// @lcpr case=end

 */

