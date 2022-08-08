import random
import tkinter as tk
window = tk.Tk()
window.title('demo')
window.geometry('600x400')
# txt = tk.StringVar()
# demo_label = tk.Label(window, textvariable=txt, bg='cyan', width=10, height=3, font=('Arial', 12))
# demo_label.pack()

# hit = True

#
# def f():
#     global hit
#     if hit:
#         txt.set('SYP')
#         hit = False
#     else:
#         txt.set('')
#         hit = True
# demo_button = tk.Button(window, text='my name', width=8, height=3, font=('Arial', 30), command=f)
# demo_button.pack()
#
# entry = tk.Entry(window, show=None)
# entry.pack()
#
#
# def insert_point():
#     txt.insert('insert', entry.get())
#
#
# def insert_tail():
#     txt.insert('end', entry.get())
#
#
# def insert_head():
#     txt.insert(1.0, entry.get())
#
#
# button1 = tk.Button(window, width=16, height=2, text='插入文本到光标处', command=insert_point)
# button1.pack()
#
# button2 = tk.Button(window, width=16, height=2, text='插入文本到尾部', command=insert_tail)
# button2.pack()
#
# button3 = tk.Button(window, width=16, height=2, text='插入文本到开头', command=insert_head)
# button3.pack()
#
# txt = tk.Text(window, width=32, height=18)
# txt.pack()
# txt = tk.StringVar()
# data = {2185759039: 'SYP123456'}
#
#
# def login():
#     if data.get(int(entry1.get())) == entry2.get():
#         txt.set('登录成功')
#     else:
#         txt.set('登录失败')
#
#
# def register():
#     data[int(entry1.get())] = entry2.get()
#
#
# txt1 = tk.Label(window, text='账号', height=2)
# txt1.pack()
# entry1 = tk.Entry(window)
# entry1.pack()
# txt2 = tk.Label(window, text='密码', height=2)
# txt2.pack()
# entry2 = tk.Entry(window, show='*')
# entry2.pack()
# button1 = tk.Button(window, text='登录', command=login)
# button1.pack()
# button2 = tk.Button(window, text='注册', command=register)
# button2.pack()
#
# txt3 = tk.Label(window, textvariable=txt, width=16, height=9)
# txt3.pack()
# listbox = tk.Listbox(window)
# for i in range(10):
#     v = random.random()
#     listbox.insert('end', v)
# listbox.pack()
# var = tk.StringVar()
# label = tk.Label(window, textvariable=var, bg='cyan', width=40, height=2)
# label.pack()
#
#
# def print_selection():
#     e = listbox.get(listbox.curselection())
#     var.set(e)
#
# entry1 = tk.Entry(window)
# entry1.pack()
# var = tk.StringVar()
#
#
# def randoms():
#     x = random.randint(1, int(entry1.get()))
#     var.set(x)
#
#
# label = tk.Label(window, textvariable=var, height=2)
# label.pack()
# button = tk.Button(window, text='Print what you have selected', height=2, command=randoms)
# button.pack()
# var = tk.StringVar()
# label = tk.Label(window, textvariable=var, bg='cyan', width=3)
# label.pack()
#
# button = tk.Radiobutton(window, variable=var, value='A', text='option A', height=2)
# button.pack()
#
# button = tk.Radiobutton(window, variable=var, value='B', text='option B', height=2)
# button.pack()
#
# button = tk.Radiobutton(window, variable=var, value='C', text='option C', height=2, bg='cyan')
# button.pack(side='top', anchor='sw', fill='x')

label = tk.Label(window, height=2, text='', bg='cyan', width=20)
label.pack()


def f(v):
    label.config(text='you have select '+v)


s = tk.Scale(window, label='scale', from_=0, to=10, orient=tk.HORIZONTAL,
             length=400, tickinterval=2, resolution=0.01
             , command=f)
s.pack()
window.mainloop()
