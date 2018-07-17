def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


def solve_test_case():
    n = get()
    A = array()
    for a in A:
        print (a if a % 2 == 1 else a - 1),


n_test_cases = 1

if n_test_cases == 0:
    n_test_cases = get()

for i_test_case in range(n_test_cases):
    solve_test_case()
