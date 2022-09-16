/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution1 {
public:
    vector<vector<int>> findSolution_violate(CustomFunction &customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 0; x <= 1000; x++) {
            for (int y = 1; y <= 1000; y++) {
                if (customfunction.f(x, y) == z) {
                    ans.push_back({x, y});
                }
            }
        }
        return ans;
    }

    vector<vector<int>> findSolution_2(CustomFunction &customfunction, int z) {
        vector<vector<int>> ans;
        struct Node {
            int left, right, top, bottom;
        };

        stack<Node> st;
        st.push({1, 1000, 1, 1000});
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (customfunction.f(node.left, node.top) > z || customfunction.f(node.right, node.bottom) < z) {
                continue;
            }
            int x = (node.right + node.left) / 2;
            int y = (node.bottom + node.top) / 2;
            int v = customfunction.f(x, y);
            if (v < z) {
                if (x + 1 <= node.right) {
                    st.push({x + 1, node.right, node.top, node.bottom});
                }
                if (y + 1 <= node.bottom) {
                    st.push({node.left, x, y + 1, node.bottom});
                }
            } else if (v > z) {
                if (node.left + 1 <= x) {
                    st.push({node.left, x - 1, node.top, node.bottom});
                }
                if (node.top + 1 <= y) {
                    st.push({x, node.right, node.top, y - 1});
                }
            } else {
                ans.push_back({x, y});
                if (x + 1 <= node.right && node.top + 1 <= y) {
                    st.push({x + 1, node.right, node.top, y - 1});
                }
                if (node.left + 1 <= x && y + 1 <= node.bottom) {
                    st.push({node.left, x - 1, y + 1, node.bottom});
                }
            }
        }
        return ans;
    }

    vector<vector<int>> findSolution3(CustomFunction &customfunction, int z) {
        vector<vector<int>> ans;
        int x = 1, y = 1000;
        while (x <= 1000 && y >= 1) {
            int v = customfunction.f(x, y);
            if (v > z) {
                y--;
            } else if (v < z) {
                x++;
            } else {
                ans.push_back({x, y});
                x++;
                y--;
            }
        }
        return ans;
    }

    enum Direction {
        UP = 0, RIGHT = 2
    };

    class MoveForward {
    public:
        Direction d = UP;

        Direction getDirection() const {
            return d;
        }

        void ChangeDirection() {
            if (d == UP) {
                d = RIGHT;
            } else {
                d = UP;
            }
        }
    };

    class State {
    public:
        State() {
            x = 1;
            y = 1000;
        }

        int x, y;
        MoveForward d;
    };

    static bool ok(State &s) {
        return s.x <= 1000 && s.y >= 1;
    }


    class NormalStrategy {
    public:
        virtual void changeState(State &next) {
            if (next.d.getDirection() == UP) {
                next.y--;
            } else {
                next.x++;
            }
        }

        bool canFit(CustomFunction &customfunction, State &s, int z) {
            // cout << s.x << "\t" << s.y << "\t";
            State next = s;
            changeState(next);
            // cout << next.x << "\t" << next.y << endl;
            // 是否是正常状态
            if (!ok(next)) {
                return false;
            }
            int v = customfunction.f(next.x, next.y);
            do {
                if (v == z) {
                    break;
                }
                if (next.d.getDirection() == UP) {
                    if (v < z) {
                        return false;
                    }
                    break;
                }
                if (next.d.getDirection() == RIGHT) {
                    if (v > z) {
                        return false;
                    }
                }
            } while (false);
            s = next;
            return true;
        }
    };

    class HalfStrategy : public NormalStrategy {
    public:
        void changeState(State &next) override {
            if (next.d.getDirection() == UP) {
                next.y /= 2;
                return;
            } else {
                next.x = (next.x + 1000) / 2;
            }
        }
    };

    class HalfHalfStrategy : public NormalStrategy {
    public:
        void changeState(State &next) override {
            if (next.d.getDirection() == UP) {
                next.y = next.y * 3 / 4;
                return;
            } else {
                next.x = (3000 + next.x) / 4;
            }
        }
    };

    class TenStrategy : public NormalStrategy {
    public:
        void changeState(State &next) override {
            if (next.d.getDirection() == UP) {
                next.y -= 10;
                return;
            } else {
                next.x += 10;
            }
        }
    };

    class StateStrategy {
    public:
        int up_index = 0;
        int right_index = 0;
        NormalStrategy *strategy[4] = {new HalfStrategy, new HalfHalfStrategy, new TenStrategy, new NormalStrategy};

        void try_most(CustomFunction &customfunctionm, State &s, int z, int &index) {
            // 尝试尽最大可能替换
            while (index <= 2) {
                if (strategy[index]->canFit(customfunctionm, s, z)) {
                    return;
                }
                index++;
            }
            // 委屈求全替换
            strategy[index]->changeState(s);
        }

        void try_most_right(CustomFunction &customfunctionm, State &s, int z) {
            try_most(customfunctionm, s, z, right_index);
        }

        void try_most_up(CustomFunction &customfunctionm, State &s, int z) {
            try_most(customfunctionm, s, z, up_index);
        }
    };

    class Saver {
    public:
        vector<vector<int>> data;

        virtual void push(int x, int y) {
            data.push_back({x, y});
        }
    };

    class StateMachine {
    public:
        State &s;
        CustomFunction &customfunction;
        void *data;
        StateStrategy ss;

        StateMachine(CustomFunction &customfunction, State &s, void *data) : customfunction(customfunction), s(s),
                                                                             data(data) {}

        void equal_next() {
            s.x++;
            s.y--;
        }

        void equal_state() {
            ((Saver *) (data))->push(s.x, s.y);
            equal_next();
        }

        void try_most_right(int z) {
            ss.try_most_right(customfunction, s, z);
        }

        void try_most_up(int z) {
            ss.try_most_up(customfunction, s, z);
        }

        void nextState(int z) {
            int v = customfunction.f(s.x, s.y);
            if (v == z) {
                equal_state();
                return;
            }
            bool one = v > z;
            auto d = s.d.getDirection();
            // 是否需要调整运动方向
            if (one + d == 0 || one + d == 3) {
                s.d.ChangeDirection();
            }
            if (s.d.getDirection() == UP) {
                try_most_up(z);
            } else {
                try_most_right(z);
            }
        }

        void run(int z) {
            while (ok(s)) {
                nextState(z);
            }
        }
    };

    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        State s;
        Saver sa;
        StateMachine machine(customfunction, s, &sa);
        machine.run(z);
        return sa.data;
    }
};

