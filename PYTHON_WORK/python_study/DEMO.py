# coding=utf-8
# import urllib.request
# a = str(urllib.request.urlopen('https://www.swpu.edu.cn/').read())
# with open('c.txt', 'w', encoding='utf-8') as b:
#     b.write(a)
# import schedule
# schedule.every(3).seconds.do(print('hhh'))
# file=open('A.txt','w')
# file.write(str(urllib.request.urlopen('https://www.swpu.edu.cn/').read()))
# file.close()
# file2=open('A.txt','r')
# file1=open('b.txt','w')
# file1.write(file2.readline())
# file.close()
# file1.close()
# file1=open('b.txt','r')
# file2=open('c.txt','w')
# file2.write(file1.readline())
# file1.close()
# file2.close()
# file=open('b.txt','r')
# file.seek(1)
# print(file.tell())
# print(file.read())
# file.close()
# import os
# file1=os.popen()
# file2=open('a.txt','w')
# file2.write(file1.read())
# file1.close()
# file2.close()
# with open('b.txt','r')as file:
#     print(file.read())
# print(type(open('b.txt','r')))
# help(open('b.txt','r'))
# print((600-157)/2)
# file = open('a.txt', 'r')
# print(file.name)
# import copy
# a=[1]
# b=copy.copy(a)
# print(id(a))
# print(id(b))
# print(bool(0))
# print(type(chr(97)))
# import re
# import csv
# with open('swpuba.txt', 'r', encoding='utf-8') as f:
#     source = f.read()
# print(re.findall('<div class="threadlist_abs threadlist_abs_onlyline ">\n *(.*?)\n *</div>', source))
# name_list = re.findall(' title="锟斤拷锟斤拷锟斤拷锟斤拷:(.*?)"', source)
# print(name_list)
# import requests
# print(requests.get('https://www.swpu.edu.cn/').content.decode())
# with open('喜锟斤拷锟斤拷锟斤拷/demo.txt', 'w') as f:
#     f.write('abc')
# lam = lambda x: x**2
# print(lam(10))
# import re
# a = re.compile(r'a \w+', re.IGNORECASE)
# b = a.search('A B C D')
# d = a.findall('A B C D')
# print(d)
# c = a.sub('18202850979', '锟揭的电话锟斤拷锟斤拷锟斤拷13766321090')
# print(c)
# if b:
#     print('匹锟斤拷晒锟�')
#     print(b.group())
# else:
#     print('未匹锟戒到锟侥憋拷')
# print(re.findall('1+(\\d*)', '锟揭的电话锟斤拷锟斤拷锟斤拷13766321090, 锟斤拷锟侥电话锟斤拷锟斤拷锟斤拷18202850979'))
# import logging
# try:
#     a = int(input())
# except:
#     raise Exception('this is a error message')
# logging.Logger(a)
# webbrowser.open('https://www.swpu.edu.cn/')
# import requests, webbrowser, re, random
# ss = input('锟斤拷锟斤拷锟斤拷')
# html = f'https://cn.bing.com/search?q={ss}'
# content = requests.get(html).content.decode()
# web = re.findall('href="(.*?)"', content)
# # print(web)
# for i in range(10):
#     one_web = web[random.randint(0, len(web))]
#     if 'https' not in one_web:
#         webbrowser.open('https://cn.bing.com' + web[i])
#         continue
#     webbrowser.open(one_web)
# import bs4
# import requests
# source = requests.get('https://www.swpu.edu.cn/').content.decode()
# source3 = '<div><p>content<p>content2</p></p><title>title</title></div>'
# source4 = '<div><p>ddd<div>content</div></p><title>title</title></div>'
# # print(source)
# soup = bs4.BeautifulSoup(source3, 'lxml')
# print(soup.p.parent)
# for i in soup.div.strings:````````````````````````````````````````````````````111111
#     print(i)
# for i in soup.div.children:
#     print(i)
# print('------------')
# for i in soup.div.descendants:
#     print(i)
# print(soup.prettify)
#
# print(type(soup.name))mp
# num = eval(input())
# num_empty = 0
# i = 0
# while pass:
#     num = num + num//3
#
#
#
# print(num_empty)
# print(i)
# print([9/2])
# a = int(input())
# if a % 4 == 0:
#     print('锟斤拷锟斤拷锟斤拷')
# else:
#     print('锟斤拷锟斤拷锟斤拷锟斤拷')
# import openpyxl
# workbook1 = openpyxl.load_workbook('锟斤拷锟斤拷锟斤拷锟斤拷业锟斤拷锟斤拷.xlsx')
# workbook2 = openpyxl.load_workbook('锟节讹拷锟斤拷锟斤拷业锟秸革拷 (1).xlsx')
# sheet1 = workbook1.active
# sheet2 = workbook2.active
# name_cell_tuple1 = sheet1['A']
# name_cell_tuple2 = sheet2['A']
# name_frequency = []
# for i in name_cell_tuple1:
#     name_frequency.append([i.value, 1])
# # print(name_frequency)
# name_list = []
# num = 0
# only_one_list = []
# for i in name_frequency:
#     name_list.append(i[0])
# # print(name_list)
# name_list2 = [i.value for i in name_cell_tuple2]
# for i in name_list2:
#     for m in name_frequency:
#         if i in m:
#             m[1] += 1
# for i in name_frequency:
#     if i[1] == 1:
#         only_one_list.append(i[0])
# print(name_frequency)
# print('只锟斤拷锟斤拷一锟轿碉拷锟斤拷锟斤拷锟斤拷', only_one_list)
# workbook1.close()
# workbook2.close()
# import re
# from typing import List, Any
#


