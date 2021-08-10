class hash_heap {
private:
    vector<int> _indexes;

    unordered_map<int, int> _index_map;

    const vector<int> _data;

    function<bool(int, int)> _cmp;

    int sz;

    int get_value(int index) {
        return _data[index];
    }

    void heap_down(int i = 0) {
        if (sz <= 1) {
            return;
        }
        int index = _indexes[i];
        while (2 * i + 1 < sz) {
            int mm = 2 * i + 1;
            int ma = mm + 1;
            if (ma < sz && _cmp(get_value(_indexes[ma]), get_value(_indexes[mm]))) {
                mm = ma;
            }
            if (_cmp(get_value(index), get_value(_indexes[mm]))) {
                break;
            }
            // 往下挪
            _indexes[i] = _indexes[mm];
            // 更新 kv
            _index_map[_indexes[i]] = i;
            i = mm;
        }
        _indexes[i] = index;
        _index_map[_indexes[i]] = i;
    }

    void heap_up() {
        if (sz <= 1) {
            return;
        }
        int i = sz - 1;
        int index = _indexes[i];
        while (i) {
            int p = i >> 1;
            if (!_cmp(get_value(index), get_value(_indexes[p]))) {
                break;
            }
            _indexes[i] = _indexes[p];
            _index_map[_indexes[i]] = i;
            i = p;
        }
        _indexes[i] = index;
        _index_map[_indexes[i]] = i;
    }


public:
    explicit hash_heap(const vector<int> &data, function<bool(int, int)> cmp = less<int>{}) : _data(data),
                                                                                              _cmp(std::move(cmp)),
                                                                                              sz(0) {}

    void push(int index) {
        if (index >= _data.size()) {
            return;
        }
        if (sz >= _indexes.size()) {
            _indexes.push_back(index);
        } else {
            _indexes[sz] = index;
        }
        // 更新 kv
        _index_map[index] = sz;
        ++sz;
        heap_up();
    }

    void pop(int inner_index = 0) {
        if (inner_index >= sz) {
            return;
        }
        // 存储大小减1
        --sz;
        // 删除 kv
        _index_map.erase(_indexes[inner_index]);
        if (inner_index == sz) {
            // 就是最后一个, 删除结束
            return;
        }
        // 最后一个往前挪
        _indexes[inner_index] = _indexes[sz];
        // 更新 kv
        _index_map[_indexes[inner_index]] = inner_index;
        // 更新堆
        heap_down(inner_index);
    }

    int top() {
        return _indexes[0];
    }

    void hash_pop(int index) {
        if (_index_map.count(index) == 0) {
            return;
        }
        int inner_index = _index_map[index];
        pop(inner_index);
    }

    int size() {
        return sz;
    }

    bool check(int i = 0) {
        if (i >= sz) {
            return true;
        }
        int mm = 2 * i + 1, ma = mm + 1;
        if (ma < sz && _cmp(get_value(_indexes[ma]), get_value(_indexes[mm]))) {
            mm = ma;
        }
        if (!_cmp(get_value(_indexes[i]), get_value(_indexes[mm]))) {
            return false;
        }
        return check(mm);
    }

    void print() {
        for (auto &kv : _index_map) {
            cout << kv.first << "\t" << kv.second << "\t" << get_value(_indexes[kv.first]) << "\t" << _data[kv.second]
                 << endl;
        }
    }
};

class medianWindows {
private:
    const vector<int> &data;
    hash_heap min_heap;
    hash_heap max_heap;
    int k;
    int mid;
    int cur;
    int sz;
    double _m;

    void adjust() {
        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(mid);
            mid = max_heap.top();
            max_heap.pop();
        }

        while (min_heap.size() > max_heap.size()) {
            max_heap.push(mid);
            mid = min_heap.top();
            min_heap.pop();
        }
    }

    void init() {
        cur = 0;
        mid = -1;
        for (; cur < k && cur < data.size(); cur++) {
            ++sz;
            if (cur == 0) {
                mid = cur;
                continue;
            }
            if (data[cur] <= data[mid]) {
                max_heap.push(cur);
            } else {
                min_heap.push(cur);
            }
            adjust();
        }
        _m = median();
    }

    double median() {
        if (sz % 2 == 0) {
            return (data[mid] + data[max_heap.top()]) / 2.0;
        }
        return data[mid];
    }

public:
    medianWindows(const vector<int> &data, int k) :
            data(data), min_heap(data), max_heap(data, greater<int>{}), k(k),
            mid(-1), cur(0), sz(0) {
        init();
    }

    bool nextMedian(double &m) {
        if (cur >= data.size()) {
            m = -1;
            return false;
        }
        if (k == 1) {
            return data[cur];
        }
        // push
        if (data[cur] <= data[mid]) {
            max_heap.push(cur);
        } else {
            min_heap.push(cur);
        }

        // pop
        int pre = cur - k;
        if (pre == mid) {
            mid = max_heap.top();
            max_heap.pop();
        } else {
            max_heap.hash_pop(pre);
            min_heap.hash_pop(pre);
        }
        adjust();
        m = median();
        cur++;
        return true;
    }

    vector<double> getMedian() {
        vector<double> res;
        res.push_back(_m);
        while (nextMedian(_m)) {
            res.push_back(_m);
        }
        return res;
    }
};

class violateWindows {
private:
    const vector<int> &data;
    int cur;
    int k;
    double m{};

public:
    violateWindows(const vector<int> &data, int k) : data(data), cur(0), k(k) {}

    bool median() {
        vector<int> res;
        if (cur + k > data.size()) {
            return false;
        }
        for (int i = 0; i < k; i++) {
            res.push_back(data[cur + i]);
        }
        sort(res.begin(), res.end());
        int sz = res.size();
        if (sz % 2 == 0) {
            m = (res[sz / 2 - 1] + res[sz / 2]) / 2.0;
        } else {
            m = res[sz / 2];
        }
        cur++;
        return true;
    }

    vector<double> getMedian() {
        vector<double> res;
        //res.push_back(m);
        while (median()) {
            res.push_back(m);
        }
        return res;
    }
};

///  ===============测试代码=============================

//

vector<int> get_random_vec(int n, int limit) {
    vector<int> data(n);
    random_device rd{};
    mt19937 mt(rd());
    uniform_int_distribution<int> u(-limit, limit);
    for (int i = 0; i < n; i++) {
        data[i] = u(mt);
    }
    return data;
}