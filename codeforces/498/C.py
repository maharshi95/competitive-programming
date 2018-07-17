def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


def solve_test_case():
    n = get()
    A = array()
    C = [0] * (n + 1)
    for i in range(1, n + 1):
        C[i] = C[i - 1] + A[i - 1]

    ans = 0

    l = 1
    r = n

    while l < r:
        if C[l] == C[n] - C[r - 1]:
            ans = l
            l += 1
            r -= 1
        elif C[l] > C[n] - C[r - 1]:
            r -= 1
        else:
            l += 1

    print C[ans]


n_test_cases = 1

if n_test_cases == 0:
    n_test_cases = get()

for i_test_case in range(n_test_cases):
    solve_test_case()
