import pygame
import sys
import math
import traceback
from pygame.locals import *
from random import *

class Ball(pygame.sprite.Sprite):
    def __init__(self, grayball_image, greenball_image, position, speed, bg_size, target):
        pygame.sprite.Sprite.__init__(self)

        self.grayball_image = pygame.image.load(grayball_image).convert_alpha()
        self.greenball_image = pygame.image.load(greenball_image).convert_alpha()
        self.rect = self.grayball_image.get_rect()
        self.rect.left, self.rect.top = position
        self.side = [choice([-1, 1]), choice([-1, 1])]
        self.speed = speed
        self.collide = False
        self.target = target
        self.control = False
        self.width , self.height = bg_size[0], bg_size[1]
        self.radius = self.rect.width / 2

    def move(self):
        if self.control:
            self.rect = self.rect.move(self.speed)
        else:
            self.rect = self.rect.move((self.side[0] * self.speed[0], self.side[1] * self.speed[1]))

        if self.rect.right <= 0:
            self.rect.left = self.width
        elif self.rect.left >= self.width:
            self.rect.right = 0
        elif self.rect.bottom <= 0:
            self.rect.top = self.height
        elif self.rect.top >= self.height:
            self.rect.bottom = 0

    def check(self, motion):
        if self.target < motion < self.target + 5:
            return True
        else:
            return False

class Glass(pygame.sprite.Sprite):
    def __init__(self, glass_image,mouse_image, bg_size):
        pygame.sprite.Sprite.__init__(self)

        self.glass_image = pygame.image.load(glass_image).convert_alpha()
        self.glass_rect = self.glass_image.get_rect()
        self.glass_rect.left, self.glass_rect.top = (bg_size[0] - self.glass_rect.width) //2, \
                                                    bg_size[1] - self.glass_rect.height

        self.mouse_image = pygame.image.load(mouse_image).convert_alpha()
        self.mouse_rect = self.mouse_image.get_rect()
        self.mouse_rect.left, self.mouse_rect.top = self.glass_rect.left, self.glass_rect.top
        
        pygame.mouse.set_visible(False)
            
def collide_check(item, target):
    col_balls = []
    for each in target:
        distance = math.sqrt(math.pow(item.rect.center[0] - each.rect.center[0], 2) +\
                             math.pow(item.rect.center[1] - each.rect.center[1], 2))

        if distance <= (item.rect.width + each.rect.width) / 2:
            col_balls.append(each)

    return col_balls


