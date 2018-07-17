import sys

sys.setrecursionlimit(10000000)


def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


def dfs(G, i, V, L):
    L[i] = 1
    V.append(i)
    for j in G[i]:
        L[i] += dfs(G, j, V, L)
    return L[i]


def solve_test_case():
    n, q = array()
    P = array()

    G = [[] for _ in range(n)]
    for i, p in enumerate(P):
        G[p - 1].append(i + 1)
    for i in range(n):
        G[i].sort()
    # print G

    L = [0] * n
    V = []

    dfs(G, 0, V, L)
    # print V
    # print L
    mp = {}

    for i, v in enumerate(V):
        mp[v] = i

    # print mp

    for qi in range(q):
        u, k = array()
        i = mp[u - 1]
        if L[u - 1] >= k:
            print V[i + k - 1] + 1
        else:
            print -1


n_test_cases = 1

if n_test_cases == 0:
    n_test_cases = get()

for i_test_case in range(n_test_cases):
    solve_test_case()

