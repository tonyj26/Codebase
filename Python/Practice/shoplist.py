spam = ['apples', 'bananas', 'tofu', 'cats']

def func(list):
    for i in range(len(list)):
        if(i == len(list) - 1):
            print("and " + list[i])
        else:
            print(list[i], end=", ")

func(spam)
