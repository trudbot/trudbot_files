import pygame
import sys
from multiprocessing.dummy import Pool
import random
import time

t0 = time.time()
pool = Pool(6)

pygame.init()
pygame.display.set_caption('alien_invasion')
length = 1200
width = 800
window = pygame.display.set_mode((length, width))
window.fill((128, 128, 128))
airship = pygame.image.load('34rocket.png')
monster = pygame.image.load('小怪兽.png')
monster = pygame.transform.rotozoom(monster, 0, 0.5)
airship = pygame.transform.rotozoom(airship, 0, 0.5)
window_rect = window.get_rect()
window_rect_centerx = window_rect.centerx
window_rect_bottom = window_rect.bottom
airship_rect = airship.get_rect()
airship_rect.centerx = window_rect_centerx
airship_rect.bottom = window_rect_bottom
# monster_rect = monster.get_rect()
x = y = None
r = 10.0
shoot = False
print(monster.get_size())


class Monster:
    coordinate_x = random.randint(100, 1100)

    coordinate_y = 0

    def monster_run(self):
        window.blit(monster, (self.coordinate_x, self.coordinate_y))
        self.coordinate_y += 0.5


def run(i):
    if type(i) == Monster:
        i.monster_run()
    if m.coordinate_y + 100 == airship_rect.top:
        return None


m = Monster()


def draw_bullet(lit):
    pygame.draw.circle(window, (255, 0, 0), lit, r)
    lit[1] -= 1
    pygame.display.update()
    if lit[1] <= r:
        bullet_list.remove(lit)
        return None


def draw_airship():
    window.fill((128, 128, 128))
    window.blit(airship, airship_rect)
    run(m)
    pygame.display.update()


pygame.display.flip()
bullet_list = []
x_move = None
y_move = None

while True:
    # pool.map(event_reaction, pygame.event.get())
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_d and airship_rect.right <= length:
                x_move = 'right'
                airship_rect.centerx += 1
            elif event.key == pygame.K_a and airship_rect.left >= 0:
                x_move = 'left'
                airship_rect.centerx -= 1
            elif event.key == pygame.K_w and airship_rect.top >= 0:
                y_move = 'up'
                airship_rect.centery -= 1
            elif event.key == pygame.K_s and airship_rect.bottom <= width:
                y_move = 'down'
                airship_rect.centery += 1
            elif event.key == pygame.K_j:
                print(len(bullet_list))
                shoot = True
                y = airship_rect.top - r
                x = airship_rect.centerx
                bullet_list.append([x, y])
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_a or event.key == pygame.K_d:
                x_move = None
            if event.key == pygame.K_w or event.key == pygame.K_s:
                y_move = None
    if x_move == 'right' and airship_rect.right <= length:
        airship_rect.centerx += 1
    if x_move == 'left' and airship_rect.left >= 0:
        airship_rect.centerx -= 1
    if y_move == 'up' and airship_rect.top >= 0:
        airship_rect.centery -= 1
    if y_move == 'down' and airship_rect.bottom <= width:
        airship_rect.centery += 1
    draw_airship()
    pool.map(draw_bullet, bullet_list)
