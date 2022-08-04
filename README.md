# Tony-Stark-style-Keyboard
Tony Stark style Keyboard

In iron man movies you can see tony stark controls his computer with hand gestures, which is so cool.
in this project I built a simple version of tony stark's keyboard, that can
turning it on by swiping hand to the right. and move the mouse cursor between the keyboard letters with hand tracking based virtual mouse.

this project have two parts:
one part is with Arduino that's read a gesture sensor and it sends a command to computer to activate on-screen keyboard.
and other part is hand tracking based virtual mouse in python that runs on the computer.

1.
for this project you need use HID (Human Interface Device) supporting Arduino. I used Digispark board. And a PAJ7620U2 Gesture Sensor.
PAJ7620U2 Gesture Sensor, gesture recognition function with general I2C interface into a single chip. It can recognize 9 gestures including move up, move down, move left, move right, etc. with a simple swipe of your hand.
(this sensor works with 3.3V)

2.
For running the python code you need PyCharm software
before running the code you should install:
opencv
mediapipe
pyautogui 

OpenCV (Open Source Computer Vision Library) is an open source computer vision and machine learning software library.
OpenCV was built to provide a common infrastructure for computer vision applications and to accelerate the use of machine perception in the commercial products.
MediaPipe offers open source cross-platform, customizable ML solutions for live and streaming media. 
PyAutoGUI lets your Python scripts control the mouse and keyboard to automate interactions with other applications.

YouTube Video: https://youtu.be/ZGo54vpdwcc
