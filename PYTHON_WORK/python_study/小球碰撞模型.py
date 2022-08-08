import pygame

pygame.init()  # 初始化

pygame.display.set_caption('demo game')  # 设置游戏标题

length = 600
width = 400
game_window = pygame.display.set_mode((length, width))  # 创建600*400的游戏窗口

# 填充背景颜色
game_window.fill((128, 128, 128))


import random
y_speed = 1
x_speed = 1
# print('x_speed为：\n{0}'.format(x_speed))
color = (0, 0, 0)
color1 = (0, 0, 0)
x = 1
x1 = random.randint(100, 600)
y1 = random.randint(100, 400)
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
a = False
while True:
    num += 1
    if num == 10000:
        num = 0
        # 球1
        if ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5 <= 2 * radius:  # 对碰撞进行定义并做出反应
            if i2 == 0:
                x_speed = x_speed * -1 * random.randint(1, 3)  # 使小球碰撞后的情况更加多样化
                # print(x_speed)
                y_speed = y_speed * -1 * random.randint(1, 3)
                color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
                i2 = 1  # 防止抽搐小球的出现
        else:
            i2 = 0
        if y + radius >= width:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            y_speed = y_speed * -1
        if y <= radius:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            y_speed = y_speed * -1
        if x + radius >= length:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            x_speed = x_speed * -1
            # print(x_speed)
        if x <= radius:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            x_speed = x_speed * -1
            # print(x_speed)
        if x_speed >= 7:  # 保证速度在一定范围
            x_speed = 3
        if y_speed >= 7:
            y_speed = 3
        if 0 < x_speed < 1:
            x_speed += 1

        x += x_speed
        y += y_speed
        if x < radius:
            x = radius
        if x + radius > length:
            x = length - radius
        if y < radius:
            y = radius
        if y + radius > width:
            y = width - radius

        # 球2
        if ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5 <= 2 * radius:
            if i1 == 0:
                x1_speed = x1_speed * -1 * random.randint(1, 3)
                y1_speed = y1_speed * -1 * random.randint(1, 3)
                color1 = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
                i1 = 1
        else:
            i1 = 0
        if y1 + radius >= width:
            color1 = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            y1_speed = y1_speed * -1
        if y1 <= radius:
            color1 = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            y1_speed = y1_speed * -1
        if x1 + radius >= length:
            color1 = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            x1_speed = x1_speed * -1
        if x1 <= radius:
            color1 = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            x1_speed = x1_speed * -1
        if x1_speed >= 10:  # 防超速
            x1_speed = 3
        if y1_speed >= 10:
            y1_speed = 3

        x1 += x1_speed
        y1 += y1_speed
        if x1 < radius:
            x1 = radius
        if x1 + radius > length:
            x1 = length - radius
        if y1 < radius:
            y1 = radius
        if y1 + radius > width:
            y1 = width - radius

        if ((x - x1) ** 2 + (y - y1) ** 2) ** 0.5 <= 2 * radius and (x_speed, y_speed) == (x1_speed, y1_speed):
            x1_speed = x1_speed * -1 * random.randint(1, 3)
            y1_speed = y1_speed * -1 * random.randint(1, 3)
            x_speed = x_speed * -1 * random.randint(1, 3)
            y_speed = y_speed * -1 * random.randint(1, 3)

        game_window.fill((128, 128, 128))
        pygame.draw.circle(game_window, color1, (x1, y1), radius)
        pygame.draw.circle(game_window, color, (x, y), radius)
        pygame.display.update()

    '''-------------------------对事件的检测及反应------------------'''
    for event in pygame.event.get():  # 检测事件

        if event.type == pygame.QUIT:  # 若发生QUIT事件（点击窗口关闭按钮），则执行执行体
            a = True
            break  # 退出循环,即结束程序， 也可直接用exit（）

    if a:
        break
