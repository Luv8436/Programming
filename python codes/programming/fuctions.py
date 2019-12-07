def hello():
    name=input("Enter your name: ")
    print("Hello,",name)
n=int(input("Enter the number of students in class: "))
for i in range(n):
    print(f"{i+1}.")
    hello()
