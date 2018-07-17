def get(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]


def solve_test_case():
    n, k = array()
    S = raw_input()

    cost = [0] * (n - 1)
    for i in range(n - 1):
        cost[i] = int(S[i] != S[i + 1])

    cum_cost = [0] * (n)

    for i in range(0, n - 1):
        cum_cost[i + 1] = cum_cost[i] + cost[i]

    # print cost
    # print cum_cost

    total_cost = 0
    for i in range(k):
        start = i
        end = n - k + i - 1
        i_cost = cum_cost[end + 1] - cum_cost[start]
        # print i, start, end, i_cost
        total_cost += i_cost
    print total_cost
    # print ''


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
