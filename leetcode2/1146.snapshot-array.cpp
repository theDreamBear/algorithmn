/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 * @lcpr version=30122
 *
 * [1146] 快照数组
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
class SnapshotArray {
private:
    struct Node {
        int snap_id;
        int val;
    };

    int snapId = 0;
    vector<vector<Node>> data;

public:
    SnapshotArray(int length):data(length) {
        for (int i = 0; i < length; i++) {
            data[i].push_back({-1, 0});
        }
    }

    void set(int index, int val) {
        if (data[index].size() < snapId + 1 and data[index].back().snap_id < snapId) {
            data[index].push_back({snapId, -1});
        }
        data[index].back().val = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto& vec = data[index];
        auto it = lower_bound(vec.rbegin(), vec.rend(), snap_id, [&](Node& lhs, int snap_id) {
            return lhs.snap_id > snap_id;
        });
        return it->val;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end



/*
// @lcpr case=start
// ["SnapshotArray","set","snap","set","get"][[3],[0,5],[],[0,6],[0,0]]\n
// @lcpr case=end

 */

