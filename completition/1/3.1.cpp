#include <vector>
using namespace std;


class Solution {
public:
    constexpr static int dx[] = {0, -1, 0, 1};
    constexpr static int dy[] = {-1, 0, 1, 0};
    
    bool binary_dfs(int i, int j, vector<vector<int>>& heights, int limit, vector<vector<bool>>& used) {
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            return true;
        }
        used[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= heights.size() || ny < 0 ||
                ny >= heights[0].size() || used[nx][ny]) {
                continue;
            }
            if (abs(heights[i][j] - heights[nx][ny]) <= limit) {
                if (binary_dfs(nx, ny, heights, limit, used)) {
                    return true;
                }
            }
        }
        used[i][j] = false;
        return false;
    }

    void reset(vector<vector<bool>>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                vec[i][j] = false;
            }
        }
    }

    /* 
    二分 + dfs
    */
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 999999;
        vector<vector<bool>> used(heights.size(), vector<bool>(heights[0].size(), false));
        while (left < right) {
            int mid = (left + right) / 2;
            if (binary_dfs(0, 0, heights, mid, used)) {
                right = mid;
            } else {
                left = mid + 1;
            }
            reset(used);
        }
        return left;
    }
};