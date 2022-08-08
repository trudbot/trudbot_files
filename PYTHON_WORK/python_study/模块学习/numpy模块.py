import numpy as np
import random

'''
numpy:
NumPy是一个开源的Python科学计算基础库,包含:
• 一个强大的N维数组对象 ndarray（具有进行矢量算术运算及复杂广播能力）
• 广播功能函数
• 整合C/C++/Fortran代码的工具
• 线性代数、傅里叶变换、随机数生成等功能
NumPy是SciPy、Pandas等数据处理或科学计算库的基础'''
a = np.array([1, 3, 5])  # 由列表创建一个数组
b = np.array([1, 2, 3])
print(a)
print(type(a))  # <class 'numpy.ndarray'>
print(a + b)
c = np.array(range(10))
print(c)
d = np.arange(10)  # 快速创建一个数组, [0 1 2 3 4 5 6 7 8 9]
# np.arange(a, b, c) = np.array(range(a, b, c))
print(d)
e = np.arange(1, 10, 3)  # [1 4 7]
print(e)
print(e.dtype)  # dtype属性返回数组中数据的数据类型，NumPy 支持比 Python 更多种类的数值类型, 如int64 float64
f = np.arange(4, dtype=float)  # dtype属性指定数据类型
print(f, f.dtype)
g = np.array([1, 0, 0, 1], dtype=bool)
print(g)  # [ True False False  True]
h = g.astype('int8')  # 改变数组中数据的类型， 返回一个新数组
print(h, h.dtype)  # [1 0 0 1] int8
i = np.array([random.random() for m in range(10)])
print(i, i.dtype)
print(i.shape)  # (10,) 为一维数组，10为元素个数
j = np.round(i, 2)  # 保留两位小数
print(j)
k = np.zeros(10)  # 创建全为0的数组， 传入int or tuple of ints表示形状
print(k)
n = np.ones((3, 4))
print(n)  # [[1. 1. 1. 1.]
#            [1. 1. 1. 1.]
#            [1. 1. 1. 1.]]
print(n.shape)  # (3, 4) 二维数组，三行四列(真实含义为此数组中有三个列表，每个列表有四个元素)
# 数组的shape中有几个值，数组就为几维
n.shape = (2, 6)  # 改变原数组的形状
print(n)  # [[1. 1. 1. 1. 1. 1.]
#            [1. 1. 1. 1. 1. 1.]]
o = n.reshape(12,)  # 改变数组的形状, 返回新数组
print(o)  # [1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1.]
print(o.ndim)  # 1 , 返回数组的维度数
p = o.reshape((4, 3))

print(p)  # [[1. 1. 1.]
#            [1. 1. 1.]
#            [1. 1. 1.]
#            [1. 1. 1.]]
print(p.flatten())  # 将数组展开成一维数组 [1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1.]
print(p.ravel())  # [1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1. 1.]
p.ravel()[4] = 2
print(p)  # [[1. 1. 1.]
#            [1. 2. 1.]
#            [1. 1. 1.]
#            [1. 1. 1.]]
# flatten 和ravel两者的区别在于返回拷贝（copy）还是返回视图（view），numpy.flatten()返回一份拷贝，对拷贝所做的修改不会影响（reflects）原始矩阵
# 而numpy.ravel()返回的是视图（view，也颇有几分C/C++引用reference的意味），会影响（reflects）原始矩阵。

print(p.flatten().size)  # 返回数组元素个数
print(p.flatten() + 1)  # [2. 2. 2. 2. 2. 2. 2. 2. 2. 2. 2. 2.] numpy的广播机制
print(p.flatten() < 2)  # [ True  True  True  True  True  True  True  True  True  True  True  True]
# print(np.arange(10)/0)  --> [nan inf inf inf inf inf inf inf inf inf]  nan:not a number  inf:infinite 无穷
print(type(np.nan), type(np.inf))   # <class 'float'>  <class 'float'>
t = np.arange(11).astype(float)
t[0] = np.nan  # 为数组赋值nan或inf的方法
print(t)  # [nan  1.  2.  3.  4.  5.  6.  7.  8.  9. 10.]
print(p.flatten()+np.arange(12))  # 若相同形状的数组进行计算， 则对应位置的元素分别进行计算
q = np.arange(12).reshape(3, 4)
# q:[[ 0  1  2  3]
#    [ 4  5  6  7]
#    [ 8  9 10 11]]
r1 = np.array([1, 1, 1, 1])
# r1:[1. 1. 1. 1.]
r2 = np.array([[1], [1], [1]])
# r2:[[1]
#     [1]
#     [1]]
result1 = q-r1
result2 = q-r2
print(result1)
print(result2)
# result1:[[-1  0  1  2]  因为q的每一行都与r1的形状相同，所以q的每一行都与r1进行了相减计算
#          [ 3  4  5  6]
#          [ 7  8  9 10]]
# result2:[[-1  0  1  2]  因为q的每一列都与r2的形状相同，所以q的每一列都与r2进行了相减计算
#          [ 3  4  5  6]
#          [ 7  8  9 10]]

