/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

// @lc code=start
class Solution {
private:
    double x_c, y_c, r;
    uniform_real_distribution<double> u;
    mt19937 de;
public:
    Solution(double radius, double x_center, double y_center):r(radius), x_c(x_center), y_c(y_center), u(-r, r), de(random_device{}()) {
       
    }

    vector<double> randPoint() {
        double x = u(de);
        double y = u(de);
        while (x * x + y * y > r * r) {
            x = u(de);
            y = u(de);
        }
        return {x + x_c, y + y_c};

//        uniform_real_distribution<double> u(0, 360);
//        default_random_engine de(time(NULL));
//        double jd = u(de) / (2 * M_PI);
//        return {r * cos(jd) + x_c, r * sin(jd) + y_c};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

