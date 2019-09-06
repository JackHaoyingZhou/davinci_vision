#!/usr/env/bin python

import cv2
import pyscreenshot as ImageGrab
import numpy as np

while(True):
    printscreen_pil = ImageGrab.grab(bbox=(0,0,1280,1024)) # grab the left-most monitor only
    printscreen_numpy = np.array(printscreen_pil.getdata(),dtype='uint8')\
    .reshape((printscreen_pil.size[1],printscreen_pil.size[0],3))
    cv2.imshow('window',printscreen_numpy)
    if cv2.waitKey(25) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break
