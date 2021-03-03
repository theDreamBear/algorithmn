/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int robotSim1(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction = 0;
        int max_distance = 0;
        int x = 0, y = 0;

        set<pair<int, int>>  obs;
        for (auto& vec : obstacles) {
            obs.insert({vec[0], vec[1]});
        }

        for (auto v : commands) {
            if (v < 0) {
                if (v == -2) {
                    direction = (direction + 3) % 4;
                } else {
                    direction = (direction + 1) % 4;
                }
            } else {
                switch (direction) {
                    case 0 : {
                        int newy = y + v;
                        ++y;
                        for (; y <= newy; ++y) {
                            if (obs.count({x, y}) != 0) {
                                break;
                            }
                        }
                        --y;
                        break;
                    }
                    case 1 : {
                        int newx = x + v;
                        ++x;
                        for (; x <= newx; ++x) {
                            if (obs.count({x, y}) != 0) {
                                break;
                            }
                        }
                        --x;
                        break;
                    }
                    case 2 : {
                        int newy = y - v;
                        --y;
                        for (; y >= newy; --y) {
                            if (obs.count({x, y}) != 0) {
                                break;
                            }
                        }
                        ++y;
                        break;
                    }
                    case 3 : {
                        int newx = x - v;
                        --x;
                        for (; x >= newx; --x) {
                            if (obs.count({x, y}) != 0) {
                                break;
                            }
                        }
                        ++x;
                        break;
                    }
                }
                max_distance = max(max_distance, x * x + y * y);
            }
        }
        return max_distance;
    }

    // dir 简化操作
    vector<vector<int>> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);
    
            return h1 ^ h2;
        }
    };

    /*
        若不定义hash 函数， 则需要把 unordered_set 改成 set
    */
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int direction = 0;
        int max_distance = 0;
        int x = 0, y = 0;

        unordered_set<pair<int, int>, pair_hash>  obs;
        for (auto& vec : obstacles) {
            obs.insert({vec[0], vec[1]});
        }

        for (auto v : commands) {
            if (v < 0) {
                if (v == -2) {
                    direction = (direction + 3) % 4;
                } else {
                    direction = (direction + 1) % 4;
                }
            } else {
                while (v) {
                    int nx = x + dir[direction][0];
                    int ny = y + dir[direction][1];
                    if (obs.count({nx, ny}) == 0) {
                        x = nx;
                        y = ny;
                    } else {
                        break;
                    }
                    --v;    
                }
                max_distance = max(max_distance, x * x + y * y);
            }
        }
        return max_distance;
    }
};
// @lc code=end

