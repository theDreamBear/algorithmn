#include <iostream>
#include <tuple>
using namespace std;


bool ok(int a, int b) { return a + b; }

template <typename Fn, typename T, size_t... i>
bool _invoke(Fn&& fn, T&& t, index_sequence<i...>) {
    return fn(get<i>(t)...);
}

template <typename Fn, typename... T>
bool invoke(Fn&& fn, tuple<T...> t) {
    return _invoke(fn, t, make_index_sequence<sizeof...(T)>());
}


int main() {
    auto inp = std::make_tuple(0, 12);
    cout << invoke(ok, inp);
}