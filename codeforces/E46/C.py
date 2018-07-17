def array():
    return [int(num) for num in raw_input().split()]


n, M = array()

A = [0] + array() + [M]

print(A)

left = [[0, 0] for _ in range(n)]
right = [[0, 0] for _ in range(n)]

for i in range(1, n + 1):
    left[i - 1][0] = (A[i] - A[i - 1]) * (i % 2)
    left[i - 1][1] = (A[i] - A[i - 1]) * (1 - i % 2)

for i in range(n, 0, -1):
    right[i - 1][0] += (A[i + 1] - A[i]) * (i % 2)
    right[i - 1][1] += (A[i + 1] - A[i]) * (1 - i % 2)

print left

print('')

print right
