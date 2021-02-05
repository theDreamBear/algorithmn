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

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool matrixValid(int i, int j, const vector<vector<int>>& matrix) {
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size()) {
        return false;
    }
    return true;
}

bool matrixDfs(int i, int j, vector<vector<int>>& matrix,
               vector<vector<bool>> visited) {
    // 边界
    if (visited[i][j] || !matrixValid(i, j, matrix)) {
        return false;
    }
    // 修改
    visited[i][j] = true;
    bool ok = false;

    // 递归
    for (int k = 0; k < 4; ++k) {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if (!matrixValid(xx, yy, matrix)) {
            continue;
        }
        ok |= matrixDfs(xx, yy, matrix, visited);
        if (ok) {
            return ok;
        }
    }
    //
    // visited[i][j] = false;
    return false;
}

int main() {}