#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// 声明
template <typename... Strings>
struct lazy_string_concat_helper;

// 递归
template <typename LastString, typename... Strings>
struct lazy_string_concat_helper<LastString, Strings...> {
    const LastString& data;
    const lazy_string_concat_helper<Strings...> tail;

    lazy_string_concat_helper(const LastString& data, const lazy_string_concat_helper<Strings...>& tail):data(data), tail(tail){}

    size_t size() const { return data.size() + tail.size(); }

    template <typename It>
    void save(It it) const{
        It begin = it - data.size();
        copy(data.begin(), data.end(), begin);
        tail.save(begin);
    }

    lazy_string_concat_helper<string, LastString, Strings...> operator+(
        const string& other) {
        return lazy_string_concat_helper<string, LastString, Strings...>(other,
                                                                         *this);
    }

    operator string() const {
        string result(size(), '\0');

        save(result.end());
        return result;
    }
};

// 终止条件
template <>
struct lazy_string_concat_helper<> {
    size_t size() const { return 0; }

    template <typename It>
    void save(It) const{
        return;
    }

    lazy_string_concat_helper<string> operator+ (const string& other) const {
        return lazy_string_concat_helper<string>(other, *this);
    }
};


int main() {
    string r = lazy_string_concat_helper<>() + "hello " + string("good");
    cout << r << endl;
}