import pygame
from random import *


class SmallEnemy(pygame.sprite.Sprite):
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load("image/enemy1.png")   #加载敌方飞机图片
        self.rect = self.image.get_rect()   #获得地方飞机的位置
        self.width, self.height = bg_size[0], bg_size[1]  #本地化背景图片位置
        self.speed = 2  #设置敌机的速度

        self.rect.left, self.rect.top = (randint(0, self.width - self.rect.width),  #定义敌机出现的位置
                                         randint(-5*self.rect.height, -5)    #保证敌机不会在程序一开始就立即出现
                                         )
        self.mask = pygame.mask.from_surface(self.image)
        self.active = True
        self.destroy_images = []   #加载飞机损毁图片
        self.destroy_images.extend([pygame.image.load("image/enemy1_down1.png"),
                                    pygame.image.load("image/enemy1_down2.png"),
                                    pygame.image.load("image/enemy1_down3.png"),
                                    pygame.image.load("image/enemy1_down4.png")])

        
    def move(self):  #定义敌机移动函数
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            self.reset()
    def reset(self):  #当敌机向下移动出屏幕时
        self.active = True
        self.rect.left, self.rect.top = (randint(0, self.width - self.rect.width),
                                         randint(-5*self.rect.height, 0))

class MidEnemy(pygame.sprite.Sprite):
    energy = 5
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)
        
        self.image = pygame.image.load("image/enemy2.png")  #加载敌方飞机图片
        self.rect = self.image.get_rect()   #获得地方飞机的位置
        self.width, self.height = bg_size[0], bg_size[1]  #本地化背景图片位置
        self.speed = 1  #设置敌机的速度应该比小型机速度稍慢
        self.rect.left, self.rect.top = (randint(0, self.width - self.rect.width),  #定义敌机出现的位置
                                         randint(-10*self.rect.height, -self.rect.height))
        self.mask = pygame.mask.from_surface(self.image)
        self.active = True
        self.destroy_images = []
        self.destroy_images.extend([pygame.image.load("image/enemy2_down1.png"),
                                    pygame.image.load("image/enemy2_down2.png"),
                                    pygame.image.load("image/enemy2_down3.png"),
                                    pygame.image.load("image/enemy2_down4.png")])

        self.energy = MidEnemy.energy
        self.image_hit = pygame.image.load("image/enemy2_hit.png")   #加载中型敌机中弹图片
        self.hit = False   #飞机是否被击中标志位

    def move(self):  #定义敌机移动函数
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            self.reset()

    def reset(self):   #当敌机向下移动出屏幕时
        self.active = True
        self.rect.left, self.rect.top = (randint(0, self.width - self.rect.width),
                                         randint(-10*self.rect.height, -self.rect.height))
        self.energy = MidEnemy.energy
        self.hit = False

class BigEnemy(pygame.sprite.Sprite):
    energy = 15
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)
        self.image1 = pygame.image.load("image/enemy3_n1.png")
        self.image2 = pygame.image.load("image/enemy3_n2.png")
        self.rect = self.image1.get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        self.speed = 1
        self.rect.left, self.rect.top = (randint(0, self.width - self.rect.width),
                                         randint(-15*self.rect.height, -5*self.rect.height))
        self.mask = pygame.mask.from_surface(self.image1)
        self.active = True
        self.destroy_images = []
        self.destroy_images.extend([pygame.image.load("image/enemy3_down1.png"),
                                    pygame.image.load("image/enemy3_down2.png"),
                                    pygame.image.load("image/enemy3_down3.png"),
                                    pygame.image.load("image/enemy3_down4.png"),
                                    pygame.image.load("image/enemy3_down5.png"),
                                    pygame.image.load("image/enemy3_down6.png")])
        self.energy = BigEnemy.energy
        self.image_hit = pygame.image.load("image/enemy3_hit.png")   #加载大型敌机中弹图片
        self.hit = False

    def move(self):
       if self.rect.top < self.height:
           self.rect.top += self.speed
       else:
           self.reset()

    def reset(self):
        self.active = True
        self.rect.left, self.rect.top = (randint(0, self.width - self.rect.width),
                                         randint(-15*self.rect.height, -5*self.rect.height))
        self.energy = BigEnemy.energy
        self.hit = False
    
