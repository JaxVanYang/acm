import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def getInts():
    return map(int, input().split())

n, q, c = getInts()

sky = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(11)]

sum = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(11)]

for _ in range(n):
    x, y, s = getInts()
    sky[s][x][y] += 1


def calc(id: int):
    for i in range(1, 101):
        for j in range(1, 101):
            # 带眼睛写
            sum[id][i][j] = sum[id][i - 1][j] + sum[id][i][j - 1] + sky[id][i][j] - sum[id][i - 1][j - 1]

for i in range(c + 1):
    calc(i)

for _ in range(q):
    t, x1, y1, x2, y2 = getInts()
    ans = 0
    for id in range(c + 1):
        val = (id + t) % (c + 1)
        cnt = sum[id][x2][y2] - sum[id][x1 - 1][y2] - sum[id][x2][y1 - 1] + sum[id][x1 - 1][y1 - 1]
        ans += val * cnt
    print(ans)