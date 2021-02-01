import serial
import pyautogui

# The port that the arduino is plugged into (Check the port setting in your IDE)
port = "COM5"

arduino = serial.Serial(port, 9600)
while True:

    try:
        data = arduino.readline()[:-2].decode("utf-8")
        print(data)
        if(len(data) > 0):
            if(data == "1"):
                pyautogui.mouseDown()
            elif(data == "0"):
                pyautogui.mouseUp()
    except Exception:
        print("Error happened")
