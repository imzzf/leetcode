#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row    = matrix.size();
        int column = matrix[0].size();
        int maxl   = 0;
        // dp[i][j]代表了以(i,j)点为右下角的正方形的最大边长
        vector<vector<int>> dp(row, vector<int>(column));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // dp初始化，在矩阵的边界上出现1，最大边长为1
                        dp[i][j] = 1;
                    } else {
                        // 转移方程的证明在1277的题解
                        // dp[i][j]只与其相邻三点有关，当且仅当三个点的值为1时才能将左上角的正方形扩展1个长度
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxl = max(maxl, dp[i][j]);
                }
            }
        }
        return maxl * maxl;
    }
};

int main() {
    return 0;
}