import os.path
'''
abspath(path)       获取文件或目录的绝对路径
join（path, name)   将目录与目录或文件名连接起来
splitext()          分离文件名与扩展名
basename(path)      返回最后一级文件名
dirname(path)       返回最后一级之前的路径
split(path)         将路径在最后一个反斜杠处分为两部分，返回所组成的元组
'''
path1 = os.path.abspath('os.path模块.py')
print(os.path.split(path1))
print(os.path.splitext(path1))
print(os.path.basename(path1))
path2 = os.path.basename(path1)
print(os.path.dirname(path1))
path3 = os.path.dirname(path1)
print(os.path.join(path3, path2))
print(os.path.isdir(path3))
print(os.path.split(path1))
'''
调用os.path.getsize(path)将返回path 参数中文件的字节数。
调用os.listdir(path)将返回文件名字符串的列表，包含path 参数中的每个文件
如果path 参数所指的文件或文件夹存在，调用os.path.exists(path)将返回True，否则返回False。
如果path 参数存在，并且是一个文件，调用os.path.isfile(path)将返回True，否则返回False。
如果path 参数存在，并且是一个文件夹，调用os.path.isdir(path)将返回True，否则返回False。
'''
print(os.path.getsize(os.path.abspath('.')))
print(os.listdir('.'))