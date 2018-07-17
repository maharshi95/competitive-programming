#!/usr/bin/env python

def array(dtype=int):
	return [dtype(num) for num in raw_input().split()]

def get(dtype=int):
	return dtype(raw_input())

t = get()

for ti in range(t):
	n, k, v = array()
	names = []

	for i in range(n):
		name = raw_input()
		names.append(name)

	start = (k * (v - 1))

	visits = []
	for j in range(k):
		name = names[(start + j) % n]
		visits.append(name)
	print 'Case #{}: {}'.format(ti + 1, ' '.join(visits))
	
