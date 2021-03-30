n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(input())
cnts = [0 for i in range(m)]
for i in range(n):
    for j in range(m):
        cnts[j] += 0 if grid[i][j] == '0' else 1
for i in range(n):
    flag = True
    for j in range(m):
        if grid[i][j] == '1' and cnts[j] == 1:
            flag = False
            break
    if flag:
        print('YES')
        exit(0)
print('NO')
