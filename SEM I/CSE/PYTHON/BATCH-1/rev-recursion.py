def f(n):
    if n == 1:
        return 1
    else:
        print(n)
        f(n-1)
        #print(n-1)

f(5)