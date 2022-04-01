
def init_automobile():
    automobile = {
        'name' : input("Enter automobile's name: "),
        'release_date' : init_date("release"),
        'sale_date' : init_date("sale")
    }
    return automobile

def print_automobile(automobile):
    print(f"Automobile's name: {automobile['name']}")
    print("Release date: ", end = '')
    print_date(automobile['release_date'])
    print("Sale date: ", end = '')
    print_date(automobile['sale_date'])

def init_date(type_of_data):
    str = input(f"Enter {type_of_data} date in this format dd.mm.yyyy: ")
    str = str.split('.')
    date = {
       'day' : int(str[0]), 
       'month' : int(str[1]),
       'year' : int(str[2])
    }
    return date

def print_date(date):
    if date['day'] < 10:
        print(f"0{date['day']}.", end = '')
    else:
        print(f"{date['day']}.", end = '')
    if date['month'] < 10:
        print(f"0{date['month']}.", end = '')
    else:
        print(f"{date['month']}.", end = '')
    print(date['year']) 

def create_automobile_list():
    n = int(input("Enter number of the automobiles: "))
    print()
    automobile_list = []
    for i in range(n):
        automobile = init_automobile()
        automobile_list.append(automobile)
        print()
    print("----------------------------------------\n")
    return automobile_list


def print_automobile_list(automobile_list):
    for automobile in automobile_list:
        print_automobile(automobile)
        print()