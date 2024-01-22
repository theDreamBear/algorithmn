/*
 * @lc app=leetcode.cn id=433 lang=cpp
 * @lcpr version=30113
 *
 * [433] 最小基因变化
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
#include <string>
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
        /*
        这道题一共犯了三个致命问题
        1、 while() 循环写成了 if
        2、 队列的大小应该用 sz, 二不是q.size();
        3、外层循环和内层循环的 循环变量用了一样的值 i

            if (!q.empty()) {
                ++ans;
                int sz = q.size();
                for (int i = 0; i < q.size(); i++) {
                    string now = q.front();
                    q.pop();
                    // 寻找下一批
                    for (int i = 0; i < bank.size(); i++) {
                        if (visited[i]) {
                            continue;
                        }
                        const string& next = bank[i];
                        if (isDiffOneChar(now, bank[i])) {
                            if (endGene == bank[i]) {
                                return ans;
                            }
                            visited[i] = 1;
                            q.push(bank[i]);
                        }
                    }
                }
            }


        */


public:
    /*
        算法分析
        时间复杂度: O(N * N * M) N是bank的长度，M是字符串的长度

    */
    int minMutation1(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }
        // 可能是一个bfs的搜索
        // 查找 bank 里面和startGene 查一个字符的 子集
        // 取出每一个子集， 校验
        set<string> bs(bank.begin(), bank.end());
        auto findInBank = [&](const string& now) {
            set<string> candidate;
            for (auto& str : bs) {
                int diffcnt = 0;
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] != now[i]) {
                        diffcnt++;
                    }
                }
                if (diffcnt == 1) {
                    candidate.insert(str);
                }
            }
            return candidate;
        };

        queue<string> q;
        q.push(startGene);
        if (bs.count(startGene)) {
            bs.erase(startGene);
        }
        int ans = 0;
        // 粗心while 写出if了
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto now = q.front();
                q.pop();
                // 在bank
                auto candidate = std::move(findInBank(now));
                if (candidate.empty()) {
                    printf("no\n");
                    continue;
                }
                // 入队列
                for (const string& str : candidate) {
                    if (str == endGene) {
                        return ans;
                    }
                    q.push(str);
                    bs.erase(str);
                }
            }
        }
        return -1;
    }

    /*
        start.length == 8
        end.length == 8
        0 <= bank.length <= 10
        bank[i].length == 8
        start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
    */
    int minMutation2(string startGene, string endGene, vector<string>& bank) {
        // 本来就想等
        if (startGene == endGene) {
            return 0;
        }
        //
        auto isDiffOneChar = [&](const string& lhs, const string& rhs) {
            if (lhs.size() != rhs.size()) {
                return false;
            }
            int diff = 0;
            for (int i = 0; i < lhs.size(); i++) {
                if (lhs[i] != rhs[i] && ++diff > 1) {
                    return false;
                }
            }
            return true;
        };
        queue<string> q;
        vector<int> visited(bank.size());
        // startGen设置已经访问
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == startGene) {
                visited[i] = 1;
            }
        }
        int ans = 0;
        q.push(startGene);
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int iq = 0; iq < sz; iq++) {
                string now = q.front();
                q.pop();
                // 寻找下一批
                for (int ib = 0; ib < bank.size(); ib++) {
                    if (visited[ib]) {
                        continue;
                    }
                    const string& next = bank[ib];
                    if (isDiffOneChar(now, next)) {
                        if (endGene == next) {
                            return ans;
                        }
                        visited[ib] = 1;
                        q.push(next);
                    }
                }

            }
        }
        return -1;
    }

    /*
        时间复杂度:
        m : bank size
        n : startGene size
        m * n * 4; 有点问题, 因为 string next = now; 这个位置复杂度为 n
    */
    int minMutation3(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) {
            return -1;
        }
        unordered_set<string> bs(bank.begin(), bank.end());
        unordered_map<string, int> visited;

        queue<string> q;
        visited[startGene] = 1;
        q.push(startGene);

        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string now = move(q.front()); q.pop();
                for (char ch : "ATCG") {
                    for (int j = 0; j < 8; j++) {
                        if (ch != now[j]) {
                            string next = now;
                            next[j] = ch;
                            if (next == endGene) {
                                return ans;
                            }
                            if (bs.count(next) && !visited[next]) {
                                visited[next] = 1;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

    int minMutation4(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }
        // 邻接表
        int m = bank.size();
        auto isDiffOneChar = [&](const string& lhs, const string& rhs) {
            int diff = 0;
            for (int i = 0; i <  lhs.size() && diff <= 1; i++) {
                if (lhs[i] != rhs[i]) {
                    ++diff;
                }
            }
            return diff == 1;
        };
        // m * m * n
        vector<vector<int>> adjacent(m, vector<int>{});
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                if (isDiffOneChar(bank[i], bank[j])) {
                    adjacent[i].push_back(j);
                    adjacent[j].push_back(i);
                }
            }
        }
        int visited[10] = {0};
        auto it = find(bank.begin(), bank.end(), startGene);
        if (it != bank.end()) {
            bank[it - bank.begin()] = 1;
        }
        queue<int> q;
        int eIndex = 0;
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == endGene) {
                eIndex = i;
            }
            if (isDiffOneChar(bank[i], startGene)) {
                if (bank[i] == endGene) {
                    return 1;
                }
                q.push(i);
                visited[i] = 1;
            }
        }
        int ans = 1;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            while (sz-- > 0) {
                int now = q.front(); q.pop();
                for(const int next : adjacent[now]) {
                    if (visited[next]) {
                        continue;
                    }
                    if (next == eIndex) {
                        return ans;
                    }
                    q.push(next);
                    visited[next] = 1;
                }
            }
        }
        return -1;
    }

    /*
        双向 bfs , 这个实现太慢了
    */
    int minMutation5(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) {
            return -1;
        }
        int visited[10]{0};
        auto isDiffOneChar = [&](const string& lhs, const string& rhs) {
            int diff = 0;
            for (int i = 0; i < lhs.size() && diff <= 1; i++) {
                if (lhs[i] != rhs[i]) {
                    ++diff;
                }
            }
            return diff == 1;
        };
        queue<int> lq, rq;
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == startGene) {
                visited[i] = 1;
            }
            if (isDiffOneChar(startGene, bank[i])) {
                if (bank[i] == endGene) {
                    return 1;
                }
                lq.push(i);
                visited[i] = 1;
            }
        }
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == endGene) {
                visited[i] = 2;
            }
            if (isDiffOneChar(endGene, bank[i])) {
                if (visited[i] == 1) {
                    return 2;
                }
                rq.push(i);
                visited[i] = 2;
            }
        }
        int ans = 2;
        auto search = [&](queue<int>& q, int target, int source) {
            ++ans;
            int sz = q.size();
            while (sz-- > 0) {
                int now = q.front();
                q.pop();
                for (int i = 0; i < bank.size(); i++) {
                     if (isDiffOneChar(bank[i], bank[now])) {
                        if (visited[i] == target) {
                            return true;
                        }
                        if (visited[i] == 0) {
                            q.push(i);
                            visited[i] = source;
                        }
                    }
                }
            }
            return false;
        };
        while (!lq.empty() && !rq.empty()) {
            if (search(lq, 2, 1)) {
                return ans;
            }
            if (search(rq, 1, 2)) {
                return ans;
            }
        }
        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) {
            return 0;
        }
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) {
            return -1;
        }
        unordered_map<string, int> visited;
        auto isDiffOneChar = [&](const string& lhs, const string& rhs) {
            int diff = 0;
            for (int i = 0; i < lhs.size() && diff <= 1; i++) {
                if (lhs[i] != rhs[i]) {
                    ++diff;
                }
            }
            return diff == 1;
        };
    }
};
// @lc code=end



/*
// @lcpr case=start
// "AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]\n
// @lcpr case=end

// @lcpr case=start
// "AACCGGTT"\n"AAACGGTA"\n["AACCGGTA","AACCGCTA","AAACGGTA"]\n
// @lcpr case=end

// @lcpr case=start
// "AAAAACCC"\n"AACCCCCC"\n["AAAACCCC","AAACCCCC","AACCCCCC"]\n
// @lcpr case=end

 */

