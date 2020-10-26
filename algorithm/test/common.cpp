#include <fstream>
#include <iostream>
#include <tuple>
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
    tuple<Input...> input;
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

    template <typename T>
    vector<T> getVec(int n) {
        vector<T> res(n);
        for (int i = 0; i < n; ++i) {
            in >> res[i];
        }
        return res;
    }

    vector<int> getVec(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            in >> res[i];
        }
        return res;
    }

    template <typename T>
    vector<vector<T>> getVec(int n, int m) {
        vector<vector<T>> res(n, vector<T>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> res[i][j];
            }
        }
        return res;
    }

    vector<vector<int>> getVec(int n, int m) {
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> res[i][j];
            }
        }
        return res;
    }
};

template <typename T>
inputReader& operator>>(inputReader& inReader, T& t) {
    inReader.in >> t;
    return inReader;
}

using InputType =  vector<vector<int>>;
using ResultType = int;
using Item = tester2<ResultType, InputType>;

// 输入函数
// template<typename T>
void solve(inputReader& in) {
    vector<Item> total_test;
    while (!in.in.eof()) {
        // 输入
        int m;
        in >> m;
        auto nums = move(in.getVec(m));
        // 预期
        int res;
        in >> res;

        // 存储
        total_test.emplace_back(res, nums);
    }
    for (int i = 0; i < total_test.size(); ++i) {
        if (total_test[i].r != total_test[i].checkResultCommon(add)) {
            cout << i  << "error" << endl;
        }
    }
}

void solve(vector<vector<int>>& num) {}

void solve() {
    inputReader inReader;
    solve(inReader);
}

int main() {
    solve();
}
