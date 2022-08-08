import openpyxl
import numpy
import random
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
# wb = openpyxl.load_workbook('2021级校纪校规考试成绩-向各学院发布.xlsx')
# ws = wb.active
# total_list = []
# for i in ws['C']:
#     if type(i.value) == int:
#         total_list.append(i.value)
q = 11
list_i = [random.randint(0, q-1) for i in range(1000000)]
print(list_i[0])
group = [i for i in range(1000000)]
# plt.hist(list_i, group, histtype='bar', rwidth=0.8)
plt.plot(group, list_i)
plt.show()
# plt.xlabel('score_group')
# plt.ylabel('num')
# plt.show()

