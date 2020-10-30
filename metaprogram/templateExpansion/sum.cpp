#include <iostream>
using namespace std;

template<size_t N>
struct Sum;

template<>
struct Sum<0> {
    constexpr static int value = 0;
};


template<size_t N>
struct Sum {
    constexpr static int value = N + Sum<N - 1>::value;
};

int main() {
    cout << Sum<20>::value << endl;
}