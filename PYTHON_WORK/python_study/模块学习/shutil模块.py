'''
shutil（或称为shell 工具）模块中包含一些函数，让你在Python 程序中复制、移动、改名和删除文件。

1, 复制文件和文件夹
shutil.copy(source, destination)
将路径source 处的文件复制到路径destination处的文件夹（source 和destination 都是字符串）。
如果destination 是一个文件名，它将作为被复制文件的新名字
该函数返回一个字符串，表示被复制文件的路径。
shutil.copytree(source, destination)
shutil.copy()将复制一个文件，shutil.copytree()将复制整个文件夹，以及它包含的文件夹和文件。

2,文件和文件夹的移动与改名
shutil.move(source, destination)
将路径source 处的文件夹移动到路径destination，并返回新位置的绝对路径的字符串。
如果destination 指向一个文件夹，source 文件将移动到destination 中，并保持原来的文件名
若destination为文件名， 则文件被移动后将被改为此文件名(路径中的最后一个在计算机中找不到，就会被判定为文件名)
3,永久删除文件和文件夹
shutil.rmtree(path)
将删除path 处的文件夹，它包含的所有文件和文件夹都会被删除。



'''
import shutil

# shutil.copy('D:\PYTHON_WORK\music\yinxiao424.mp3', 'D:\PYTHON_WORK\python_study')
# shutil.move('D:\PYTHON_WORK\python_study\yinxiao424.mp3', 'D:\PYTHON_WORK\music')
shutil.rmtree('D:\PYTHON_WORK\\fontpackage')