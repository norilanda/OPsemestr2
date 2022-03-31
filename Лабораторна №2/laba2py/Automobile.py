
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
        print(f"0{date['day']}.", end = '')
    if date['month'] < 10:
        print(f"0{date['month']}.", end = '')
    else:
        print(f"{date['month']}.", end = '')
    print(date['year']) 

def create_automobile_list():
    n = input("Enter number of the automobiles: ")
    automobileList = []
    for i in range(n):
        automobile = init_automobile()
        automobileList.append(automobile)
    print("----------------------------------------\n")
    return automobileList


def print_automobile_list(automobileList):
    for automobile in automobileList:
        print_automobile(automobile)
        print()