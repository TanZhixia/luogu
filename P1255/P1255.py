import sys
sys.setrecursionlimit(10000000)
dp = [-1] * 5005
def dfs(x):
    if dp[x] != -1:
        return dp[x]
    if x <= 1:
        return 1
    dp[x] = dfs(x - 2) + dfs(x - 1)
    return dp[x]
n = int(input())
print(dfs(n))