#include<unordered_map>
#include<queue>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=837 lang=cpp
 *
 * [837] 新 21 点
 */

// @lc code=start
class Solution1 {
public:
	// 什么错误逻辑， 概率白学了
    double new21Game0(int n, int k, int maxPts) {
    	// n 不超过n, k， maxPts  [1, maxPts]
    	unordered_map<int, int> mp;
    	queue<int> q;

    	q.push(0);
		mp[0] = 1;

    	while (!q.empty()) {
    		int sz = q.size();
    		for (int i = 0; i < sz; i++) {
    			auto val = q.front();
    			q.pop();
				if (val >= k) {
					mp[val] *= maxPts;
					continue;
				}
                for (int j = 1; j <= maxPts; j++) {
    			    int next = val + j;
    			    mp[next]++;
    			    if (next < k) {
    				    q.push(next);
    			    }
                }
    		}
    	}
    	int total = 0;
    	int less_than = 0;
    	for (auto& p : mp) {
    		if (p.first < k) {
    			continue;
    		}
    		total += p.second;
    		if (p.first <= n) {
    			less_than += p.second;
    		}
    	}
    	return less_than * 1.0 / total;
    }

	// 方法对了， 超时
	double new21Game4(int n, int k, int maxPts) {
		// n 不超过n, k， maxPts  [1, maxPts]
    	queue<pair<int, double>> q;
    	q.push({0, 1});
		double total = 0;
    	double less_than = 0;
    	while (!q.empty()) {
    		int sz = q.size();
    		for (int i = 0; i < sz; i++) {
    			auto [val, p] = q.front();
    			q.pop();
				if (val >= k) {
					total += p;
					if (val <= n) {
						less_than += p;
					}
					continue;
				}
				double base = 1.0 / maxPts;
                for (int j = 1; j <= maxPts; j++) {
    			    int next = val + j;
    			  	q.push({next, p * base});
                }
    		}
    	}
    	return less_than * 1.0 / total;
	}

	double new21Game3(int n, int k, int maxPts) {
		if (n < k) {
            return 0;
        }
        int max_score = k + maxPts - 1;
        if (n >= max_score) {
            return 1;
        }
        vector<double> dp(max_score + 1);
        dp[0] = 1;
        double fz = 0;
        double fm = 0;
        for (int i = 0; i < k; i++) {
            for (int step = 1; step <= maxPts; step++) {
                dp[i + step] += dp[i] / maxPts;
            }
        }
        for (int i = k; i <= max_score; i++) {
            if (i <= n) {
                fz += dp[i];
            }
            fm += dp[i];
        }
        return fz / fm;
    }

        double new21Game(int n, int k, int maxPts) {
        if (k <= 0) {
            return 1;
        }
        int max_score = k + maxPts - 1;
        if (n >= max_score) {
            return 1;
        }
        double fz = 0;
        vector<double> dp(max_score + 1);
        dp[0] = 1;
        dp[1] = dp[0] / maxPts;
        for (int point = 2; point <= min(maxPts, k); point++) {
            dp[point] = dp[point - 1] / maxPts + dp[point - 1];
        }
        for (int point = maxPts + 1; point <= k; point++) {
            dp[point] = (dp[point - 1] * (maxPts + 1) - dp[point - 1 - maxPts]) / maxPts;
        }
        for (int point = k + 1; point <= max_score; point++) {
            double sub = 0;
            if (point - 1 - maxPts >= 0) {
                sub = dp[point - 1 - maxPts];
            }
            dp[point] = dp[point - 1] - sub / maxPts;
        }
        for (int point = k; point <= n; point++) {
            fz += dp[point];
        }
        return fz;
    }
};
class Solution {
public:
    double getValue(int x, int k, vector<double>& dp) {
        if (x < 0) {
            return 0;
        }
        if (x >= k) {
            return 0;
        }
        return dp[x];
    }
    double new21Game(int n, int k, int maxPts) {
        if (k <= 0) {
            return 1;
        }
        int max_score = k + maxPts - 1;
        if (n >= max_score) {
            return 1;
        }
        double fz = 0;
        double fm = 0;
#ifdef MYFORWARD
        vector<double> dp(max_score + 1);
        dp[0] = 1;
        // 正推模型
        // 已知f(i) ->  正推 f(i + 1), f(i + 2) .... f(i + maxPts - 1)
        // 问题是每次计算的新值都不是稳定的， 只有当前值是稳定的，不能滚动数组
        for (int i = 0; i <= max_score; i++) {
            for (int step = 1; step <= maxPts; step++) {
                dp[i + step] += dp[i] / maxPts;
            }
        }
        for (int i = k; i <= max_score; i++) {
            if (i <= n) {
                fz += dp[i];
            }
            fm += dp[i];
        }
        return fz / fm;
#elifdef MEM_OPTS
        // 没连续的maxPts个数的概率和等于1
        vector<double> dp(maxPts);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int left = max(i - maxPts, 0);
            int right = min(i - 1, k - 1);
            double p = 0;
            if (left <= right) {
                for (int j = left; j <= right; j++) {
                    p += (dp[j % maxPts] / maxPts);
                }
                dp[i % maxPts] = p;
            }
            if (i >= k) {
                fz += dp[i % maxPts];
            }
        }
        return fz;
#else
        // 去掉重复计算
        vector<double> dp(max_score + 1);
        dp[0] = 1;
        dp[1] = dp[0] / maxPts;
#ifdef OJBK
        for (int point = 2; point <= min(maxPts, k); point++) {
            dp[point] = dp[point - 1] / maxPts + dp[point - 1];
        }
        for (int point = maxPts + 1; point <= k; point++) {
            dp[point] = (dp[point - 1] * (maxPts + 1) - dp[point - 1 - maxPts]) / maxPts;
        }
        for (int point = k + 1; point <= max_score; point++) {
            double sub = 0;
            if (point - 1 - maxPts >= 0) {
                sub = dp[point - 1 - maxPts];
            }
            dp[point] = dp[point - 1] - sub / maxPts;
        }
#else
        for (int point = 2; point <= max_score; point++) {
            double v1 = getValue(point - 1, k, dp);
            double v2 = getValue(point - 1 - maxPts, k, dp);
            dp[point] = dp[point - 1] + (v1 - v2) / maxPts;
        }
#endif
        for (int point = k; point <= n; point++) {
            fz += dp[point];
        }
        return fz;
#endif
    }
};
// @lc code=end

int main() {
    cout << Solution{}.new21Game(6 ,2, 10);
}
