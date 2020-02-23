n = int(input("enter the value of n: "))
for i in range(n):
    for j in range(n):
        if i == 0 :
            print(j+1,end =' ')
        else:
            if j==0:
                print(i+1,end =" ")
            elif j == n-1-i :
                print(n,end = " ")
            else:
                print(" ",end = " ")

    print()
