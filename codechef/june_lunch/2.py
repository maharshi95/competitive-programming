import sys

sys.setrecursionlimit(200000)


def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


T = []


def apply(A, B):
    # print 'apply', A, B
    return [B[a] for a in A]


def inv(A):
    I = [0] * len(A)
    for i, a in enumerate(A):
        I[a] = i
    # test = apply(A, I)
    # for i, t in enumerate(test):
    #     assert i == t
    return I


def solve_test_case():
    n, m = array()
    P = [[]] * n

    for i in range(n):
        P[i] = array()
        P[i] = [p - 1 for p in P[i]]

    C = [None] * (n + 1)
    I = [None] * (n + 1)
    C[0] = range(m)
    I[0] = range(m)

    for i in range(1, n + 1):
        C[i] = apply(C[i - 1], P[i - 1])
        I[i] = inv(C[i])

        # print 'C[{}]: {}'.format(i, C[i])
        # print 'I[{}]: {}'.format(i, I[i])
        # print('')

    q = get()

    for qi in range(q):
        l, r = array()
        B = apply(C[r], I[l - 1])
        # print qi, ':'
        # print C[r], I[l - 1]
        ans = 0
        for i, b in enumerate(B):
            ans += (i + 1) * (b + 1)
        print(ans)
        # print 'B: {}'.format(qi, B), ans
        # print(ans)


n_test_cases = 0

if n_test_cases == 0:
    n_test_cases = get()

for i_test_case in range(n_test_cases):
    solve_test_case()

"""

1 1 1 2 2 2 3 3 3 4 4 4

[ _ _ _ _ ]
  1 1 1 2
  1 1 2 2
  1 2 2 2
  2 2 2 3
  

"""
