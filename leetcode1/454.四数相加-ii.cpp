/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution1 {
public:
    int findLeftIndex(const vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (vec[mid] >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (vec[low] == target) {
            return low;
        }
        if (vec[high] == target) {
            return high;
        }
        return -1;
    }

    int findRightIndex(const vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (vec[mid] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (vec[high] == target) {
            return high;
        }
        if (vec[low] == target) {
            return low;
        }
        return -1;
    }

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                for (int k = 0; k < nums3.size(); k++) {
                    int now = nums1[i] + nums2[j] + nums3[k];
                    int left = findLeftIndex(nums4, -now);
                    if (left == -1) {
                        continue;
                    }
                    int right = findRightIndex(nums4, -now);
                    ans += (right - left + 1);
                }
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    int findLeftIndex(const vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (vec[mid] >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (vec[low] == target) {
            return low;
        }
        if (vec[high] == target) {
            return high;
        }
        return -1;
    }

    int findRightIndex(const vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (vec[mid] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (vec[high] == target) {
            return high;
        }
        if (vec[low] == target) {
            return low;
        }
        return -1;
    }

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        vector<int> lhs;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                lhs.push_back(nums1[i] + nums2[j]);
            }
        }
        vector<int> rhs;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                rhs.push_back(nums3[i] + nums4[j]);
            }
        }
        sort(rhs.begin(), rhs.end());

        int ans = 0;
        for (int i = 0; i < lhs.size(); i++) {
            int now = lhs[i];
            int left = findLeftIndex(rhs, -now);
            if (left == -1) {
                continue;
            }
            int right = findRightIndex(rhs, -now);
            ans += (right - left + 1);
        }
        return ans;
    }
};

class Solution3 {
public:
    int findLeftIndex(const vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (vec[mid] >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (vec[low] == target) {
            return low;
        }
        if (vec[high] == target) {
            return high;
        }
        return -1;
    }

    int findRightIndex(const vector<int> &vec, int target) {
        int low = 0, high = vec.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (vec[mid] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (vec[high] == target) {
            return high;
        }
        if (vec[low] == target) {
            return low;
        }
        return -1;
    }

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        map<int, int> lhs;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                lhs[nums1[i] + nums2[j]]++;
            }
        }
        unordered_map<int, int> rhs;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                rhs[nums3[i] + nums4[j]]++;
            }
        }
        int ans = 0;
        for (auto p : lhs) {
            auto [now, t] = p;
            if (rhs.count(-now)) {
                ans += t * rhs[-now];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> rhs;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                rhs[nums3[i] + nums4[j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int val = -(nums1[i] + nums2[j]);
                if (rhs.count(val)) {
                    ans += rhs[val];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

