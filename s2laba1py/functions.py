def create_file(path):
    out_file=open(path,'wt')
    string_of_text=input("Enter your strings. To finish press 'Enter' twice\n")
    while string_of_text!='':
        out_file.write(string_of_text+'\n')
        string_of_text=input()
    out_file.close()

def print_file(path):
    in_file=open(path,'rt')
    for string in in_file:
        print(string,end='')
    in_file.close()

def check_last_char(string):
    chars_to_check=' .,'
    string_without_end=string.rstrip('\n')
    if chars_to_check.find(string_without_end[-1])==-1:
        string='-\n'
    return string

def rewrite_text_into_new_file(path, new_path):
    in_file=open(path,'rt')
