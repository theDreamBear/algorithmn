/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */
#include<vector>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 简单并查集
    struct UnionQuery {
        int sz;
        int* fa;
        int* rank;
        UnionQuery(int sz) {
            this->sz = sz;
            fa = new int[sz];
            rank = new int[sz];
            init();
        }
        // 初始化
        void init() {
            for (int i = 0; i < sz; ++i) {
                fa[i] = i;
                rank[i] = 1;
            }
        }
        
        // 查找
        int find(int x) {
            if (x == fa[x]) {
                return x;
            }
            // 压缩
            fa[x] = find(fa[x]);
            return fa[x];
        }

        // 合并
        void merge(int i, int j) {
            int p = find(i);
            int q = find(j);
            if (rank[p] <= rank[q]) {
                fa[p] = q;
            } else {
                fa[q] = p;
            }
            if (rank[p] == rank[q] && p != q) {
                ++rank[q];
            }
        }

        ~UnionQuery() {
            delete []fa;
            delete []rank;
        }
    };


    int findCircleNum(vector<vector<int>>& M) {
        UnionQuery uq(M.size());
        set<int> pset;
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (M[i][j] == 1) {
                    uq.merge(i, j);
                }
            }
        }
        for (int i = 0; i < M.size(); ++i) {
            pset.insert(uq.find(i));
        }
        return pset.size();
    }
};
// @lc code=end

