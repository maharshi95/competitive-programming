n = 100

########## 1D Vanilla BIT - Point Update Range Query #########

bit_array = [0] * (n + 1)


def point_update(i, v):
    while i <= n:
        bit_array[i] += v
        i += (i & (-i))


def prefix_query(i):
    s = 0
    while i > 0:
        s += bit_array[i]
        i -= (i & (-i))
    return s


def range_query(i, j):
    return prefix_query(j) - prefix_query(i - 1)


def build_bit(A):
    global n, bit_array
    n = len(A)
    bit_array = [0] * (n + 1)
    for i, a in enumerate(A):
        point_update(i + 1, a)


########### 1D BIT - Point Query Range Update ########

diff_bit_array = [0] * (n + 1)


def suffix_update(i, v):
    while i < n:
        diff_bit_array[i] += v
        i += (i & (-i))


def point_query(i):
    s = 0
    while i > 0:
        s += diff_bit_array[i]
        i -= (i & (-i))
    return s


def range_update(i, j, v):
    suffix_update(i, v)
    if j < n:
        suffix_update(j + 1, -v)


def build_diff_bit(A):
    global n, diff_bit_array
    n = len(A)
    diff_bit_array = [0] * (n + 1)
    for i, a in enumerate(A):
        suffix_update(i + 1, a)
        if i < n - 1:
            suffix_update(i + 2, -a)
