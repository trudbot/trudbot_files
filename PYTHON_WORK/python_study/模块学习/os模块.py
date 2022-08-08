import os
# os 是与系统操作相关的模块

# cmd命令
# os.system('notepad')     打开记事本
# os.system('calc')     打开计算器


#      调用可执行文件
# os.startfile('C:\\Program Files\\Microsoft Office\\root\\Office16\\excel.exe')  启动excel

# print(os.getcwd())   返回当前的工作目录
'''os.getcwd()                                  返回当前的工作目录
   os.listdir(path)                             返回指定路径下的文件和目录信息
   os.mkdir(path)                               创建目录
   os.makedirs(path1,path2,,,)                  创建多级目录
   os.rmdir(path)                               删除文件夹（该文件夹必须为空，其中没有任何文件和文件夹）
   os.removedirs(path1,path2,path3,,,)          删除多级目录
   os.chdir(path)                               将path设为当前工作目录
   os.unlink(path)                              删除路径处的文件  '''
'''
遍历目录树
os.walk(path）
在一个for循环语句中使用os.walk()函数，遍历目录树
os.walk()在循环的每次迭代中，返回3个值：
1．当前文件夹的绝对路径
2．当前文件夹中子文件夹的字符串的列表。
3．当前文件夹中所有文件的字符串的列表。
'''
print(os.path.abspath('.'))
print(os.path.split(os.path.abspath('.')))
# os.unlink('D:\PYTHON_WORK\\fontpackage')
# os.rmdir('D:\PYTHON_WORK\\fontpackage')
for a, b, c in os.walk('D:\PYTHON_WORK'):
    print(a, b, c)