# def remove_list(namelist):
#     for i in namelist:
#         if not len(i):
#             namelist.remove(i)
#
#
# remove_list(name_list_2128)
# remove_list(name_list_2128)
# name_list_2128.insert(0, '锟斤拷锟斤拷锟斤拷')
# name_list_2128.insert(0, '锟斤拷锟斤拷锟斤拷')
# name_list_2128.insert(0, '锟斤拷锟斤拷桐')
# name_list_2128.insert(0, '锟斤拷盛锟斤拷')
# name_list_2128.insert(0, '锟斤拷锟斤拷')
# name_list_2128.insert(0, '锟斤拷锟斤拷')
# name_list_2128.insert(0, '锟斤拷志锟斤拷')
# name_list_2128[81] = '锟斤拷小锟斤拷'
# name_list_2128[91] = '努锟斤拷锟斤拷耶姆锟斤拷锟斤拷斯锟斤拷锟斤拷锟斤拷'
# name_list_2128[106] = '锟斤拷双权'
# name_list_2128[24] = '锟竭瑀'
#
# # print(name_list)
# # print(len(name_list_2192))
# # for i in name_list_2128:
# #     if '' in i:
# #         print(i, name_list_2128.index(i))
# q = []
# a = eval(input(''))
# print(q[a-1])
# import pyautogui
# import time
# try:
#     while True:
#         print(pyautogui.position())
#         time.sleep(1)
# except KeyboardInterrupt:
#     print('\ndone')
# a = [1, 2, 3]
# print(sum(a))
# print(min(a))
# from matplotlib import pyplot as plt

