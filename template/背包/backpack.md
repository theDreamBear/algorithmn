# 背包问题

## 01 背包


### lintcode 92 · 背包问题
> 描述:
在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]


​




#### 分析
每一个值可以取或者不取,故暴力解法复杂度为 2^n, 故会得到 2^n中状态
待选值域为 {可以取得的重量的合集}, 2^n 中状态会有重复求到值域的状态, 故暴力 + 备忘录 足以

#### 暴力解法
状态 (i, w)  前 i 个时 ,取到的重量为 w

#### 暴力 + 备忘录
dp[i][w] 记录已经取到的状态
#### 方法一

#### 方法二
```c++
// 用位图进行状态压缩
constexpr int MAX_N = 102400;
class Solution {
public:
    int backPack(int m, vector<int> &A) {
        bitset<MAX_N> bs;
        bs[0] = true;
        for (int i = 0; i < A.size(); i++) {
            bs = bs | bs << A[i];
        }
        for (int i = m; i >= 0; i--) {
            if (bs[i]) {
                return i;
            }
        }
        return 0;
    }
};

```