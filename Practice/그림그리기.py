import turtle

def line(obj,a,b,th,r,k=0):
    obj.penup()
    obj.goto(a,b)
    obj.pendown()
    obj.setheading(th)
    if k == 0: obj.forward(r)
    else:
        while r > 0:
            obj.forward(14)
            obj.penup()
            obj.forward(6)
            obj.pendown()
            r-=20
    return 

def square(obj,a,b,th,w,h):
    obj.penup()
    obj.goto(a,b)
    obj.pendown()
    obj.setheading(th)
    obj.forward(w)
    obj.left(90)
    obj.forward(h)
    obj.left(90)
    obj.forward(w)
    obj.left(90)
    obj.forward(h)
    obj.left(90)
    return

def make_circle(obj,a,b,th,r,t=0):
    obj.penup()
    obj.goto(a,b)
    obj.pendown()
    obj.setheading(th)
    if t==0: obj.circle(r)
    else: obj.circle(r,t)
    return

def window(obj,a,b,w,h):
    square(obj,a,b,0,w,h)
    line(obj,a,b+h//2,0,w)
    line(obj,a+w//2,b,90,h)
    return

def move(obj,a,b,th=0):
    obj.penup()
    obj.goto(a,b)
    obj.pendown()
    obj.setheading(th)
    return

# 터틀 화면 생성
screen = turtle.Screen()
screen.screensize(2000, 1000)

# 터틀 객체 생성
road = turtle.Turtle()
building = turtle.Turtle()
car = turtle.Turtle()
tree = turtle.Turtle()

# 터틀 객체 속도 설정
road.speed(20)
building.speed(20)
car.speed(20)
tree.speed(20)

# 터틀 객체 포인터 숨기기
road.hideturtle()
building.hideturtle()
car.hideturtle()
tree.hideturtle()

# 밑 바닥
line(road,-400,-200,0,800)
line(road,-400,-215,0,800,5)
line(road,-400,-230,0,800)

# 건물
square(building,-300,-200,0,130,250)
line(building,-320,50,0,170)
building.goto(-170,70)
building.goto(-300,70)
building.goto(-320,50)
line(building,-300,65,0,130)
line(building,-305,60,0,140)
line(building,-310,55,0,150)
square(building,-200,70,0,10,15)
square(building,-278,-200,0,26,52)
make_circle(building,-273,-175,0,2)

window(building,-280,0,30,30)
window(building,-220,0,30,30)
window(building,-280,-60,30,30)
window(building,-220,-60,30,30)
window(building,-280,-120,30,30)
window(building,-220,-120,30,30)
window(building,-220,-180,30,30)

# 자동차
line(car,-100,-190,0,30)
make_circle(car,-50,-190,90,10,180)
make_circle(car,-100,-190,90,10,180)
line(car,-50,-190,0,10)
line(car,-130,-190,0,10)
make_circle(car,-40,-190,90,30,40)
make_circle(car,-130,-190,-90,30,-40)
line(car,-123,-172,0,13)
line(car,-59,-172,0,13)
make_circle(car,-110,-172,-90,50,-25)
make_circle(car,-59,-172,90,50,25)
line(car,-105,-151,0,42)
make_circle(car,-110,-200,0,8)
make_circle(car,-59,-200,0,8)
line(car,-118,-192,0,16)
line(car,-110,-200,90,16)
line(car,-67,-192,0,16)
line(car,-59,-200,90,16)
move(car,-115,-187)
car.goto(-105,-197)
move(car,-64,-187)
car.goto(-54,-197)
move(car,-115,-197)
car.goto(-105,-187)
move(car,-64,-197)
car.goto(-54,-187)
square(car,-100,-172,0,31,15)

# 나무
move(tree,-3,-200)
tree.goto(0,-50)
tree.goto(3,-200)
for i in range(10):
    if i>5:
        move(tree,0,-50-10*i)
        tree.goto(-30-2*(10-i),-70-10*i)
        move(tree,0,-50-10*i)
        tree.goto(30+2*(10-i),-70-10*i)
        continue
    move(tree,0,-50-10*i)
    tree.goto(-30-2*i,-70-10*i)
    move(tree,0,-50-10*i)
    tree.goto(30+2*i,-70-10*i)


# 터틀 그래픽 창 열린 상태로 유지
turtle.done()