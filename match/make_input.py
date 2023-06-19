import random

T = 20
MXA = 6
print(T)
for t in range(T):
    N = random.randint(1, 6)
    print(N)
    for i in range(N):
        print(random.randint(1, MXA), end=" ")
    print()
