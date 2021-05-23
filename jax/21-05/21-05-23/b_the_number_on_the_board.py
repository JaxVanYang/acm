k = int(input())

a = tuple(map(int, tuple(input())))

sum = 0
for num in a:
    sum += num

if sum >= k:
    print(0)
else:
    b = sorted(a)
    ans = 0
    for num in b:
        sum += 9 - num
        ans += 1
        if sum >= k:
            print(ans)
            exit(0)