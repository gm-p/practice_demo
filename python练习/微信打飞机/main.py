#导入相关模块
#coding: utf-8
import pygame
import sys
import traceback
from random import *
from pygame.locals import *
import myplane
import enemy
import bullet
import supply

#初始化
pygame.init()
pygame.mixer.init()   #混音器初始化
bg_size = width, height = 480, 700  #设计背景尺寸
screen = pygame.display.set_mode(bg_size)  #设置背景对话框
pygame.display.set_caption("飞机大战......FishC Demo")
background = pygame.image.load("image/background.png")  #加载背景图片，并设置为不透明

#载入游戏音乐
pygame.mixer.music.load("sound/game_music.wav")
pygame.mixer.music.set_volume(0.2)
bullet_sound = pygame.mixer.Sound("sound/bullet.wav")
bullet_sound.set_volume(0.2)
big_enemy_flying_sound = pygame.mixer.Sound("sound/big_spaceship_flying.wav")
big_enemy_flying_sound.set_volume(0.2)
enemy1_down_sound = pygame.mixer.Sound("sound/enemy1_down.wav")
enemy1_down_sound.set_volume(0.2)
enemy2_down_sound = pygame.mixer.Sound("sound/enemy2_down.wav")
enemy2_down_sound.set_volume(0.2)
enemy3_down_sound = pygame.mixer.Sound("sound/enemy3_down.wav")
enemy3_down_sound.set_volume(0.2)
me_down_sound = pygame.mixer.Sound("sound/game_over.wav")
me_down_sound.set_volume(0.2)
button_down_sound = pygame.mixer.Sound("sound/button.wav")
button_down_sound.set_volume(0.2)
level_up_sound = pygame.mixer.Sound("sound/achievement.wav")
level_up_sound.set_volume(0.2)
bomb_sound = pygame.mixer.Sound("sound/use_bomb.wav")
bomb_sound.set_volume(0.2)
get_bomb_sound = pygame.mixer.Sound("sound/get_bomb.wav")
get_bomb_sound.set_volume(0.2)
get_bullet_sound = pygame.mixer.Sound("sound/get_double_laser.wav")
get_bullet_sound.set_volume(0.2)


#敌方飞机生成控制函数
def add_small_enemies(group1, group2, num):
    for i in range(num):
        e1 = enemy.SmallEnemy(bg_size)
        group1.add(e1)
        group2.add(e1)

def add_mid_enemies(group1, group2, num):
    for i in range(num):
        e2 = enemy.MidEnemy(bg_size)
        group1.add(e2)
        group2.add(e2)

def add_big_enemies(group1, group2, num):
    for i in range(num):
        e3 = enemy.BigEnemy(bg_size)
        group1.add(e3)
        group2.add(e3)

def inc_speed(target, inc):
    for each in target:
        each.speed += inc

