def create_file(path):
    out_file=open(path,'wt')
    keyToFinishTypingText=chr(24)
    string_of_text=input("Enter your strings. To finish entering a string press 'Enter'.\n"+
			"To finish typing text press combination 'Ctrl + x' (hold 'Ctrl' and press 'x')\n")
    while string_of_text[0]!=keyToFinishTypingText:
        out_file.write(string_of_text+'\n')
        string_of_text=input()
    out_file.close()

def print_file(path):
    in_file=open(path,'rt')
    for string in in_file:
        print(string,end='')
    print('\n')
    in_file.close()

def check_last_char(string):
    chars_to_check=' .,'
    string_without_end=string.rstrip('\n')
    if chars_to_check.find(string_without_end[-1])==-1:
        string='-\n'
    return string

def rewrite_text_into_new_file(path, new_path):
    in_file=open(path,'rt')
    new_file=open(new_path, 'wt')
    for string in in_file:
        string=check_last_char(string)
        new_file.write(string)
    in_file.close()
    new_file.close()