/*
 * @lc app=leetcode.cn id=427 lang=cpp
 * @lcpr version=30113
 *
 * [427] 建立四叉树
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
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

const int dx[4] = {0, 0, 1, 1};
const int dy[4] = {0, 1, 1, 0};

Node* Node:: *children[4] = {&Node::topLeft, &Node::topRight, &Node::bottomRight, &Node::bottomLeft};

class Solution1 {
public:
    struct One {
        int x, y, rows, cols;

        One(){
            x = y = rows = cols = 0;
        }

        void setBase(int nx, int ny) {
            x = nx;
            y = ny;
        }

        void setRC(int r, int c) {
            rows = r;
            cols = c;
        }
    };

    bool allSame(const vector<vector<int>>& grid, const One& one) {
        bool value = grid[one.x][one.y];
        for (int i = 0; i < one.rows; i++) {
            for (int j = 0; j < one.cols; j++) {
                if (grid[one.x + i][one.y + j] != value) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* construct(const vector<vector<int>>& grid, const One& one) {
        // 边界条件
        if (one.rows <= 0 || one.cols <= 0 || one.rows != one.cols) {
            assert("rc invalid");
        }
        // 只剩一个
        if (one.rows == 1 && one.cols == 1 ) {
            Node* node = new Node(grid[one.x][one.y], true);
            return node;
        }
        // 全相同
        if (allSame(grid, one)) {
            Node* node = new Node(grid[one.x][one.y], true);
            return node;
        }
        // 切分
        Node* root = new Node(false, false);
        int half = one.rows >> 1;
        for (int d = 0; d < 4; d++) {
            int nx = one.x + dx[d] * half;
            int ny = one.y + dy[d] * half;
            One child;
            child.setBase(nx, ny);
            child.setRC(half, half);
            root->*children[d] = construct(grid, child);
        }
        return root;
    }


    Node* construct(vector<vector<int>>& grid) {
        One one;
        one.setBase(0, 0);
        one.setRC(grid.size(), grid[0].size());
        return construct(grid, one);
    }
};


class Solution3 {
public:
    struct One {
        int x, y, rows, cols;

        One(){
            x = y = rows = cols = 0;
        }

        void setBase(int nx, int ny) {
            x = nx;
            y = ny;
        }

        void setRC(int r, int c) {
            rows = r;
            cols = c;
        }
    };

    bool allSame(const vector<vector<int>>& grid, const One& one) {
        bool value = grid[one.x][one.y];
        for (int i = 0; i < one.rows; i++) {
            for (int j = 0; j < one.cols; j++) {
                if (grid[one.x + i][one.y + j] != value) {
                    return false;
                }
            }
        }
        return true;
    }

    class IteItem {
    private:
        void _get_one_item() {
            d++;
            if (d >= 4) {
                this->ptr = nullptr;
                return;
            }
            int nx = x + dx[d] * half;
            int ny = y + dy[d] * half;
            one.setBase(nx, ny);
            one.setRC(half, half);
            this->ptr = children[d];
            return;
        }

        IteItem() {
            half = 0;
            ptr = nullptr;
        }
    public:
        int x, y;
        One one;
        Node* Node:: *ptr;
        int d, half;

        IteItem(const One one, int half):ptr(nullptr){
            x = one.x;
            y = one.y;
            this->one = one;
            d = -1;
            this->half = half;
            if (half > 0) {
                _get_one_item();
            }
        }

        static IteItem end() {
            return {};
        }

        bool operator!= (const IteItem& rhs) const{
            return ptr != rhs.ptr;
        }

        IteItem& operator++() {
            _get_one_item();
            return *this;
        }
    };

    class Ite {
    private:
        const One one;
        int half;
    public:
        Ite(const One& one, int half):one(one) {
            this->half = half;
        }

        IteItem begin() {
            return IteItem(one, half);
        }

        IteItem end() {
            return IteItem::end();
        }

    };


    Node* construct(const vector<vector<int>>& grid, const One& one) {
        // 边界条件
        if (one.rows <= 0 || one.cols <= 0 || one.rows != one.cols) {
            assert("rc invalid");
        }
        // 只剩一个
        if (one.rows == 1 && one.cols == 1 ) {
            Node* node = new Node(grid[one.x][one.y], true);
            return node;
        }
        // 全相同
        if (allSame(grid, one)) {
            Node* node = new Node(grid[one.x][one.y], true);
            return node;
        }
        // 切分
        Node* root = new Node(false, false);
        Ite ite(one, one.rows >> 1);
        for (auto beg = ite.begin(); beg != ite.end(); ++beg) {
            root->*beg.ptr = construct(grid, beg.one);
        }
        return root;
    }


    Node* construct(vector<vector<int>>& grid) {
        One one;
        one.setBase(0, 0);
        one.setRC(grid.size(), grid[0].size());
        return construct(grid, one);
    }
};

// 这个解乏的好处就是， 代码看起来简洁
class Solution2 {
public:
    Node* construct(vector<vector<int>>& grid, int r0, int c0, int r1, int c1) {
        int nx = (r0 + r1) >> 1;
        int ny = (c0 + c1) >> 1;
        for (int i = r0; i < r1; i++) {
            for (int j = c0; j < c1; j++) {
                if (grid[i][j] != grid[r0][c0]) {
                    return new Node {
                        0,
                        false,
                        construct(grid, r0, c0, nx, ny),
                        construct(grid, r0, ny, nx, c1),
                        construct(grid, nx, c0, r1, ny),
                        construct(grid, nx, ny, r1, c1)
                    };
                }
            }
        }
        return new Node(grid[r0][c0], true);
    }

    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size(), grid.size());
    }
};

class Solution {
public:
   bool checkAllSame(const vector<vector<int>> &prefix, int r0, int c0, int r1, int c1) {
       int sum = prefix[r1][c1] - prefix[r1][c0] - prefix[r0][c1] + prefix[r0][c0];
       int total = (r1 - r0) * (c1 - c0);
       return sum == 0 || sum == total;
   }

    Node* construct(const vector<vector<int>> &prefix, const vector<vector<int>>& grid, int r0, int c0, int r1, int c1) {
        if (r0 >= r1 || c0 >= c1) {
            assert("invalid");
        }

        if (r0 + 1 == r1 || checkAllSame(prefix, r0, c0, r1, c1)) {
            return new Node(grid[r0][c0], true);
        }
        int nx = (r0 + r1) >> 1;
        int ny = (c0 + c1) >> 1;
        return new Node(true,
                        false,
                        construct(prefix, grid, r0, c0, nx, ny),
                        construct(prefix, grid, r0, ny, nx, c1),
                        construct(prefix, grid, nx, c0, r1, ny),
                        construct(prefix, grid, nx, ny, r1, c1)
                       );

    }

    Node* construct(vector<vector<int>>& grid) {
        vector<vector<int>> prefix(grid.size() + 1, vector<int>(grid.size() + 1));
        for (int i = 1; i < prefix.size(); i++) {
            for (int j = 1; j < prefix[i].size(); j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + grid[i - 1][j - 1] - prefix[i - 1][j - 1];
            }
        }
        return construct(prefix, grid, 0, 0, grid.size(), grid.size());
    }
};

// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]\n
// @lcpr case=end

 */

