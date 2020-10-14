/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <queue>
#include <vector>
#include <iostream>
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

    void addSuccessorWork(workNode* t) {
        childs.push_back(t);
    }

    void increaseRelyWorkCount() {
        ++inCount;
    }

    void oneRelycurrentWorkDone() {
        --inCount;
    }

    int getRelyWorkCount() {
        return inCount;
    }

    void currentWorkDone(vector<workNode*>& nodes) {
        for (int i = 0; i < childs.size(); ++i) {
            workNode* cur = nodes[childs[i]->seq];
            cur->oneRelycurrentWorkDone();
        }
    }
};

class Solution {
 public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                if (!visited[j] && (-1 == idx || vec_node[idx]->getRelyWorkCount() > vec_node[j]->getRelyWorkCount())) {
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
