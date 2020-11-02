#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<int> nums;

class Solution {
 public:
    int furthestBuildingHelper(int i, int bricks, int ladders,
                               const vector<int>& next) {
        if (i == next.size() || (bricks < next[i] && ladders <= 0)) {
            // 不能往前走了
            return 0;
        }
        if (next[i] == 0) {
            return furthestBuildingHelper(i + 1, bricks, ladders, next) + 1;
        }
        int useBricks = 0;
        if (bricks >= next[i]) {
            useBricks =
                furthestBuildingHelper(i + 1, bricks - next[i], ladders, next);
        }
        int useLadders = 0;
        if (ladders > 0) {
            useLadders =
                furthestBuildingHelper(i + 1, bricks, ladders - 1, next);
        }
        return max(useBricks, useLadders) + 1;
    }

    // 超时
    int furthestBuilding_dfs(vector<int>& heights, int bricks, int ladders) {
        vector<int> next;
        for (int i = 0; i < heights.size() - 1; ++i) {
            if (heights[i] >= heights[i + 1]) {
                next.push_back(0);
            } else {
                next.push_back(heights[i + 1] - heights[i]);
            }
        }
        return furthestBuildingHelper(0, bricks, ladders, next);
    }

    struct keyComparator {
        /*
        先按值从大到小排
        值相同按 index从小按大排
        */
        bool operator()(int left, int right) const {
            if (nums[left - 1] != nums[right - 1]) {
                return nums[left - 1] > nums[right - 1];
            } else {
                return left < right;
            }
        }
    };

    bool canBeThere(int pos, int bricks, set<int>& useLadder,
                    const vector<int>& next) {
        int leftBricks = bricks;
        for (int i = 1; i <= pos; ++i) {
            if (useLadder.find(i) != useLadder.end()) {
                continue;
            } else {
                leftBricks -= next[i - 1];
                if (leftBricks < 0) {
                    return false;
                }
            }
        }
        return true;
    }

    /*
     * 仍然超时
     * */
    int furthestBuilding_bad(vector<int>& heights, int bricks, int ladders) {
        vector<int> next;
        for (int i = 0; i < heights.size() - 1; ++i) {
            if (heights[i] >= heights[i + 1]) {
                next.push_back(0);
            } else {
                next.push_back(heights[i + 1] - heights[i]);
            }
        }
        nums = next;

        map<int, int, keyComparator> mp;
        for (int i = 1; i < ladders; ++i) {
            mp[i] = next[i - 1];
        }
        int maxValue = ladders;
        for (int i = ladders + 1; i < heights.size(); ++i) {
            mp[i] = next[i - 1];
            set<int> useLadder;
            int count = 0;
            for (auto it = mp.begin();;) {
                if (count == ladders) {
                    break;
                }
                useLadder.insert(it->first);
                ++count;
                ++it;
            }
            if (canBeThere(i, bricks, useLadder, next)) {
                maxValue = i;
            } else {
                break;
            }
        }
        return min(maxValue, int(heights.size() - 1));
    }

    bool canBe(int pos, const map<int, int, keyComparator>& mp,
               const vector<int>& next, int bricks, int ladders) {
        set<int> useLadder;
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (count == ladders) {
                break;
            }
            if (it->first > pos) {
                continue;
            }
            useLadder.insert(it->first);
            ++count;
        }

        return canBeThere(pos, bricks, useLadder, next);
    }

    /*
    仍然超时
    1 <= heights.length <= 105
    1 <= heights[i] <= 106
    0 <= bricks <= 109
    0 <= ladders <= heights.length
    */
    int furthestBuilding_not_so_bad(vector<int>& heights, int bricks,
                                    int ladders) {
        vector<int> next;
        for (int i = 0; i < heights.size() - 1; ++i) {
            if (heights[i] >= heights[i + 1]) {
                next.push_back(0);
            } else {
                next.push_back(heights[i + 1] - heights[i]);
            }
        }
        nums = next;
        map<int, int, keyComparator> mp;
        for (int i = 1; i < next.size(); ++i) {
            mp[i] = next[i - 1];
        }
        int maxValue = ladders - 1;
        int left = max(0, ladders - 1);
        int right = heights.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canBe(mid, mp, next, bricks, ladders)) {
                maxValue = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return maxValue;
    }


    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // 如果梯子足够多
        if (ladders + 1 >= heights.size()) {
            return heights.size() - 1;
        }

        vector<int> costs;
        // costs[i] 从 i- 1 到 i的代价
        costs.push_back(0);
        for (int i = 0; i < heights.size() - 1; ++i) {
            if (heights[i] >= heights[i + 1]) {
                costs.push_back(0);
            } else {
                costs.push_back(heights[i + 1] - heights[i]);
            }
        }
        priority_queue<int> qq;
        int leftBricks = bricks;
        int leftLadders = ladders;
#ifdef USE_LADDERS_FIRST
        for (int i = 0; i < heights.size(); ++ i) {
            if (costs[i] == 0) {
                continue;
            }
            if (leftBricks >= costs[i]) {
                leftBricks -= costs[i];
                qq.push(costs[i]);
                continue;
            }
            //

            bool ok = false;
            while (leftLadders > 0 && leftBricks < costs[i]) {
                if (qq.empty() || qq.top() < costs[i]) {
                    --leftLadders;
                    ok = true;
                    break;
                }
                if (leftLadders > 0 && !qq.empty()) {
                    auto x = qq.top();
                    leftBricks += x;
                    --leftLadders;
                }

            }
            if (!ok) {
                if (leftBricks >= costs[i]) {
                    leftBricks -= costs[i];
                    qq.push(costs[i]);
                    continue;
                } else {
                    return i - 1;
                }
            }
        }
#else
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 1; i < heights.size();++i) {
            if (costs[i] == 0) {
                continue;
            }
            minHeap.push(costs[i]);
            if (minHeap.size() > ladders) {
                leftBricks -= minHeap.top();
                minHeap.pop();
                if (leftBricks < 0)  {
                    return i - 1;
                }
            }
        }
#endif
        return heights.size() - 1;
    }
};

int main() {
    vector<int> height = {14,3,19,3};
    auto bricks = 17;
    auto ladders = 0;
    cout << Solution{}.furthestBuilding(height, bricks, ladders);
}