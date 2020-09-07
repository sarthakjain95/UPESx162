
#! /usr/bin/env python

import matplotlib.pyplot as plt

common_x= [i*10000 for i in range(1, 10)]
common_x.append(200000)

common_xo= common_x[:3]

# bs_yo= [2410.61, 10532.67, 25111.51]
bs_y= [2410.61, 10532.67, 25111.51, 46003.67, 72022.56, 118084.87, 185653.53, 265914.02, 308826.86, 1543119.84]
# ss_yo= [1159.38, 4634.16, 10566.62]
ss_y= [1159.38, 4634.16, 10566.62, 18859.20, 29777.82, 52077.55, 87086.55, 90220.50, 117307.82, 668127.42]
ms_y= [20.35, 42.73, 68.83, 97.42, 123.43, 177.82, 203.92, 241.10, 272.46, 678.32]
qs_y= [11.07, 23.57, 39.08, 51.39, 68.40, 97.85, 113.67, 130.97, 154.67, 373.86]

# plt.plot(common_xo, bs_yo, 'r', label="bubble sort")
plt.plot(common_x, bs_y, 'r', label="bubble sort")
# plt.plot(common_xo, ss_yo, 'g', label="selection sort")
plt.plot(common_x, ss_y, 'g', label="selection sort")
plt.plot(common_x, ms_y, 'b', label="merge sort")
plt.plot(common_x, qs_y, 'purple', label="quick sort")
plt.legend()
plt.show()

