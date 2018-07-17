#!/usr/bin/env python

def array(dtype=int):
	return [dtype(num) for num in raw_input().split()]

def get(dtype=int):
	return dtype(raw_input())

t = get()

for ti in range(t):
	n = get()
	P = [0] * (n + 1)
	for i in range(0, n+1):
		P[i] = get()
	for i in range(n):
		P[i] += (i + 1)
	P = P[::-1] + [0]

	zi  = P.index(0)

	print 'Case #{}: '.format(ti + 1),
	if n % 2 == 0:
		print 1
		print 0.0
	else:
		print 0

	# print P