# import random
# y = [random.randint(20, 35)for i in range(120)]
# x = [i for i in range(1, 121)]
# x_label = []
# for i in x:
#     if i > 60:
#         x_label.append(f'11:{i-60}')
#     else:
#         x_label.append(f'10:{i}')
#
# _x = [i/2 for i in x]
# _y = [i/2 for i in y]
# plt.xticks(x[::10], x_label[::10], rotation=-45)
# plt.plot(x, y)
# plt.plot(x, _y)
# plt.show()
#
#
# def abc(lit):
#     lit_new = []
#     for i in range(len(lit)-1):
#         lit_new.append(int((lit[i]+lit[i+1]))/2)
#     return lit_new
#
#
# print(abc([0, 90, 110, 120, 140, 160, 180, 200]))
# import openpyxl
# from openpyxl.styles import PatternFill
# wb1 = openpyxl.load_workbook('D:\PYTHON_WORK\python_study\\2128锟竭碉拷锟斤拷学锟斤拷业锟斤拷锟�.xlsx')
# # wb2 = openpyxl.load_workbook('D:\PYTHON_WORK\python_study\\2128锟竭碉拷锟斤拷学锟斤拷业锟斤拷锟�.xlsx')
# ws1 = wb1.active
# # ws2 = wb2.active
# for i1 in ws1['A']:
#     for i2 in ws2['A']:
#         if i1.value == i2.value:
#             ws2[f'E{i2.row}'] = ws1[f'B{i1.row}'].value
# wb2.save('2128锟竭碉拷锟斤拷学锟斤拷业锟斤拷锟�.xlsx')
# print(ws1['B:E'])
# for i in ws1['B:E']:
#     for m in i:
#         if not m.value:
#             m.fill = PatternFill("solid", fgColor="DC143C")
# wb1.save('2128锟竭碉拷锟斤拷学锟斤拷业锟斤拷锟�.xlsx')
# a = 'a111'
# import openpyxl
# wb1 = openpyxl.load_workbook('')
# wb2 = openpyxl.load_workbook('')
# ws1 = wb1.active
# ws2 = wb2.active
# for i in ws1['A']:
#     for m in ws2['A']:
#         if i.value == m.value:
#             print(i.value)

# import turtle
#
#
# # 锟斤拷锟斤拷圣锟斤拷锟斤拷锟斤拷锟斤拷叶锟斤拷锟斤拷
# def tree(d, s):
#     if d <= 0:
#         return
#     turtle.forward(s)
#     tree(d - 1, s * .8)
#     turtle.right(120)
#     tree(d - 3, s * .5)
#     turtle.right(120)
#     tree(d - 3, s * .5)
#     turtle.right(120)
#     turtle.backward(s)
#
#
# n = 100
# """ 锟斤拷锟矫伙拷图锟劫讹拷
# 'fastest' :  0
# 'fast'    :  10
# 'normal'  :  6
# 'slow'    :  3
# 'slowest' :  1
# """
# turtle.speed(0)  # 锟斤拷锟斤拷锟劫讹拷
#
# turtle.left(90)
# turtle.forward(3 * n)
# turtle.color("orange", "yellow")
# turtle.left(126)
#
# # turtle.begin_fill()
# for i in range(5):
#     turtle.forward(n / 5)
#     turtle.right(144)
#     turtle.forward(n / 5)
#     turtle.left(72)
#     turtle.end_fill()
# turtle.right(126)
# turtle.color("dark green")
# turtle.backward(n * 4.8)
#
# # 执锟叫猴拷锟斤拷
# tree(15, n)
# turtle.backward(n / 5)
# import numpy as np
#
#
# def remove_nan(array, axis=3):
#     if len(array.shape) == 1:
#         array[np.isnan(array)] = np.round(array[array == array].mean(), 2)
#         return array
#
#     elif len(array.shape) == 2:
#
#         if axis == 3:
#             array[np.isnan(array)] = np.round(array(array == array).mean())
#
#         elif axis == 0:
#             for i in range(array.shape[1]):
#                 array[:, i][np.isnan(array[:, i])] = np.round(array[:, i][array[:, i] == array[:, i]].mean())
#
#         elif axis == 1:
#
#             for i in range(array.shape[0]):
#                 array[i][np.isnan(array[i])] = np.round(array[i][array[i] == array[i]].mean())
#
#         else:
#             print('锟斤拷锟斤拷锟斤拷锟侥诧拷锟斤拷')
#
#         return array
#
#     else:
#         print('锟斤拷锟斤拷锟斤拷锟杰凤拷围')
#
#
# if __name__ == '__main__':
#     a = np.array([np.nan, 6.0, 3.0, 8.0])
#     print(remove_nan(a))
# f = open('text.txt', 'w')
# a = [1, 2, 3]
# f.write(a)
# num = 0
# for i in range(100, 301):
#     if i//7 == i/7:
#         num += i
#         print(i)


