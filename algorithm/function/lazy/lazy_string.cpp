#include <mydef.h>

template<typename ... Strings>
class lazy_string_concat_helper;


template<typename LastString, typename ...Strings>
class lazy_string_concat_helper<LastString, Strings...> {
    private:
        LastString data;
        lazy_string_concat_helper<Strings...> tail;
    public:
        lazy_string_concat_helper(LastString data, lazy_string_concat_helper<Strings...> tail):data(data), tail(tail) {}

        int size() const {
            return data.size() + tail.size();
        }

        template<typename It>
        void save(It end) const {
            const auto begin = end - data.size();
            copy(data.cbegin(), data.cend(), begin);
            tail.save(begin);
        }

        operator::string() const {
            string result(size(), '\0');
            save(result.end());
            return result;
        }

        lazy_string_concat_helper<string, LastString, Strings...> operator+(const string& other) const {
            return lazy_string_concat_helper<string, LastString, Strings...>(other, *this);
        }
};

template<>
class lazy_string_concat_helper<> {
    public:lazy_string_concat_helper() =default;

    int size() const {
        return 0;
    }

    template<typename It>
    void save(It) const {}

    lazy_string_concat_helper<string> operator + (const string& other) const {
        return lazy_string_concat_helper<string>(other, *this);
    }
};

int main() {
    string name = "hello";
    lazy_string_concat_helper<> lazy_concat;
    const string fullname = lazy_concat + name + ", " + "hello";
    cout << fullname << endl;
}