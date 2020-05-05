s=input()
a = {}
for i in range(len(s)):
    if s[i] not in a:
        a[s[i]] =1
    else:
        a[s[i]] = -1

for i in range(len(a)):
    if a[s[i]] == 1:
        return i
return -1
