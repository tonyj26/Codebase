def collatz(number):
    if number % 2 == 0:
        result = number // 2
        print(result)
        return result
    elif number % 2 == 1:
        result = number * 3 + 1
        print(result)
        return result

print("Enter a number: ", end='')
n = input()

try:
    while n != 1:
        n = collatz(int(n))
except ValueError:
    print("Value Error")
