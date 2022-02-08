from functions import create_file, print_file, rewrite_text_into_new_file

pathOfFile = "file.txt"
pathOfNewFile = "new file.txt"
create_file(pathOfFile)
print("Here is the first file:\n")
print_file(pathOfFile)
rewrite_text_into_new_file(pathOfFile, pathOfNewFile)
print("The new file:\n")
print_file(pathOfNewFile)