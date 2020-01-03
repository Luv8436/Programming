from urllib import request as r 
def fun():
    with open("C:\\Users\\luvku\\CS 2019\\india.txt",encoding = "utf8") as fobj:
        text = fobj.read()
        check_profanity(text)
        print(text)
        
    
#def call():
#   s = input("age: ")
#    print(f"your age is {s}")

def check_profanity(text_to_check):
    connection = r.urlopen("http://www.wdylike.appspot.com/?q="+text_to_check)
    output = connection.read()
    print(output)
    connection.close()

fun()
