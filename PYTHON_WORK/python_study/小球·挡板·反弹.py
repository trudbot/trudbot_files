import pygame
import random
import time

pygame.init()
pygame.mixer.init()

pygame.display.set_caption('demo game')
pygame.mixer.music.load("D:\PYTHON_WORK\music\Supercell Games - Season 6_ Golden Week 21 Menu.mp3")


image = pygame.image.load('D:\PYTHON_WORK\imagepackage\\5efa9e94032b8.jpg')
new_image = pygame.transform.rotozoom(image, 0, 0.5)
length, width = new_image.get_size()
print(length, width)
game_window = pygame.display.set_mode((length, width))
game_window.blit(new_image, (0, 0))


pygame.draw.circle(game_window, (0, 255, 0), (length/2, 7*width/8), width/8)
# print(length/2, 7*width/8)      480,,472.5
pygame.draw.rect(game_window, (255, 0, 0), (length-100, 0, 100, 50), 0)
font1 = pygame.font.Font('D:\PYTHON_WORK\python_study\模块学习\FZZJ-LongYTJW.TTF', 30)
font2 = pygame.font.Font('D:\PYTHON_WORK\python_study\模块学习\FZZJ-LongYTJW.TTF', 20)
font3 = pygame.font.Font('D:\PYTHON_WORK\python_study\模块学习\FZZJ-LongYTJW.TTF', 50)
text1 = font1.render('开始游戏', True, (255, 0, 0))
text2 = font2.render('退出游戏', True, (255, 255, 255))
text3 = font3.render('游戏失败', True, (255, 0, 0))
print(text3.get_size())
game_window.blit(text1, (415, 460))
game_window.blit(text2, (length-90, 15))
pygame.display.flip()
i = 0
while True:
    if not pygame.mixer.music.get_busy():
        pygame.mixer.music.play()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
        if event.type == pygame.MOUSEBUTTONUP:
            x, y = event.pos
            if length - 90 < x < length and 0 < y < 50:
                pygame.draw.rect(game_window, (128, 128, 128), (length - 100, 0, 100, 50), 0)
                text3 = font2.render('退出游戏', True, (255, 0, 0))
                game_window.blit(text3, (length-90, 15))
                pygame.display.update()
                exit()
            if ((x-480)**2 + (y-472.5)**2)**0.5 < width/8:
                i = 1
                game_window.blit(new_image, (0, 0))
                pygame.draw.rect(game_window, (255, 0, 0), (length - 100, 0, 100, 50), 0)
                game_window.blit(text2, (length - 90, 15))
                pygame.display.update()
                break

        if event.type == pygame.KEYUP:
            if event.key == 27:
                exit()
    if i == 1:
        break
r = 20
x = random.randint(r, length-r+1)
y = r
x_speed = random.choice([1, -1])
y_speed = 1
speed = 20
x2 = 420
color = (255, 255, 255)
pygame.draw.rect(game_window, (255, 0, 0), (x2, 3*width//4, 120, 30), 0)
pygame.display.update()
num = 0
while True:
    num += 1
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
        if event.type == pygame.MOUSEBUTTONUP:
            x1, y1 = event.pos
            if length - 90 < x1 < length and 0 < y1 < 50:
                pygame.draw.rect(game_window, (128, 128, 128), (length - 100, 0, 100, 50), 0)
                text3 = font2.render('退出游戏', True, (255, 0, 0))
                game_window.blit(text3, (length-90, 15))
                pygame.display.update()
                exit()
        if event.type == pygame.KEYUP:

            if event.key == 1073741904:
                x2 += -speed
                game_window.blit(new_image, (0, 0))
            if event.key == 1073741903:
                x2 += speed
                pygame.display.update()
        if event.type == pygame.KEYUP:
            if event.key == 27:
                exit()

    if x2 - 80 < x < x2 + 80 and y+r == 3 * width // 4:
        y_speed = y_speed * -1
    elif y + r >= width:
        game_window.blit(text3, (380, 243))
        pygame.display.update()
        pygame.mixer.stop()
        pygame.mixer.music.load("D:\PYTHON_WORK\music\Supercell Games - Lose.mp3")
        pygame.mixer.music.play()
        time.sleep(3)
        exit()
    else:
        if y < r:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            y_speed = y_speed * -1
        if x + r >= length:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            x_speed = x_speed * -1
        if x <= r:
            color = (random.randint(0, 256), random.randint(0, 256), random.randint(0, 256))
            x_speed = x_speed * -1

    # pygame.draw.circle(game_window, color, (x, y), r)
    x += x_speed
    y += y_speed
    game_window.blit(new_image, (0, 0))
    pygame.draw.circle(game_window, color, (x, y), r)
    pygame.draw.rect(game_window, (255, 0, 0), (length - 100, 0, 100, 50), 0)
    game_window.blit(text2, (length - 90, 15))
    pygame.draw.rect(game_window, (255, 0, 0), (x2, 3 * width // 4, 120, 30), 0)
    pygame.display.update()