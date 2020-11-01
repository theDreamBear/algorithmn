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
        bool operator()(int left, int right) const{
            return nums[left - 1] > nums[right - 1];
        }
    };

    bool canBeThere(int pos, int bricks, set<int>&  useLadder, vector<int>& next) {
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
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
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
};

int main() {
    vector<int> height = {14,3,19,3};
    auto bricks =  17;
    auto ladders = 0;
    cout << Solution{}.furthestBuilding(height, bricks, ladders);
}