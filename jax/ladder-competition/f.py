n, m = map(int, input().split())
li = []

def valid(s: str):
    if s.find('easy') != -1 or s.find('qiandao') != -1:
        return True
    return False

for i in range(n):
    s = input()
    if not valid(s):
        if m == 0:
            li.append(s)
        m -= 1

if len(li) == 0:
    print('Wo AK le')
else:
    print(li[0])
