def arithematic():
    print("5 + 2 =", 5 + 2)
    print("5 - 2 =", 5 - 2)
    print("5 * 2 =", 5 * 2)
    print("5 / 2 =", 5 / 2)
    print("5 % 2 =", 5 % 2)
    print("5 ** 2 = ", 5 ** 2)
    print("5 // 2 = ", 5 // 2)

def string():
    quote = "\"Always remember you are unique\""
    print(quote)

    multi_line_quote = '''just
like everyone else'''
    print(multi_line_quote)

    print("%s %s %s" % ('I like the quote', quote, multi_line_quote))

    print("I don't like ", end='')
    print('newlines')

    print('\n' * 5)

def py_list():
    grocery_list = ['Juice', 'Tomatoes', 'otatoes', 'Bananas']
    print('First item', grocery_list[0])

    grocery_list[0] = 'Green Juice'
    print('First item', grocery_list[0])

    print(grocery_list[1:3])

    other_events = ['Wash Car', 'Pick Up Kids', 'Cash Check']

    to_do_list = [other_events, grocery_list]
    print(to_do_list)

    print(to_do_list[1][1])
    grocery_list.append('Onions')
    print(to_do_list)

    grocery_list.insert(1, 'Pickle')
    print(grocery_list)
    grocery_list.remove('Pickle')
    print(grocery_list)

    grocery_list.sort()
    print(grocery_list)

    grocery_list.reverse()
    print(grocery_list)

    del grocery_list[4]
    print(grocery_list)
    print(to_do_list)

    to_do_list2 = other_events + to_do_list
    print(to_do_list2)
    print(len(to_do_list2))
    print(max(other_events))
    print(min(other_events))

def py_tuple(): # immutable
    pi_tuple = (3,1,4,1,5,9)

    # if you wanna change tuple, convert it to a list first
    new_list = list(pi_tuple)
    new_list.append(7)
    new_list.append(6)

    # then change it back to tuple
    new_tuple = tuple(new_list)

    print('pi_tuple =', pi_tuple)
    print('new_tuple =', new_tuple)
    print('min(new_tuple) =', min(new_tuple))
    print('max(new_tuple) =', max(new_tuple))
    print('len(new_tuple) =', len(new_tuple))

def py_dict(): # or map
    super_villains = {'Fiddler' : 'Isaac Bowin',
                      'Captain Cold' : 'Leonard Snart',
                      'Weather Wizard' : 'Mark Mardon',
                      'Mirror Master' : 'Sam Scudder',
                      'Pied Piper' : 'Thomas Peterson'}

    print(super_villains)
    print(super_villains['Captain Cold'])

    del super_villains['Fiddler']
    print(super_villains)

    super_villains['Pied Piper'] = 'Hartley Rathaway'
    print(super_villains)

    print('len = ', len(super_villains))

    print(super_villains.get('Pied Piper'))

    list_of_keys = super_villains.keys()
    print(list_of_keys)

    list_of_values = super_villains.values()
    print(list_of_values)

def py_condition():
    # if else elif == != > >=
    age = 21
    if age > 16:
        print('You are old enough to drive')
    else:
        print('You are not old enough to drive')

    if age >= 21:
        print('You are old enough to drive a tractor trailer')
    elif age >=16:
        print('You are old enough to drive a car')
    else:
        print('You are not old enough to drive')

    # and or not
    if ((age >= 1) and (age <= 18)):
        print('You get a birthday')
    elif ((age == 21) or (age >= 65)):
        print('You get a birthday')
    elif not(age == 30):
        print('You don\'t get a birthday')
    else:
        print('You get a birthday party yeah')

def py_loop():
    # for loop
    for x in range (0, 10):
        print(x, '',end='')
    print('\n')

    grocery_list = ['Juice', 'Tomatoes', 'Potatose', 'Bananas']
    for y in grocery_list:
        print(y,'',end='')
    print("\n")

    for x in [2,4,6,8,10]:
        print(x,'',end='')
    print('\n')

    num_list = [[1,2,3,4],[10,20,30,40],[100,200,300,400]]
    for x in range(0, 3):
        for y in range(0, 4):
            print(num_list[x][y],'',end='')
        print('\n')

    import random
    # while loop
    random_num = random.randrange(0,100)
    while (random_num != 15):
        print(random_num,'',end='')
        random_num = random.randrange(0,100)
    print('\nfound randon_num=',random_num)

    i = 0;
    while i <= 20:
        #print('i=',i)
        if i % 2 == 0:
            print(i)
        elif i == 9:
            break
        else:
            #print('else i++')
            i += 1
            continue
        #print('i++')
        i += 1

def addNumber(fNum, lNum):
    sumNum = fNum + lNum
    return sumNum

def py_function():
    string = addNumber(1011, 4)
    print(string)

def py_user_input():
    print('What is your name? ')
    import sys
    name = sys.stdin.readline()
    print('Hello', name)

def py_string():
    long_string= "I'll catch you if you fall - The Floor"

    # print the first 4 chars
    print(long_string[0:4])

    # print the last 5 chars
    print(long_string[-5:])

    # print all up to the last 5 chars
    print(long_string[:-5])

    # string concat
    print(long_string[:4] + " be there")

    # string formatting
    print("%c is my %s letter and my number %d numbr is %.5f" % ('X', 'fovorite', 1, .14))

    long_string = 'abc def'
    # Cap the first char
    print(long_string.capitalize())

    # find start index of the word - case sensitive
    print(long_string.find('def'))

    print(long_string.isalpha())
    print(long_string.isalnum())
    print(len(long_string))

    long_string= "I'll catch you if you fall - The Floor"
    print(long_string.replace('Floor', 'Ground'))

    # strip(word) - remove word @ prefix or suffix of string; not middle
    print(long_string.strip('I\'ll'))
    print(long_string.strip('Floor'))
    print(long_string.strip('if'))

    # split('word') - split strings using 'word' into list
    quote_list = long_string.split(' ')  # split with space
    print(quote_list)
    quote_list = long_string.split('if ')  # split with 'if '
    print(quote_list)

def py_file():
    test_file = open('test.txt', 'wb')  # wb - write only in binary mode
    print(test_file.mode)
    print(test_file.name)  
    test_file.write(bytes("Write me to the file\n", 'UTF-8'))
    test_file.close()

    test_file = open('test.txt', 'r+') # r+ - read and write
    test_in_file = test_file.read()
    print(test_in_file)
    test_file.close()

    import os
    os.remove('test.txt')


class Animal:
    __name = ''
    __height = 0
    __weight = 0
    __sound = 0

    # constructor
    def __init__(self, n, h, w, s):
        self.__name = n
        self.__height = h
        self.__weight = w
        self.__sound = s
        #print("Animal.__init__ - done")

    def set_name(self, name):
        self.__name = name

    def get_name(self):
        return self.__name

    def set_height(self, h):
        self.__height = h

    def get_height(self):
        return self.__height

    def set_weight(self, w):
        self.__weight = w

    def get_weight(self):
        return self.__weight

    def set_sound(self, s):
        self.__sound = s

    def get_sound(self):
        return self.__sound

    # polymorphism
    def get_type(self):
        print('Animal')

    def toString(self):
        return "{} is {} cm tall and {} kilograms and say {}".format(self.__name, self.__height, self.__weight, self.__sound)
    
# inheritance
class Dog(Animal):
    __owner = ''

    def __init__(self, n, h, w, s, o):
        super(Dog, self).__init__(n, h, w, s)
        self.__owner = o
        #print("Dog.__init__ - done")

    def set_owner(self, o):
        self.__owner = 0

    def get_owner(self):
        return self.__owner

    def get_type(self):
        print("Dog")

    # override a method toString
    def toString(self):
        #return "{} is {} cm tall and {} kilograms and say {} His owner is {}".format(self.__name, self.__height, self.__weight, self.__sound, self.__owner)
        return "{} is {} cm tall and {} kilograms and say {} His owner is {}".format(self.get_name(), self.get_height(), self.get_weight(), self.get_sound(), self.__owner)

    def multiple_sounds(self, how_many=None):
        if how_many is None:
            print(self.get_sound())
        else:
            print(self.get_sound() * how_many)

# polymorphism
class AnimalTesting:
    def get_type(self, animal):
        animal.get_type()

def py_class():
    cat = Animal('Whiskers', 33, 10, 'Meow')
    print(cat.toString())

    spot = Dog("Spot", 53, 27, "Ruff", "Derek")
    print(spot.toString())
    print(spot.multiple_sounds())

    test_animals = AnimalTesting()
    test_animals.get_type(cat)
    test_animals.get_type(spot)


arithematic()
string()
py_list()
py_tuple()
py_dict()
py_condition()
py_loop()
py_function()
#py_user_input()
py_string()
py_file()
py_class()
