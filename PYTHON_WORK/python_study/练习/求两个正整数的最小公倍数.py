def f(a, b):
    for i in range(max(a, b), a*b+1):  # 两个数的最小公倍数介于较大的那个数和两数乘积之间
        if i/a == i//a and i/b == i//b:
            return i


print(f(4, 6))
print(f(5, 15))
print(f(6, 7))
