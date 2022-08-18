/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution1 {
public:
    void Swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 循环不变量
    // [0, low] < nums[right]
    // [low + 1, left) == nums[right] 区间
    // [high, right - 1]  > nums[right];
    vector<int> Partition(vector<int> &nums, int left, int right) {
        int low = left - 1;
        int high = right;
        while (left < high) {
            if (nums[left] < nums[right]) {
                Swap(nums[++low], nums[left++]);
            } else if (nums[left] > nums[right]) {
                Swap(nums[--high], nums[left]);
            } else {
                left++;
            }
        }
        Swap(nums[high], nums[right]);
        return vector<int>{low + 1, high};
    }

    int Find(vector<int> &nums, int left, int right) {
        if (left < right) {
            srand((int) time(nullptr));
            //Swap(nums[left + rand() % (right - left + 1)], nums[right]);
            vector<int> rec = Partition(nums, left, right);
            if (rec[0] == rec[1]) {
                return nums[rec[0]];
            } else if ((rec[0] - left) % 3 == 1) {
                return Find(nums, left, rec[0] - 1);
            } else {
                return Find(nums, rec[1] + 1, right);
            }
        } else {
            return nums[left];
        }
    }

    int singleNumber(vector<int> &nums) {
        return Find(nums, 0, nums.size() - 1);
    }
};

int rightOne(int val) {
    if (val == 0) {
        return -1;
    }
    return __builtin_ffs(val) - 1;
}

auto nextRightOne = [](int val)  {
    return [value = val]() mutable {
        int p = rightOne(value);
        if (p == -1) {
            return -1;
        }
        value ^= (1 << p);
        return p;
    };
};

class Solution {
public:
    int singleNumber1(vector<int> &nums) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int ct = 0;
            for (auto v: nums) {
                if ((v >> i) & 0x1) {
                    ++ct;
                    ct %= 3;
                }
            }
            if (ct) {
                ans ^= (1 << i);
            }
        }
        return ans;
    }

    int singleNumber2(vector<int> &nums) {
        int ans = 0;
        vector<int> times(32);
        for (auto v: nums) {
            auto func = nextRightOne(v);
            int p;
            while ((p = func()) != -1) {
                ++times[p];
            }
        }
        for (int i = 0; i < 32; i++) {
            times[i] %= 3;
            if (times[i]) {
                ans ^= (1 << i);
            }
        }
        return ans;
    }

    int singleNumber(vector<int> &nums) {
        int ans = 0;
        auto myPartition = [&](int low, int high) {
            if (low > high) {
                return -1;
            }
            if (low == high) {
                return low;
            }
            int l = low - 1;
            int index = random() % (high - low);
            swap(nums[index + low], nums[high]);
            int r = nums[high];
            for (; low < high; low++) {
                if (nums[low] <= r) {
                    ++l;
                    swap(nums[low], nums[l]);
                }
            }
            swap(nums[high], nums[++l]);
            return l;
        };

        function<void(int, int)> sorter = [&](int low, int high) {
            if (low > high) {
                return;
            }
            if (low == high) {
                ans = nums[low];
                return;
            }
            int q = myPartition(low, high);
            if ((q + 1) % 3 == 0) {
                sorter(q + 1, high);
            } else {
                sorter(low, q);
            }
        };
        sorter(0, nums.size() - 1);
        return ans;
    }
};
// @lc code=end

