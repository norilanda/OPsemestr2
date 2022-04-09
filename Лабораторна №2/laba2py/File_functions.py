import pickle
from Automobile import init_automobile, print_automobile, is_less_than_two_month_between_release_and_sale

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
    n = int(input("Enter number of the automobiles: "))
    print()
    automobile_list = []
    for i in range(n):
        automobile = init_automobile()
        automobile_list.append(automobile)
        print()
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
    for automobile in automobile_list:
        print_automobile(automobile)
        print()

def write_new_file_of_automobile(path_old, path_new):
    new_list = []
    with open(path_old, 'rb') as in_file:
        in_file.seek(0, 2)
        end_of_file = in_file.tell()
        in_file.seek(0, 0)
        while in_file.tell() != end_of_file:
            automobile = pickle.load(in_file)
            if is_less_than_two_month_between_release_and_sale(automobile):
                new_list.append(automobile)   
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

    
