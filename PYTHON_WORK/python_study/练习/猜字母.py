"""猜字母（字符处理问题）
题目：

把abcd....s共19个字母组成的序列重复拼接106次，得到长度为2014的串。

接下来删除第1个字母（即开头的字母a），以及第3个，第5个等所有奇数位置的字符。

得到的新串再进行删除奇数位置字母的动作。如此下去，最后只剩下一个字母，请写出该字母。"""
string = 'abcdefghijklmnopqrs'
strings = ''
for i in range(106):
    strings = strings + string
while len(strings) != 1:
    num = 0

    lit = list(strings)
    for i in range(0, len(strings), 2):
        del lit[i - num]
        num += 1
    strings = ''
    for i in lit:
        strings = strings + i
print(strings)  # q
