#include <assert.h>

#include <climits>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class heap {
 private:
    vector<int> _data;
    function<bool(int, int)> cmp;
    int _size;

    bool _swap_if(int i, int j) { return cmp(i, j); }

    bool _swapUp(int cur, int parrent) { return _swap_if(cur, parrent); }

    bool _swapDown(int cur, int child) { return _swap_if(child, cur); }

    bool _swapChild(int left, int right) { return _swap_if(right, left); }

    void _indexCheck(int idx) { assert(idx < size() && idx >= 0); }

    void _setData(int idx, int v) {
        _indexCheck(idx);
        _dataRef()[idx] = v;
    }

    int _getData(int idx) {
        _indexCheck(idx);
        return _dataRef()[idx];
    }

    void _increaseSize() { ++_sizeRef(); }

    void _decreaseSize() { --_sizeRef(); }

    int& _sizeRef() {
        return _size;
    }

    vector<int>& _dataRef(){
        return _data;
    }
    void _resetSize() {
        _sizeRef() = _dataRef().size();
    }

   void _reset(vector<int>& nums) {
        _dataRef() = nums;
        _resetSize();
   }

    int size() { return _sizeRef(); }

    int& _frontRef() { return _dataRef()[0]; }

    int& _backRef() { return _dataRef()[size() - 1]; }

    void _heapUp(int cur) {
        _indexCheck(cur);
        int temp = _getData(cur);
        while (0 != cur) {
            int p = cur / 2;
            if (!_swapUp(temp, _getData(p))) {
                break;
            }
            _setData(cur, _getData(p));
            cur = p;
        }
        _setData(cur, temp);
    }

    int _leftChildIndex(int cur) {
        return cur * 2 + 1;
    }

    int _rightChildIndex(int cur) {
        return cur * 2 + 2;
    }

    int _lastBranchIndex() {
        return size() / 2 - 1;
    }

    void _heapDown(int cur) {
        _indexCheck(cur);
        int temp = _getData(cur);
        while (_leftChildIndex(cur)< size()) {
            int min = _leftChildIndex(cur);
            int max = _rightChildIndex(cur);
            if (max < size() &&
                _swapChild(_getData(min), _getData(max))) {
                min = max;
            }
            if (!_swapDown(temp, _getData(min))) {
                break;
            }
            _setData(cur, _getData(min));
            cur = min;
        }
        _setData(cur, temp);
    }

 public:
    heap(function<bool(int, int)> cmp = greater<int>()) : cmp(cmp) {
        _resetSize();
    }

    void push(int num) {
        _dataRef().push_back(num);
        _increaseSize();
        _heapUp(size() - 1);
    }

    int top() {
        assert(size() > 0);
        return _dataRef().front();
    }

    void pop() {
        if (size() > 0) {
            swap(_frontRef(), _backRef());
            _decreaseSize();
            if (size() > 0) {
                _heapDown(0);
            }
        }
    }

    void makeheap(vector<int>& nums) {
        _reset(nums);
        for (int i =_lastBranchIndex() ;i >= 0; --i) {
            _heapDown(i);
        }
    }
    bool empty() { return 0 == size(); }
};

class minHeap : public heap {
 public:
    minHeap() : heap(less<int>{}) {}
};

class maxHeap : public heap {
 public:
    maxHeap() : heap(greater<int>{}) {}
};

int main() {
    srand(time(NULL));
    minHeap mh;
    for (int i = 0; i < 5553; ++i) {
        int v = rand() % 10000;
        mh.push(v);
    }
    while (!mh.empty()) {
        cout << mh.top() << " ";
        mh.pop();
    }
    cout << endl;

    maxHeap mah;
    for (int i = 0; i < 123; ++i) {
        int v = rand() % 1000;
        mah.push(v);
    }
    while (!mah.empty()) {
        cout << mah.top() << " ";
        mah.pop();
    }
    cout << endl;

    vector<int> nums{10,5,2,7,3,6, 4,100,1};
    heap h;
    h.makeheap(nums);
     while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}
