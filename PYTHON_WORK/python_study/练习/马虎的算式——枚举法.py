""" 题目：小明是个急性子，上小学的时候经常抄错题目。有一次老师出的36X495=？他却抄成了396X45？但结果却很戏剧性，他的答案是正确的！！
因为36 * 495= 396 * 45=17280
类似这样的巧合可能还有很多，比如27 * 594=297 * 54。
假设a b c d e代表1~9不同的五个数字（注意是各不相同的数字，且不含0），能满足ab*cde=abd*ce
这样的格式的式子总共有多少种？"""
name = []
lit = []
for a in range(1, 10):
    for b in range(1, 10):
        for c in range(1, 10):
            for d in range(1, 10):
                for e in range(1, 10):
                    if len({a, b, c, d, e}) == 5:
                        num = int(str(a)+str(b))*int(str(c)+str(d)+str(e))
                        string = str(a)+str(b)+'*'+str(c)+str(d)+str(e)
                        if num not in lit:
                            name.append(string)
                            lit.append(num)
                        else:
                            v = list(name[lit.index(num)])
                            v.remove('*')
                            v = {int(i) for i in v}
                            if {a, b, c, d, e} == set(v) and string != name[lit.index(num)]:
                                print(string + '=' + name[lit.index(num)])
