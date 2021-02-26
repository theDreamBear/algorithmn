/**
 *
 *   带有对对空间清理的 trie数实现
 *
 *
 *
 *
*/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Tries {
private:
    struct TriesNode {
        TriesNode() : isEnd(false) {}
        unordered_map<char, TriesNode *> children;
        bool isEnd;
    };

    TriesNode *root;
    vector<TriesNode*> nodes;

    bool _startWith(const string &str, TriesNode **leaf) const{
        TriesNode *node = root;
        for (auto c : str) {
            if (node->children.count(c) == 0) {
                leaf = NULL;
                return false;
            }
            node = node->children[c];
        }
        *leaf = node;
        return true;
    }

public:
    Tries() {
        root = new TriesNode();
        nodes.push_back(root);
    }

    void insert(const string &str) {
        TriesNode *node = root;
        for (auto c : str) {
            if (node->children.count(c) == 0) {
                node->children[c] = new TriesNode;
                nodes.push_back(node->children[c]);
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool startWith(const string &str) const{
        TriesNode *leaf = NULL;
        return _startWith(str, &leaf);
    }

    bool search(const string &str) const{
        TriesNode *leaf = NULL;
        if (!_startWith(str, &leaf) || leaf == NULL) {
            return false;
        }
        return leaf->isEnd;
    }

    /*
     *  申请空间清理
     * */
    void freeTries() {
        for (auto& node : nodes) {
            delete node;
            node = NULL;
        }
    }

    ~Tries() {
        if (root == NULL) {
            return;
        }
        freeTries();
    }
};


int main() {
    Tries tr;
    tr.insert("hello");
    cout << tr.startWith("he");
    tr.freeTries();
    return 0;
}