def main():
    pygame.init()

    grayball_image = "gray_ball.png"
    greenball_image = "green_ball.png"
    glass_image = "glass.png"
    mouse_image = "hand.png"
    bg_image = "background.png"


    running = True

    pygame.mixer.music.load("bg_music.ogg")
    pygame.mixer.music.play()

    loser_sound = pygame.mixer.Sound("loser.wav")
    laugh_sound = pygame.mixer.Sound("laugh.wav")
    winner_sound = pygame.mixer.Sound("winner.wav")
    hole_sound = pygame.mixer.Sound("hole.wav")

    GAMEOVER = USEREVENT
    pygame.mixer.music.set_endevent(GAMEOVER)

    bg_size = width, height = 1024, 681
    screen = pygame.display.set_mode(bg_size)
    pygame.display.set_caption("Play the ball - FishC Demo")

    background = pygame.image.load(bg_image).convert_alpha()

    hole = [(117, 119, 199, 201), (225, 227, 390, 392), (503, 505, 320, 322),(698, 700, 192, 194), (906, 908, 419, 421)]


    msgs = []
    
    balls = []

    BALL_NUM = 5

    for i in range(BALL_NUM):
        position = randint(0, width-100,), randint(0, height-100)
        speed = [randint(1, 10), randint(1, 10)]
        ball = Ball(grayball_image, greenball_image, position, speed, bg_size, 5*(i+1))
        while collide_check(ball, balls):
            ball.rect.left, ball.rect.top = randint(0, width-100,), randint(0, height-100)
        balls.append(ball)

    glass = Glass(glass_image, mouse_image,  bg_size)

    motion =0

    MYTIMER = USEREVENT + 1
    pygame.time.set_timer(MYTIMER, 1000)

    pygame.key.set_repeat(100, 100)

    clock = pygame.time.Clock()
        

    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == GAMEOVER:
                load_sound.play()
                pygame.time.delay(2000)
                laugh_sound.play()
                running = False
            elif event.type == MYTIMER:
                if motion:
                    for each in group:
                        if each.check(motion):
                            each.speed = [0, 0]
                            each.control = True
                    motion = 0
            elif event.type == MOUSEMOTION:
                motion += 1

            elif event.type == KEYDOWN:
                if event.key == K_w:
                    for each in group:
                        if each.control:
                            each.speed[1] -= 1

                if event.key == K_s:
                    for each in group:
                        if each.control:
                            each.speed[1] += 1

                if event.key == K_a:
                    for each in group:
                        if each.control:
                            each.speed[0] -= 1
                if event.key == K_d:
                    for each in group:
                        if each.control:
                            each.speed[0] += 1
                if event.key == K_SPACE:
                    for each in group:
                        if each.control:
                            for i in hole:
                                if i[0] <= each.rect.left <= i[1] and i[2] <= each.rect.top <= i[3]:
                                    hole_sound.play()
                                    each.speed = [0, 0]
                                    group.remove(each)
                                    temp = balls.pop(balls.index(each))
                                    balls.insert(0, temp)
                                    hole.remove(i)
                            if not hole:
                                pygame.mixer.music.stop()
                                winner_sound.play()
                                pygame.time.delay(3000)
                                msg = pygame.image.load("win.png").convert_alpha()
                                msg_pos = (width - msg.get_width()) // 2, (height - msg.get_height()) // 2
                                msg.append(msg, msg_pos)
                                laugh_sound.play()
                                    
                            

        screen.blit(background, (0, 0))
        screen.blit(glass.glasss_image, glass.glass_rect)

        glass.mouse_rect.left, glass.mouse_rect.top = pygame.mouse.get_pos()
        if glass.mouse_rect.left < glass.glass_rect.left:
            glass.mouse_rect.left = glass.glass_rect.left
        if glass.mouse_rect.left > glass.glass_rect.right - glass.mouse_rect.width:
            glass.mouse_rect.left = glass.glass_rect.right -  glass.mouse_rect.width
        if glass.mouse_rect.top < glass.glass_rect.top:
            glass.mouse_rect.top = glass.glass_rect.top
        if glass.mouse_rect.top > glass.glass_rect.bottom - glass.mouse_rect.height:
            glass.mouse_rect.top = glass.glass_rect.bottom - glass.mouse_rect.height

        screen.blit(glass.mouse_image, glass.mouse_rect)

        for each in balls:
            each.move()
            if each.collide:
                each.speed = [randint(1, 10), randint(1, 10)]
                each.collide = False
            if each.control:
                screen.blit(each.greenball_image, each_rect)
            else:
                screen.blit(each.grayball_image, each.rect)


        for each in group:
            group.remove(each)

            if pygame.sprite.spritecollide(each, group, False, pygame.sprite.collide.circle):
                #each.speed[0] = -each.speed[0]
                #each.speed[1] = -each.speed[1]
                each.side[0] = -each.side[0]
                each.side[1] = -each.side[1]
                each.collide = True
                #each.speed = [randint(1, 10), randint(1, 10)]

                if each.control:
                    each.side[0] = -1
                    each.side[1] = -1
                    each.control = False

            group.add(each)


        

        '''
        for i in range(BALL_NUM):
            item = balls.pop(i)

            if collide_check(item, balls):
                item.speed[0] = -item.speed[0]
                item.speed[1] = -item.speed[1]

            balls.insert(i, item)

 
        '''
        for msg in msgs:
            screen.blit(msg[0], msg[1])
    
        pygame.display.flip()
        clock.tick(30)
             
                
        

if __name__ =="__main__":
    try:
        main()
    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()
