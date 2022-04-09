
def init_automobile():
    automobile = {
        'name' : input("Enter automobile's name: "),
        'release_date' : init_date("release"),
        'sale_date' : init_date("sale")
    }
    automobile = check_sale_date_is_not_smaller_than_release_date(automobile)
    return automobile

def print_automobile(automobile):
    print(f"Automobile's name: {automobile['name']}")
    print("Release date: ", end = '')
    print_date(automobile['release_date'])
    print("Sale date: ", end = '')
    print_date(automobile['sale_date'])

def calc_max_day(month, year):
    MAXDAY = 31
    if month == 4 or month == 6 or month == 9 or month == 11:
        MAXDAY = 30
    elif month == 2:
        if year % 4 == 0:
            MAXDAY = 29
        else:
            MAXDAY = 28
    return MAXDAY


def init_date(type_of_data):
    str = input(f"Enter {type_of_data} date in this format dd.mm.yyyy: ")
    str = str.split('.')
    date = {
       'day' : int(str[0]), 
       'month' : int(str[1]),
       'year' : int(str[2])
    }
    MINDATE = 1    
    MAXMONTH = 12
    MAXDAY = calc_max_day(date['month'], date['year'])
    while date['day'] < MINDATE or date['day']> MAXDAY or date['month'] < MINDATE or date['month']> MAXMONTH or date['year'] < MINDATE:
        str = input("Your date is incorrect! Try again! Enter date in format dd.mm.yyyy: ")
        str = str.split('.')
        date['day'] = int(str[0])
        date['month'] = int(str[1])
        date['year'] = int(str[2])
        MAXDAY = calc_max_day(date['month'], date['year'])
    return date

def check_sale_date_is_not_smaller_than_release_date(automobile):
    y_factor = 380
    m_factor = 31
    release_days = automobile['release_date']['day'] + automobile['release_date']['month']*m_factor + automobile['release_date']['year']*y_factor
    sale_days = automobile['sale_date']['day'] + automobile['sale_date']['month']*m_factor + automobile['sale_date']['year']*y_factor
    while sale_days < release_days:
        print("Sale date can't be smaller than release date. Please, enter correct dates.")
        automobile['release_date'] = init_date("release")
        automobile['sale_date'] = init_date("sale")
        release_days = automobile['release_date']['day'] + automobile['release_date']['month']*m_factor + automobile['release_date']['year']*y_factor
        sale_days = automobile['sale_date']['day'] + automobile['sale_date']['month']*m_factor + automobile['sale_date']['year']*y_factor
    return automobile

def print_date(date):
    print(str(date['day']).zfill(2) + '.', end = '')
    print(str(date['month']).zfill(2) + '.', end = '')
    print(str(date['year']).zfill(4) + '.')

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