/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution1 {
public:
    bool isValid(const string& s) {
        if (s.size() == 1) {
            return true;
        }
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        int val = atoi(s.c_str());
        if (val >=0 && val <= 255) {
            return true;
        }
        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        function<void(int, int, string)> backtrack = [&](int pos, int num, string cur) {
            if (num > 4) {
                return;
            }
            if (pos == s.size()) {
                if (num == 4) {
                    cur.pop_back();
                    ans.push_back(cur);
                }
                return;
            }
            for (int i = pos; i < s.size() && i - pos <= 2; i++) {
                string sub = s.substr(pos, i - pos + 1);
                if (isValid(sub)) {
                    backtrack(i + 1, num + 1, cur + sub + ".");
                }
            }
        };
        backtrack(0, 0,"");
        return ans;
    }
};

class Solution2 {
public:
    bool isValid(const string &s, int begin, int end) {
        if (begin < 0 && end >= s.size() || end - begin > 2) {
            return false;
        }
        if (begin == end) {
            return true;
        }
        if (s[begin] == '0') {
            return false;
        }
        if (end - begin < 2 || (end - begin == 2 && s[begin] < '2')) {
            return true;
        }
        if (end - begin == 2 && s[begin] >= '3') {
            return false;
        }
        if (s[begin + 1] > '5') {
            return false;
        }
        if (s[begin + 1] == '5' && s[begin + 2] > '5') {
            return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        char buff[s.size() + 4];
        function<void(int, int, int)> backtrack = [&](int pos, int num, int tail) {
            if (num > 4) {
                return;
            }
            if (num == 4 || pos >= s.size()) {
                if (num == 4 && pos >= s.size()) {
                    buff[s.size() + 3] = '\0';
                    ans.push_back(buff);
                }
                return;
            }
            for (int i = pos; i < s.size() && i - pos <= 2; i++) {
                if (isValid(s, pos, i)) {
                    int len = i - pos + 1;
                    memcpy(buff + tail, s.c_str() + pos, len);
                    buff[tail + len] = '.';
                    backtrack(i + 1, num + 1, tail + len + 1);
                }
            }
        };
        backtrack(0, 0, 0);
        return ans;
    }
};


class Solution {
public:
    bool isValid(const string &s, int begin, int end) {
        if (begin < 0 && end >= s.size() || end - begin > 2) {
            return false;
        }
        if (begin == end) {
            return true;
        }
        if (s[begin] == '0') {
            return false;
        }
        if (end - begin < 2 || (end - begin == 2 && s[begin] < '2')) {
            return true;
        }
        if (end - begin == 2 && s[begin] >= '3') {
            return false;
        }
        if (s[begin + 1] > '5') {
            return false;
        }
        if (s[begin + 1] == '5' && s[begin + 2] > '5') {
            return false;
        }
        return true;
    }

    struct SmartBuffer {
        string s;
        int n;

        SmartBuffer(int n): n(n) {
            s.reserve(n);
        }

        void add(int tail, const char* str, int len) {
            memcpy((void *) (s.c_str() + tail), str, len);
            s[tail + len] = '.';
        }

        const char* data() {
            s[n - 1] = '\0';
            return s.c_str();
        }
    };

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        SmartBuffer buffer(s.size() + 4);
        function<void(int, int, int)> backtrack = [&](int pos, int num, int tail) {
            if (num > 4) {
                return;
            }
            if (num == 4 || pos >= s.size()) {
                if (num == 4 && pos >= s.size()) {
                    ans.push_back(buffer.data());
                }
                return;
            }
            for (int i = pos; i < s.size() && i - pos <= 2; i++) {
                if (isValid(s, pos, i)) {
                    int len = i - pos + 1;
                    buffer.add(tail, s.c_str() + pos, len);
                    backtrack(i + 1, num + 1, tail + len + 1);
                }
            }
        };
        backtrack(0, 0, 0);
        return ans;
    }
};

// @lc code=end

