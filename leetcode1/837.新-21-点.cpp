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
class Solution {
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
	double new21Game(int n, int k, int maxPts) {
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
};
// @lc code=end

int main() {
    cout << Solution{}.new21Game(6 ,2, 10);
}
