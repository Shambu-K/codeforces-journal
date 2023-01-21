t = int(input())
while(t > 0):
    t -= 1
    n = int(input())
    ans = 0
    for i in range(1, n-1):
        ans+= (i*i+i*(i+1))
    ans += (n*n)
    ans *= 2022
    print(ans)