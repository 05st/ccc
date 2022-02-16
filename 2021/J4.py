init=input()

Ls=0
Ms=0
Ss=0

R={}

for c in init:
    if c=='L':
        Ls+=1
    if c=='M':
        Ms+=1
    if c=='S':
        Ss+=1

for c in "LMS":
    R[c] = {}
    for c2 in "LMS":
        R[c][c2] = 0

for i in range(len(init)):
    if 0 <= i and i < Ls:
        R['L'][init[i]]+=1
    elif Ls <= i and i < Ms+Ls:
        R['M'][init[i]]+=1
    elif Ms+Ls <= i and i < Ss+Ms+Ls:
        R['S'][init[i]]+=1

ans=0

for c in "LMS":
    for c2 in "LMS":
        if c == c2:
            continue
        temp=min(R[c][c2], R[c2][c])
        R[c][c2]-=temp
        R[c2][c]-=temp
        ans+=temp

for c in "LMS":
    for c2 in "LMS":
        if c == c2:
            continue
        if (R[c][c2] > 0):
            for c3 in "LMS":
                if c3 == c or c3 == c2:
                    continue
                temp=R[c3][c]
                R[c][c2]-=temp
                R[c][c]+=temp
                R[c3][c]=0
                R[c3][c3]+=temp
                R[c2][c2]+=temp
                R[c2][c3]-=temp
                ans+=temp*2

print(ans)