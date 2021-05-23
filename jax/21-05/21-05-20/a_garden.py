def getInts():
    return map(int, input().split())

n, k = getInts()

a = getInts()

div = 1
for num in a:
    if n % k == 0:
        div = max(div, num)

print(int(n / div))