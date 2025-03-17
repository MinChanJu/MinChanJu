import pygame
import random

#게임초기화
pygame.init() 

#게임창 설정
size = [1600,900]
screen = pygame.display.set_mode(size)
title ='피하기'
pygame.display.set_caption(title)

#게임 내 필요한 설정
clock = pygame.time.Clock()
color = (204,153,255)

class obj:
    def __init__(self):
        self.x = 0
        self.y = 0
    def put_img(self, address):
        self.img = pygame.image.load(address).convert_alpha()
        self.sx, self.sy = self.img.get_size()
    def change_size(self, sx, sy):
        self.img = pygame.transform.scale(self.img,(sx,sy))
        self.sx, self.sy = self.img.get_size()
    def show(self):
        screen.blit(self.img, (self.x, self.y))

def crash(a, b):
    if (a.x-b.sx <= b.x <= a.x+a.sx):
        if (a.y-b.sy <= b.y <= a.y+a.sy):
            return True
    return False

bg = obj()
bg.put_img("./이미지/바탕.png")
bg.change_size(1600,900)
bg.x=0
bg.y=0

crt = obj()
crt.put_img("./이미지/캐릭터 앞.png")
crt.change_size(80,130)
crt.x=750
crt.y=720
crt.move = 8

block1 = obj()
block1.put_img("./이미지/블럭.png")
block1.change_size(300,50)
block1.x=100
block1.y=600

block2 = obj()
block2.put_img("./이미지/블럭.png")
block2.change_size(300,50)
block2.x=1200
block2.y=600

block3 = obj()
block3.put_img("./이미지/블럭.png")
block3.change_size(300,50)
block3.x=650
block3.y=420

laser1 = obj()
laser1.put_img("./이미지/레이져 표시.png")
laser1.change_size(1500,15)
laser1.x=50
laser1.y=860

laser2 = obj()
laser2.put_img("./이미지/레이져 표시.png")
laser2.change_size(1500,15)
laser2.x=50
laser2.y=830

laser3 = obj()
laser3.put_img("./이미지/레이져 표시.png")
laser3.change_size(1500,15)
laser3.x=50
laser3.y=800

laser4 = obj()
laser4.put_img("./이미지/레이져 표시.png")
laser4.change_size(1500,15)
laser4.x=50
laser4.y=770

laser5 = obj()
laser5.put_img("./이미지/레이져 표시.png")
laser5.change_size(1500,15)
laser5.x=50
laser5.y=740

laser6 = obj()
laser6.put_img("./이미지/레이져 표시.png")
laser6.change_size(1500,15)
laser6.x=50
laser6.y=710

laser7 = obj()
laser7.put_img("./이미지/레이져 표시.png")
laser7.change_size(1500,15)
laser7.x=50
laser7.y=680

block_list = [block1, block2, block3]

left_go = False
right_go = False
space_go = False
down_go = False

k=0
h=0
j=0
n=40
x=0
r=720

#메인 이벤트
game_quit = False
while game_quit == False:
    clock.tick(120)
    #각종 입력 감지
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_quit = True
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                left_go = True
            elif event.key == pygame.K_RIGHT:
                right_go = True
            elif event.key == pygame.K_DOWN:
                down_go = True
            elif event.key == pygame.K_SPACE:
                space_go = True
        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                left_go = False
            elif event.key == pygame.K_RIGHT:
                right_go = False
            elif event.key == pygame.K_DOWN:
                down_go = False
            elif event.key == pygame.K_SPACE:
                space_go = False
    #입력시간에 따른 변화
    k+=1
    p = random.randint(1,5)
    if left_go == True:
        crt.put_img("./이미지/캐릭터 왼.png")
        crt.x -= crt.move
        if crt.x <= 0:
            crt.x = 0
    if right_go == True:
        crt.put_img("./이미지/캐릭터 오.png")
        crt.x += crt.move
        if crt.x >= size[0]-crt.sx:
            crt.x = size[0] - crt.sx
    if down_go == True:
        crt.put_img("./이미지/캐릭터 앞.png")
    if space_go == True:
        if n>=38:
            j=1
            x=0
            n=0
    x+=1
    n=x/2
    if j==1:
        if n==1:
            crt.y -=20
        if n==2:
            crt.y -=20
        if n==3:
            crt.y -=20
        if n==4:
            crt.y -=20
        if n==5:
            crt.y -=20
        if n==6:
            crt.y -=20
        if n==7:
            crt.y -=20
        if n==8:
            crt.y -=20
        if n==9:
            crt.y -=20
        if n==10:
            crt.y -=20
        if n==11:
            crt.y -=20
        if n==12:
            crt.y -=20
        if n==13:
            crt.y -=20
        if n==14:
            crt.y -=20
        if n==15:
            crt.y -=20
        if n==16:
            crt.y -=20
        if n==17:
            crt.y -=20
        if n==18:
            crt.y -=20
        if n==19:
            j=0
    if crt.y <= 720 and j==0:
        if k%2==0:
            crt.y+=20
            if crt.y > 720:
                crt.y = 720
    for b in block_list:
        if crash(crt,b) == True:
            if crt.y > b.y:
                crt.y = b.y + b.sy
            if crt.y < b.y:
                crt.y = b.y - crt.sy

    #그리기
    screen.fill(color)
    bg.show()
    block1.show()
    block2.show()
    block3.show()
    laser1.show()
    laser2.show()
    laser3.show()
    laser4.show()
    laser5.show()
    laser6.show()
    laser7.show()
    crt.show()
    #업데이트
    pygame.display.flip()
pygame.quit()
