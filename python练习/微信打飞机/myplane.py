import pygame


class MyPlane(pygame.sprite.Sprite):
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)

        self.image1 = pygame.image.load("image/hero1.png").convert_alpha()  #加载飞机图片1
        self.image2 = pygame.image.load("image/hero2.png").convert_alpha()
        self.rect = self.image1.get_rect()  #得到当前我方飞机的位置
        self.width, self.height = bg_size[0], bg_size[1]  #本地化背景图片的尺寸
        self.rect.left, self.rect.top = (self.width - self.rect.width) // 2, (self.height - self.rect.height - 60)  #定义飞机初始化位置，底部预留60像素
        self.speed = 10  #设置飞机移动速度
        self.mask = pygame.sprite.from_surface(self.image1)
        self.destroy_images = []
        self.destroy_images.extend([pygame.image.load("image/hero_blowup_n1.png").convert_alpha(),
                                    pygame.image.load("image/hero_blowup_n2.png").convert_alpha(),
                                    pygame.image.load("image/hero_blowup_n3.png").convert_alpha(),
                                    pygame.image.load("image/enemy1_down4.png").convert_alpha()])
        self.active = True
        self.invincible = False  #飞机初始化时有三秒的无敌时间

    def move_up(self):   #飞机向上移动的操作函数，其余移动函数方法类似
        if self.rect.top > 0:  #如果飞机尚未移动出背景区域
            self.rect.top -= self.speed
        else:  #若即将移动出背景区域，则及时纠正为背景边缘位置
            self.rect.top = 0

    def move_down(self):
        if self.rect.bottom < self.height - 60:
            self.rect.top += self.speed
        else:
            self.rect.bottom = self.height - 60

    def move_left(self):
        if self.rect.left > 0:
            self.rect.left -= self.speed
        else:
            self.rect.left = 0

    def move_right(self):
        if self.rect.right < self.width:
            self.rect.right += self.speed
        else:
            self.rect.right = self.width

    def reset(self):
        self.rect.left, self.rect.top = (self.width -self.rect.width) // 2, (self.height - self.rect.height - 60)
        self.active = True
        self.invincible = True
