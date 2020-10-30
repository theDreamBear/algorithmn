#include <mydef.h>
#include <utility>

// 结果集
template<size_t ...>
struct my_index_sequence {};

template<size_t N, size_t ...S>
struct  make_index_sequence_helper : make_index_sequence_helper<N - 1, N - 1, S...> {

};

template<size_t ...S>
struct make_index_sequence_helper<0, S...> {
    typedef my_index_sequence<S...> type;
};

template<size_t N>
using my_make_index_sequence = typename make_index_sequence_helper<N>::type;


void hell(int x, int y) {
    cout << x << y << endl;
}


template <typename ... T>
void DummyWrapper(T... t){}

template <class T>
T unpacker(const T& t){
	cout <<t << endl;
	return t;
}

template<typename T, size_t ...i>
void print(T&& t, my_index_sequence<i...> ) {
    (unpacker(get<i>(t)), ...);
}


int main() {
    auto t = make_tuple("nic", 28, "man", "good man");
    print(t, my_make_index_sequence< tuple_size<decltype(t)>::value>());
}