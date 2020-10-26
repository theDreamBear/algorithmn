#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
    int reslove(string s, int a) { return -1; }
};

int add(int a, int b) { return a + b; }

#ifdef DEBUG
template <typename Result, typename... Input>
struct tester {
    Result r;
    tuple<Input...> input;
    tester(Result r, Input... input) : r(r), input(input...) {}

    template <typename Obj, typename Fn>
    bool checkResultObj(Obj obj, Fn&& fn) {
        if constexpr (tuple_size<decltype(input)>::value == 0) {
            return r == (obj->*fn)();
        } else if constexpr (tuple_size<decltype(input)>::value == 1) {
            return r == (obj->*fn)(get<0>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 2) {
            return r == (obj->*fn)(get<0>(input), get<1>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 3) {
            return r == (obj->*fn)(get<0>(input), get<1>(input), get<2>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 4) {
            return r == (obj->*fn)((get<0>(input), get<1>(input), get<2>(input),
                                    get<3>(input)));
        } else {
            cout << "too many" << endl;
            return false;
        }
    }

    template <typename Fn>
    bool checkResult(Fn&& fn) {
        if constexpr (tuple_size<decltype(input)>::value == 0) {
            return r == fn();
        } else if constexpr (tuple_size<decltype(input)>::value == 1) {
            return r == fn(get<0>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 2) {
            return r == fn(get<0>(input), get<1>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 3) {
            return r == fn(get<0>(input), get<1>(input), get<2>(input));
        } else if constexpr (tuple_size<decltype(input)>::value == 4) {
            return r == fn((get<0>(input), get<1>(input), get<2>(input),
                            get<3>(input)));
        } else {
            cout << "too many" << endl;
            return false;
        }
    }

    template <size_t...>
    struct index_sequence {};
    template <size_t N, size_t... S>
    struct make_index_sequence_helper
        : make_index_sequence_helper<N - 1, N - 1, S...> {};
    template <size_t... S>
    struct make_index_sequence_helper<0, S...> {
        typedef index_sequence<S...> type;
    };
    template <size_t N>
    using make_index_sequence = typename make_index_sequence_helper<N>::type;

    template <typename Obj, typename F, size_t... i, typename T>
    bool checkResultCommonHelperObject(Obj obj, F f, index_sequence<i...>,
                                       T&& t) {
        return r == (obj.*f)(get<i>(t)...);
    }

    template <typename Obj, typename F, typename... T>
    bool _checkResultCommonObject(Obj obj, F f, const std::tuple<T...>& t) {
        return checkResultCommonHelperObject(
            obj, f, make_index_sequence<sizeof...(T)>(), t);
    }

    template <typename Obj, typename F>
    bool checkResultCommonObject(Obj obj, F f) {
        return _checkResultCommonObject(obj, f, input);
    }

    template <typename Obj, typename F>
    bool checkResultCommonObject2(Obj obj, F f) {
        return r == apply(obj, f, input);
    }

    template <typename F, size_t... i, typename T>
    bool checkResultCommonHelper(F f, index_sequence<i...>, T&& t) {
        return r == f(get<i>(t)...);
    }

    template <typename F, typename... T>
    bool _checkResultCommon(F f, const std::tuple<T...>& t) {
        return checkResultCommonHelper(f, make_index_sequence<sizeof...(T)>(),
                                       t);
    }

    template <typename F>
    bool checkResultCommon(F&& f) {
        return _checkResultCommon(f, input);
    }

    template <typename F>
    bool checkResultCommon2(F&& f) {
        return r == apply(f, input);
    }
};

#endif  // DEBUG

template <typename Result, typename... Input>
struct tester2 {
    Result r;
    tuple<decay_t<Input>...> input;
    tester2(Result r, Input... input) : r(r), input(input...) {}

    template <typename Obj, typename F>
    bool checkResultCommonObject(Obj obj, F f) {
        return r == apply(obj, f, input);
    }

    template <typename F>
    bool checkResultCommon(F&& f) {
        return r == apply(f, input);
    }
};

struct inputReader {
    constexpr static int LINEMAX = 1024;
    string fileName;
    vector<string> _data;
    ifstream in;

    inputReader(const string& fileName = "data") : fileName(fileName) {
        in.open(fileName, ios_base::in);
        if (!in.is_open()) {
            cout << "Error opening file";
            exit(1);
        }
    }

    ~inputReader() { in.close(); }
};

template <typename T>
inputReader& operator>>(inputReader& inReader, T& t) {
    inReader.in >> t;
    return inReader;
}

constexpr static char* NUMBERSTART = "[number]";
constexpr static char* INSTART = "[in]";
constexpr static char* OUTSTART = "[out]";

// 输入函数
// template<typename T>
void input(inputReader& in) {
    string number_start;
    while (!in.in.eof()) {
        in >> number_start;
        if (number_start == string(NUMBERSTART)) {
            break;
        }
    }
    // 
    //return move(temp);
}

void solve(vector<vector<int>>& num) {}

void solve() {
    inputReader inReader;
    while (!inReader.in.eof()) {
        //auto vec = input(inReader);
        //solve(vec);
    }
}

int main() {
    int (Solution::*pf)(string s, int a) = &Solution::reslove;  //修改函数名
    Solution s;
    // vector<tester<int, int, int> > ve = {
    //     {3, 1, 2},
    //     {4, 2, 2},
    //     {5, 3, 2},
    //     {6, 4, 2},
    // };
    // for (int i = 0; i < ve.size(); ++i) {
    //     int v = ve[i].checkResultCommon(add);
    //     if (!v) {
    //         cout << i << " " << v << endl;
    //     }
    // }
}
