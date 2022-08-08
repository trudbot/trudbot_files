import pygame
from random import randint
pygame.init()  # 初始化

pygame.display.set_caption('demo game')  # 设置游戏标题

length = 600
width = 400
game_window = pygame.display.set_mode((length, width))  # 创建600*400的游戏窗口

# 填充背景颜色
game_window.fill((255, 255, 255))  # fill((R, G, B))

'''----------------------图片-----------------------------------'''

image = pygame.image.load('imagepackage/OIP-C.jfif')  # 加载图片

# 对图片进行旋转和缩放
new_image1 = pygame.transform.scale(image, (length, width))  # scale(图片对象，大小（length,width)),对图片进行变形缩放
new_image2 = pygame.transform.rotozoom(image, 90, 0.5)  # rotozoom(图片对象，旋转角度（逆时针），缩放比例），缩放按比例，不发生形变

# w, h = image.get_size()  # 获取图片大小信息
# print(w, h)

# 渲染图片（把图片放到窗口）
game_window.blit(new_image1, (0, 0))  # bilt(渲染对象，坐标（x,y)），以左上角为坐标原点，以图片的左上角为定位点，，横轴向左为x正轴，纵轴向下为y正轴
# game_window.blit(new_image2, (0, 200))

'''---------------------------文字------------------------------------'''

font = pygame.font.Font('fontpackage/FZZJ-HBYBJW.TTF', 30)  # 创建字体对象，，font.Font('路径’，字号）

text = font.render('hello pygame', True, (0, 0, 255), (255, 255, 0))  # 创建文字对象 render(文本内容，是否平滑，文字颜色，背景颜色)

# 对文字对象的操作（与图片对象一样）
w, h = text.get_size()
# print(w, h)

# 缩放和旋转--同图片操作

game_window.blit(text, ((length - w) / 2, 0))  # 渲染到窗口

'''-----------------------------画图-----------------------------------------------'''
#
# '''画一条线，draw.line（操作对象，颜色，起点坐标，终点坐标，线宽（默认为1））'''
# pygame.draw.line(game_window, (0, 255, 0), ((length-w)/2, 34), (length/2+w/2, 34), 1)
#
# '''画连接着的多条线'''
# # 点列表=[点1，点2，，，点n]
# # lines(操作对象，颜色，是否首尾相连，点列表，线宽（1））
# points = [((length-w)/2, 100), (length/2+w/2, 100), (length/2+w/2, 300), (length/2-w/2, length/2)]
# pygame.draw.lines(game_window, (0, 0, 255), True, points)
#
# '''画圆'''
# # circle(操作对象，颜色，圆心坐标，半径，线宽（默认为0，线宽=0时为填充圆，不为0时为圆环）)
# pygame.draw.circle(game_window, (255, 0, 0), (300, 200), w/2)
#
# '''画矩形'''
# # rect(操作对象，颜色，矩形范围（x,y,length,width）,线宽（同上）)
# pygame.draw.rect(game_window, (120, 120, 120), (200, 50, 200, 20), 1)
#
# '''画椭圆'''
# # ellipse(操作对象，颜色，矩形范围（x,y,length,width）,线宽（同上）),参数与矩形完全相同，原理为画一个矩形的完全内切椭圆
# pygame.draw.ellipse(game_window, (120, 255, 120), (200, 50, 200, 20))
#
# '''画椭圆弧线'''
# # arc(操作对象，颜色，矩形范围，起始弧度，终止弧度，线宽（1）)       标准弧度带pi       逆时针从 起始弧度对应位置 画到 终止弧度对应位置
# pygame.draw.arc(game_window, (0, 0, 255), (200, 50, 200, 20), 0, 2, 3)
#
# '''画 等等'''


'''--------------------------------刷新-------------------------------------------------'''

# 只要改变了窗口的内容，都要刷新后才能应用到窗口
# pygame.display.flip()  第一次刷新
# pygame.display.update()   非第一次刷新
pygame.display.flip()

