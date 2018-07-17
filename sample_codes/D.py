def read(dtype=int):
    return dtype(raw_input())


def array(dtype=int):
    return [dtype(word) for word in raw_input().split()]


n = read()
