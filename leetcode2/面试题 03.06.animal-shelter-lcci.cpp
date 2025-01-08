/*
 * @lc app=leetcode.cn id=面试题 03.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.06] 动物收容所
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
class AnimalShelf1 {
public:
    int timer = 0;
    queue<pair<int, int>> cats, dogs;
    AnimalShelf1() {
        
    }
    
    void enqueue(vector<int> animal) {
        int id = animal[0], type = animal[1];
        if (type == 0) cats.push({id, timer});
        else dogs.push({id, timer});
        timer++;
    }
    
    vector<int> dequeueAny() {
        if (!dogs.empty() and !cats.empty()) {
            if (cats.front().second < dogs.front().second) {
                vector<int> ans{cats.front().first, 0};
                cats.pop();
                return ans;
            } else {
                vector<int> ans{dogs.front().first, 1};
                dogs.pop();
                return ans;
            }
        } else if (!cats.empty()) {
            vector<int> ans{cats.front().first, 0};
            cats.pop();
            return ans;
        } else if (!dogs.empty()) {
            vector<int> ans{dogs.front().first, 1};
            dogs.pop();
            return ans;
        } else {
            return {-1, -1};
        }
    }

    vector<int> dequeueDog() {
        if (!dogs.empty()) {
            vector<int> ans{dogs.front().first, 1};
            dogs.pop();
            return ans;
        } 
        return {-1, -1};
    }
    
    vector<int> dequeueCat() {
        if (!cats.empty()) {
            vector<int> ans{cats.front().first, 0};
            cats.pop();
            return ans;
        } 
        return {-1, -1};
    }
};

class AnimalShelf {
public:
    int timer = 0;
    queue<vector<int>> pets[2];
#define cats pets[0]
#define dogs pets[1]

    AnimalShelf() {
        
    }
    
    void enqueue(vector<int> animal) {
        int id = animal[0], type = animal[1];
        pets[type].push({id, timer});
        timer++;
    }
    
    vector<int> dequeueAny() {
        if ((!cats.empty() and !dogs.empty() and cats.front()[1] < dogs.front()[1]) || (!cats.empty() and dogs.empty())) {
                return dequeueCat();
        } 
        return dequeueDog();
    }

    vector<int> dequeueDog() {
        if (!dogs.empty()) {
            auto res = dogs.front();
            dogs.pop();
            res[1] = 1;
            return res;
        } else {
            return {-1, -1};
        }
    }
    
    vector<int> dequeueCat() {
        if (!cats.empty()) {
            auto res = cats.front();
            cats.pop();
            res[1] = 0;
            return res;
        } else {
            return {-1, -1};
        }
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
// @lc code=end



/*
// @lcpr case=start
// ["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"][[], [[0, 0]], [[1, 0]], [], [], []]\n
// @lcpr case=end

// @lcpr case=start
// ["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"][[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]\n
// @lcpr case=end

 */

