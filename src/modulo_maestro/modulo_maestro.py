from time import sleep
import serial

zigbee = serial.Serial('/dev/ttyUSB0', 38400 ) # Establish the connection on a specific port

def actualizar_led():
    M = medir_m()
    if M < 160 and M >= 230:
        led_verde()
    if M < 145 and M >= 160:
        led_amarillo()
    if M < 145 :
        led_rojo()


def medir_m():  
    if zigbee.readable():
        zigbee.write('M')
        M = int(zigbee.readline())
        print M
        return M

def medir_n():  
    if zigbee.readable():
        zigbee.write('N')
        M = int(zigbee.readline())
        print N
        return N

def encender_bomba_a():
    if zigbee.readable():
        zigbee.write('A')

def encender_bomba_b():
    if zigbee.readable():
        zigbee.write('B')

def apagar_bomba_a():
    if zigbee.readable():
        zigbee.write('C')

def apagar_bomba_b():
    if zigbee.readable():
        zigbee.write('D')

def led_rojo():
    if zigbee.readable():
        zigbee.write('R')

def led_amarillo():
    if zigbee.readable():
        zigbee.write('E')

def led_verde():
    if zigbee.readable():
        zigbee.write('W')

def led_apagar():
    if zigbee.readable():
        zigbee.write('Q')

if __name__=='__main__':
    while True:
        M = medir_m()
        if M <=140:
            while not M > 220:
                encender_bomba_b()
                sleep(1)
                M = medir_m()
                sleep(0.5)
                actualizar_led()
                sleep(0.5)
        apagar_bomba_b()
        sleep(1)
