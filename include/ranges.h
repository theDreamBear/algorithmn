#ifndef __MY_RANGES_H__
#define __MY_RANGES_H__
#include <vector>
using namespace std;

struct rangeIterator {
    typedef long VALUE_TYPE;
    rangeIterator(VALUE_TYPE value) {
        _value = value;
    }

    bool operator != (rangeIterator& rhs) {
        return getValue() != rhs.getValue();
    }

    VALUE_TYPE operator*() const {
        return getValue();
    }

    const rangeIterator&  operator ++() {
        ++_value;
        return *this;
    }
 private:
    VALUE_TYPE getValue() const{
        return _value;
    }
    VALUE_TYPE _value;


};

struct range {
    int left,right;

    range(int left, int right) {
        this->left = left;
        this->right = right;
    }

    range(int right) {
        left = 0;
        this->right = right;
    }

    rangeIterator begin() const {
        return rangeIterator(left);
    }

    rangeIterator end() const {
        return rangeIterator(right);
    }
};

template<typename T>
struct rangeVecIterator {
    //typedef long T;

    rangeVecIterator(int index, const vector<T>& values):_index(index), _values(values){}

    bool operator!=(const rangeVecIterator& rhs) {
        return getIndex() != rhs.getIndex();
    }

    const pair<int, T> operator* () const{
        int index = getIndex();
        return {index, _values[index]};
    }

    const rangeVecIterator& operator++() {
        ++_index;
        return *this;
    }

 private:
    int getIndex() const{
        return _index;
    }

    int _index;
    const vector<T>& _values;
};

template<typename T>
struct rangeVec {
    //typedef long T;
    const vector<T>& values;

    rangeVec(const vector<T>& values):values(values) {}

    rangeVecIterator<T> begin() const {
        return rangeVecIterator<T>(0, values);
    }

    rangeVecIterator<T> end() const {
        return rangeVecIterator<T>(values.size(), values);
    }
};

#endif