'''--------------------------------------------------------------------------------------'''

y_speed = 1
x_speed = 1
# print('x_speed为：\n{0}'.format(x_speed))
color = (0, 0, 0)
color1 = (0, 0, 0)
x = 1
x1 = randint(100, 600)
y1 = randint(100, 400)
if x1 >= 300:
    x1_speed = -1
else:
    x1_speed = 1
if y1 > 200:
    y1_speed = -1
else:
    y1_speed = 1
y = 1
num = 0
radius = 55
i1 = 0
i2 = 0
count = 0
a = False
while True:  # 让游戏保持运行状态（ game loop  游戏循环）
    '''------------------------动画------------------------------------------'''
    num += 1
    # if num == 100000:  # 引入变量num可以实现小球速度的控制，如左，执行while循环十万次小球动一次（我电脑太厉害了吧）
    #     num=0
    #     pygame.draw.circle(game_window, (255, 255, 255), (300, 19 + i), 20)  # 在画下一个圆之前把前一个圆用白色覆盖，当背景为白色时，就能实现视觉上的小球掉落
    #     i+=1
    #     pygame.draw.circle(game_window, (0, 255, 0), (300, 20+i), 20)
    #     pygame.display.update()

    # if num == 10000:  # 实现圆的缩放
    #     num = 0
    #     i += 1
    #     pygame.draw.circle(game_window, (0, 0, 0), (300, 200), i) # 从中心扩散性放大的黑圆
    #     pygame.display.update()
    '''反弹的实现'''
    # if num == 10000:
    #     num = 0
    #
    #     if radius <= 99:
    #         radius += 1
    #     i += y_speed
    #     game_window.blit(new_image1, (0, 0))
    #     game_window.blit(text, ((length - w) / 2, 0))
    #
    #     if i+radius <= 400:
    #         pygame.draw.circle(game_window, color, (300, i), radius)
    #         pygame.display.update()
    #
    #     else:
    #         color = (0, 0, 255)
    #         y_speed = y_speed*-1
    #
    #     if i <= radius:
    #         color = (0, 255, 0)
    #         y_speed = y_speed*-1
    '''小球在框内的无限反弹'''
    # if num == 10000:
    #     num = 0
    #     if y >= 400:
    #         color = (0, 255, 0)
    #         y_speed = 2*y_speed * -1
    #     if y <= 0:
    #         color = (255, 0, 0)
    #         y_speed = (y_speed * -1)/2
    #     if x >= 600:
    #         color = (0, 0, 255)
    #         x_speed = 2*x_speed * -1
    #     if x <= 0:
    #         color = (255, 255, 255)
    #         x_speed = (x_speed * -1)/2
    #     x += x_speed
    #     y += y_speed
    #     game_window.blit(new_image1, (0, 0))
    #     game_window.blit(text, ((length - w) / 2, 0))
    #     pygame.draw.circle(game_window, color, (x, y), radius)
    #     pygame.display.update()
    '''框内多球碰撞模型'''
    # if num == 10000:
    #     num = 0
    #     # 球1
    #     if ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5 <= 2 * radius:  # 对碰撞进行定义并做出反应
    #         if i2 == 0:
    #             x_speed = x_speed * -1 * randint(1, 3)  # 使小球碰撞后的情况更加多样化
    #             # print(x_speed)
    #             y_speed = y_speed * -1 * randint(1, 3)
    #             color = (255, 0, 255)
    #             i2 = 1  # 防止抽搐小球的出现
    #     else:
    #         i2 = 0
    #     if y + radius >= width:
    #         color = (0, 255, 0)
    #         y_speed = y_speed * -1
    #     if y <= radius:
    #         color = (255, 0, 0)
    #         y_speed = y_speed * -1
    #     if x + radius >= length:
    #         color = (0, 0, 255)
    #         x_speed = x_speed * -1
    #         # print(x_speed)
    #     if x <= radius:
    #         color = (255, 255, 255)
    #         x_speed = x_speed * -1
    #         # print(x_speed)
    #     if x_speed >= 7:  # 保证速度在一定范围
    #         x_speed = 3
    #     if y_speed >= 7:
    #         y_speed = 3
    #     if 0 < x_speed < 1:
    #         x_speed += 1
    #
    #     x += x_speed
    #     y += y_speed
    #     if x < radius:
    #         x = radius
    #     if x + radius > length:
    #         x = length - radius
    #     if y < radius:
    #         y = radius
    #     if y + radius > width:
    #         y = width - radius
    #
    #     # 球2
    #     if ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5 <= 2 * radius:
    #         if i1 == 0:
    #             x1_speed = x1_speed * -1 * randint(1, 3)
    #             y1_speed = y1_speed * -1 * randint(1, 3)
    #             color1 = (1, 255, 255)
    #             i1 = 1
    #     else:
    #         i1 = 0
    #     if y1 + radius >= width:
    #         color1 = (0, 255, 0)
    #         y1_speed = y1_speed * -1
    #     if y1 <= radius:
    #         color1 = (255, 0, 0)
    #         y1_speed = y1_speed * -1
    #     if x1 + radius >= length:
    #         color1 = (0, 0, 255)
    #         x1_speed = x1_speed * -1
    #     if x1 <= radius:
    #         color1 = (255, 255, 255)
    #         x1_speed = x1_speed * -1
    #     if x1_speed >= 10:  # 防超速
    #         x1_speed = 3
    #     if y1_speed >= 10:
    #         y1_speed = 3
    #
    #     x1 += x1_speed
    #     y1 += y1_speed
    #     if x1 < radius:
    #         x1 = radius
    #     if x1 + radius > length:
    #         x1 = length - radius
    #     if y1 < radius:
    #         y1 = radius
    #     if y1 + radius > width:
    #         y1 = width - radius
    #
    #     if ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5 <= 2 * radius and (x_speed, y_speed) == (x1_speed, y1_speed):
    #         x1_speed = x1_speed * -1 * randint(1, 3)
    #         y1_speed = y1_speed * -1 * randint(1, 3)
    #         x_speed = x_speed * -1 * randint(1, 3)
    #         y_speed = y_speed * -1 * randint(1, 3)
    #
    #     game_window.blit(new_image1, (0, 0))
    #     game_window.blit(text, ((length - w) / 2, 0))
    #     pygame.draw.circle(game_window, color1, (x1, y1), radius)
    #     pygame.draw.circle(game_window, color, (x, y), radius)
    #     pygame.display.update()

    '''-------------------------对事件的检测及反应------------------'''
    for event in pygame.event.get():  # 检测事件
        count += 1
        # print(count)
        '''常见的数据类型
        QUIT---点击窗口关闭按钮
        
        1.鼠标事件
         MOUSEBUTTONDOWN---鼠标摁下（左右键都算）
         MOUSEBUTTONUP---鼠标弹起
         MOIUSEMDTION---鼠标移动
        2.键盘事件
         KEYDOWN---键盘按下
         KEYUP---键盘弹起
         键的检测：event.key   返回键的key值
         键盘上每个键都有自己的‘key’（ascll码值）
         
        '''

        if event.type == pygame.QUIT:  # 若发生QUIT事件（点击窗口关闭按钮），则执行执行体
            a = True
            break  # 退出循环,即结束程序， 也可直接用exit（）
        # 鼠标的位置属性----event.pos-----返回光标的位置坐标
        elif event.type == pygame.MOUSEBUTTONDOWN:
            print('鼠标摁下了')
            pygame.draw.circle(game_window, (255, 255, 255), event.pos, 50)
            pygame.display.update()
        # elif event.type == pygame.MOUSEBUTTONUP:
        #     print('鼠标弹起了')
        # elif event.type == pygame.MOUSEMOTION:
        #     print('鼠标移动了')
        elif event.type == pygame.KEYDOWN:
            print(event.key)

    if a:
        break
