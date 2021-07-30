#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

vector<int> get_random_vec(int sz, int limit) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> u(0, limit);
    vector<int> res(sz);
    for (int i = 0; i < sz; i ++) {
        res[i] = u(mt);
    }
    return res;
}


//#define SLI2


bool existIncreaseThreeSubSequence(const vector<int>& nums) {
#ifdef VI  //暴力解法 O(n^3)
    for (int i = 2; i < nums.size(); i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 0; k < j; k++) {
                if (nums[k] < nums[j] && nums[j] < nums[i]) {
                    return true;
                }
            }
        }
    }
    return false;
#endif

    // 暴力解法问题优化, 寻找优化点
    // 1. 枚举三元组第一个点  O(n^2)
#ifdef SLI
    for (int i = 0; i < nums.size(); i++) {
        vector<int> st;
        st.push_back(nums[i]);
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > st.back()) {
                st.push_back(nums[j]);
                if (st.size() == 3) {
                    return true;
                }
                continue;
            }
            if (st.size() == 2) {
                if (nums[j] < st[1] && nums[j] > st[0]) {
                    st[1] = nums[j];
                }
                continue;
            }
        }
    }
    return false;
#endif

    // 枚举 中间节点  比枚举左端点更快
#ifdef SLI2
    for (int i = 1; i < nums.size(); i++) {
        // 左端点
        bool left = false;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                left = true;
                break;
            }
        }
        if (left) {
            // 右端点
            for (int k = i + 1; k < nums.size(); k++) {
                if (nums[k] > nums[i]) {
                    return true;
                }
            }
        }
    }
    return false;
#endif

    // 左边最小值, 右边最大值, 可以用线段树 lgn 来求, 线段树查找 logn, 整体复杂度 nlgn
#ifdef SLI2_SPEED_UP
    for (int i = 1; i < nums.size(); i++) {
        // 左端点
        bool left = segementSmall.query(0, i - 1) < nums[i];
        if (left) {
            // 右端点
            if (segementBig.query(i + 1, nums.size() - 1) > nums[i]) {
                return true;
            }
        }
    }
    return false;
#endif
    // 还是没达到 时间O(n), 空间 O(1) 还可以怎么加速
    // O(n) 代表一次到多次遍历
    vector<int> vec;
    vec.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > vec.back()) {
            if (vec.size() == 2) {
                return true;
            }
            vec.push_back(nums[i]);
            continue;
        }
        if (vec[0] >= nums[i]) {
            vec[0] = nums[i];
            continue;
        }
        if (vec.size() == 2 && vec[1] > nums[i]) {
            vec[1] = nums[i];
            continue;
        }
    }
    return false;
}


int main() {
    for (int i = 0; i < 10; i++) {
        auto data = get_random_vec(5, 20);
        for (int j : data) {
            cout << j << "\t";
        }
        cout << "result: " << existIncreaseThreeSubSequence(data) << endl;
    }

}