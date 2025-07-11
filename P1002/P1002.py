dp = []
for i in range(25):
    dp.append([0] * 25)
dx = [-2, -2, -1, -1, 1, 1, 2, 2, 0]
dy = [1, -1, 2, -2, 2, -2, 1, -1, 0]
a, b, n, m = input().split()
a, b, n, m = int(a), int(b), int(n), int(m)
dp[0][0] = 1
for i in range(9):
    newX = n + dx[i]
    newY = m + dy[i]
    if newX >= 0 and newX <= a and newY >= 0 and newY <= b:
        dp[newX][newY] = -1
for i in range(a + 1):
    for j in range(b + 1):
        if dp[i][j] == -1:
            dp[i][j] = 0
            continue
        if i - 1 >= 0:
            dp[i][j] += dp[i - 1][j]
        if j - 1 >= 0:
            dp[i][j] += dp[i][j - 1]
print(dp[a][b])