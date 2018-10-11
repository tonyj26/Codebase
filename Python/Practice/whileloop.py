while True:
    print('Who are you?')
    name = input()
    if name != 'Joe':
        continue
    print('Hello, Joe. What is your password?(it is a fish.)')
    password = input()
    if password == 'swordfish':
        break

print('Access granted')
