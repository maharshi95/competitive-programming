#!/usr/bin/env python3

import sys
sys.setrecursionlimit(2000000)

def get_array(data_type=int):
	return [data_type(num) for num in input().split()]

n = int(input())

G = [[] for _ in range(n)]

for i in range(n-1):
	u, v = get_array()
	G[u-1].append(v-1)
	G[v-1].append(u-1)

counter = 0

def dfs(p, u):
	global counter
	nodes = 1
	for v in G[u]:
		if v == p:
			continue
		nodes += dfs(u, v)
	if nodes % 2 == 0:
		counter += 1
	return nodes

dfs(-1, 0)

st = []
st.append((-1, 0))

while st:
	p, u = st.pop()
	nodes = 1
	for v in G[u]:
		if v == p:
			continue
		st.append((u, v))
	if nodes % 2 == 0:
		counter += 1


print (counter - 1)
