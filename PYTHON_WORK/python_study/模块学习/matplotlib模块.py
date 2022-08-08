# import numpy as np
from matplotlib import pyplot as plt
from matplotlib import font_manager
import openpyxl
# import random


'''
python的底层绘图库
能将数据可视化，更直观的呈现
使数据更加客观，更具说服力'''

wb = openpyxl.load_workbook('2021级校纪校规考试成绩-向各学院发布.xlsx')
ws = wb.active
total_list = []
for i in ws['C']:
    if type(i.value) == int:
        total_list.append(i.value)
# total_list = total_list[:100]
# 设置一个字体
font = font_manager.FontProperties(fname='D:\PYTHON_WORK\python_study\模块学习\FZZJ-LongYTJW.TTF')
fig = plt.figure(figsize=(20, 10), dpi=60)
x = total_list
y = [i + 1 for i in range(len(total_list))]

plt.plot(x, y, label='成绩数据', color='cyan', linewidth=5)  # 传入x, y数据，绘制折线（x, y数据一一对应）
# # 用多次plot画多条线
# plt.plot([np.mean(total_list)for i in np.linspace(0, len(total_list))], np.linspace(0, len(total_list)), label='平均线', linestyle='-.')
# '''plot的其他参数'''
# # color,设置颜色， 可传入颜色名，颜色的16进制
# # linestyle,设置线条风格，（实线，'-'）（点划线，'-.') (虚线，'--'）（点虚线，’:‘) (无线条，'')
# # linewidth, 设置线条粗细
# # alpha, 线条透明度
#
# # plt.savefig('折线图.jpg')  # 保存图片， 传入的名称要加格式后缀
# # plt.xticks(range(0, 101, 2))  # 传入数组， 绘制x轴的刻度
# plt.xticks(range(0, 101, 10), [f'{i}分' for i in range(0, 101, 10)], fontproperties=font)
# # plt.xticks(数组， 名称数据， rotation= ) 数值数据决定刻度的位置，名称数据决定刻度处的文字，名称与数值一一对应， rotation参数为文字逆时针旋转的度数
# # plt.yticks()
# plt.grid(alpha=0.4)  # 绘制网格,alpha参数控制网格线的透明度，0为完全透明，1为不透明, 参数同plot
# # 添加图像描述信息
# plt.xlabel('分数', size=30, fontproperties=font)  # x标签
# plt.ylabel('序号', size=30, fontproperties=font, rotation=0)  # y标签
# plt.title('校规校纪考试数据', fontproperties=font, size=50)  # 标题
# # 添加图例（显示图线的标签）
plt.legend(prop=font, loc='upper right')
plt.show()  # 将前面得到的图线展示出来

'''绘制散点图'''
# 唯一区别为scatter方法
# plt.scatter(y, x)
# plt.xticks(y[::1000], [' ' for i in y[::1000]])
# plt.title('校规校纪考试数据', fontproperties=font, size=50, color='cyan')
# plt.plot(y, [np.mean(total_list) for i in y], color='r', linewidth=5)
plt.grid(linestyle='-.')
plt.show()

'''绘制条形图'''
# plt.bar(range(1, 100), [random.randint(0, 99)for i in range(1, 100)], width=0.4)  # 绘制竖形条形图
# # plt.bar(x, height, width)    height 和 width 为数据条的属性
# plt.barh(range(1, 199, 2), [random.randint(1, 99) for i in range(1, 100)], 1)
# # plt.barh(range(1, 100), [random.randint(1, 20) for i in range(1, 100)])
# # plt.barh(y, width ,height)
# plt.show()

'''绘制直方图'''
'''a = [131, 98, 125, 131, 124, 139, 131, 117, 128, 108, 135, 138, 131, 102, 107, 114, 119, 128, 121, 142, 127, 130, 124, 101, 110, 116, 117, 110, 
128 , 128, 115, 99, 136, 126, 134, 95, 138, 117, 111, 78, 132, 124, 113, 150, 110, 117, 86, 95, 144, 105, 126, 130, 126, 130, 126, 116, 123, 106, 
112, 138, 123, 86, 101, 99, 136, 123, 117, 119, 105, 137, 123, 128, 125, 104, 109, 134, 125, 127, 105, 120, 107, 129, 116, 108, 132, 103, 136, 118, 
102, 120, 114, 105, 115, 132, 145, 119, 121, 112, 139, 125, 138, 109, 132, 134, 156, 106, 117, 127, 144, 139, 139, 119, 140, 83, 110, 102, 123, 
107, 143, 115, 136, 118, 139, 123, 112, 118, 125, 109, 119, 133, 112, 114, 122, 109, 106, 123, 116, 131, 127, 115, 118, 112, 135, 115, 146, 137, 
116, 103, 144, 83, 123, 111, 110, 111, 100, 154, 136, 100, 118, 119, 133, 134, 106, 129, 126, 110, 111, 109, 141, 120, 117, 106, 149, 122, 122, 
110, 118, 127, 121, 114, 125, 126, 114, 140, 103, 130, 141, 117, 106, 114, 121, 114, 133, 137, 92, 121, 112, 146, 97, 137, 105, 98, 117, 112, 81, 
97, 139, 113, 134, 106, 144, 110, 137, 137, 111, 104, 117, 100, 111, 101, 110, 105, 129, 137, 112, 120, 113, 133, 112, 83, 94, 146, 133, 101, 131, 
116, 111, 84, 137, 115, 122, 106, 144, 109, 123, 116, 111, 111, 133, 150] '''
# klein_blue = (0, 47, 167)
# bin_lit = [0, 90, 110, 130, 150, 170, 190]
# plt.hist(a, bin_lit, rwidth=1, density=True)
# # plt.hist(数据， bins, range, density等等)
# # bins可为int或数组，传入int时表示将数据按range等分为int份
# # bins为数组时，数组中的数依次作为每个划分区间的两限
# # range默认值为（min(数据），max(数据））， 当bins为数组时range参数无效
# # density传入true，变为频率分布直方图（默认为频数分布直方图）
#
#
# class A:
#
#     def __init__(self, lit):
#         self.lit = lit
#
#     def fc_1(self):
#         lit_new = []
#         for __iter in range(len(self.lit) - 1):
#             lit_new.append(int((self.lit[__iter] + self.lit[__iter + 1])) / 2)
#         return lit_new
#
#     def fc_2(self):
#         lit_new = []
#         for __iter in range(len(self.lit) - 1):
#             lit_new.append((self.lit[__iter], self.lit[__iter + 1]))
#         return lit_new
#
#
# print(A(bin_lit).fc_2())
# plt.xticks(A(bin_lit).fc_1(), [f'{i[0]}到{i[1]}分钟'for i in A(bin_lit).fc_2()], fontproperties=font, size=12)
# plt.show()
