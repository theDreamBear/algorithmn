1. random_shuffle
```cpp
void random_shuffle(vector<int>& data) {
    mt19937 mt(random_device{}());
    uniform_int_distribution u;
    for (int i = 0; i < data.size(); i++) {
        int j = u(mt) % ((int)data.size() - i) + i;
        swap(data[i], data[j]);
    }
}
```

2. 水塘抽样算法

```cpp n个数据选取k个
vector<int> get_k(vector<int>& data, int k) {
    vector<int> ans(k);
    int n = data.size();
    for (int i = 0; i < k; i++) {
        ans[i] = data[i];
    }
    for (int i = k; i < n; i++) {
        int j = u(mt) % (i + 1);
        if (j < k) {
            ans[j] = data[i];
        }
    }
    return data;
}
```

```cpp n个数据选取1个
int get_one(vector<int>& data) {
    int val = 0;
    for (int i = 0; i < data.size(); i++) {
        int j = u(mt) % (i + 1);
        if (j == 0) val = data[i];
    }
    return val;
}
```