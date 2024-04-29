/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30122
 *
 * [1329] 将矩阵按对角线排序
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
    vector<vector<int>> diagonalSort1(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        auto insertSort = [&](int i, int j) {
            while (i < m and j < n) {
                int v = mat[i][j];
                int nx = i - 1, ny = j - 1;
                while (nx >= 0 and ny >= 0 and mat[nx][ny] > v) {
                    mat[nx + 1][ny + 1] = mat[nx][ny];
                    nx -= 1;
                    ny -= 1;
                }
                mat[nx + 1][ny + 1] = v;
                i += 1;
                j += 1;
            }

            };
        for (int i = 0; i < mat.size(); i++) {
            insertSort(i, 0);
        }
        for (int j = 1; j < mat[0].size(); j++) {
            insertSort(0, j);
        }
        return mat;
    }

    vector<vector<int>> diagonalSort2(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        auto insertSort = [&](int lx, int ly, int hx, int hy) {
            while (lx <= hx and ly <= hy) {
                int v = mat[lx][ly];
                int nx = lx - 1, ny = ly - 1;
                while (nx >= 0 and ny >= 0 and mat[nx][ny] > v) {
                    mat[nx + 1][ny + 1] = mat[nx][ny];
                    nx -= 1;
                    ny -= 1;
                }
                mat[nx + 1][ny + 1] = v;
                lx += 1;
                ly += 1;
            }

            };

        auto partition = [&](int lx, int ly, int hx, int hy)-> pair<int, int> {
            int v = mat[hx][hy];
            int px = lx - 1, py = ly - 1;
            while (lx < hx and ly < hy) {
                if (mat[lx][ly] < v) {
                    ++px, ++py;
                    if (px != lx) {
                        swap(mat[lx][ly], mat[px][py]);
                    }
                }
                lx++;
                ly++;
            }
            swap(mat[hx][hy], mat[++px][++py]);
            return { px, py };
            };

        function<void(int, int, int, int)> quickSort = [&](int lx, int ly, int hx, int hy) {
            if (lx >= hx || ly >= hy) {
                return;
            }
            if (lx + 20 >= hx || ly + 20 >= hy) {
                insertSort(lx, ly, hx, hy);
                return;
            }
            auto [px, py] = partition(lx, ly, hx, hy);
            int ex = px, ey = py;
            while (ex < hx and ey < hy and mat[ex][ey] == mat[ex + 1][ey + 1]) {
                ex++;
                ey++;
            }
            quickSort(lx, ly, px - 1, py - 1);
            quickSort(ex + 1, ey + 1, hx, hy);
            };

        for (int i = 0; i < mat.size(); i++) {
            int w = min(m - i, n) - 1;
            quickSort(i, 0, i + w, w);
        }
        for (int j = 1; j < mat[0].size(); j++) {
            int w = min(m, n - j) - 1;
            quickSort(0, j, w, j + w);
        }
        return mat;
    }

    template<typename Derived>
    class EqualityComparable {
    public:
        friend bool operator==(Derived const& x1, Derived const& x2) {
            return !(x1 < x2) && !(x2 < x1);
        }

        friend bool operator!=(Derived const& x1, Derived const& x2) {
            return !(x1 == x2);
        }

        friend bool operator>(Derived const& x1, Derived const& x2) {
            return x2 < x1;
        }

        friend bool operator>=(Derived const& x1, Derived const& x2) {
            return !(x1 < x2);
        }

        friend bool operator<=(Derived const& x1, Derived const& x2) {
            return !(x1 > x2);
        }
    };


    class DiagIte : public EqualityComparable<DiagIte> {
    private:
        std::vector<std::vector<int>>& mat;
        int lx, ly;

    public:
        using difference_type = int;
        using value_type = int;
        using pointer = int*;
        using reference = int&;
        using iterator_category = std::random_access_iterator_tag;

        DiagIte(std::vector<std::vector<int>>& mat, int lx, int ly) : mat(mat), lx(lx), ly(ly) {}

        // Copy constructor
        DiagIte(const DiagIte& other) : mat(other.mat), lx(other.lx), ly(other.ly) {}

        // Assignment operator
        DiagIte& operator=(const DiagIte& other) {
            if (this != &other) {
                mat = other.mat;
                lx = other.lx;
                ly = other.ly;
            }
            return *this;
        }

        reference operator*() const {
            return mat[lx][ly];
        }

        DiagIte& operator++() {
            ++lx;
            ++ly;
            return *this;
        }

        DiagIte operator++(int) {
            DiagIte temp = *this;
            ++(*this);
            return temp;
        }

        DiagIte& operator--() {
            --lx;
            --ly;
            return *this;
        }

        DiagIte operator--(int) {
            DiagIte temp = *this;
            --(*this);
            return temp;
        }

        DiagIte& operator+=(difference_type n) {
            lx += n;
            ly += n;
            return *this;
        }

        DiagIte& operator-=(difference_type n) {
            lx -= n;
            ly -= n;
            return *this;
        }

        DiagIte operator+(difference_type n) const {
            DiagIte result = *this;
            result += n;
            return result;
        }

        DiagIte operator-(difference_type n) const {
            DiagIte result = *this;
            result -= n;
            return result;
        }

        difference_type operator-(const DiagIte& other) const {
            return (lx - other.lx);
        }

        reference operator[](difference_type n) const {
            return *(*this + n);
        }

        bool operator<(const DiagIte& other) const {
            return (lx < other.lx);
        }
    };

    class Diag {
    public:
        vector<vector<int>>& mat;
        int lx, ly;

        Diag(vector<vector<int>>& mat, int lx, int ly) : mat(mat), lx(lx), ly(ly) {}

        DiagIte begin() {
            return DiagIte(mat, lx, ly);
        }

        DiagIte end() {
            int w = std::min(mat.size() - lx, mat[0].size() - ly);
            return DiagIte(mat, lx + w, ly + w);
        }
    };

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < mat.size(); i++) {
            Diag Di(mat, i, 0);
            std::sort(Di.begin(), Di.end());
        }
        for (int j = 1; j < mat[0].size(); j++) {
            Diag Di(mat, 0, j);
            std::sort(Di.begin(), Di.end());
        }
        return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

