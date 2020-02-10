import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl

mpl.rcParams['font.family'] = 'sans-serif'
mpl.rcParams['font.sans-serif'] = 'NSimSun,Times New Roman'
a = np.loadtxt('Data.txt')
list1 = [x for x in range(61)]
print(a[0])

for x in range(0, 8):
    plt.plot(list1, a[x], '+', label='PoW', color='black')
    z1 = np.polyfit(list1, a[x], 15)  # 用3次多项式拟合  可以改为5 次多项式。。。。 返回三次多项式系数
    p1 = np.poly1d(z1)
    print(p1)
    list2 = p1(list1)
    plot2 = plt.plot(list1, list2, 'r', label='polyfit values')
    plt.show()
plt.xlabel('Horizontal axis')
plt.ylabel('Vertical axis')
plt.title('Title')
plt.legend()
