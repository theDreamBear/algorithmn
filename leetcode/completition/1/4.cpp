#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        typedef tuple<int, int, int> node ;
        typedef priority_queue<node, vector<node>, greater<node>> pqueen;

        vector<pqueen> rowVec(matrix.size());
        vector<pqueen> colVec(matrix[0].size());
       // pqueen all;

        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), -1));
        int total = matrix.size() * matrix[0].size();

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                rowVec[i].push({matrix[i][j], i, j});
               // all.push({matrix[i][j], i, j});
            }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                colVec[i].push({matrix[j][i], j, i});
            }
        }
        int cur = 1;
        while (true) {
            queue<vector<int>> change;
            bool wait = false;
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[i].size(); ++j) {
                    if (ans[i][j] == -1) {
                        auto [v1, x1, y1] = rowVec[i].top();
                        auto [v2, x2, y2] = colVec[j].top();
                        if (x1 == x2 && y1 == y2) {
                            change.push({x1, y1});
                        }
                    }
                }
            }
            if (change.empty()) {
                break;
            }
            while (!change.empty()) {
                auto nd = change.front(); change.pop();
                int x = nd[0];
                int y = nd[1];
                
                int v = matrix[x][y];
                ans[x][y] = cur;
                rowVec[x].pop();
                colVec[y].pop();
                
                if ((!rowVec[x].empty() && get<0>(rowVec[x].top()) == v) || !colVec[y].empty() && get<0>(colVec[y].top()) == v) {
                    for (int i = 0; i < matrix.size(); ++i) {
                        auto [v1, x1, y1] = rowVec[i].top();
                        if (v1 == v) {
                            change.push({x1, y1});
                        }
                    } 
                    for (int j = 0; j < matrix[0].size(); ++j) {
                        auto [v1, x1, y1] = colVec[j].top();
                        if (v1 == v) {
                            change.push({x1, y1});
                        }
                    } 
                }
            }
           
            ++cur;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> v = {{7,7},{7,7}};
    auto ans = Solution{}.matrixRankTransform(v);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
}