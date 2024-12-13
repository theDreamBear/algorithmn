/*
 * @lc app=leetcode.cn id=2653 lang=cpp
 * @lcpr version=30204
 *
 * [2653] 滑动子数组的美丽值
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
// @lcpr-template-end
// @lc code=start
const int maxn = 1e5 + 1;
struct Node {
    int l, r, val, size, key;
}tr[maxn];

mt19937 rd(233);

int cnt, root;

void init() {
    cnt = root = 0;
    memset(tr, 0, sizeof tr);
}

#define get tr[now]
#define getl tr[get.l]
#define getr tr[get.r]

#define getx tr[x]
#define getxl tr[getx.l]
#define getxr tr[getx.r]

#define gety tr[y]
#define getyl tr[gety.l]
#define getyr tr[gety.r]

int newNode(int val) {
    int now = ++cnt;
    get.val = val;
    get.key = rd();
    get.size = 1;
    return now;
}

void update(int now) {
    get.size = getl.size + getr.size + 1;
}

int x, y, z;

void split(int now, int& x, int& y, int val) {
    if (!now) {
        x = y = 0;
        return;
    }
    if (get.val <= val) {
        x = now;
        split(get.r, get.r, y, val);
    } else {
        y = now;
        split(get.l, x, get.l, val);
    }
    update(now);
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (getx.key >= gety.key) {
        gety.l = merge(x, gety.l);
        update(y);
        return y;
    } else {
        getx.r = merge(getx.r, y);
        update(x);
        return x;
    }
}

void ins(int val) {
    split(root, x, y, val);
    root = merge(merge(x, newNode(val)), y);
}

void del(int val) {
    split(root, x, y, val);
    split(x, x, z, val - 1);
    z = merge(tr[z].l, tr[z].r);
    root = merge(merge(x, z), y);
}

int getrank(int val) {
    split(root, x, y, val - 1);
    z = getx.size + 1;
    root = merge(x, y);
    return z;
}

int getnum(int rk) {
    int now = root;
    while (now) {
        if (getl.size + 1 == rk) {
            break;
        }
        if (getl.size >= rk) {
            now = get.l;
        } else {
            rk -= (getl.size + 1);
            now = get.r;
        }
    }
    return get.val;
}

int prev(int val) {
    split(root, x, y, val - 1);
    int now = x;
    while (get.r) {
        now = get.r;
    }
    z = get.val;
    root = merge(x, y);
    return z;
}

int nxt(int val) {
    split(root, x, y, val);
    int now = y;
    while (get.l) {
        now = get.l;
    }
    z = get.val;
    root = merge(x, y);
    return z;
}

class BIT {
public:
    int offset = 51;
    vector<int> bits;

    BIT(int n):bits(n + 1){}

    void add(int i, int v) {
        i += offset;
        while (i < bits.size()) {
            bits[i] += v;
            i += (i & (-i));
        }
    }

    int sum(int i) {
        i += offset;
        int res = 0;
        while (i) {
            res += bits[i];
            i &= (i - 1);
        }
        return res;
    }

    int binary_search(int rk) {
        int low = -50, high = 50;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (sum(mid) >= rk) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (sum(low) >= rk) {
            return low;
        }
        return high;
    }
};

class Solution {
public:
    // 平衡树
    vector<int> getSubarrayBeauty1(vector<int>& nums, int k, int x) {
        init();
        vector<int> ans;
        for (int i = 0; i + 1 < k; i++) {
            ins(nums[i]);
        }
        for (int i = k - 1; i < nums.size(); i++) {
            ins(nums[i]);
            int v = getnum(x);
            if (v >= 0) v = 0;
            ans.push_back(v);
            del(nums[i - k + 1]);
        }
        return ans;
    }

    // 观察值域非常小, 树状数组
    vector<int> getSubarrayBeauty2(vector<int>& nums, int k, int x) {
        BIT bit(200);
        for (int i = 0; i + 1 < k; i++) {
            bit.add(nums[i], 1);
        }
        vector<int> ans;
        for (int i = k - 1; i < nums.size(); i++) {
            bit.add(nums[i], 1);
            int v = bit.binary_search(x);
            if (v >= 0) v = 0;
            ans.push_back(v);
            bit.add(nums[i - k + 1], -1);
        }
        return ans;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        const int BIAS = 50;
        int cnt[BIAS * 2 + 1]{};
        for (int i = 0; i < k - 1; i++) { // 先往窗口内添加 k-1 个数
            cnt[nums[i] + BIAS]++;
        }

        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = k - 1; i < n; i++) {
            cnt[nums[i] + BIAS]++; // 进入窗口（保证窗口有恰好 k 个数）
            int left = x;
            for (int j = 0; j < BIAS; j++) { // 暴力枚举负数范围 [-50,-1]
                left -= cnt[j];
                if (left <= 0) { // 找到美丽值
                    ans[i - k + 1] = j - BIAS;
                    break;
                }
            }
            cnt[nums[i - k + 1] + BIAS]--; // 离开窗口
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-1,-3,-2,3]\n3\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4,-5]\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// [-3,1,2,-3,0,-3]\n2\n1\n
// @lcpr case=end

 */

