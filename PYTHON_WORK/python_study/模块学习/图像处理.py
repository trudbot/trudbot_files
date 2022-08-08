import PIL
from PIL import ImageColor
from PIL import Image
'''Pillow 的模块名称是PIL，这保持与老模块Python Imaging Library 向后兼容，
这就是为什么必须from PIL importImage，而不是from Pillow import Image。
由于Pillow 的创建者设计Pillow 模块的方式，你必须使用from PIL import Image 形式的import 语句，而不是简单地import PIL。'''

'''RGBA值：一组数字，指定顔色中的红、绿、蓝和alpha（透明度）的值'''
print(PIL.ImageColor.getcolor('red', 'RGBA'))  # 传入颜色名称、颜色模式（RGBA）,返回颜色的RGBA值

'''像素的坐标(同pygame)'''
# 同pygame，坐标原点为图像坐上角，向右为x轴，向下为y轴
# 许多Pillow 函数和方法需要一个矩形元组参数，用于确定一个矩形（x, y, length, width)
'''图像操作'''
demo_image = PIL.Image.open('D:\PYTHON_WORK\imagepackage\\5efa9e94032b8.jpg')  # 加载图像
print(type(demo_image))  # 对象类型为JpegImage
print(demo_image.size)  # 得到图像的分辨率
print(demo_image.filename)  # 得到图像的文件名称
print(demo_image.format)  # 得到图像格式名
print(demo_image.format_description)  # 更详细的格式名
demo_image.save('awaa.jpg')  # 将操作后的图像以传入文件名重新存储

demo_image_2 = PIL.Image.new('RGBA', (1920, 1080), 'red')  # 新建一个image对象；传入颜色模式，分辨率，背景颜色（标准颜色名或颜色RGBA值）
new_demo_image = demo_image_2.crop((0, 0, 960, 540))  # 裁剪一个图像。传入一个矩形范围，将原图像在矩形范围内的部分裁剪下来，返回一个新image对象
new_demo_image.save('new_image.png')
demo_image_3 = PIL.Image.new('RGBA', (400, 400), 'blue')
demo_image_2.paste(demo_image_3, (0, 0))  # 将image3粘贴到image2的原点处（直接修改image2对象）
rotate_image = demo_image_2.rotate(30)  # 将图像旋转传入的度数，返回新对象
rotate_image.save('rotate_image.png')
demo_image_2.save('demo_image.png')
