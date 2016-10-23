# -*- coding: utf_8 -*-

def lcs(x, y, dp):
    for i in range(len(x) - 1):
        for j in range(len(y) - 1):
            if x[i] == y[j]:
                print(dp)
                dp[i + 1][j + 1] = dp[i][j] + 1
            else:
                dp[i][j + 1] = dp[i][j]

if __name__ == "__main__":
    q = int(input())
    for i in range(0, q * 2):
        x = list(input())
        y = list(input())
        dp = [[0 for i in range(len(x) + 1)] for j in range(len(y) + 1)]
        lcs(x, y, dp)
        print(dp)
        # print(dp[len(x)][len(y)])

