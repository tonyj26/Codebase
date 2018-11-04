import pprint

inven = {'rope': 1, 'torch': 6, 'gold coin': 42, 'dagger': 1,
        'arrow': 12}

def displayInventory():
    pprint.pprint(inven)
    print(inven['rope'])

displayInventory()

