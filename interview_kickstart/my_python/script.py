import sys

print(sys.version)
print(sys.executable)

def greet(who):
    greeting = 'Hell, {}'.format(who)
    return greeting

print(greet('John'))
print(greet('Corey'))
