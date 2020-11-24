#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>

#include <type_traits>

using namespace std;

template <typename ...Args>
struct isCallable {
    constexpr  static bool value = false;
};

/*
 * 类成员指针
 * */
template <typename R, typename AClass, typename ...Args>
struct isCallable<R(AClass::*)(Args...)> {
    constexpr  static bool value = true;
};

/*
 * 函数指针
 * */
template <typename R, typename ...Args>
struct isCallable<R(*)(Args...)> {
    constexpr  static bool value = true;
};

/*
 * 函数
 * */
template <typename Fun, typename ...Args>
struct isCallable<Fun(Args...)> {
    constexpr  static bool value = true;
};

class A {
 public:
    int add(int left, int right) {
        return left + right;
    }

    static void print(int a, int b){
        cout << a << b;
    }
};

int add(int left, int right) {
    return left + right;
}

int main() {
    cout << isCallable<decltype(&A::add)>::value << endl;
    cout << isCallable<decltype(add)>::value << endl;
    cout << isCallable<decltype(A::print)>::value << endl;
}