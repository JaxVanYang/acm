n, m = map(int, input().split())

mp = {}
for i in range(n):
    s = input()
    if s in mp:
        mp[s] += 1
    else:
        mp[s] = 1

li = []
for key in mp:
    li.append((mp[key], key))

def cmp(a):
    ret = []
    ret.append(-a[0])
    back = list(map(int, a[1].split()))
    for item in back:
        ret.append(item)
    # print(ret)
    return ret

li.sort(key=cmp)

print(len(li))
for each in li:
    print(f'{each[0]} {each[1]}')