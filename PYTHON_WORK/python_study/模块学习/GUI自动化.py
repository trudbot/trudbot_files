import pyautogui
pyautogui.PAUSE = 0.2

'''我的电脑屏幕分辨率为1920*1080，鼠标坐标范围为x(0-1079) y(0-1919)'''
print(pyautogui.size())
pyautogui.moveTo(1500, 1079, duration=1)  # 将光标移动到（width， height），移动时间为duration秒
pyautogui.moveRel(-250, -20, duration=1)  # 将光标向右移动-400像素，向下移动0像素
print(pyautogui.position())  # 返回当前光标位置坐标
pyautogui.click()  # 鼠标左键点击一次
pyautogui.moveTo(607, 437, duration=1)
pyautogui.click()
# pyautogui.doubleClick()  # 双击左键
# pyautogui.rightClick()  # 右键点击一次
# pyautogui.middleClick()  # 中键点击一次
# # pyautogui.mouseDown()  # 鼠标左键按下
# # pyautogui.moveRel(0, -200, duration=2)
# # pyautogui.mouseUp()  # 鼠标左键松开
move = 500
'''按下鼠标左键的同时移动光标'''
# pyautogui.dragRel(100, 100, duration=2)
# pyautogui.dragTo(500, 500, duration=2)
# while move:
#     pyautogui.dragRel(move, 0, duration=0.2)
#     move -= 5
#     pyautogui.dragRel(0, move, duration=0.2)
#     pyautogui.dragRel(-move, 0, duration=0.2)
#     move -= 5
#     pyautogui.dragRel(0, -move, duration=0.2)
'''滚轮控制'''
pyautogui.scroll(500)  # 传入整形参数作为滚动的单位，正数表示向上滚动，负数向下滚动
'''屏幕快照'''
# image = pyautogui.screenshot()  # 获取屏幕快照
# # image = pyautogui.screenshot(region=[x, y, width, height) 获取指定矩形区域内的截图
# print(type(image))  # <class 'PIL.Image.Image'>
# image.save('截图.png')
# print(image.getpixel((200, 200)))  # 获取屏幕快照中（200， 200）的点的RGB值
# print(pyautogui.pixelMatchesColor(200, 200, (65, 67, 68)))  # 判断（200， 200）点处的RGB值是否为（65， 67， 68）
'''键盘控制'''
# pyautogui.typewrite('xnsydx1', 0.5)  # 模拟键盘依次敲击x,n,s,y,d,x,1;每次敲击间隔0.5秒
# pyautogui.typewrite(['x', 'n', 's', 'y', 'd', 'x', '1'], 0.5)  # 作用完全同上
# pyautogui.keyDown('shiftleft')  # 按下键
# pyautogui.press(['4', '5'])  # 敲击键
# pyautogui.keyUp('shiftleft')  # 松开键
pyautogui.hotkey('ctrl', 'n')  # 接受多个键字符串参数，按顺序按下，再按相反的顺序松开
# 键盘键字符串                                    含义
# 'a', 'b', 'c', 'A', 'B', 'C',
# '1', '2', '3',
# '!', '@', '#'，等等                         单个字符的键

# 'enter'（or 'return' or '\n'）              回车键
# 'esc'                                      Esc 键
# 'shiftleft', 'shiftright'                  左右Shift 键
# 'altleft', 'altright'                      左右Alt 键
# 'ctrlleft', 'ctrlright'                    左右Ctrl 键
# 'tab'（or '\t'）                            Tab 键
# 'backspace', 'delete'                      Backspace 和Delete 键
# 'pageup', 'pagedown'                       Page Up 和Page Down 键
# 'home', 'end'                              Home 和End 键
# 'up', 'down', 'left', 'right'              上下左右箭头键
# 'f1', 'f2', 'f3'，等等                      F1 至F12 键
# 'volumemute', 'volumedown', 'volumeup'     静音、减小音量、放大音量键（有些键盘没有这些键，但你的操作系统仍能理解这些模拟的按键）
# 'pause'                                    Pause 键
# capslock', 'numlock', 'scrolllock'         Caps Lock，Num Lock 和Scroll Lock 键
# 'insert'                                   Ins 或Insert 键
# 'printscreen'                              Prtsc 或Print Screen 键
# 'winleft', 'winright'                      左右Win 键

