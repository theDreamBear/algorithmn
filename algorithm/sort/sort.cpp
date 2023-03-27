#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

class myTimer {
public:
    chrono::time_point<chrono::steady_clock> beg;
    chrono::time_point<chrono::steady_clock> end;

    void start() {
        beg = chrono::steady_clock::now();
    }

    void stop() {
        end = chrono::steady_clock::now();
    }

    int get_s() {
        return duration_cast<chrono::seconds>(end - beg).count();
    }

    int get_us() {
        return duration_cast<chrono::microseconds>(end - beg).count();
    }
};

//
void BubbleSort(vector<int> &data) {
    int low = 0;
    int high = data.size() - 1;
    // [low, high] 为未排序区间
    // (high, data.size() - 1] 为已排序区间
    while (low < high) {
        //【last， high] 为有序的
        // last为最后一个和前面交换的位置
        int last = low;
        for (int i = low + 1; i <= high; i++) {
            if (data[i] < data[i - 1]) {
                swap(data[i], data[i - 1]);
                last = i;
            }
        }
        high = last - 1;
    }
}

void InsertionSort(vector<int> &data) {
    // [i, sz) 为未排序位置
    // [0, i) 已有序位置
    // 插入排序的时间复杂度为 O(n + 逆序对的个数)
    for (int i = 1; i < data.size(); i++) {
        int target = data[i];
        int j = i;
        // 循环不变式
        // j 就是最终插入的位置
        while (j > 0 && target < data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = target;
    }
}
// pick
void PickSort(vector<int>& data) {
    // （i，sz) 已排序区域
    // [0, i] 待排序区域
    for (int i = data.size() - 1; i > 0; i--) {
        int biggestIndex = i;
        for (int j = 0; j < i; j++) {
            if (data[j] > data[biggestIndex]) {
                biggestIndex = j;
            }
        }
        swap(data[i], data[biggestIndex]);
    }
}

void _mergeSort(vector<int>& data, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + ((high - low) >> 1);
    _mergeSort(data, low, mid);
    _mergeSort(data, mid + 1, high);

    // merge
    int l = low, r = mid + 1;
    int temp[high - low + 1];
    for (int i = 0; i <= high - low + 1; i++) {
        if (l > mid || r <= high && data[l] > data[r]) {
            temp[i] = data[r++];
        } else {
            temp[i] = data[l++];
        }
    }
    for (int i = 0; i <= high - low + 1; i++) {
        data[i + low] = temp[i];
    }
}
//
void MergeSort(vector<int>& data) {
    _mergeSort(data, 0, data.size() - 1);
}

pair<int, int> three_partition(vector<int>& data, int low, int high) {
    if (low >= high) {
        return {low - 1,  high + 1};
    }
    int pivot = data[high];
    // left
    // [low, left] 为 < 区间
    // [i, high - 1] 待处理区间
    int i = low;
    int left = low - 1;
    for (; i < high; i++) {
        if (data[i] < pivot) {
            swap(data[i], data[++left]);
        }
    }
    // [right, high - 1] > 区间
    // （left, j] 待处理区域
    // (j, right) == 区间， 因为<的都被上一步一走了之了
    int j = high - 1;
    int right = high;
    for (; j > left; j--) {
        if (data[j] > pivot) {
            swap(data[j], data[--right]);
        }
    }
    swap(data[high], data[right++]);
    return {left, right};
}

void _quickSort(vector<int>& data, int low, int high) {
    if (low >= high) {
        return;
    }
#ifdef USE_STL_PARTITION
    int pivot = data[high];
    // p 为第一个不符合的位置， 前面都符合
    // 使用自带partition的
    // 1.这个函数为前[ ) 的区间
    // 2.返回值为第一个不符合预期的位置
    // 3.用作快排机注意死循环
    auto p = partition(data.begin() + low, data.begin() + high + 1, [&](int value) {
        return value < pivot;
    }) - data.begin();
    auto q = data.rend() - 1 -  partition(data.rbegin(), data.rend() - p, [&](int value) {
        return value > pivot;
    });
    _quickSort(data, q + 1, high);
    _quickSort(data, low, p - 1);
#else
    auto x = three_partition(data, low, high);
    _quickSort(data, low, x.first);
    _quickSort(data, x.second, high);
#endif
}

void QuickSort(vector<int>& data) {
    _quickSort(data, 0, data.size() - 1);
}

void heapUp(vector<int>& data, int idx) {
    int val = data[idx];
    while (idx >= 1) {
        int p = (idx - 1) >> 1;
        if (data[p] <= val) {
            break;
        }
        data[idx] = data[p];
        idx = p;
    }
    data[idx] = val;
}

void heapDown(vector<int>& data, const int sz) {
    int idx = 0;
    int val = data[idx];
    while (idx * 2 + 1 < sz) {
        int mm = (idx << 1) + 1;
        int ma = (idx << 1) + 2;
        if (ma >= sz || data[ma] >= data[mm]) {
            ma = mm;
        }
        if (data[ma] >= val) {
            break;
        }
        data[idx] = data[ma];
        idx = ma;
    }
    data[idx] = val;
}

void push(vector<int>& data, int& sz, int val) {
    if (sz < data.size()) {
        data[sz] = val;
    } else {
        data.push_back(val);
    }
    sz++;
    heapUp(data, sz - 1);
}

int popMin(vector<int>& data, int& sz) {
    swap(data[0], data[sz - 1]);
    --sz;
    heapDown(data, sz);
    return data[sz];
}

void HeapSort(vector<int>& data) {
    vector<int> temp;
    int sz = 0;
    for (auto val : data) {
        push(temp, sz, val);
    }
    for (auto i = 0; i < data.size(); i++) {
        data[i] = popMin(temp, sz);
    }
}

void test(vector<int> data, void(*sorter)(vector<int>&), const char* msg) {
    myTimer timer;
    timer.start();

    sorter(data);

    timer.stop();
    cout << msg << "\t";
    cout << "cost: " << timer.get_us() << "(us)" << endl;
}

vector<int> random_vec(int n) {
    vector<int> ans(n);
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<int> u;
    for (int i = 0; i < n; i++) {
        ans[i] = u(mt);
    }
    return ans;
}

int main() {
    vector<int> data = random_vec(100000);
    test(data, BubbleSort, "BubbleSort");
    test(data, InsertionSort, "InsertionSort");
    test(data, PickSort, "PickSort");
    test(data, MergeSort, "MergeSort");
    test(data, QuickSort, "QuickSort");
    test(data, HeapSort, "HeapSort");
}
