# gui test application

import tkinter as tk

gui = tk.Tk()

label_1 = tk.Label(gui, text="Name")
label_2 = tk.Label(gui, text="Password")
entry_1 = tk.Entry(gui)
entry_2 = tk.Entry(gui)

label_1.grid(row=0, sticky=tk.E)
label_2.grid(row=1, sticky=tk.E)

entry_1.grid(row=0, column=1)
entry_2.grid(row=1, column=1)

c = tk.Checkbutton(gui, text="keep me logged in")
c.grid(columnspan=2)

gui.mainloop()
