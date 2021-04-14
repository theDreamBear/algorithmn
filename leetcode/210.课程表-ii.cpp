/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites) {
        // 待选队列
        unordered_map<int, set<int>> course_rely;
        unordered_map<int, set<int>> course_relyed;
        for (auto& vec : prerequisites) {
            course_rely[vec[0]].insert(vec[1]);
            course_relyed[vec[1]].insert(vec[0]);
        }
        queue<int> candidate;
        for (int i = 0; i < numCourses; ++i) {
            if (course_rely.count(i) == 0) {
                candidate.push(i);
            }
        }
        vector<int> ans;
        while (!candidate.empty()) {
            auto node = candidate.front();
            ans.push_back(node);
            candidate.pop();
            for (auto& rely : course_relyed[node]) {
                course_rely[rely].erase(node);
                if (course_rely[rely].empty()) {
                    candidate.push(rely);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }

    /*
     *  bfs
     * */
    vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
        // 待选队列
        vector<set<int>> course_rely(numCourses);
        vector<set<int>> course_relyed(numCourses);
        for (auto& vec : prerequisites) {
            course_rely[vec[0]].insert(vec[1]);
            course_relyed[vec[1]].insert(vec[0]);
        }
        queue<int> candidate;
        for (int i = 0; i < numCourses; ++i) {
            if (course_rely[i].empty()) {
                candidate.push(i);
            }
        }
        vector<int> ans;
        while (!candidate.empty()) {
            auto node = candidate.front();
            ans.push_back(node);
            candidate.pop();
            for (auto& rely : course_relyed[node]) {
                course_rely[rely].erase(node);
                if (course_rely[rely].empty()) {
                    candidate.push(rely);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }


    void dfs(int curID, vector<int>& inCount, const vector<vector<int>>& matrix, vector<int>& ans, vector<bool>& visited) {
        if (inCount[curID] > 0) {
            return;
        }
        visited[curID] = true;
        ans.push_back(curID);
        for (auto nextId : matrix[curID]) {
            if (--inCount[nextId] == 0) {
                dfs(nextId, inCount, matrix, ans, visited);
            }
        }
    }
    /*
     *  dfs
     * */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inCount(numCourses);
        vector<bool> visited(numCourses);
        vector<vector<int>> matrix(numCourses);
        vector<int> ans;
        for (auto& vec : prerequisites) {
            ++inCount[vec[0]];
            matrix[vec[1]].push_back(vec[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && inCount[i] == 0) {
                dfs(i, inCount, matrix, ans, visited);
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};
// @lc code=end

int main() {
    vector<vector<int>> course = {{1, 0}};
    Solution{}.findOrder(2, course);
}
