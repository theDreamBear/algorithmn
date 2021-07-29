#ifndef __MY_RANGES2_H__
#define __MY_RANGES2_H__

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

using namespace std;

template<typename ...T>
struct Range;


struct intIterator {
    typedef long VALUE_TYPE;
    explicit intIterator(VALUE_TYPE value) {
        _value = value;
    }

    bool operator != (intIterator& rhs) {
        return getValue() != rhs.getValue();
    }

    VALUE_TYPE operator*() const {
        return getValue();
    }

    const intIterator&  operator ++() {
        ++_value;
        return *this;
    }
private:
    [[nodiscard]] VALUE_TYPE getValue() const{
        return _value;
    }
    VALUE_TYPE _value;


};

template<>
struct Range<int> {
    int left,right;

    Range(int left, int right) {
        this->left = left;
        this->right = right;
    }

    explicit Range(int right) {
        left = 0;
        this->right = right;
    }

    [[nodiscard]] intIterator begin() const {
        return intIterator(left);
    }

    [[nodiscard]] intIterator end() const {
        return intIterator(right);
    }
};

template<typename T>
struct vecIterator {
    explicit vecIterator(const vector<T>& values):_index(0), _values(values){}

    vecIterator(int index, const vector<T>& values):_index(index), _values(values){}

    bool operator!=(const vecIterator& rhs) {
        return getIndex() != rhs.getIndex();
    }

    pair<int, T> operator* () const{
        int index = getIndex();
        return {index, ref(_values[index])};
    }

    const vecIterator& operator++() {
        ++_index;
        return *this;
    }

private:
    [[nodiscard]] int getIndex() const{
        return _index;
    }

    int _index;
    const vector<T>& _values;
};

template<typename T>
struct Range<vecIterator<T>> {
    //typedef long T;
    const vector<T>& values;

    explicit Range(const vector<T>& values):values(values) {}

    [[nodiscard]] vecIterator<T> begin() const {
        return vecIterator<T>(0, values);
    }

    [[nodiscard]] vecIterator<T> end() const {
        return vecIterator<T>(values.size(), values);
    }
};


template<typename KType, typename VType, typename Container = unordered_map<KType, VType>>
struct mapIterator{
    explicit mapIterator(const Container& container1):container(container1), it(container.begin()) {}

    mapIterator(typename Container::const_iterator pos, const Container& container1): container(container1), it(pos){}

    bool operator!=(const mapIterator& rhs) {
        return getIndex() != rhs.getIndex();
    }

    pair<KType, VType> operator* () const{
        auto pos = getIndex();
        return {pos->first, pos->second};
    }

    const mapIterator& operator++() {
        it++;
        return *this;
    }

private:
    [[nodiscard]] typename Container::const_iterator getIndex() const{
        return it;
    }

    const Container& container;
    typename Container::const_iterator it;
};


template<typename KType, typename VType>
struct Range<mapIterator<KType, VType>> {
    const unordered_map<KType, VType>& hash_map;

    explicit Range(const unordered_map<KType, VType>& values):hash_map(values) {}

    [[nodiscard]] mapIterator<KType, VType> begin() const {
        return mapIterator<KType, VType>(hash_map);
    }

    [[nodiscard]] mapIterator<KType, VType> end() const {
        return mapIterator<KType, VType>(hash_map.end(), hash_map);
    }
};


Range<int> range(int left, int right) {
    return Range<int>(left, right);
}

Range<int> range(int right) {
    return Range<int>(0, right);
}

template<typename T>
Range<vecIterator<T>> range(const vector<T>& data) {
    return Range<vecIterator<T>>(data);
}

template<typename KType, typename VType>
Range<mapIterator<KType, VType>> range(const unordered_map<KType, VType>& data) {
    return Range<mapIterator<KType, VType>>(data);
}


int main() {
    vector<int> data;
    // 整数
    for (auto i : range(10)) {
        data.emplace_back(i);
    }

    for (auto i : range(11, 20)) {
        data.emplace_back(i);
    }

    // vector
    for (auto [index, value] : range(data)) {
        cout << index << "\t" << value << endl;
    }

    // map 测试用例
    unordered_map<int, int> om;
    om[1] = 1;
    om[2] = 2;
    om[3] = 3;
    for (auto [k, v] : range(om)) {
        cout << "key: " << k << " value: " << v << endl;
    }

    // set 不需要 range
}

#endif