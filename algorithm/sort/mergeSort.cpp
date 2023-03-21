#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <random>
#include <chrono>

using namespace std;


class myTimer {
private:
    chrono::steady_clock::time_point beg;
    chrono::steady_clock::time_point end;

public:
    void start() {
        beg = chrono::steady_clock::now();
    }

    void stop() {
        end = chrono::steady_clock::now();
    }

    long long get_s() {
        return std::chrono::duration_cast<chrono::seconds>(end - beg).count();
    }

    long long get_ms() {
        return std::chrono::duration_cast<chrono::milliseconds>(end - beg).count();
    }
};


class MergeSort {
private:
    void _insertion_sort(vector<int> &data, int low, int high) {
        for (int k = low + 1; k < high + 1; k++) {
            int value = data[k];
            int j = k;
            // 【j, k) > value 区间
            // [low, j - 1] 待处理区间
            for (; j > low; j--) {
                if (data[j - 1] > value) {
                    data[j] = data[j - 1];
                } else {
                    break;
                }
            }
            data[j] = value;
        }
    }

    void _merge(vector<int> &data, vector<int> &temp, int low, int mid, int high, int idx) {
        int i = low;
        int j = mid + 1;
        for (int k = low; k < high + 1; k++) {
            if (j > high) {
                data[k] = temp[i++];
                continue;
            }
            if (i > mid) {
                data[k] = temp[j++];
                continue;
            }
            if (temp[i] <= temp[j]) {
                data[k] = temp[i++];
            } else {
                data[k] = temp[j++];
            }
        }
    }

    void _sort(vector<int> &data, vector<int> &temp, int low, int high, int idx) {
        if (low + 4 >= high) {
            // insertSort
            if ((idx & 0x1) == 0) {
                _insertion_sort(temp, low, high);
                return;
            }
            _insertion_sort(data, low, high);
            return;
        }
        int mid = low + ((high - low) >> 1);
        _sort(data, temp, low, mid, idx + 1);
        _sort(data, temp, mid + 1, high, idx + 1);
        if (idx & 0x1) {
            _merge(data, temp, low, mid, high, idx + 1);
        } else {
            _merge(temp, data, low, mid, high, idx + 1);
        }

    }

public:
    void sort(vector<int> &data) {
        vector<int> temp = data;
        _sort(temp, data, 0, (int) data.size() - 1, 0);
    }
};

auto printer = [](auto &&data) {
    for (auto v: data) {
        cout << v << "\t";
    }
    cout << endl;
};

vector<int> randomVec(int num, int minVal, int maxVal) {
    vector<int> data(num);
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<int> u(minVal, maxVal);
    for (int i = 0; i < num; i++) {
        data[i] = u(mt);
    }
    return data;
}

MergeSort mergeSort;

void bigTest(int caseNum) {
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<int> u(1000000, 5000000);
    myTimer timer;
    for (int i = 0; i < caseNum; i++) {
        int num = u(mt);
        auto data = randomVec(num, -1e8, 1e8);
        auto other = data;
        timer.start();
        mergeSort.sort(data);
        timer.stop();
        auto d = timer.get_ms();
        timer.start();
        sort(other.begin(), other.end());
        timer.stop();
        auto d2 = timer.get_ms();
        cout << num << "\t" << d << "\t" << d2 << "\t" << d * 1.0 / d2 << endl;
        if (!is_sorted(data.begin(), data.end())) {
            printer(data);
            return;
        }
    }
}

// 性能还是有些不够， 比自带sort慢不少

int main(int argc, char *argv[]) {
    bigTest(1000);
}
