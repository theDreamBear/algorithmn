/*
 * @lc app=leetcode.cn id=2353 lang=cpp
 * @lcpr version=30204
 *
 * [2353] 设计食物评分系统
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
#include <map>
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class FoodRatings {
public:
    // food
    struct Node {
        int rate;
        string name;
        string type;
        Node (int rate = 0, string name = "", string type = ""):rate(rate),name(name),type(type){}

        bool operator<(const Node& other) const{
            return rate < other.rate or (rate == other.rate and name > other.name);
        }
    };
    map<string, Node> hs;
    map<string, set<Node>> ff;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            auto name = foods[i], type = cuisines[i];
            int rata = ratings[i];
            Node node(rata, name, type);
            hs[name] = node;
            ff[type].insert(node);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto node = hs[food];
        hs[food].rate = newRating;
        ff[node.type].erase(node);
        node.rate = newRating;
        ff[node.type].insert(node);
    }
    
    string highestRated(string cuisine) {
        auto& xx = ff[cuisine];
        return prev(xx.end())->name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end



