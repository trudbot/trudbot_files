"""    题目：

        观察下面的加法算式：

               祥    瑞    生   辉

  +            三    羊    献   瑞

          ————————————————————————

        三     羊     生   瑞    气
"""
'''相同的汉字代表相同的数字， 不同的汉字所代表的数字不同'''
'''求三羊献瑞'所代表的四位数字'''
'''答案唯一'''

# 三 —— a
# 羊 —— b
# 献 —— c
# 瑞 —— d
# 祥 —— e
# 生 —— f
# 辉 —— g
for a in range(1, 10):
    for b in range(10):
        for c in range(10):
            for d in range(10):
                for e in range(1, 10):
                    for f in range(10):
                        for g in range(10):
                            if len({a, b, c, d, e, f, g}) == 7:
                                num1 = int(str(e)+str(d)+str(f)+str(g))
                                num2 = int(str(a)+str(b)+str(c)+str(d))
                                result = num2+num1
                                lit = list(str(result))
                                if a == int(lit[0]) \
                                        and b == int(lit[1]) \
                                        and f == int(lit[2]) \
                                        and d == int(lit[3]) \
                                        and int(lit[4]) not in [a, b, c, d, e, f, g]:
                                    print(a, b, c, d, e, f, g)
                                    print(num1)
                                    print(num2)
                                    exit()
'''
这是一道非常非常经典的蓝桥真题枚举问题。
最直接最暴力的方法就直接去写七个for循环分别将祥瑞生辉三羊献七个字枚举出来，再写一个判断答案是否符合要求的方法。
思路很简单，但是步骤写起来需要小心。但其实这里我想说的是这里其实是可以优化的，两个四位数相加得到一个五位数。
那么这个这个五位数的万位只可能是1，也就是三字其实就是1，既然祥加三得进位，三又是1，那么祥肯定就只能是9，进而再可得羊是0。
大家可以和上面我贴出的答案对比就能看出来。
这样其实我们的循环就少了几层了，但蓝桥杯做出答案才是目的，即使是7个for循环，但其实都是常数级的循环，瞬间就可以枚举出结果。
'''
