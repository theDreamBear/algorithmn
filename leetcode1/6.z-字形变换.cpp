/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class MoveStrategy {
public:
    int limit;

    explicit MoveStrategy(int limit) : limit(limit) {}

    virtual void moveForward(int &row, int &col) = 0;
};

class DownStrategy : public MoveStrategy {
public:
    explicit DownStrategy(int limit) : MoveStrategy(limit) {}

    void moveForward(int &row, int &col) override {
        ++row;
        assert(row + 1 <= limit);
    }
};

class DiagonalStrategy : public MoveStrategy {
public:
    explicit DiagonalStrategy(int limit) : MoveStrategy(limit) {}

    void moveForward(int &row, int &col) override {
        --row;
        ++col;
        assert(row >= 0);
    }
};

class StrategyManager {
public:
    MoveStrategy *strategy;
    MoveStrategy *one;
    MoveStrategy *two;
    int limit;

    explicit StrategyManager(int limit) : limit(limit) {
        one = new DownStrategy(limit);
        two = new DiagonalStrategy(limit);
        strategy = one;
    }

    void change(int row) {
        if (row + 1 == limit) {
            strategy = two;
            return;
        }
        if (row == 0) {
            strategy = one;
            return;
        }
    }

    ~StrategyManager() {
        delete one;
        one = nullptr;

        delete two;
        two = nullptr;

        strategy = nullptr;
    }
};

class IndexChanger {
public:
    StrategyManager *strategy;
    int row = 0;
    int col = 0;

    explicit IndexChanger(int numRows) {
        strategy = new StrategyManager(numRows);
        row = 0;
        col = 0;
    }

    void moveForward() {
        strategy->strategy->moveForward(row, col);
        strategy->change(row);
    }

    ~IndexChanger() {
        delete strategy;
        strategy = nullptr;
    }

};

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1) {
            return s;
        }
        int cols = ceil(s.size() / 2.0);
        IndexChanger changer(numRows);
        vector<vector<char>> tables(numRows, vector<char>(cols, '='));
        int &row = changer.row;
        int &col = changer.col;
        for (int i = 0; i < s.size();) {
            tables[row][col] = s[i];
            if (++i >= s.size()) {
                break;
            }
            changer.moveForward();
        }
        string ans(s.size(), '\0');
        int i = 0;
        for (int x = 0; x < numRows; x++) {
            for (int y = 0; y < cols; y++) {
                if (tables[x][y] != '=') {
                    ans[i++] = tables[x][y];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

