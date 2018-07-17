def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


def solve_test_case():
    n, k = array()
    A = array()
    B = sorted([(a, i) for i, a in enumerate(A)], reverse=True)
    C = [0] * n
    ans = 0
    for i in range(k):
        C[B[i][1]] = 1
        ans += B[i][0]
    M = [i for i in range(n) if C[i] == 1]
    # print C
    print ans
    if k == 1:
        print n
    else:
        print (M[0] + 1),
        for i in range(1, k - 1):
            print M[i] - M[i - 1],
        print n - M[k - 2] - 1


n_test_cases = 1

if n_test_cases == 0:
    n_test_cases = get()

for i_test_case in range(n_test_cases):
    solve_test_case()
