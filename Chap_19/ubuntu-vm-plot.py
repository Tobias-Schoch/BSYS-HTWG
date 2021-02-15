# importing the required module 
import matplotlib.pyplot as plt

# x axis values 
x = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
# corresponding y axis values 
y = [87, 108, 142, 211, 287, 502, 960, 1838, 4115, 6995, 13918]
xi = list(range(len(x)))
# plotting the points  
plt.plot(xi, y, marker='o')
plt.xticks(xi, x)
# naming the x axis 
plt.xlabel('Number of pages')
# naming the y axis 
plt.ylabel('time in ns')

# giving a title to my graph 
plt.title('Ubuntu VM')

# function to show the plot 
plt.show() 