# def c_f(integer):
#     result = integer
#     if type(integer) == int and integer > 0:
#         while integer != 1:
#             result = result*(integer-1)
#             integer -= 1
#         return result
#     else:
#         print('锟斤拷锟斤拷锟斤拷一锟斤拷锟斤拷锟斤拷锟斤拷')
#
#
# print(c_f(-1))

# for i1 in range(1, 10000):
#     lit = []
#     for i2 in range(100):
#         if i2**2 == i1+100 or i2**2 == i1+168:
#             lit.append(i2)
#     if len(lit) == 2:
#         print('锟斤拷锟轿獅}'.format(i1))
#         break
# name = []
# lit = []
# for a in range(1, 10):
#     for b in range(1, 10):
#         for c in range(1, 10):
#             for d in range(1, 10):
#                 for e in range(1, 10):
#                     if len({a, b, c, d, e}) == 5:
#                         num = int(str(a)+str(b))*int(str(c)+str(d)+str(e))
#                         string = str(a)+str(b)+'*'+str(c)+str(d)+str(e)
#                         if num not in lit:
#                             name.append(string)
#                             lit.append(num)
#                         else:
#                             v = list(name[lit.index(num)])
#                             v.remove('*')
#                             v = {int(i) for i in v}
#                             if {a, b, c, d, e} == set(v) and string != name[lit.index(num)]:
#                                 print(string + '=' + name[lit.index(num)])

# print(name)
#
# import turtle
# import time
# turtle.getscreen().colormode(255)
#
# # turtle.screensize(800, 600, 'black')
# turtle.setup(600, 400)
# turtle.bgcolor('black')
# turtle.bgpic(picname='new_ia_100007137.png')
# turtle.title('demo')
# dog1 = turtle.Turtle()
# dog2 = turtle.Turtle()
# dog1.shape('turtle')
# dog1.pencolor('cyan')
# dog2.pencolor('crimson')
# dog1.fillcolor('honeydew')
# # dog1.speed(0)
# dog1.lt(180)
# dog1.forward(100)
# dog2.forward(100)
# dog1.stamp()
# dog1.penup()
# dog1.hideturtle()
#
# dog1.back(200)
# dog1.showturtle()
# dog1.pendown()
# dog1.pensize(5)
# dog1.pencolor((0, 47, 167))
# dog1.circle(50)
# dog1.fillcolor('cyan')
# # turtle.bye()
# # dog1.reset()
# turtle.mainloop()


# dog = turtle.Turtle()
# dog.pensize(3)
# dog.shape('turtle')
# for i in range(5, 361, 5):
#     turtle.speed(0)
#     dog.pencolor("cyan")
#     dog.forward(150)
#     # time.sleep(2)
#     dog.left(90)
#     dog.pencolor('lawngreen')
#     dog.forward(100)
#     # time.sleep(2)
#     dog.left(90)
#     dog.pencolor((0, 47, 167))
#     dog.forward(150)
#     # time.sleep(2)
#     dog.left(90)
#     dog.pencolor('cyan')
#     dog.forward(100)
#     # time.sleep(2)
#     dog.left(90)
#     dog.left(5)
# turtle.mainloop()
#
# a = [1]
# a.index()
# import turtle
# t = turtle.Turtle('turtle')
# t.forward(20)
# turtle.mainloop()
# import random
# import time
#
#
# def sort_1(seq):
#     for i in range(len(seq)):
#         smallest = i
#         for m in range(i + 1, len(seq)):
#             if seq[m] < seq[i]:
#                 smallest = m
#         seq[i], seq[smallest] = seq[smallest], seq[i]
#     return seq
#
#
# def sort_2(seq):  # 冒泡排序
#     while True:
#
#         for b in range(1, len(seq)-2):
#             num = 0
#             for i in range(len(seq) - b):
#                 if seq[i] > seq[i + 1]:
#                     num += 1
#                     seq[i], seq[i + 1] = seq[i + 1], seq[i]
#             if num == 0:
#                 break
#         break
#     return seq
#
#
# def sort_3(seq):  # 归并排序
#     if len(seq) < 2:
#         return seq
#
#
# def merge(a, b):
#     c = []
#     h = j = 0
#     while j < len(a) and h < len(b):
#         if a[j] < b[h]:
#             c.append(a[j])
#             j += 1
#         else:
#             c.append(b[h])
#             h += 1
#
#     if j == len(a):
#         for i in b[h:]:
#             c.append(i)
#     else:
#         for i in a[j:]:
#             c.append(i)
#
#     return c
#
#
# def merge_sort(lists):
#     if len(lists) <= 1:
#         return lists
#     middle = len(lists) // 2
#     left = merge_sort(lists[:middle])
#     right = merge_sort(lists[middle:])
#     return merge(left, right)
#
#
# demo_array = [random.randint(1, 100) for i in range(10000)]
# time1 = time.time()
# print(sort_2(demo_array))
# time2 = time.time()
# print(time2-time1)

