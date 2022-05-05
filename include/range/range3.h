#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

class RangeIte {
   public:
    int val;
    int step;

    RangeIte(int val, int step = 1) : val(val), step(step) {}

    RangeIte& operator++() {
        val += step;
        return *this;
    }

    bool operator!=(const RangeIte& rhs) { return this->val < rhs.val; }

    int operator*() { return val; }
};

class Range {
   public:
    int _begin;
    int _end;
    int _step;

    Range(int _begin, int _end, int _step) : _begin(_begin), _end(_end), _step(_step) {}

    Range(int _end) : Range(0, _end, 1) {}

    Range(int _begin, int _end) : Range(_begin, _end, 1) {}

    RangeIte begin() const { return RangeIte(_begin, _step); }

    RangeIte end() const { return RangeIte(_end, _step); }
};


template <template <typename...> typename Container, typename ...T>
class ContainerRangeIte {
   public:
    int index;
    typename Container<T...>::const_iterator ite;

    ContainerRangeIte(int index, typename Container<T...>::const_iterator ite) : index(index), ite(ite) {}

    ContainerRangeIte& operator++() {
        index++;
        ++ite;
        return *this;
    }

    bool operator!=(const ContainerRangeIte& rhs) const { return index < rhs.index && ite != rhs.ite; }

    pair<int, typename Container<T...>::const_iterator> operator*() {
        return pair<int, typename Container<T...>::const_iterator>{index, ite};
    }
};

template <template <typename...> typename Container, typename ...T>
class ContainerRange {
   public:
    const Container<T...>& _data;

    ContainerRange(const Container<T...>& _data) : _data(_data) {}

    ContainerRangeIte<Container, T...> begin() const {
        return ContainerRangeIte<Container, T...>{0, _data.begin()};
    }

    ContainerRangeIte<Container, T...> end() const {
        return ContainerRangeIte<Container, T...>{(int)_data.size(), _data.end()};
    }
};


auto range(int end) {
    return Range(0, end, 1);
}

auto range(int start, int end) {
    return Range(start, end, 1);
}

auto range(int start, int end, int step) {
    return Range(start, end, step);
}

template <template <typename...> typename Container, typename ...T>
auto range(const Container<T...>& data) {
    return ContainerRange<Container, T...>(data);
}

int main() {
    // 一般区间range
    for (auto v : range(3, 10, 4)) {
        cout << v << "\t";
    }
    cout << endl;

    // vector range
    vector<int> data{0, 1, 2, 3, 4 ,5 ,6};
    for (auto [index, val] : range(data)) {
        cout << "index:" << index << "\tvalue:" << *val << endl;
    }
    cout << endl;

    //  map range
    map<int, string> mis;
    mis[0] = "hello";
    mis[1] = "thank you";
    for (auto [index, val] : range(mis)) {
        cout << index << "\t" << val->first << "\t" << val->second << endl;
    }
    cout << endl;
}
