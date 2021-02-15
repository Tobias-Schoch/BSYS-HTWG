import matplotlib.pyplot as plt

# die Y-Werte:
import numpy as np

fifo = [0.49, 0.78, 0.88, 0.91]
lru = [0.49, 0.84, 0.89, 0.93]
random = [0.48, 0.78, 0.86, 0.90]
clock = [0.49, 0.8, 0.88, 0.92]


loop = [1, 2, 3, 4]
plt.xlabel("Cache Block size")
plt.ylabel("Hit Rate")

plt.plot(loop, fifo, "b", label='FIFO')
plt.plot(loop, lru, "r", label='LRU')
plt.plot(loop, random, "y", label='RANDOM')
plt.plot(loop, clock, "g", label='CLOCK')
plt.legend(loc='best')
plt.show()