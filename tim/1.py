import keyboard
import time

keyboard.wait('f1')
# keyboard.add_hotkey('esc', lambda: exit(0))
for i in range(0,1000000):
    s = '%06d' % (999999 - i)
    keyboard.write(str(s))
    keyboard.press_and_release("enter")
    time.sleep(0.05)
    
    for j in range(0,7):
        keyboard.press_and_release("backspace")
        time.sleep(0.01)
    
 
