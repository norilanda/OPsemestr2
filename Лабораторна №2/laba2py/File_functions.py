import pickle
from Automobile import create_automobile_list, print_automobile_list

def choose_file_mode():
    print("Do you want to create a new file or just to add new information?")
    answer = input("To create a new file enter 'n', to add information enter 'a': ")
    while answer != 'a' and answer != 'n':
        answer = input("Wrong letter! Try again!")
    return answer

def write_automobiles_into_file(path):
    answer = choose_file_mode()
    if answer == 'n':
        out_file = open(path, 'wb')
    else:
        out_file = open(path, 'ab')
    automobile_list = create_automobile_list()
    for automobile in automobile_list:
        pickle.dump(automobile, out_file)
    out_file.close()

def read_file_into_list(path):
    automobile_list = []
    with open(path, 'rb') as in_file:
        in_file.seek(0, 2)
        end_of_file = in_file.tell()
        in_file.seek(0, 0)
        while in_file.tell() != end_of_file:
            automobile = pickle.load(in_file)
            automobile_list.append(automobile)
    return automobile_list

def display_file_information(path):
    automobile_list = read_file_into_list(path)
    print_automobile_list(automobile_list)
