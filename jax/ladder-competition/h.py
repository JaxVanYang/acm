a, b, n = map(int, input().split())
li = [a, b]
i = 0
while len(li) < n:
    num = li[i] * li[i + 1]
    s = str(num)
    i += 1
    for ch in s:
        li.append(int(ch))

if n > 0:
    print(li[0], end='')
for i in range(1, n):
    print(f' {li[i]}', end='')