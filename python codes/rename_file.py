import os
#taking file names and saves into the list
def rename_files():
    file_list=os.listdir(r"C:\Users\luvku\CS 2019\prank\prank")
    #print(file_list)
    saved_path=os.getcwd()
    print("Current working directory is =" +saved_path)
    os.chdir(r"C:\Users\luvku\CS 2019\prank\prank")
    #rename file in the directory one by one
    for file_name in file_list:
        os.rename(file_name,file_name.translate({ord(c):'' for c in "1234567890"}))
    os.chdir(saved_path)


rename_files()

