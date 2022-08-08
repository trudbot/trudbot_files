import requests
import re
# a = requests.get('网址')   获取网页
# b = a.content    获取网页的byte型源代码
# c = b. decode()  解码为字符串型的源代码
source = requests.get('https://www.swpu.edu.cn/').content.decode()  # 获取网页源代码
html_list = re.findall(' <li><a href="(https://www.swpu.edu.cn.*?)" target="_blank"', source)
title_list = re.findall(' target="_blank" title="(.*?)">', source)[1:9]
del title_list[3]
del title_list[6]
b = ''
for i in range(len(html_list)):
    f = open(' swpu_new{}.txt'.format(i+1), 'w', encoding='utf-8')
    source2 = requests.get(html_list[i]).content.decode()
    content = re.findall('<span style="font-size: 16px;">(.*?)</span></p>', source2)
    for a in range(len(content)):
        b = b + content[a]
    f.write('{0}\n{1}'.format(title_list[i], b))
    f.close()
