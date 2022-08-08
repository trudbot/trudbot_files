
'''
有两种方法指定一个文件路径。
• “绝对路径”，总是从根文件夹开始。
• “相对路径”，它相对于程序的当前工作目录。

“纯文本文件”只包含基本文本字符，不包含字体、大小和颜色信息。带有.txt 扩展名的文本文件，以及带有.py 扩展名的Python 脚本文件，都是纯文本文件的例子。
“二进制文件”是所有其他文件类型，诸如字处理文档、PDF、图像、电子表格和可执行程序。如果用Notepad 或TextEdit 打开一个二进制文件，它看起来就像乱码
'''
'''
文件读写的步骤：
1．调用open()函数，返回一个File 对象。
file_name = open('file_path', 'mode')  #File 对象代表计算机中的一个文件
常用mode:
r:只读模式
w:只写模式
a:添加模式

2．调用File 对象的read()或write()方法。
file.read():将整个文件的内容读取为一个字符串值
file.readlines():返回以文件每一行为元素的列表
file.write(content):将内容写入文件
3．调用File 对象的close()方法，关闭该文件
'''
file = open('text.txt', 'w')
file.write('hello world')
file.close()