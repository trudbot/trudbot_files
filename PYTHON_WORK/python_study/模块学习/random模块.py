import random

'''random.randrange()'''
# random.randrange(0, 100, 3)  返回[1,100)范围内的随机数整数，不包括100,步长为3

'''random.randint()'''
# random.randint(0, 100)    返回[1, 100]范围内的随机整数，包括100

'''random.random()'''
# random.random()   返回[0, 1)范围内随机浮点数,不包括1

'''random.choice()'''
print(random.choice([1, 2, 3]))  # 在给定容器中随机选择一个元素
print(random.choice('python'))

'''random.shuffle()'''
i = [1, 2, 3, 4]
random.shuffle(i)  # 对序列进行随机排序
print(i)

'''random.sample()'''
print(random.sample(i, 2))  # 返回在指定序列中抽取指定数量且不重复元素所形成的新序列。

'''random.uniform()'''
print(random.uniform(1.5, 2.5))  # 获取[1.5~2.5]之间的浮点数

'''random.seed(self, a=None, version=2)'''
# seed() 方法用于初始化随机数生成器，在【调用其他方法之前使用】，以实现随机相同的数值。
# a: 表示需要指定的种子，如果未提供 a 或者 a=None，则使用系统时间作为种子。种子相同时即可随机生成相同的数值。
# version: 默认值为2，如果参数 a 为整数将不计较参数 version 对应的值是否相同，如果参数 a 为字符类型，此时需要参数 version 对应的值相同。
random.seed(a=1)
random_num = random.random()
print(random_num)
random.seed(a=1)
print(random.random())
random.gauss()