'''numpy读取数据'''
# np.loadtxt(fname,dtype=np.float,delimiter=None,skiprows=0,usecols=None,unpack=False)
# fname:文件、字符串或产生器
# dtype:读入数据的数据类型，默认为float
# delimiter：每个应被读入数据之间的分隔字符串
# skiprows：跳过前x行，默认为0
# 读取指定的列，索引，元组类型
# unpack:unpack就是矩阵中“转置”（将数据元素的行标和列标互换）的效果，默认False，指定"unpack=True"实施转置效果

# 对数组转置的其他方法
print(result1.transpose())  # [[-1  3  7]
#                              [ 0  4  8]
#                              [ 1  5  9]
#                              [ 2  6 10]]
# ndarry.transpose = ndarry.T
# ndarry.swapaxes(1, 0)  把轴从（0, 1)变为（1， 0），相当于反转轴


'''numpy索引和切片'''
# ndarray[行数，列数]
a = np.arange(12)
print(a)  # [ 0  1  2  3  4  5  6  7  8  9 10 11]
print(a[0])  # 0

a = np.arange(12).reshape(3, 4)
# 基本切片
print(a)  # [[ 0  1  2  3]
#            [ 4  5  6  7]
#            [ 8  9 10 11]]
print(a[0])  # [0 1 2 3]
print(a[1:])  # [[ 4  5  6  7]
#                [ 8  9 10 11]]
print(a[::2])  # [[ 0  1  2  3]
#                 [ 8  9 10 11]]
# 取不连续的行
print(a[[1, 2]])  # [[ 4  5  6  7]
#                    [ 8  9 10 11]]
# 取单独元素
print(a[0, 0])  # 0
print(type(a[0, 0]))  # <class 'numpy.int32'>
# 取单独列
print(a[:, 1])  # [1 5 9]
# 取多行多列
print(a[1:3, 1:3])  # [[ 5  6]     选取1、2行，1、2列交集的数据
#                      [ 9 10]]
print(a[[0, 2, 2], [0, 2, 0]])  # 取出[0, 0]、[2, 2]和[2, 0]元素    [ 0 10  8]
# 条件取元素
print(a[a > 5])  # [ 6  7  8  9 10 11]
t = np.array([1, 2, 3, 4])
t2 = np.array([True, False, True, False])
print(t[t2])  # [1 3]

'''numpy中数值的修改'''
# 单个元素直接赋值
a[0, 0] = 100
print(a)  # [[100   1   2   3]
#            [  4   5   6   7]
#            [  8   9  10  11]]
a[a > 5] = 5
print(a)  # [[5 1 2 3]
#            [4 5 5 5]
#            [5 5 5 5]]
# numpy的三元运算符
print(np.where(a == 5, 1, 0))  # [[1 0 0 0]    当a中的值为5时被替换为1，否则替换为0
#                                 [0 1 1 1]
#                                 [1 1 1 1]]
# ndarray.clip(a, b)   数组中小于a的替换为a, 大于b的替换为b（nan不会被替换）
print(np.arange(11).clip(3, 7))  # [3 3 3 3 4 5 6 7 7 7 7]


'''numpy中的nan和inf'''
# nan(NAN,Nan):not a number表示不是一个数字
# 什么时候numpy中会出现nan：
#  当我们读取本地的文件为float的时候，如果有缺失，就会出现nan
#  当做了一个不合适的计算的时候(比如无穷大(inf)减去无穷大)
#  nan和任何值进行计算的结果都是nan

