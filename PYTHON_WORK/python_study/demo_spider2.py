import lxml.html
import requests
import re
html = 'https://www.swpu.edu.cn/hgy/'
source = requests.get(html).content.decode()
print(source)
selector = lxml.html.fromstring(source)
txt = selector.xpath('//script[@language="JavaScript"]/text()')
# useful_txt = txt[0].xpath('string(.)')
# title = re.findall('"(.*?)"', txt)
# print(title)
print(txt)
print('-------------------------------------')
# print(useful_txt)
# html_lis
# t = re.findall('"(info.*?)"', txt)
# print(html_list)
# html_list = []
# for i in txt:
#     useful_html = re.findall('"(info.*?)"', i)
#
#     if useful_html:
#         for a in useful_html:
#             html_list.append(html+a)
# for use_html in html_list:
#     source = requests.get(use_html).content.decode()
#     selector = lxml.html.fromstring(source)
#     content = selector.xpath('//span[@style="line-height: 150%; font-size: 16px; font-family: 宋体, SimSun;"]/text()')
#     with open('text.txt', 'w', encoding='utf-8') as f:
#         for i in content:
#             f.write(i)




