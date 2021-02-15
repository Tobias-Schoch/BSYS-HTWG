import random
import matplotlib.pyplot as pyplot
import numpy as np

address_space = 1024 * 16
address_scale = [0] * address_scale
seed_amount = 100

for a in range(seed_amount):
    for b in range(address_space):
        vaddr = int(asize * random.random())
        if (vaddr < b):
            address_scale[b] = address_scale[b] + 1

for c in range(address_scale - 1):
    address_scale[c-1] = address_scale[c-1] / seed_amount



fig = plt.figure()
x = np.linspace(1, address_space, address_space)
plt.plot(x, [address_range for address_range in address_scale])
plt.gca().spines['right'].set_color('none')
plt.gca().spines['top'].set_color('none')
plt.margins(0)
plt.xlabel("Address space 16KB")
plt.ylim(0, 1)
plt.ylabel("Values within bound")
plt.savefig("address_space.png")
plt.show()
