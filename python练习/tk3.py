from tkinter import *

root = Tk()

textLabel = Label(root, text="您所下载的影片含有未成年人限制内容，\n请满18周岁后再点击观看！",
                  justify=LEFT,
                  padx=10)
textLabel.pack(side=LEFT)


photo = PhotoImage(file="18.gif")
imgLabel=Label(root, image=photo)
imgLabel.pack(side=RIGHT)

mainloop()
