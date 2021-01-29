/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
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

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    // 递归实现比较简单
    int getImportanceHelper( unordered_map<int, int>& imports, unordered_map<int, vector<int>*>& sub, const int id) {
        int sum = imports[id];
        for (auto& subID : *sub[id]) {
            sum += getImportanceHelper(imports, sub, subID);
        }
        return sum;
    }

    // 非递归实现 , 队列
    int getImportanceHelper_loop( unordered_map<int, int>& imports, unordered_map<int, vector<int>*>& sub, const int id) {
        queue<int> waitID;
        waitID.push(id);
        int sum = 0;
        while(!waitID.empty()) {
            int tempID = waitID.front();
            waitID.pop();
            sum += imports[tempID];
            for (auto v : *sub[tempID]) {
                waitID.push(v);
            }
        }
        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        vector<int> ves;
        unordered_map<int, int> imports;
        unordered_map<int, vector<int>*> sub;
        for (auto & e : employees) {
            imports[e->id] = e->importance;
            sub[e->id] = &e->subordinates;
        }
        return getImportanceHelper_loop(imports, sub, id);
    }
};
// @lc code=end