enum Direction {
    UP = 0, RIGHT = 2
};

class MoveForward {
public:
    Direction d = UP;

    Direction getDirection() const {
        return d;
    }

    void ChangeDirection() {
        if (d == UP) {
            d = RIGHT;
        } else {
            d = UP;
        }
    }
};

class State {
public:
    State() {
        x = 1;
        y = 1000;
    }

    int x, y;
    MoveForward d;
};

static bool ok(State &s) {
    return s.x <= 1000 && s.y >= 1;
}

// 每次前进1
class NormalStrategy {
public:
    virtual void changeState(State &next) {
        if (next.d.getDirection() == UP) {
            next.y--;
        } else {
            next.x++;
        }
    }

    bool tryFit(CustomFunction &customfunction, State &s, int z) {
        State next = s;
        changeState(next);
        // 是否是正常状态
        if (!ok(next)) {
            return false;
        }
        int v = customfunction.f(next.x, next.y);
        do {
            if (v == z) {
                break;
            }
            if (next.d.getDirection() == UP) {
                if (v < z) {
                    return false;
                }
                break;
            }
            if (next.d.getDirection() == RIGHT) {
                if (v > z) {
                    return false;
                }
            }
        } while (false);
        // 更新状态
        s = next;
        return true;
    }
};

// 每次前进一半
class QuarterStrategy : public NormalStrategy {
public:
    void changeState(State &next) override {
        if (next.d.getDirection() == UP) {
            next.y /= 4;
            return;
        } else {
            next.x = (next.x + 3000) / 4;
        }
    }
};

// 每次前进一半
class HalfStrategy : public NormalStrategy {
public:
    void changeState(State &next) override {
        if (next.d.getDirection() == UP) {
            next.y /= 2;
            return;
        } else {
            next.x = (next.x + 1000) / 2;
        }
    }
};

// 每次前进四分之一
class HalfHalfStrategy : public NormalStrategy {
public:
    void changeState(State &next) override {
        if (next.d.getDirection() == UP) {
            next.y = next.y * 3 / 4;
            return;
        } else {
            next.x = (3000 + next.x) / 4;
        }
    }
};

// 每次前进10
class TenStrategy : public NormalStrategy {
public:
    void changeState(State &next) override {
        if (next.d.getDirection() == UP) {
            next.y -= 10;
            return;
        } else {
            next.x += 10;
        }
    }
};

class StateStrategy {
public:
    int up_index = 0;
    int right_index = 0;
    NormalStrategy *strategy[5] = {new QuarterStrategy, new HalfStrategy, new HalfHalfStrategy, new TenStrategy, new NormalStrategy};

    void try_most(CustomFunction &customfunctionm, State &s, int z, int &index) {
        // 尝试尽最大可能前进
        // 最开始急剧的收缩 每次减半
        // 后面每次减少 1 / 4
        // 每次减少 10
        while (index + 2 <= size(strategy)) {
            if (strategy[index]->tryFit(customfunctionm, s, z)) {
                return;
            }
            index++;
        }
        // 委屈求全前进, 每次减少1
        strategy[index]->changeState(s);
    }

    void try_most_right(CustomFunction &customfunctionm, State &s, int z) {
        try_most(customfunctionm, s, z, right_index);
    }

    void try_most_up(CustomFunction &customfunctionm, State &s, int z) {
        try_most(customfunctionm, s, z, up_index);
    }
};

class Saver {
public:
    vector<vector<int>> data;

    virtual void push(int x, int y) {
        data.push_back({x, y});
    }
};

class StateMachine {
public:
    State &s;
    CustomFunction &customfunction;
    void *data;
    StateStrategy ss;

    StateMachine(CustomFunction &customfunction, State &s, void *data) : customfunction(customfunction), s(s),
                                                                         data(data) {}
    void equal_next() {
        s.x++;
        s.y--;
    }

    void equal_state() {
        ((Saver *) (data))->push(s.x, s.y);
        equal_next();
    }

    void nextState(int z) {
        int v = customfunction.f(s.x, s.y);
        if (v == z) {
            equal_state();
            return;
        }
        bool one = v > z;
        auto d = s.d.getDirection();
        // 是否需要调整运动方向
        if (one + d == 0 || one + d == 3) {
            s.d.ChangeDirection();
        }
        if (s.d.getDirection() == UP) {
            ss.try_most_up(customfunction, s, z);
        } else {
            ss.try_most_right(customfunction, s, z);
        }
    }

    void run(int z) {
        while (ok(s)) {
            nextState(z);
        }
    }
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        State s;
        Saver sa;
        StateMachine machine(customfunction, s, &sa);
        machine.run(z);
        return sa.data;
    }
};
// @lc code=end

