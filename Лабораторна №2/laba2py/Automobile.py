
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

def is_less_than_two_month_between_release_and_sale(automobile):
    is_less = False
    year_difference = automobile['sale_date']['year'] - automobile['release_date']['year']
    month_difference = 3    
    if year_difference == 1:
        month_difference = 12 - automobile['release_date']['month'] + automobile['sale_date']['month']
    elif year_difference == 0:
        month_difference = automobile['sale_date']['month'] - automobile['release_date']['month']
    if month_difference == 2:
        if automobile['sale_date']['day'] <= automobile['release_date']['day']:
            is_less = True
    elif month_difference < 2:
        is_less = True
    return is_less

def create_list_of_two_month_automobile(old_list):
    new_list = []
    for automobile in old_list:
        if is_less_than_two_month_between_release_and_sale(automobile):
            new_list.append(automobile)
    return new_list