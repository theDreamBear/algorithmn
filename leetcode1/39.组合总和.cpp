/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int, int)> backtrack = [&](int pos, int curSum) {
            if (curSum > target) {
                return;
            }
            if (curSum == target) {
                ans.push_back(temp);
                return;
            }
            for (int i = pos; i < candidates.size() && curSum + candidates[i] <= target; i++) {
                if (i > pos && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                backtrack(i, curSum + candidates[i]);
                temp.pop_back();
            }
        };
        backtrack(0, 0);
        return ans;
    }

    struct State {
        vector<int> vec;
        int next_pos{};
        int cur_sum{};

        State() = default;

        State(State &state, int pos, int val) {
            vec = state.vec;
            next_pos = pos;
            cur_sum = state.cur_sum;

            vec.push_back(val);
            cur_sum += val;
        }
    };

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        auto state = new State;
        sort(candidates.begin(), candidates.end());
        stack<State *> st;
        st.push(state);
        while (!st.empty()) {
            auto s = st.top();
            st.pop();
            if (s->cur_sum > target) {
                continue;
            }
            if (s->cur_sum == target) {
                ans.push_back(s->vec);
                continue;
            }
            for (int i = s->next_pos; i < candidates.size(); i++) {
                State* next_state = new State(*s, i, candidates[i]);
                st.push(next_state);
            }
        }
        return ans;
    }

};
// @lc code=end

