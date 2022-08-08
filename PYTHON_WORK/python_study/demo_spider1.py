import requests
import re
source = requests.get('https://book.qidian.com/info/1028052881/#Catalog').content.decode()
title_list = re.findall('alt="喜遇良辰 (.*?) 首发时间', source)
html_list = re.findall('class="book_name"><a href="(.*?)"', source)
effective_html = []
effective_title = []
for i in range(len(html_list)):
    if html_list[i].find('vipreader') == -1 and html_list[i].find('read.') != -1:
        effective_html.append(html_list[i])
        effective_title.append(title_list[i])
txt = ''
for i in range(len(effective_title)):
    source = requests.get('https:'+effective_html[i]).content.decode()
    txt_list = re.findall('<p>[\s]*(.*?)<p>', source)
    for a in range(len(txt_list)):
        txt = txt + txt_list[a]
    with open('喜遇良辰/第{}章.txt'.format(i+1), 'w', encoding='utf-8') as f:
        f.write('{0}\n{1}'.format(effective_title[i].center(100), txt))



