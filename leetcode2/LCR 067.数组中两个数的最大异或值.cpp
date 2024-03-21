/*
 * @lc app=leetcode.cn id=LCR 067 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 067] 数组中两个数的最大异或值
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
class Solution {
public:
    int findMaximumXOR_violate(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int x = nums[i] ^ nums[j];
                ans = max(ans, x);
            }
        }
        return ans;
    }

    inline void split_vec(vector<int>& nums, int idx, vector<int>& zero, vector<int>& one) {
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] >> idx) & 0x1) {
                one.push_back(nums[i]);
            } else {
                zero.push_back(nums[i]);
            }
        }
    }

    int findMaximumXORHelper(int idx, vector<int>& zero, vector<int>& one) {
        if (idx < 0) {
            return 0;
        }
        // 如果当前还没找到
        if (zero.empty() or one.empty()) {
            vector<int> no, nz;
            while (idx >= 0) {
                no.clear();
                nz.clear();
                split_vec(one, idx, no, nz);
                split_vec(zero, idx, no, nz);
                if (!no.empty() and !nz.empty()) {
                    break;
                }
                idx--;
            }
            if (idx < 0 and no.empty() and nz.empty()) {
                return 0;
            }
            // 找到了
            if (!no.empty() and !nz.empty()) {
                return  (1 << idx) + findMaximumXORHelper(idx - 1, nz, no);
            }
            return 0;
        } else {
            vector<int> oz, oo, zz, zo;
            split_vec(one, idx, oz, oo);
            split_vec(zero, idx, zz, zo);
            if ((oz.empty() || zo.empty()) && (oo.empty() || zz.empty())) {
                return findMaximumXORHelper(idx - 1, zero, one);
            }
            if (oz.empty() || zo.empty()) {
                return (1 << idx) + findMaximumXORHelper(idx - 1, zz, oo);
            }
            if (oo.empty() || zz.empty()) {
                return (1 << idx) + findMaximumXORHelper(idx - 1, oz, zo);
            }
            return (1 << idx) + max(findMaximumXORHelper(idx - 1, zz, oo), findMaximumXORHelper(idx - 1, oz, zo));
        }
    }
    int findMaximumXOR_1(vector<int>& nums) {
        vector<int> zero, one = nums;
        return findMaximumXORHelper(31, zero, one);
    }

    int findMaximumXOR_hash(vector<int>& nums) {
        int x = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> seen;
            for (auto v : nums) {
                seen.insert(v >> i);
            }
            int nx = (x << 1) + 1;
            bool found = false;
            for (auto v : nums) {
                if (seen.count((v >> i) ^ nx)) {
                    found = true;
                    break;
                }
            }
            x = nx - !found;
        }
        return x;
    }

    class TrieNode {
     public:
        TrieNode* children[2];
        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };

    class Trie {
     public:
        TrieNode root;
        int max_bit;

        Trie(int max_bit):max_bit(max_bit) {}

        void add(int num) {
            TrieNode* node = &root;
            for (int i = max_bit; i >= 0; i--) {
                int v = (num >> i) & 0x1;
                if (!node->children[v]) {
                    node->children[v] = new TrieNode;
                }
                node = node->children[v];
            }
        }

        int check(int num) {
            int x = 0;
            TrieNode* node = &root;
            for (int i = max_bit; i >= 0; i--) {
                int v = (num >> i) & 0x1;
                if (!node->children[(v + 1) % 2]) {
                    x <<= 1;
                    node = node->children[v];
                } else {
                    x = (x << 1) + 1;
                    node = node->children[(v + 1) % 2];
                }
            }
            return x;
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        int max_bit = 0;
        for (auto v : nums) {
            int bit = v == 0 ? 0 : 31 - __builtin_clz(v);
            max_bit = max(max_bit, bit);
        }
        Trie root(max_bit);
        for (int i = 1; i < nums.size(); i++) {
            root.add(nums[i - 1]);
            x = max(x, root.check(nums[i]));
        }
        return x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,10,5,25,2,8]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

// @lcpr case=start
// [8,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [14,70,53,83,49,91,36,80,92,51,66,70]\n
// @lcpr case=end

 */