def main():
    pygame.mixer.music.play(-1)
    running = True

    me = myplane.MyPlane(bg_size)  #生成我方飞机

    clock = pygame.time.Clock()  #设置帧率

    switch_image = True   #控制飞机图片切换的标志（用以模拟 发动机喷火效果）
    delay = 60


    #实例化敌方飞机
    enemies = pygame.sprite.Group()  #生成敌方飞机组
    small_enemies = pygame.sprite.Group()   #敌方小型飞机组
    add_small_enemies(small_enemies, enemies, 1)  #生成若干小型飞机
    mid_enemies = pygame.sprite.Group()  #敌方中型飞机组
    add_mid_enemies(mid_enemies, enemies, 1)  #生成若干敌方中型飞机
    big_enemies = pygame.sprite.Group()  #敌方大型飞机组
    add_big_enemies(big_enemies, enemies, 1)   #生成敌方若干大型飞机

    #飞机损毁图像索引
    e1_destroy_index = 0
    e2_destroy_index = 0
    e3_destroy_index =0
    me_destroy_index =0

    #生成普通子弹
    bullet1 = []
    bullet1_index = 0
    bullet1_num = 6  #定义子弹实例化个数
    for i in range(bullet1_num):
        bullet1.append(bullet.Bullet1(me.rect.midtop))

    #生成超级子弹
    bullet2 = []
    bullet2_index = 0
    bullet2_num = 10  #定义超级子弹实例个数
    for i in  range(bullet2_num//2):
        bullet2.append(bullet.Bullet2((me.rect.centerx - 33, me.rect.centery)))
        bullet2.append(bullet.Bullet2((me.rect.centerx + 30, me.rect.centery)))

    color_black = (0, 0, 0)
    color_green = (0, 255, 0)
    color_red = (255, 0, 0)
    color_white = (255, 255, 255)

    score = 0   #统计用户得分

    score_font = pygame.font.SysFont("arial", 48)  #定义分数字体

    level = 1  # 游戏难度级别

    bomb_num = 3  #初始化为三个炸弹
    bomb_image = pygame.image.load("image/bomb.png")   #加载全屏炸弹图标
    bomb_rect = bomb_image.get_rect()
    bomb_front = score_font

    supply_timer = USEREVENT #补给包发送定时器
    pygame.time.set_timer(supply_timer, 10*1000)  #定义每10秒发送一次补给包

    #实例化补给包
    bullet_supply = supply.BulletSupply(bg_size)
    bomb_supply = supply.BombSupply(bg_size)

    is_double_bullet = False   #是否使用超级子弹标志位

    double_bullet_timer = USEREVENT + 1   #超级子弹持续时间定时器

    life_image = pygame.image.load("image/life.png").convert()
    life_rect = life_image.get_rect()
    life_num = 3   #一共有三条命

    invincible_time = USEREVENT + 2 #解除我方飞机无敌时间定时器

    paused = False  #标志是否暂停游戏
    pause_nor_image = pygame.image.load("image/game_pause_nor.png")  #加载暂停相关按钮
    pause_pressed_image = pygame.image.load("image/game_pause_pressed.png")
    resume_nor_image = pygame.image.load("image/game_resume_nor.png")
    resume_pressed_image = pygame.image.load("image/game_resume_pressed.png")
    paused_rect = pause_nor_image.get_rect()
    paused_rect.left, paused_rect.top = width - paused_rect.width - 10, 10   #设置暂停按钮位置
    paused_image = pause_nor_image   #设置默认显示的暂停按钮

    gameover_image = pygame.image.load("image/game_over.png")   #游戏结束背景图片
    gameover_rect = gameover_image.get_rect()

    flag_recorded = False  #是否已经打开记录文件标志位
    
    while running:
        screen.blit(background, (0,0))
        
        #定义难度递进操作
        if level == 1 and score > 5000:  # 如果达到第二难度等级，则增加3架小型机，2架中型机，1架大型机，并提升小型敌机速度
            level = 2
            level_up_sound.play()
            add_small_enemies(small_enemies, enemies, 3)
            add_mid_enemies(mid_enemies, enemies, 2)
            add_big_enemies(big_enemies, enemies, 1)
            inc_speed(small_enemies, 1)
        elif level == 2 and score > 30000: #如果达到第三难度等级
            level = 3
            level_up_sound.play()
            add_small_enemies(small_enemies, enemies, 3)
            add_mid_enemies(mid_enemies, enemies, 2)
            add_big_enemies(big_enemies, enemies, 1)
            inc_speed(small_enemies, 1)
            inc_speed(mid_enemies, 1)
        elif level == 3 and score > 60000:  #乳沟达到第四难度等级
            level = 4
            level_up_sound.play()
            add_small_enemies(small_enemies, enemies, 3)
            add_mid_enemies(mid_enemies, enemies, 2)
            add_big_enemies(big_enemies, enemies, 1)
            inc_speed(small_enemies, 1)
            inc_speed(mid_enemies, 1)
            inc_speed(big_enemies, 1)
        
        for event in pygame.event.get():   #响应用户的偶然操作
            if event.type == QUIT:   #如果用户按下屏幕上的关闭按钮，触发QUIT事件，程序退出
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                if event.key == K_SPACE:  #如果检测到用户按下空格键
                    if bomb_num:    #如果炸弹数量大于零，则引爆一颗超级炸弹
                        bomb_num -= 1
                        bomb_sound.play()
                        for each in enemies:
                            if each.rect.bottom > 0:  #屏幕上的所有敌机均销毁
                                each.active = False
            elif event.type == supply_timer:  #响应补给发送的事件消息
                if choice([True, False]):
                    bomb_supply.reset()
                else:
                    bullet_supply.reset()
            elif event.type == double_bullet_timer:
                is_double_bullet = False
                pygame.time.set_timer(double_bullet_timer, 0)
            elif event.type == invincible_time:   #如果无敌时间已过
                me.invincible = False
                pygame.time.set_timer(invincible_time, 0)
            elif event.type == MOUSEMOTION:
                if paused_rect.collidepoint(event.pos):   #如果鼠标停在按钮区域
                    if paused:   #如果当前的状态是暂停
                        paused_image = resume_pressed_image
                    else:
                        paused_image = pause_pressed_image
                else:
                    if paused:
                        paused_image = resume_nor_image
                    else:
                        paused_image = pause_nor_image
            elif event.type == MOUSEBUTTONDOWN:
                button_down_sound.play()
                if event.button == 1 and paused_rect.collidepoint(event.pos):  #如果检测到用户在指定按钮区域按下鼠标左键
                    paused = not paused
                    if paused:  #如果当前的状态是暂停
                        paused_image = resume_pressed_image
                        pygame.time.set_timer(supply_timer, 0)  #关闭补给机制以及所有音效
                        pygame.mixer.music.pause()
                        pygame.mixer.pause()
                    else:
                        paused_image = pause_pressed_image
                        pygame.time.set_timer(supply_timer, 30*1000)  #开启补给机制以及所有音效
                        pygame.mixer.music.unpause()
                        pygame.mixer.unpause()
                        
        if life_num and (not paused):   #如果游戏未被暂停，正常运行
            key_pressed = pygame.key.get_pressed() #获得用户所有的键盘输入序列
            if key_pressed[K_w] or key_pressed[K_UP]:
                me.move_up()
            elif key_pressed[K_s] or key_pressed[K_DOWN]:
                me.move_down()
            elif key_pressed[K_a] or key_pressed[K_LEFT]:
                me.move_left()
            elif key_pressed[K_d] or key_pressed[K_RIGHT]:
                me.move_right()


            #绘制补给并检测玩家是否获得
            if bomb_supply.active:  #如果是超级炸弹补给包
                bomb_supply.move()
                screen.blit(bomb_supply.image, bomb_supply.rect)
                if pygame.sprite.collide_mask(bomb_supply, me): # 如果玩家获得超级炸弹补给包
                    get_bomb_sound.play()
                    if bomb_num < 3:
                        bomb_num += 1
                    bomb_supply.active = False

            if bullet_supply.active:  #如果是超级子弹补给包
                bullet_supply.move()
                screen.blit(bullet_supply.image, bullet_supply.rect)
                if pygame.sprite.collide_mask(bullet_supply, me):
                    get_bullet_sound.play()
                    is_double_bullet = True
                    pygame.time.set_timer(double_bullet_timer, 18*1000)
                    bullet_supply.active = False       
            

            for each in small_enemies:    #绘制小型敌机并自动移动
                if each.active:
                    each.move()
                    screen.blit(each.image, each.rect)
                else:
                    if e1_destroy_index == 0:
                        enemy1_down_sound.play()
                    if not (delay % 3):
                        screen.blit(each.destroy_images[e1_destroy_index], each.rect)
                        e1_destroy_index = (e1_destroy_index + 1) % 4
                        if e1_destroy_index == 0:
                            score += 500
                            each.reset()

            for each in mid_enemies:
                if each.active:
                    each.move()
                    if not each.hit:
                        screen.blit(each.image, each.rect)
                    else:
                        screen.blit(each.image_hit, each.rect)
                        each.hit = False
                    pygame.draw.line(screen, color_black, (each.rect.left, each.rect.top - 5),
                                     (each.rect.right, each.rect.top - 5), 2)
                    energy_remain = each.energy / enemy.MidEnemy.energy
                    if energy_remain > 0.2:
                        energy_color = color_green
                    else:
                        energy_color = color_red
                    pygame.draw.line(screen, energy_color, (each.rect.left, each.rect.top - 5),
                                     (each.rect.left + each.rect.width * energy_remain, each.rect.top - 5), 2)
                else:
                    if e2_destroy_index == 0:
                        enemy2_down_sound.play()
                    if not(delay % 3):
                        screen.blit(each.destroy_images[e2_destroy_index], each.rect)
                        e2_destroy_index = (e2_destroy_index + 1) % 4
                        if e2_destroy_index == 0:
                            score += 2000
                            each.reset()
                        

            for each in big_enemies:  #绘制大型敌机并自动移动
                if each.active:
                    each.move()
                    if not each.hit:
                        if switch_image:
                            screen.blit(each.image1, each.rect)  #绘制大型敌机
                        else:
                            screen.blit(each.image2, each.rect)
                    else:
                        screen.blit(each.image_hit, each.rect)
                        each.hit = False

                    #绘制血槽
                    pygame.draw.line(screen, color_black, (each.rect.left, each.rect.top - 5),
                                     (each.rect.right, each.rect.top - 5), 2)
                    energy_remain = each.energy / enemy.BigEnemy.energy
                    if energy_remain > 0.2:   #如果血量大于20%则为绿色，否则为红色
                        energy_color = color_green
                    else:
                        energy_color = color_red
                    pygame.draw.line(screen, energy_color, (each.rect.left, each.rect.top - 5),
                                     (each.rect.left + each.rect.width * energy_remain, each.rect.top - 5), 2)
                    if each.rect.bottom == -50:
                        big_enemy_flying_sound.play(-1)
                    
                else:
                    big_enemy_flying_sound.stop()
                    if e3_destroy_index == 0:
                        enemy3_down_sound.play()  #播放飞机撞毁音效
                    if not (delay % 3): #每三帧播放一张损毁图片
                        screen.blit(each.destroy_images[e3_destroy_index], each.rect)
                        e3_destroy_index = (e3_destroy_index + 1) % 6
                        if e3_destroy_index == 0:
                            score += 6000
                            each.reset()
                '''
                if each.rect.bottom == -50:
                    big_enemy_flying_sound.play(-1) '''

            enemies_down = pygame.sprite.spritecollide(me, enemies, False, pygame.sprite.collide_mask)
            if enemies_down and (not me.invincible):
                me.active = False
                for e  in enemies_down:
                    e.active = False  #敌机损毁

            if me.active:
                if switch_image:
                    screen.blit(me.image1, me.rect)
                else:
                    screen.blit(me.image2, me.rect)
            else:
                if not(delay % 3):
                    #if me_destroy_index == 0:
                     #   me_down_sound.play()
                    screen.blit(me.destroy_images[me_destroy_index], me.rect)
                    me_destroy_index = (me_destroy_index + 1) % 4
                    if me_destroy_index == 0:
                        life_num -= 1
                        me_down_sound.play()
                        me.reset()   #我方飞机重生并开始无敌计时
                        pygame.time.set_timer(invincible_time, 3*1000)


            if not (delay % 10):   #每十帧发射一颗移动的子弹
                bullet_sound.play()
                if not is_double_bullet:   #普通子弹
                    bullets = bullet1
                    bullets[bullet1_index].reset(me.rect.midtop)
                    bullet1_index = (bullet1_index + 1) % bullet1_num
                else:    #超级子弹
                    bullets = bullet2
                    bullets[bullet2_index].reset((me.rect.centerx - 33, me.rect.centery))
                    bullets[bullet2_index + 1].reset((me.rect.centerx + 30, me.rect.centery))
                    bullet2_index = (bullet2_index + 2) % bullet2_num
                    

            for b in bullets:
                if b.active:  #只有激活的子弹才可能击中敌机
                    b.move()
                    screen.blit(b.image, b.rect)
                    enemies_hit = pygame.sprite.spritecollide(b, enemies, False, pygame.sprite.collide_mask)
                    if enemies_hit:   #如果子弹击中飞机
                        b.active = False  #子弹损毁
                        for e in enemies_hit:
                            if e in big_enemies or e in mid_enemies:
                                e.energy -= 1
                                e.hit = True   #标示飞机已经被击中
                                if e.energy == 0:
                                    e.active = False  #大中型敌机损毁
                            else:
                                e.active = False    #小型敌机损毁


            #绘制全屏炸弹数量和剩余生命数量
            bomb_text = bomb_front.render("× %d" % bomb_num, True, color_black)
            bomb_text_rect = bomb_text.get_rect()
            screen.blit(bomb_image, (10, height - 10 - bomb_rect.height))
            screen.blit(bomb_text, (20 + bomb_rect.width, height - 10 - bomb_text_rect.height))

            if life_num:
                for i in range(life_num):
                    screen.blit(life_image, (width-10-(i+1)*life_rect.width, height-10-life_rect.height))
            
            #绘制得分
            score_text = score_font.render("Score : %s" % str(score), True, color_white)
            screen.blit(score_text, (10, 5))
        elif life_num == 0:  #生命值为零，绘制游戏结束画面
            screen.blit(gameover_image, gameover_rect)
            pygame.mixer.music.stop()   #关闭背景音乐
            pygame.mixer.stop()   #关闭所有音效
            pygame.time.set_timer(supply_timer, 0)   #关闭补给机制

            if not flag_recorded:
                flag_recorded = True
                with open("score_record.txt", "r") as f:
                    record_score = int(f.read())
                if score > record_score:   #如果玩家得分大于历史最高分，则将当前分数存档
                    with open("score_record.txt", "w") as f:
                        f.write(str(score))
            record_score_text = score_font.render("%d" % record_score, True, color_white)
            screen.blit(record_score_text, (150, 25))
            game_over_score_text = score_font.render("%d" % score, True, color_white)
            screen.blit(game_over_score_text, (180, 370))

        screen.blit(paused_image, paused_rect)   #绘制暂停按钮

        if not (delay % 5):
            switch_image = not switch_image

        delay -= 1
        if not delay:
            delay = 60
        
        pygame.display.flip()
        clock.tick(60)    #设置帧数为60
        

if __name__ == '__main__':
    try:
        main()
    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()
