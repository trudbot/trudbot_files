import pygame
import sys
length = 1200
width = 800
window = pygame.display.set_mode((length, width))
airship = pygame.image.load('34rocket.png')
airship = pygame.transform.rotozoom(airship, 0, 0.5)
window_rect = window.get_rect()
window_rect_centerx = window_rect.centerx
window_rect_bottom = window_rect.bottom
airship_rect = airship.get_rect()
airship_rect.centerx = window_rect_centerx
airship_rect.bottom = window_rect_bottom
a = [100, 100]
pygame.draw.circle(window, (255, 0, 0), a, 20)
pygame.display.flip()
while True:
    pass

