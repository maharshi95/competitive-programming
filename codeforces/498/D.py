def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


def solve_test_case():
    n = get()
    A = list(raw_input())
    B = list(raw_input())

    # print A, B

    total_cost = 0
    for i in range(n // 2):
        j = n - i - 1
        # print i, j, n

        a = sorted([A[i], A[j]])
        b = sorted([B[i], B[j]])
        intersection = {A[i], A[j]}.intersection({B[i], B[j]})

        # print(intersection)

        if a == b or (A[i] == A[j] and B[i] == B[j]):
            cost = 0
        elif len(intersection) == 1:
            cost = 1
        else:
            if B[i] == B[j]:
                cost = 1
            else:
                cost = 2

        total_cost += cost

    if n % 2 == 1:
        m = n // 2
        if A[m] != B[m]:
            total_cost += 1

    print total_cost


n_test_cases = 1

if n_test_cases == 0:
    n_test_cases = get()

for i_test_case in range(n_test_cases):
    solve_test_case()
