/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] ???
 */
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
struct workNode {
    int seq;
    int inCount;
    vector<workNode*> childs;
    vector<workNode*> _works;
    workNode(int seq) {
        this->seq = seq;
        this->inCount = 0;
    }

    void addSuccessorWork(workNode* t) { childs.push_back(t); }

    void increaseRelyWorkCount() { ++inCount; }

    void oneRelycurrentWorkDone() { --inCount; }

    int getRelyWorkCount() { return inCount; }

    void currentWorkDone(vector<workNode*>& nodes) {
        for (int i = 0; i < childs.size(); ++i) {
            workNode* cur = nodes[childs[i]->seq];
            cur->oneRelycurrentWorkDone();
        }
    }
};

class Solution {
 public:
    bool canFinish_bad(int numCourses, vector<vector<int>>& prerequisites) {
        vector<workNode*> vec_node;
        for (int i = 0; i < numCourses; ++i) {
            vec_node.push_back(new workNode(i));
        }
        for (int i = 0; i < prerequisites.size(); ++i) {
            int cur = prerequisites[i][0];
            int rely = prerequisites[i][1];

            vec_node[rely]->addSuccessorWork(vec_node[cur]);

            vec_node[cur]->increaseRelyWorkCount();
        }
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            int idx = -1;
            for (int j = 0; j < numCourses; ++j) {
                if (!visited[j] &&
                    (-1 == idx || vec_node[idx]->getRelyWorkCount() >
                                      vec_node[j]->getRelyWorkCount())) {
                    idx = j;
                }
            }
            if (-1 == idx) {
                return true;
            }
            if (vec_node[idx]->getRelyWorkCount() > 0) {
                return false;
            }
            vec_node[idx]->currentWorkDone(vec_node);
            visited[idx] = true;
        }
        return true;
    }

    bool canFinish_BFS(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> readyQueue;
        int mInCount[numCourses];
        fill(mInCount, mInCount + numCourses, 0);
        map<int, vector<int>> mFollowers;
        for (int i = 0; i < prerequisites.size(); ++i) {
            int cur = prerequisites[i][0];
            int pre = prerequisites[i][1];
            ++mInCount[cur];
            mFollowers[pre].push_back(cur);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (mInCount[i] == 0) {
                readyQueue.push(i);
            }
        }
        int ret = 0;
        while (!readyQueue.empty()) {
            int cur = readyQueue.front();
            ++ret;
            readyQueue.pop();
            for (auto& x : mFollowers[cur]) {
                if (--mInCount[x] == 0) {
                    readyQueue.push(x);
                }
            }
        }
        return ret == numCourses;
    }
    /*
    0 ????
    1 ???
    -1 ??? dfs ??

    */
    bool dfs(vector<vector<int>>& mFollowers, short int* state,
             int i) {
        // ?????
        if (state[i] == -1) {
            return false;
        }
        if (state[i] == 1) {
            return true;
        }
        state[i] = -1;
        for (auto& x : mFollowers[i]) {
            if (!dfs(mFollowers, state, x)) {
                return false;
            }
        }
        state[i] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        short int state[numCourses];
        fill(state, state + numCourses, 0);
        //
        vector<vector<int>> mFollowers(numCourses, vector<int>{});

        for (auto& node : prerequisites) {
            int cur = node[0];
            int pre = node[1];
            mFollowers[pre].push_back(cur);
        }
        for (int i = 0; i < numCourses; ++i) {
            if(!dfs(mFollowers, state, i)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> pre;
    vector<int> i = {1, 0};
    pre.push_back(i);
    cout << pre.size();
    Solution s;
    s.canFinish(2, pre);
}
