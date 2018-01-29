# Collatz sequence solver
import sys

if sys.version_info[0] < 3:
    raise "Must be using Python 3"


def collatz(number):
    if number % 2 == 0:
        value = number // 2
        print(str(value))
        return value
    else:
        value = number * 3 + 1
        print(str(value))
        return value


try:
    number = int(input('Enter a number: '))
except ValueError:
    print('Not a valid number')

while number != 1:
    number = collatz(number)
