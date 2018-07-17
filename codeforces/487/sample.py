#!/usr/bin/env python

def get_array(data_type=int):
	return [data_type(num) for num in raw_input().split()]

def get(data_type=int):
	return data_type(raw_input())


n, p = get_array()

s = raw_input()

S = list(s)

poss = False

for i in range(p):
	s = set()
	i_set = set()
	
	for j in range((n + p - 1) // p):
		idx = i + p * j
		if idx >= n:
			continue
		if S[idx] == '.':
			i_set.add(idx)
		else:
			s.add(S[idx])
	
	if len(s) > 0:
		c = '1' if '1' in s else '0'
		d = '1' if c == '0' else '0'
		
		for idx in i_set:
			S[idx] = d
			poss = True
	elif len(i_set) > 1:
		c = ['0', '1']
		for e, idx in enumerate(i_set):
			S[idx] = c[e % 2]
		poss = True

	if poss:
		break


if not poss:
	print "No"
else:
	for i in range(n):
		if S[i] == '.':
			S[i] = '0'
	print "".join(S)

