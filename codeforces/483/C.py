import os

def read_list():
    return [int(num) for num in input().split()]

def gcd(a, b):
    if b == 0: return a
    return b if a % b == 0 else gcd(b, a % b)

n = int(input())

for _ in range(n):
    p, q, b = read_list()

    g = gcd(p, q)

    q /= g

    while q > 1 and b > 1:
        b = gcd(b, q)
        q /= b

    print("Finite" if p == 0 or q == 1 else "Infinite")
