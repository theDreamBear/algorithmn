/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
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
// @lc code=start
class Solution {
 public:
    struct Node {
        vector<Node*> children;
        int numOfNode;
        bool end;

        Node() : children(26) { 
            end = false; 
            numOfNode = 0;
        }

        ~Node() {
            for (auto& ptr : children) {
                if (ptr) {
                    delete ptr;
                    ptr = NULL;
                }
            }
        }
    };

    struct Tries {
        Node* root;
        Tries() { root = new Node; }

        void insert(string str) {
            Node* th = root;
            for (auto c : str) {
                if (th->children[c - 'a'] == NULL) {
                    th->numOfNode++;
                    th->children[c - 'a'] = new Node;
                }
                th = th->children[c - 'a'];
            }
            th->end = true;
        }

        bool search(string str) {
            Node* th = root;
            for (auto c : str) {
                if (th->children[c - 'a'] == NULL) {
                    return false;
                }
                th = th->children[c - 'a'];
            }
            return th->end;
        }

        Node* search(Node* node, char c) {
            if (node->children[c - 'a'] == NULL || node->numOfNode == 0) {
                return NULL;
            }
            return node->children[c - 'a'];
        }

        void traversal(Node* node, vector<Node*>& vec) {
            if (node == NULL) {
                return;
            }
            vec.push_back(node);
            for (auto& child : node->children) {
                if (!child) {
                    traversal(child, vec);
                }
            }
        }

        ~Tries() {
            delete root;
        }
    };

    Tries trie;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void backTrack1(set<string>& ans, Node* node, string temp, const vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) { 
        if (node == NULL) {
            return;
        }
        Node* newNode = trie.search(node, board[i][j]);
        if (newNode == NULL) {
            return;
        }
        temp.push_back(board[i][j]);
        // 添加完立刻判断
        if (newNode->end) {
            ans.insert(temp);
            // 可能有单词共享前缀，不能return
        }
        visited[i][j] = true;

        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[nx].size() || visited[nx][ny]) {
                continue;
            }
            backTrack1(ans, newNode, temp, board, visited, nx, ny);
        }
        visited[i][j] = false;
        temp.pop_back();
    }

    vector<string> findWords1(vector<vector<char>>& board, vector<string>& words) {
        for (string& str : words) {
            trie.insert(str);
        }
        set<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                backTrack1(ans, trie.root, "", board, visited, i, j);
            }
        }
        return {ans.begin(), ans.end()};
    }

    void backTrack(vector<string>& ans, Node* node, string temp, vector<vector<char>>& board, int i, int j) { 
        if (node == NULL) {
            return;
        }
        Node* newNode = trie.search(node, board[i][j]);
        if (newNode == NULL) {
            return;
        }
        temp.push_back(board[i][j]);
        // 添加完立刻判断
        if (newNode->end) {
            ans.emplace_back(temp);
            newNode->end = false;
            // 可能有单词共享前缀，不能return
        }
        //   直接修改当前board;
        board[i][j] -= 26;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[nx].size() || board[nx][ny] < 'a') {
                continue;
            }
            backTrack(ans, newNode, temp, board, nx, ny);
        }
        board[i][j] += 26;
        temp.pop_back();
        //   若子节点为叶节点, 表示该路径已经便利完毕，可以删除
        if (newNode->numOfNode == 0) {
            --node->numOfNode;
            delete newNode;
            node->children[board[i][j] - 'a'] = NULL;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& str : words) {
            trie.insert(str);
        }
        vector<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                backTrack(ans, trie.root, "", board, i, j);
            }
        }
        return ans;
    }
};
// @lc code=end
