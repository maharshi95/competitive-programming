#!/usr/bin/env python

def get_array(data_type=int):
	return [data_type(num) for num in raw_input().split()]

n = input()

S = raw_input()

n = len(S)

poss = True

for i in range(1, n):
	if S[i] == '1' and S[i-1] == '1':
		poss = False
		break
	if S[i] == '0' and S[i-1] == '0' and (i == 1 or i == n - 1 or S[i-2] == '0'):
		poss = False
		break

if n == 1 and S[0] == '0':
	poss = False

print ('Yes' if poss else 'No')


