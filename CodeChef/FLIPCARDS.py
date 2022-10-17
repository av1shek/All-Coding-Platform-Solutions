for _ in range(int(input())):
    N,X = map(int, input().split())
    if N>2*X:
        print(X)
    else:
        print(N-X)