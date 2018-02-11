import tkinter as tk

root = tk.Tk()


def printName(event):
    print("Hello my name is Kyle!")


button_1 = tk.Button(root, text="Print my name")
button_1.bind("<Button-1>", printName)
button_1.pack()

root.mainloop()
