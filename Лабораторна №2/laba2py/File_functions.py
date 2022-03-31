import pickle

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
