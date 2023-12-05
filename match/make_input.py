import random

N = 10
W = 1000
print(N, W)
for i in range(N):
    a, b, c = random.randint(1, 100), random.randint(1, 100), random.randint(1, 100)
    print(a, b, c)
