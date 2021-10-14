t = int(input())

def solve():
    n = int(input())

    for i in range(1, n + 1):
        print("(" * i + ")" * i + "()" * (n - i))

for _ in range(t):
    solve()