# def f(s: str):
#     res = ''
#     for i in list(s):
#         if i not in res:
#             res += i
#     if len(res) >= 10:
#         res = res[:10]
#     return res
#
#
# print(f('Hello world, hello python'))
# import numpy as np

# result = []
#
#
# def auxiliary_f(i, n):
#
#     res = []
#     a = (i//n) + 1
#     if a == n:
#         return True
#
#     for m in range(n*a, n*(a+1)):
#         if m not in range(i+n-1, i+n+2):
#             res.append(m)
#
#     if len(res):
#         result.append(res)
#         for b in res:
#             auxiliary_f(b, n)
#     else:
#         return None
#
# def f(n: int):
#     res = 0
#     while n % 10 == 0:
#         res += 1
#         n /= 10
#
#     return res
#
#
# print(f(1100))

# x = []
# for i in x:
#     print('aaa')
# else:
#     x.append(100)
#     print(x)

# class Solution:
#     def longestCommonPrefix(self, strs: list[str]) -> str:
#         res = ''
#         for i in range(len(strs[0])):
#             temp = strs[0][:i+1]
#             for j in strs[1:]:
#                 if j.find(temp) != 0:
#                     return res
#             res = temp
#         return res
#
#
# s = Solution()
# print(s.longestCommonPrefix(['flow', 'flow', 'flow']))

# def fact(x: int):
#     if x == 2:
#         return True
#     for i in range(2, x):
#         if x % i == 0:
#             break
#     else:
#         return True
#     return False
#
#
# def f(x: int):
#     res = []
#     if fact(x):
#         return [x]
#     while not fact(x):
#         for i in range(2, x):
#             if fact(i) and x % i == 0:
#                 x = int(x/i)
#                 res.append(i)
#                 break
#     res.append(x)
#     return res
#
# fact_data = f(12345678)
# hash_ = dict()
# for i in fact_data:
#     if i not in hash_.keys():
#         hash_[i] = 1
#     else:
#         hash_[i] += 1
# res = 1
# for i in hash_.keys():
#     if hash_[i] == 1:
#         res = res * i
# print(res)
#
# from turtle import *
# Screen().setup(650,350,200,200)
# penup()
# fd(-250)
# pendown()
# a=7
# pensize(a)
# seth(-40)
# for i in range(4):
#     pensize(a)
#     if i<1:
#         pencolor("blue")
#     elif i<2:
#         pencolor("red")
#         seth(295)
#     elif i<3:
#         pencolor("yellow")
#         seth(340)
#     else:
#         pencolor("purple")
#         seth(-40)
#     a=a+3
#     circle(40,80)
#     circle(-40,80)
# circle(40,80/2)
# pencolor("green")
# fd(40)
# circle(16,90)
# fd(40/3)
# pensize(30)
# fd(40/3)
# penup()
# right(90)
# fd(8)
# pendown()
# pensize(4)
# pencolor("red")
# circle(3)
# penup()
# left(160)
# fd(16)
# pendown()
# pensize(4)
# circle(3)
# penup()
# right(160)
# fd(8)
# seth(90)
# fd(8)
# pendown()
# pensize(2)
# pencolor("red")
# fd(20)
# penup()
# done()


