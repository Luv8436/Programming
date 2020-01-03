import webbrowser
import time
for i in range(6):
    #print the current time on your computer
    print("The time is "+time.ctime())
    #open the web browser
    webbrowser.open("https://www.youtube.com/watch?v=fwbFdo0adHQ")
    #wait for 5 sec 
    time.sleep(1*60*60)
