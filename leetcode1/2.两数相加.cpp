/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
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
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    class AddListNodeAbs {
       private:
        void appendOneNode(ListNode*& tail, int val, int& carryBit) {
            carryBit = val / 10;
            val %= 10;
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        virtual bool isDone() = 0;
        virtual int getVal() = 0;
        virtual void next() = 0;

       public:
        void append(ListNode*& tail, int& carryBit) {
            while (!isDone()) {
                int val = getVal() + carryBit;
                appendOneNode(tail, val, carryBit);
                next();
            }
        }
    };

    class AddListNodeOne : public AddListNodeAbs {
       private:
        ListNode*& node;
        virtual bool isDone() { return nullptr == node; }
        virtual int getVal() { return node->val; }
        virtual void next() { node = node->next; }

       public:
        AddListNodeOne(ListNode*& node) : node(node) {}
    };

    class AddListNodeTwo : public AddListNodeAbs {
       private:
        ListNode *&l1, *&l2;
        virtual bool isDone() { return nullptr == l1 || nullptr == l2; }
        virtual int getVal() { return l1->val + l2->val; }
        virtual void next() {
            l1 = l1->next;
            l2 = l2->next;
        }

       public:
        AddListNodeTwo(ListNode*& l1, ListNode*& l2) : l1(l1), l2(l2) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carryBit = 0;

        unique_ptr<AddListNodeAbs> abs;

        abs = make_unique<AddListNodeTwo>(l1, l2);
        abs->append(tail, carryBit);

        abs = make_unique<AddListNodeOne>(l1);
        abs->append(tail, carryBit);

        abs = make_unique<AddListNodeOne>(l2);
        abs->append(tail, carryBit);

        // 特殊处理最后的进位
        if (carryBit) {
            tail->next = new ListNode(carryBit);
            tail = tail->next;
        }
        return dummy.next;
    }

    void appendLeftNode(ListNode*& tail, ListNode* left, int& carryBit) {
        while (left) {
            int val = left->val + carryBit;

            carryBit = val / 10;
            val %= 10;
            tail->next = new ListNode(val);
            tail = tail->next;

            left = left->next;
        }
    }

    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carryBit = 0;
        while (l1 && l2) {
            int val = l1->val + l2->val + carryBit;

            carryBit = val / 10;
            val %= 10;
            tail->next = new ListNode(val);
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        appendLeftNode(tail, l1, carryBit);
        appendLeftNode(tail, l2, carryBit);
        if (carryBit) {
            tail->next = new ListNode(carryBit);
            tail = tail->next;
        }
        return dummy.next;
    }
};
// @lc code=end
