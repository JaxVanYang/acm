s = input()
if len(s) == 6:
    print(f'{s[0:4]}-{s[4:6]}')
else:
    year = int(s[0:2])
    if year < 22:
        pre = str(year)
        if len(pre) == 1:
            pre = '0' + pre
        print(f'20{pre}-{s[2:4]}')
    else:
        print(f'19{s[0:2]}-{s[2:4]}')
