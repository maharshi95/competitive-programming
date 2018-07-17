#!/usr/bin/env python

def array(dtype=int):
	return [dtype(num) for num in raw_input().split()]

def get(dtype=int):
	return dtype(raw_input())

M = 1000000007

def pow_mod(b, e):
    if e == 0:
        return 1
    p = pow_mod(b, e // 2)
    p = (p * p) % M
    if e % 2 == 1:
        p = (p * b) % M
    return p

def inv_mod(num):
    return pow_mod(num, M-2)

n = get()
k = get()

deno = inv_mod(pow_mod(2, n-1))

ans = ((M - (n * deno) % M) + 1) % M

print ans

