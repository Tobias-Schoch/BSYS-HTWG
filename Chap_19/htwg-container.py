# importing the required module 
import matplotlib.pyplot as plt

# x axis values 
x = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
# corresponding y axis values 
y = [8, 17, 35, 173, 638, 373, 782, 524, 556, 311, 405]
xi = list(range(len(x)))
# plotting the points  
plt.plot(xi, y, marker='o')
plt.xticks(xi, x)
# naming the x axis 
plt.xlabel('Number of pages')
# naming the y axis 
plt.ylabel('time in ns')

# giving a title to my graph 
plt.title('HTWG Container')

# function to show the plot 
plt.show() 