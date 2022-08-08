from multiprocessing.dummy import Pool
import requests, time
def fx(a):
    return a**3

pool = Pool(4)  # 初始化线程池，参数为线程数
def fx(content):
    requests.get(content)

lit = []
# run = pool.map(fx, lit)  # map(函数名， 可迭代对象-元素作为函数参数）
# print(run)
# start = time.time()
# for i in range(100):
#     requests.get('https://baidu.com')
# one = time.time()
# for i in range(100):
#     lit.append('https://baidu.com')
# pool.map(fx, lit)
# two = time.time()
# print(one-start, two-one)
class A:
    pass
a= A()
if type(a) == A:
    print(1)

