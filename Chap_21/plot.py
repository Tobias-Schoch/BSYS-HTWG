import matplotlib.pyplot as plt

# die Y-Werte:
import numpy as np

gb4 = [755.82, 1105.36, 1075.37, 1063.51, 1081.62, 1079.94, 1066.14, 1081.57, 985.42, 1015.42]
gb5 = [753.29, 1082.12, 1087.79, 1088.47, 1109.78, 1096.02, 1000.34, 1107.56, 1100.87, 1073.02]
gb6 = [728.18, 1029.15, 1066.31, 1024.47, 1000.20, 1056.20, 1043.28, 1053.26, 978.74, 1027.16]
gb7 = [734.02, 1079.31, 1089.40, 1039.75, 1050.50, 1051.99, 1058.31, 1056.42, 998.17, 1016.11]

gb4_mean = np.mean(gb4)
gb5_mean = np.mean(gb5)
gb6_mean = np.mean(gb6)
gb7_mean = np.mean(gb7)

mean = []
mean.append(gb4_mean)
mean.append(gb5_mean)
mean.append(gb6_mean)
mean.append(gb7_mean)

loop = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
plt.xlabel("Loop")
plt.ylabel("Bandwidth")

plt.plot(loop, gb4, "b", label='4GB')
plt.plot(loop, gb5, "r", label='5GB')
plt.plot(loop, gb6, "y", label='6GB')
plt.plot(loop, gb7, "g", label='7GB')
plt.legend(loc='best')
plt.show()

loop = [4000, 5000, 6000, 7000]
plt.xlabel("Memory size in MB")
plt.ylabel("Bandwidth")

plt.plot(loop, mean, "b",)
plt.legend(loc='best')
plt.show()
