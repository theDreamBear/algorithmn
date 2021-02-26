/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
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

// @lc code=start
constexpr int MAX_N = 1e5;
int n, tree[MAX_N - 1];

class NumArray {
private:
    //vector<int> tree;
    //int n;
    void init(int sz) {
        n = 1;
        while (n < sz) {
            n <<= 1;
        }
        //tree.resize(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; ++i) {
            tree[i] = 0;
        }
    }

    int query(int ql, int qr, int node, int l, int r ) {
        if (ql > r || qr < l) {
            return 0;
        }
        if (ql <= l && qr >= r) {
            return tree[node];
        } else {
            int lv = query(ql, qr, node * 2 + 1, l, (l + r) / 2);
            int rv = query(ql, qr, node * 2 + 2, (l + r) / 2 + 1, r);
            return lv + rv;
        }
    }

public:
    NumArray(vector<int>& nums) {
        init(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        index += n - 1;
        tree[index] = val;
        while (index > 0) {
            index = (index - 1) / 2;
            tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];
        }
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

