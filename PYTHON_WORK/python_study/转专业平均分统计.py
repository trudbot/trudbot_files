import openpyxl
import numpy
import matplotlib.pyplot as plt
hot_list = ['油气储运工程', '计算机类', '电气工程及其自动化', '自动化类', '数学与应用数学', '会计学']
hot_dict = dict()
wb_2020 = openpyxl.load_workbook('2020级本科新生拟获得转专业（类）资格学生名单.xlsx')
wb_2021 = openpyxl.load_workbook('2 2021级各本科专业拟接收转专业转入人数计划汇总表.xlsx')
ws_2021 = wb_2021.active
ws_2020 = wb_2020.active
# group = [i for i in range(300, 500, 10)]
# print('---------------------2020年转专业数据整理-----------------------------------------------')
# total_list = []
# for num in ws_2020['A']:
#     if str(num.value).isdecimal():
#         total_list.append(ws_2020[f'D{num.row}'].value)
# print("总预接收人数：1344")
# print('获得转专业资格的人数：{}'.format(len(total_list)))
# print(min(total_list))
# print(max(total_list))
# print('全体平均分为：{}'.format(numpy.around(numpy.mean(total_list), 2)))
# print('方差为：{}'.format(numpy.var(total_list, ddof=1)))
# plt.hist(total_list, group, histtype='bar', rwidth=0.8)
#
# plt.xlabel('score-group')
# plt.ylabel('num')
# plt.show()
# print('---------------------------------------------------------------------')
# for major in hot_list:
#     for i in ws_2021['B']:
#         if i.value == major:
#             hot_dict[f'{major}'] = ws_2021[f'G{i.row}'].value
#     major_list = []
#     for i in ws_2020['G']:
#         if i.value == major:
#             major_list.append(ws_2020[f'D{i.row}'].value)
#     print(f'              {major}\n'
#           f' 转入平均分：{numpy.around(numpy.mean(major_list), 2)}\n',
#           f'最高分：{max(major_list)}\n',
#           f'最低分：{(min(major_list))}\n',
#           f'2020接收人数：{len(major_list)}\n'
#           f' 2021接收人数：{hot_dict[major]}'
#           )
#
#     print('-----------------------------------------------------------------')
# total_major_list = []
# major_dict = dict()
# for i in ws_2020['E']:
#     if i.value not in total_major_list:
#         total_major_list.append(i.value)
# total_major_list.remove('原所在专业（类）')
# for major in total_major_list:
#     p = 0
#     xx_list = []
#     for i in ws_2020['G']:
#         if i.value == f'{major}':
#             xx_list.append(ws_2020[f'D{i.row}'].value)
#     for i in ws_2020['E']:
#         if i.value == f'{major}':
#             p += 1
#     print(f'{major}转入平均分：{numpy.mean(xx_list)}')
#     print(xx_list)
#     print('转出人数：{}'.format(p))
#     print(f"转入人数：{len(xx_list)}")
#     print(f'{major}转入转出比：{len(xx_list)/p}')
#     major_dict[f'{major}'] = len(xx_list)/p
#     print('-----------------------------------------------')
# low_list = []
#
# for i in major_dict:
#     if major_dict[i] == min(list(major_dict.values())):
#         low_list.append(i)
#         print('入出比最低的专业是{}'.format(i))
#     elif major_dict[i] == max(list(major_dict.values())):
#         print('------------------------------')
#         print('王者专业为：{}'.format(i))
#         print('------------------------------')
# wb_2020.close()
# num_zhuanlu = 0
# for i in ws_2020['F']:
#     if i.value == '化学化工学院':
#         num_zhuanlu += 1
# num_zhuanchu = 0
# for i in ws_2020['H']:
#     if i.value == '化学化工学院' and ws_2020[f'F{i.row}'].value != '化学化工学院' and ws_2020[f'F{i.row}'].value != '石油与天然气工程学院':
#         num_zhuanchu += 1
# print(f'2020年化学化工学院转出{num_zhuanlu}人,转入{num_zhuanchu}人')
print(1)


for a in hot_list:
    x = 0
    dit = []
    print(a)
    for i in ws_2020['G']:
        for b in ws_2021['B']:
            if b.value == a:
                x = int(ws_2021[f'G{b.row}'].value)
        if i.value == a:
            dit.append(ws_2020[f'D{i.row}'].value)
    dit.sort()
    print(dit[len(dit)-x:])
    print('----------------------')
