# DP
## problem
- https://www.acwing.com/problem/content/273/
## solution
- dp[i][j][k][l][m] 表示轮廓为第一排最多i个，第二排最多j个，第三排最多k个，第四排最多l个，第五排最多m个的方案数
$$ 
dp[i][j][k][l][m] = dp[i-1][j][k][l][m] +
                    dp[i][j-1][k][l][m] +
                    dp[i][j][k-1][l][m] +
                    dp[i][j][k][l-1][m] +
                    dp[i][j][k][l][m-1]
$$
- 限制是i >= j >= k >= l >= m >= 0
