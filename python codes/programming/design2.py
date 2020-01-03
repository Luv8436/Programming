import turtle
def square():
    window = turtle.Screen()
    window.bgcolor("orange")

    brad = turtle.Turtle()
    brad.speed(15)
    brad.hideturtle()
    brad.color("green")
    for j in range(3):
        i=0
        while i<36*2:
            
            brad.forward(50)
            brad.left(90)
            brad.forward(50)
            brad.left(90)
            brad.forward(50)
            brad.left(90)
            brad.forward(50)
            brad.left(95)
            i=i+1
        brad.right(120)
        brad.forward(200)
    window.exitonclick()
square()

