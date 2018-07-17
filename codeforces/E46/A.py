n = input()

old = []
new = []

all_types = {'M', 'S', 'L', 'XS', 'XL', 'XXS', 'XXL', 'XXXS', 'XXXL'}


def to_map(tees):
    mp = {t: 0 for t in all_types}
    for t in tees:
        mp[t] += 1
    return mp


for i in range(n):
    old.append(raw_input())

for i in range(n):
    new.append(raw_input())

old_map = to_map(old)

new_map = to_map(new)

cost = 0

for tee in new_map:
    common = min(old_map[tee], new_map[tee])
    old_map[tee] -= common
    new_map[tee] -= common
    cost += new_map[tee]

print(cost)