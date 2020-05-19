import serial

controllerSerial = serial.Serial("/dev/ttyACM0", baudrate=9600)

try:
    controllerSerial.open()
except serial.serialutil.SerialException:
    print("Already open, cool!")
except:
    while True:
        try: 
            controllerSerial.open()
        except (UnicodeDecodeError, ValueError):
            pass


controllerData = {
    'A': "False",
    'B': "False",
    'C': "False",
    'joy1X': 0,
    'joy1Y': 0
}

currentAction = controllerSerial.readline()

while currentAction != "shutoff":
    while True:
        try:
            currentAction = controllerSerial.readline().decode("utf-8")
            break
        except UnicodeDecodeError:
            pass
    if currentAction.startswith("button"):
        if currentAction[8] == "-":
            controllerData[currentAction[7]] = "False"
        elif currentAction[8] == "+":
            controllerData[currentAction[7]] = "True "
    if currentAction.startswith("joy"):
        controllerData[currentAction[:5]] = int(currentAction[7:])
    if "shutoff" in currentAction:
        controllerSerial.close()
        quit()
    print("                                                                                                      ", end="\r")
    print(controllerData, end="\r")