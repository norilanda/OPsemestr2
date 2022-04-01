import pickle
from Automobile import create_automobile_list, print_automobile_list, create_list_of_two_month_automobile, print_automobile

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

def write_new_file_of_automobile(path_old, path_new):
    current_list = read_file_into_list(path_old)
    new_list = create_list_of_two_month_automobile(current_list)
    with open(path_new, 'wb') as out_file:
        for automobile in new_list:
            pickle.dump(automobile, out_file)

def display_automobiles_released_not_earlier_than_year(path):
    year = int(input("Enter the year to see automobiles which have not been released before this year: "))
    automobile_list = read_file_into_list(path)
    for automobile in automobile_list:
        if automobile['release_date']['year'] >= year:
            print_automobile(automobile)
            print()

    
