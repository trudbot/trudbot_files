import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib import font_manager

font = font_manager.FontProperties(fname='D:\PYTHON_WORK\python_study\模块学习\STXINWEI.TTF')
df = pd.read_csv('D:\PYTHON_WORK\python_study\IMDB-Movie-Data.csv')
# print(df.info())
'''
<class 'pandas.core.frame.DataFrame'>
RangeIndex: 1000 entries, 0 to 999
Data columns (total 12 columns):
 #   Column              Non-Null Count  Dtype  
---  ------              --------------  -----  
 0   Rank                1000 non-null   int64  
 1   Title               1000 non-null   object 
 2   Genre               1000 non-null   object 
 3   Description         1000 non-null   object 
 4   Director            1000 non-null   object 
 5   Actors              1000 non-null   object 
 6   Year                1000 non-null   int64  
 7   Runtime (Minutes)   1000 non-null   int64  
 8   Rating              1000 non-null   float64
 9   Votes               1000 non-null   int64  
 10  Revenue (Millions)  872 non-null    float64
 11  Metascore           936 non-null    float64
dtypes: float64(3), int64(4), object(5)
memory usage: 93.9+ KB
None
'''

'''
任务一：
统计每一种类型的电影的平均分,得到电影类型受欢迎程度的排行
problem：每个电影有好几个类型
         数据存在缺失
'''

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
# t = pd.DataFrame(genre.items(), columns=['genre', 'average score'])
# t.sort_values('average score', ascending=False, inplace=True, ignore_index=True)
# print(t)


'''result:
        genre  average score
0     History  70.857143
1   Animation  70.782609
2   Biography  68.943662
3         War  64.500000
4       Drama  63.497890
5       Sport  61.562500
6       Music  60.687500
7     Musical  60.000000
8     Mystery  59.272727
9    Thriller  58.677596
10     Sci-Fi  58.228070
11      Crime  57.787234
12  Adventure  57.670683
13     Comedy  57.604478
14     Horror  56.685185
15     Family  55.620000
16    Romance  55.458015
17    Fantasy  55.142857
18     Action  53.830450
19    Western  53.500000
'''


'''
任务二：
哪位演员是票房之王
'''

actor_dict = {}

for row_num in range(len(df)):
    row = df.iloc[row_num]
    for name in row['Actors'].split(','):
        actor_dict[name] = actor_dict.get(name, 0) + row['Revenue (Millions)']

data = pd.DataFrame(actor_dict.items(), columns=['name', 'revenue'])
data.sort_values('revenue', ascending=False, ignore_index=True, inplace=True)

# print(data.head(10))
# print(data)
plt.figure(figsize=(20, 8))

plt.barh(data.head(10)['name'], data.head(10)['revenue'])

plt.xlabel('总票房', fontproperties=font, size=15)
plt.ylabel('actor_name', size=15)
plt.title('票房之王', fontproperties=font, size=30)

plt.show()
'''
result:
                name  revenue
0  Robert Downey Jr.  2564.58
1     Christian Bale  1559.62
2        Zoe Saldana  1542.68
3     Liam Hemsworth  1538.46
4    Josh Hutcherson  1496.22
5        Emma Watson  1388.85
6         Will Smith  1340.28
7   Domhnall Gleeson  1299.63
8        Johnny Depp  1280.94
9       Rupert Grint  1269.90
'''


'''任务三：统计中各种电影类型对应电影的数量'''
genre_list = df['Genre'].tolist()
genre_names = {i for a in genre_list for i in list(a.split(','))}  # 得到电影所有种类的名称

zero_df = pd.DataFrame(np.zeros((len(genre_list), len(genre_names))), columns=genre_names)
# 创建一个全0dataframe对象，键为电影总类，行数和电影数相同

for i in range(len(genre_list)):  # 对电影的genre数组进行遍历， 每部电影的数据会对应的保存在zero_df的一行中
    lit = genre_list[i].split(',')  # 将每一部电影的genre信息分割为列表
    zero_df.loc[i, lit] = 1  # 将电影所属分类的值赋为1

keys = zero_df.keys()

values = [zero_df[i].sum() for i in keys]  # 求出每一种电影类型的电影数

result = pd.Series(values, index=keys)

result.index.name = 'Genre'

result.sort_values(ascending=False, inplace=True)

print(result)

plt.figure(figsize=(8, 4.5))

plt.barh(result.index, width=result.values, color='cyan')

plt.ylabel('电影类型', fontproperties=font, size=15)
plt.xlabel('数量', fontproperties=font, size=15)

plt.show()

'''
Genre
Drama        513.0
Action       303.0
Comedy       279.0
Adventure    259.0
Thriller     195.0
Crime        150.0
Romance      141.0
Sci-Fi       120.0
Horror       119.0
Mystery      106.0
Fantasy      101.0
Biography     81.0
Family        51.0
Animation     49.0
History       29.0
Sport         18.0
Music         16.0
War           13.0
Western        7.0
Musical        5.0
dtype: float64'''
