#include <iostream>
#include <vector>

using namespace std;

// 一般并查集
class UnionFind {
private:
	void init() {
		for (int i = 0; i < parents.size(); ++i) {
			parents[i] = i;
		}
	}

	void setParent(int val, int pval) {
		parents[val] = pval;
	}

	vector<int> parents;

 public:
	UnionFind(int n):parents(n) {
		init();
	}

	/* 这个递归解读
		find(val) 返回 val 的最顶层祖宗节点
		find(val) 一定等于 find(parents[val]);

	*/
	int find(int val) {
		// 递归终止条件
		if (val == parents[val]) {
			return val;
		}

		int p = find(parents[val]);
		setParent(val, p);
		return p;
	}

	/*
	 	最简单的合并
	 */
	void merge(int left, int right) {
		int pl = find(left);
		int pr = find(right);
        if (pl == pr) {
            return;
        }
		setParent(pl, pr);
	}

	void print() {
		for (int i = 0; i < parents.size(); ++i) {
			cout << i << "\t" << parents[i] << endl;
		}
	}
};

// 带权并查集
class UnionFind2{
private:
	void init() {
		for (int i = 0; i < parents.size(); ++i) {
			parents[i] = i;
            rank[i] = 0;
		}
	}

	void setParent(int val, int pval) {
		parents[val] = pval;
	}

    // void setWeight(int val) {
    //     weight[val] = 1;
    // }

	vector<int> parents;
    vector<int> rank;

 public:
	UnionFind2(int n):parents(n) {
		init();
	}

	/* 这个递归解读
		find(val) 返回 val 的最顶层祖宗节点
		find(val) 一定等于 find(parents[val]);

	*/
	int find(int val) {
		// 递归终止条件
		if (val == parents[val]) {
			return val;
		}

		int p = find(parents[val]);
		setParent(val, p);

		return p;
	}

	/*
	 	最简单的合并
	 */
	void merge(int left, int right) {
		int pl = find(left);
		int pr = find(right);
        if (pl == pr) {
            return;
        }
		if (rank[pl] > rank[pr]) {
            setParent(pr, pl);
        } else {
            setParent(pl, pr);
            if (rank[pl] == rank[pr]) {
                ++rank[pr];
            }
        }
	}

	void print() {
		for (int i = 0; i < parents.size(); ++i) {
			cout << i << "\t" << parents[i] << endl;
		}
	}
};


int main() {
	UnionFind uf(10);
	//uf.print();
	uf.merge(0, 2);
	uf.merge(2, 3);
	uf.find(0);
	uf.print();
	return 0;
}

