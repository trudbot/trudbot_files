import re
'''
1, 创建正则表达式对象
向re.compile()传入一个字符串值，表示正则表达式，它将返回一个Regex 模式对象（或者就简称为Regex 对象）。

2, 匹配Regex 对象
Regex 对象的search()方法查找传入的字符串，寻找该正则表达式的所有匹配。如果字符串中没有找到该正则表达式模式，search()方法将返回None。
如果找到了该模式，search()方法将返回一个Match 对象。Match 对象有一个group()方法，它返回被查找字符串中实际匹配的文本.
基本语法格式
v = re.compile('正则表达式').search('目标字符串').group()

3, 用管道匹配多个分组
字符|称为“管道”。希望匹配许多表达式中的一个时，就可以使用它。

4， 利用括号分组
添加括号将在正则表达式中创建“分组”。
正则表达式字符串中的第一对括号是第1 组。第二对括号是第2 组。
向group()方法传入整数1 或2，就可以取得不同组的匹配内容。

5,常用符号
 ?匹配零次或一次前面的分组。
 *匹配零次或多次前面的分组。
 +匹配一次或多次前面的分组。
 {n}匹配n 次前面的分组。
 {n,}匹配n 次或更多前面的分组。
 {,m}匹配零次到m 次前面的分组。
 {n,m}匹配至少n 次、至多m 次前面的分组。
 {n,m}?或*?或+?对前面的分组进行非贪心匹配。
 ^spam 意味着字符串必须以spam 开始。
 spam$意味着字符串必须以spam 结束。
 .匹配所有字符，换行符除外。
 \d、\w 和\s 分别匹配数字、单词和空格。
 \D、\W 和\S 分别匹配出数字、单词和空格外的所有字符。
 [abc]匹配方括号内的任意字符（诸如a、b 或c）。
 [^abc]匹配不在方括号内的任意字符。

6,字符分类
\d 0 到9 的任何数字
\D 除0 到9 的数字以外的任何字符
\w 任何字母、数字或下划线字符（可以认为是匹配“单词”字符）
\W 除字母、数字和下划线以外的任何字符
\s 空格、制表符或换行符（可以认为是匹配“空白”字符）
\S 除空格、制表符和换行符以外的任何字符

7, findall()方法
除了search 方法外，Regex 对象还有一个findall()方法。search()将返回一个Match对象，包含被查找字符串中的“第一次”匹配的文本
，而findall()方法将返回一个字符串列表，包含被查找字符串中的所有匹配。
v = re.compile('正则表达式').findall('目标字符串')

8, 用句点字符匹配换行
点-星将匹配除换行外的所有字符。
通过传入re.DOTALL 作为re.compile()的第二个参数，可以让句点字符匹配所有字符，包括换行字符。

9, 不区分大小写的匹配
要让正则表达式不区分大小写，可以向re.compile()传入re.IGNORECASE 或re.I，作为第二个参数。

10, 用sub()方法替换字符串
正则表达式不仅能找到文本模式，而且能够用新的文本替换掉这些模式。
sub()方法会用替换字符串替换正则表达式匹配到的字符串，并返回替换后的字符串。
Regex对象的sub()方法需要传入两个参数。第一个参数是一个字符串，用于取代发现的匹配。
第二个参数是一个目标字符串。sub()方法返回替换完成后的字符串。
v = re.compile('正则表达式').sub('替换字符串'， ‘目标字符串’)
在sub()的第一个参数中，可以输入\1、\2、\3……。表示“在替换中输入分组1、2、3……的文本”。

11， 管理复杂的正则表达式
向re.compile()传入变量re.VERBOSE，作为第二个参数
会告诉re.compile()，忽略正则表达式字符串中的空白符和注释
再使用了三重引号（''' ''')，创建一个多行字符串。这样就可以将正则表达式定义放在多行中，让它更可读。

12, 使用多个compile变量
re.compile()函数只接受一个值作为它的第二参数。
可以使用管道字符（|）将变量组合起来，从而绕过这个限制
someRegexValue = re.compile('foo', re.IGNORECASE | re.DOTALL | re.VERBOSE)

13， re.findall()方法
返回所有匹配的字符串组成的列表
v = re.findall('正则表达式', '目标字符串'）
'''


# with open('swpuba.txt', 'r', encoding='utf-8') as f:
#     source = f.read()
# name_list = re.findall('title="主题作者:(.*?)"', source)
# print(name_list)
# creating_time_list = re.findall('title="创建时间">(.*?)</span>', source)
# print(creating_time_list)
# title_list = re.findall(' target="_blank" class="j_th_tit ">(.*?)</a>', source)
# print(title_list)
# text_list = re.findall('<div class="threadlist_abs threadlist_abs_onlyline ">\n *(.*?)\n *</div>', source)
# print(text_list)
#
# g = open('new.csv', 'w', encoding='utf-8')
# csv_writer = csv.writer(g)
# csv_writer.writerow(['publisher', 'release_time', 'title', 'content'])
# for i in range(7):
#     result = [name_list[i], creating_time_list[i], title_list[i], text_list[i]]
#     csv_writer.writerow(result)
# g.close()

'''强密码检测'''
def Password_Check(i):
    i = str(i)
    if re.compile('[a-z]').search(i):
        re1 = re.compile('[a-z]').search(i).group()
    else:
        re1 = ''
    if re.compile('[A-Z]').search(i):
        re2 = re.compile('[A-Z]').search(i).group()
    else:
        re2 = ''
    if re.compile('\\d').search(i):
        re3 = re.compile('\\d').search(i).group()
    else:
        re3 = ''
    if len(re1) and len(re2) and len(re3) and len(i) >= 8:
        return '为强密码'
    else:
        return '不为强密码'


print(Password_Check('Syp123456'))

'''strip函数'''


def strip_imitation(str1, str2=''):
    if len(str2):
        if re.compile(str2).search(str1):
            return strip_imitation(re.compile(str2).sub('', str1))
        else:
            return '传入了错误的参数'
    else:
        if re.compile(r'^\s+').search(str1) and re.compile(r'\s$').search(str1):
            str1 = re.compile(r'^\s+').sub('', str1)
            str1 = re.compile(r'\s+$').sub('', str1)
            return str1
        if re.compile(r'^\s+').search(str1):
            return re.compile(r'^\s+').sub('', str1)
        if re.compile(r'\s$').search(str1):
            return re.compile(r'\s+$').sub('', str1)
        return str1


print(' hello ')
print(strip_imitation(' hello python', 'python'))



