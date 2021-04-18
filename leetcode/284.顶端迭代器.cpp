/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Iterator {
    struct Data;
    Data* data;

 public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

/*
	这个思路有些意思
*/
class PeekingIterator : public Iterator {
 private:
	int next_val;
	bool flag;
 public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
		if (Iterator::hasNext()) {
			next_val = Iterator::next();
			flag = true;
		} else {
			flag = false;
		}
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
		return next_val;
	}

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
		int temp = next_val;
		if (Iterator::hasNext()) {
			next_val = Iterator::next();
		} else {
			flag = false;
		}
		return temp;
	}

    bool hasNext() const {
		return flag;
	}
};
// @lc code=end
