/*
 * @lc app=leetcode.cn id=1386 lang=cpp
 * @lcpr version=30122
 *
 * [1386] 安排电影院座位
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
    // 内存超限制了
    int maxNumberOfFamilies_OOM(int n, vector<vector<int>>& reservedSeats) {
        vector<short> bits(n, -1);
        for (auto& vec : reservedSeats) {
            int idx = vec[0] - 1;
            int p   = vec[1];
            bits[idx] ^= (1 << p);
        }
        int ans = 0;
        for (auto v : bits) {
            if ((v & 0x3fc) == 0x3fc) {
                ans += 2;
            } else if ((v & 0x3c) == 0x3c) {
                ans++;
            } else if ((v & 0x3c0) == 0x3c0) {
                ans++;
            } else if ((v & 0xf0) == 0xf0) {
                ans++;
            }
        }
        return ans;
    }

    int maxNumberOfFamilies2(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), [&](const vector<int>& left, const vector<int>& right) {
            if (left[0] != right[0]) {
                return left[0] < right[0];
            }
            return left[1] < right[1];
        });
        int v      = -1;
        int curIdx = -1;
        int ans = 0;
        for (auto& vec : reservedSeats) {
            int idx = vec[0] - 1;
            int p   = vec[1];
            if (curIdx == -1 || curIdx == idx) {
                curIdx = idx;
            } else {
                if ((v & 0x3fc) == 0x3fc) {
                    ans += 2;
                } else if ((v & 0x3c) == 0x3c) {
                    ans++;
                } else if ((v & 0x3c0) == 0x3c0) {
                    ans++;
                } else if ((v & 0xf0) == 0xf0) {
                    ans++;
                }
                v      = -1;
                curIdx = idx;
                n--;
            }
            v ^= (1 << p);
        }
        n--;
        if ((v & 0x3fc) == 0x3fc) {
            ans += 2;
        } else if ((v & 0x3c) == 0x3c) {
            ans++;
        } else if ((v & 0x3c0) == 0x3c0) {
            ans++;
        } else if ((v & 0xf0) == 0xf0) {
            ans++;
        }
        ans += n * 2;
        return ans;
    }
    
    int cal(int v) {
        if ((v & 0x3fc) == 0x3fc) {
            return 2;
        }
        if ((v & 0x3c) == 0x3c || (v & 0x3c0) == 0x3c0 || (v & 0xf0) == 0xf0) {
            return 1;
        }
        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> occupied;
        for (auto& vec : reservedSeats) {
            int idx = vec[0];
            int p   = vec[1];
            if (!occupied.count(idx)) {
                occupied[idx] = -1;
            }
            occupied[idx] ^= (1 << p);
        }
        int ans = (n - occupied.size()) << 1;
        for (auto& [k, v] : occupied) {
            ans += cal(v);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n[[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[2,1],[1,8],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[4,3],[1,4],[4,6],[1,7]]\n
// @lcpr case=end

 */