# inf(-inf,inf):infinity,inf表示正无穷，-inf表示负无穷
# 什么时候回出现inf包括（-inf，+inf）:
# 比如一个数字除以0，（python中直接会报错，numpy中是一个inf或者-inf）
print(np.nan == np.nan)  # False
a = np.arange(10).astype(float)
a[1] = np.nan
print(a)  # [ 0. nan  2.  3.  4.  5.  6.  7.  8.  9.]
print(np.count_nonzero(a))  # 得到数组中不为零的元素个数 9
print(a != a)  # [False  True False False False False False False False False]
print(np.count_nonzero(a != a))  # 1 , 利用nan!=nan的特性和count——nonzero方法可得到数组中nan的个数
print(np.isnan(a))  # [False  True False False False False False False False False]   同a!=a ,nan返回true否则为false
a[np.isnan(a)] = 0  # 将a中的nan替换为0
print(a)  # [0. 0. 2. 3. 4. 5. 6. 7. 8. 9.]


'''常用统计函数'''
# 对于一个二维数组
# axis=0时，对每一列进行计算，返回一维数组
# axis=1时，对每一行进行计算，返回一维数组
a = np.arange(20).reshape(4, 5)
#                                  [[ 0  1  2  3  4]
#                                   [ 5  6  7  8  9]
#                                   [10 11 12 13 14]
#                                   [15 16 17 18 19]]
print(a)

# 求和：t.sum(axis=None)
# 不传入axis时，默认求所有数据的和
print(a.sum())  # 190
print(a.sum(axis=0))  # [30 34 38 42 46]
print(a.sum(axis=1))  # [10 35 60 85]

# 均值：t.mean(a,axis=None)  受离群点的影响较大
print(a.mean())  # 9.5

# 中值(中位数)：np.median(t,axis=None)
print(np.median(a))  # 9.5

# 最大值：t.max(axis=None)
print(a.max())  # 19

# 最小值：t.min(axis=None)
print(a.min())  # 0

# 极差：np.ptp(t,axis=None) 即数据中最大值和最小值之差
print(np.ptp(a))  # 19

# 标准差：t.std(axis=None)  标准差是一组数据平均值分散程度的一种度量,标准差越小数据越聚拢与平均值、越稳定
print(a.std())  # 5.766281297335398


'''函数：将nan替换成所在行或列的平均值'''


def remove_nan(array, axis=3):
    if len(array.shape) == 1:
        array[np.isnan(array)] = np.round(array[array == array].mean(), 2)
        return array

    elif len(array.shape) == 2:

        if axis == 3:
            array[np.isnan(array)] = np.round(array(array == array).mean())

        elif axis == 0:
            for _i in range(array.shape[1]):
                array[:, _i][np.isnan(array[:, _i])] = np.round(array[:, _i][array[:, _i] == array[:, _i]].mean())

        elif axis == 1:

            for _i in range(array.shape[0]):
                array[_i][np.isnan(array[_i])] = np.round(array[_i][array[_i] == array[_i]].mean())

        else:
            print('传入错误的参数')

        return array

    else:
        print('超出功能范围')


'''NumPy - 数组上的迭代'''
for i in np.nditer(np.arange(24).reshape(6, 4)):
    print(i, end=' ')  # 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
print(' ')
'''数组的拼接'''
a = np.array([1, 2, 3, 4])
b = np.array([3, 4, 5, 6])
print(np.vstack((a, b)))  # [[1 2 3 4]   竖直拼接
#                            [3 4 5 6]]
print(np.hstack((a, b)))  # [1 2 3 4 3 4 5 6]  水平拼接
'''行列交换'''
a = np.arange(12).reshape(2, 6)
print(a)  # [[ 0  1  2  3  4  5]
#            [ 6  7  8  9 10 11]]
a[[0, 1], :] = a[[1, 0], :]
print(a)  # [[ 6  7  8  9 10 11]
#            [ 0  1  2  3  4  5]]

'''numpy生成随机数'''
b.cumsum

# np.random.rand()生成均匀分布的随机数，范围为0~1
# np.random.randn()生成标准正态分布随机数组成的数组（mean=0, sigma=1)
# 传入的参数表示数组的形状
# 如np.random.rand(3, 4)表示生成一个三行四列的随机数数组


# np.random.randint(low, high, (shape), dtype)从给出的上下限[low, high)中随机选取整数组成指定形状的数组
# np.random.uniform(low, high, (shape)) 从上下限中选取具有均匀分布特征的数据
# 等等

'''数组的轴，axis'''
# 二维数组，y轴为1，x轴为0
# 二维数组的shape中第一个即为y轴的索引，第二个为x轴索引
# 三位数组，

