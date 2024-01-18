/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    double EuclideanDistance(const vector<int> &left, const vector<int> &right) const {
        int w = left[0] - right[0];
        int h = left[1] - right[1];
        return sqrt(w * w + h * h);
    }

    // o(n^3)
    // 暴力
    int numberOfBoomerangs_violate(vector<vector<int>> &points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (j == i) {
                    continue;
                }
                double x = EuclideanDistance(points[i], points[j]);
                for (int k = 0; k < points.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    double y = EuclideanDistance(points[i], points[k]);
                    if (abs(x - y) < numeric_limits<double>::epsilon()) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }

    int cal(int n) {
        return (n * (n - 1));
    }

    int numberOfBoomerangs(vector<vector<int>> &points) {
        if (points.size() == 1) {
            return 0;
        }
        int ans = 0;
        vector<vector<double>> distance(points.size());
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < i; j++) {
                double x = EuclideanDistance(points[i], points[j]);
                distance[i].push_back(x);
                distance[j].push_back(x);
            }
        }
        for (int i = 0; i < points.size(); i++) {
            sort(distance[i].begin(), distance[i].end());
            auto& vec = distance[i];
            int ct = 1;
            double v = vec[0];
            for (int j = 1; j < vec.size(); j++) {
                double x = abs(vec[j] - v);
                if (x >= numeric_limits<double>::epsilon()) {
                    ans += cal(ct);
                    ct = 1;
                     v = vec[j];
                } else {
                    ct++;
                }
            }
            ans += cal(ct);
        }
        return ans;
    }
};
// @lc code=end

