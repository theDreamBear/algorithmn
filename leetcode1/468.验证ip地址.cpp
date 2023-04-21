/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {
public:
    enum TYPE{
        IPv4,
        IPv6,
        Neither,
    };

    TYPE checkType(const string &s) {
        int docCnt = 0;
        int mhCnt = 0;

        for (auto ch: s) {
            if (isdigit(ch)) {
                continue;
            }
            if ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')) {
                continue;
            }
            if (ch == '.' || ch == ':') {
                if (ch == '.') {
                    docCnt++;
                } else {
                    mhCnt++;
                }
                continue;
            }
            return Neither;
        }
        if (docCnt * mhCnt) {
            return Neither;
        }
        if (docCnt == 3) {
            return IPv4;
        }
        if (mhCnt == 7) {
            return IPv6;
        }
        return Neither;
    }

    vector<string> split(const string& s, const char* delim) {
        vector<string> ans;
        string temp = s;
        const char* token = strtok((char*)temp.c_str(), delim);
        while (token) {
            ans.push_back(token);
            token = strtok(NULL, delim);
        }
        return ans;
    }

    vector<string> split2(const string& s, char ch) {
        vector<string> ans;
        stringstream ss(s);
        string temp;
        while(getline(ss, temp, ch)) {
            ans.push_back(temp);
        }
        return ans;
    }

    bool isIPv6(const string& s) {
        auto data = split(s, ":");
        if (data.size() != 8) {
            return false;
        }
        for (auto temp : data) {
            if (temp.size() > 4 || temp.empty()) {
                return false;
            }
        }
        return true;
    }

    bool isIPv4(const string &s) {
        auto data = split(s, ".");
        if (data.size() != 4) {
            return false;
        }
        for (auto temp : data) {
            if (temp.size() > 1 && temp[0] == '0') {
                return false;
            }
            if (temp.size() > 3 || temp.empty()) {
                return false;
            }
            int val = atoi(temp.c_str());
            if (val < 0 || val > 255) {
                return false;
            }
            if (to_string(val) != temp) {
                return false;
            }
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        auto type = checkType(queryIP);
        if (type == Neither) {
            return "Neither";
        }
        auto valid = false;
        if (type == IPv4) {
            valid = isIPv4(queryIP);
            if (valid) {
                return "IPv4";
            }
        } else {
            valid = isIPv6(queryIP);
            if (valid) {
                return "IPv6";
            }
        }
        return "Neither";
    }
};
// @lc code=end

