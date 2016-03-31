n = int(raw_input())
R_list = [int(raw_input()) for _ in range(n)]

min_R = int(1e10)
ans = -int(1e10)
for R in R_list:
    ans = max(ans, R - min_R)
    min_R = min(min_R, R)

print ans
