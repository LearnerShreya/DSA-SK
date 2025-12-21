import math

n = 11

if n < 2:
    print("Not Prime")
else:
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            print("Not Prime")
            break
    else:
        print("Prime")