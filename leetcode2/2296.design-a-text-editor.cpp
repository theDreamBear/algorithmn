/*
 * @lc app=leetcode.cn id=2296 lang=cpp
 * @lcpr version=30204
 *
 * [2296] 设计一个文本编辑器
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class TextEditor {
    string left, right; // 光标左侧、右侧字符

    string text() {
        // 光标左边至多 10 个字符
        return left.substr(max((int) left.size() - 10, 0));
    }

public:
    void addText(string text) {
        left += text; // 入栈
    }

    int deleteText(int k) {
        k = min(k, (int) left.length());
        left.resize(left.length() - k); // 出栈
        return k;
    }

    string cursorLeft(int k) {
        while (k && !left.empty()) {
            right += left.back(); // 左手倒右手
            left.pop_back();
            k--;
        }
        return text();
    }

    string cursorRight(int k) {
        while (k && !right.empty()) {
            left += right.back(); // 右手倒左手
            right.pop_back();
            k--;
        }
        return text();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end



/*
// @lcpr case=start
// ["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft","cursorRight"][[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]\n
// @lcpr case=end

 */

