// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

template<size_t ... Seq>
struct Index_Sequence{};

// N -> N - 1, N -> N - 2 N - 1 N

template<auto N, auto ... Other>
struct Seq_Imp: Seq_Imp<N - 1, N - 1, Other...> {

};

template<auto ... Other>
struct Seq_Imp<0, Other...>{
    using type = Index_Sequence<Other...>;
};


template<auto N>
using make_seq = typename Seq_Imp<N>::type;


template<typename T>
struct AddSpace {
    T& t;

    AddSpace(T& t):t(t){}

    friend ostream& operator << (ostream& os, AddSpace<T> s) {
        return os << s.t << " ";
    }
};

template<typename T, size_t ...Index>
void printTuple(T && tuple, Index_Sequence<Index...>) {
    (cout << ... << AddSpace(get<Index>(tuple)));
}

template<typename ...Args>
void printTuple(tuple<Args...> & tuple) {
    make_seq<sizeof ...(Args)> seq;
    printTuple(tuple, seq);
}


template<unsigned p, unsigned d>
struct IsPrimeImp {
    static constexpr bool value = (p % d == 0) and IsPrimeImp<p, d - 1>:: value;
};

template<unsigned p>
struct IsPrimeImp<p, 2> {
    static constexpr bool value = p % 2 != 0;
};

template<unsigned p>
struct IsPrime {
    static constexpr bool value = IsPrimeImp<p, p / 2>::value;
};

template<>
struct IsPrime<0> {
    static constexpr bool value = false;
};

template<>
struct IsPrime<1> {
    static constexpr bool value = false;
};

template<>
struct IsPrime<2> {
    static constexpr bool value = true;
};

template<>
struct IsPrime<3> {
    static constexpr bool value = true;
};


int main() {
    auto t = make_tuple("nic", 28, "man", "good man");
    printTuple(t);

    cout << "\nisPrime: " << IsPrime<1007>:: value << endl;
}