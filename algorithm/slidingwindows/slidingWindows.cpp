#include <assert.h>

#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class slidingWindows {
 public:
    slidingWindows(const vector<int>& nums, int windows_size,
                   function<bool(int, int)> op)
        : _nums(nums), _windows_size(windows_size), _op(op) {}

    // 数据入窗口
    void add(int i) {
        while (!_data.empty() && _op(_nums[i], _nums[_data.back()])) {
            _data.pop_back();
        }
        _data.push_back(i);
        while (expire(i)) {
            _data.pop_front();
        }
    }

    bool top(int& val) {
        if (!_data.empty()) {
            assert(_data.front() >= 0 && _data.front() < _nums.size());
            val = _nums[_data.front()];
            return true;
        }
        return false;
    }

    int top() { return _nums[_data.front()]; }

 private:
    const vector<int>& _nums;
    int _windows_size;
    function<bool(int, int)> _op;
    deque<int> _data;

    bool expire(int i) {
        if (!_data.empty() && i - _data.front() >= _windows_size) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<int> ans{1, 4, 2, 7, 3, 9, 2, 12, 5, 9};
    int windows_size = 3;
    // 最大值滑动窗口
    slidingWindows smax(ans, windows_size, greater<int>());
    // 最小值滑动窗口
    slidingWindows smin(ans, windows_size, less<int>());
    vector<int> mm;
    int gap = 0;
    for (int i = 0; i < windows_size; ++i) {
        smax.add(i);
        smin.add(i);
    }
    cout << "index: " << windows_size - 1 << "\t"
         << "max: " << smax.top() << "  |||  "
         << "min: " << smin.top() << endl;
    if (smax.top() - smin.top() > gap) {
        gap = smax.top() - smin.top();
    }
    for (int i = windows_size; i < ans.size(); ++i) {
        smax.add(i);
        smin.add(i);
        cout << "index: " << i << "\t"
             << "max: " << smax.top() << "  |||  "
             << "min: " << smin.top() << endl;
        if (smax.top() - smin.top() > gap) {
            gap = smax.top() - smin.top();
        }
    }
    cout << "maxgap: " << gap << endl;
}