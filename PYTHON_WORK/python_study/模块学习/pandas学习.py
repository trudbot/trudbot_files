import pandas as pd
import numpy as np
"""numpy能够帮助我们处理数值，但是pandas除了处理数值之外(基于numpy)，还能够帮助我们处理其他类型的数据"""

'''pandas常用数据类型'''
# Series 一维，带标签数组
# DataFrame 二维，Series容器
# df = pd.read_csv('D:\PYTHON_WORK\python_study\dog_names_data.csv')
# # print(df.describe())
# # print(type(df['AgeAsOf2015']))
# name = {}
# for i in df['AnimalName']:
#     name[i] = name.get(i, 0) + 1
# print(len(name))
# df = pd.DataFrame(name.items(), columns=['name', 'quantity'])
# print(df[(df['quantity'] > 100) & (df["name"].str.len() > 6)].sort_values(by='quantity', ascending=False))
# print(df.head(10))
# df = df.sort_values(by='quantity', ascending=False, ignore_index=True)
# print(df.head(10))
# print(df.describe())
t = pd.DataFrame(np.arange(12).reshape(3, 4))
# # t.dropna
#
# print(dir(t))
# print(t.round(2))
# df = pd.read_csv('D:\PYTHON_WORK\python_study\IMDB-Movie-Data.csv')
# # print(df['Metascore'].mean())
# # print(df[df['Metascore'].isnull()])
# genre = {}
# for i in range(len(df)):
#     i = df.iloc[i]
#     f = i['Genre'].split(',')
#     for m in f:
#         if not genre.get(m, 0):
#             genre[m] = []
#             genre[m].append(float(i['Metascore']))
#         else:
#             genre[m].append(float(i['Metascore']))
#
# for i in genre:
#     genre[i] = float(pd.DataFrame(genre[i]).mean())
# # print(genre['Action'])
# t = pd.DataFrame(genre.items(), columns=['genre', 'quantity'])
# t.sort_values('quantity', ascending=False, inplace=True, ignore_index=True)
# print(t)
# print(df['Revenue (Millions)'].dtype)
t.join()
