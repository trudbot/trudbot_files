import time


def f1(n: int):
    res = []
    for i in range(2, n+1):
        count = 0
        for j in range(1, i+1):
            if i % j == 0:
                count += 1
        if count == 2:
            res.append(i)
    return res


def f2(n: int):
    res = []
    for i in range(2, n+1):
        for j in range(2, i+1):
            if i == j:
                res.append(i)
            if i % j == 0:
                break
    return res


def f3(n: int):
    res = []
    for i in range(2, n+1):
        for j in res:
            if i % j == 0:
                break
        else:  # python特性，只有在for循环把所有值都遍历完后，else中语句才会执行
            res.append(i)
    return res


time1 = time.time()
f1(10000)
time2 = time.time()
print("f1:{}".format(time2-time1))  # f1:2.6391661167144775
print("---------------")
time3 = time.time()
f2(10000)
time4 = time.time()
print("f2:{}".format(time4-time3))  # f2:0.43380022048950195
print("----------------")
time5 = time.time()
f3(10000)
time6 = time.time()
print("f3: {}".format(time6-time5))   # f3: 0.057845354080200195
