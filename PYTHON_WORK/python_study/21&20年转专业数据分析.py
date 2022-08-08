import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import font_manager
font = font_manager.FontProperties(fname='D:\PYTHON_WORK\python_study\模块学习\FZZJ-LongYTJW.TTF')
df = pd.read_excel('D:\PYTHON_WORK\python_study\\21&20数据.xlsx')
# print(df.tail(30))

i = 3
plt.plot(df['2021总成绩'], label='2021', color='blue', linewidth=i)
plt.legend(prop=font, loc='upper right')

plt.plot(df['2020总成绩'], label='2020', color='red', linewidth=i)
plt.legend(prop=font, loc='upper right')

plt.ylabel('分数', size=20, fontproperties=font, rotation=0)
plt.show()


bins = [300, 320, 340, 360, 380, 400, 410, 420, 430, 440, 450, 460, 470, 480]
plt.hist(df['2021总成绩'], bins=bins, alpha=0.7, label='2021', color='orange')
plt.hist(df['2020总成绩'], bins=bins, alpha=0.5, color='cyan', label='2020')
plt.ylabel('人数', size=20, fontproperties=font, rotation=0)
plt.legend(prop=font, loc='upper right')
plt.xticks(bins, bins)
plt.show()
