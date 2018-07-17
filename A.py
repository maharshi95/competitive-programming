#!/usr/bin/env python

import sys, time, os

def array(dtype=int):
    return [dtype(num) for num in raw_input().split()]

def get(dtype=int):
    return dtype(raw_input())

n = get()

A = array()

G = [[] for _ in range(n)]

for a,b in edges:
    G[a].append(b);
    G[b].append(a);

    