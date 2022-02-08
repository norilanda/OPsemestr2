def create_file(path):
    out_file=open(path,'wt')
    string_of_text=input("Enter your strings. To finish press 'Enter' twice\n")
    while string_of_text!='':
        out_file.write(string_of_text)
        string_of_text=input()
    out_file.close()

def print_file(path):
    in_file=open(path,'rt')
    for string in in_file:
        print(string)
    in_file.close()