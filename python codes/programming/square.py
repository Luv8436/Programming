import turtle
def square():
    window = turtle.Screen()
    window.bgcolor("orange")

    brad = turtle.Turtle()
    brad.speed(7)
    brad.hideturtle()
    brad.color("green")
    i=0
    while i<36*2:
        brad.forward(100)
        brad.left(90)
        brad.forward(100)
        brad.left(90)
        brad.forward(100)
        brad.left(90)
        brad.forward(100)
        brad.left(95)
        i=i+1
    brad.right(90)
    brad.forward(350)

    window.exitonclick()
square()

