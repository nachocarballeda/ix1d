from time import sleep
import serial

zigbee = serial.Serial('/dev/ttyUSB0', 38400 ) # Establish the connection on a specific port

def actualizar_led():
    M = medir_m()
    print M 
    if   M >= 200:
        led_verde()
    elif M >= 120:
        led_amarillo()
    else :
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
    print "BOMBA A encendida"
    if zigbee.readable():
        zigbee.write('A')

def encender_bomba_b():
    print "BOMBA B encendida"
    if zigbee.readable():
        zigbee.write('B')

def apagar_bomba_a():
    print "BOMBA A apagada"
    if zigbee.readable():
        zigbee.write('C')

def apagar_bomba_b():
    print "BOMBA B apagada"
    if zigbee.readable():
        zigbee.write('D')

def led_rojo():
    print "LED ROJO"
    if zigbee.readable():
        zigbee.write('R')

def led_amarillo():
    print "LED AMARILLO"
    if zigbee.readable():
        zigbee.write('E')

def led_verde():
    print "LED VERDE"
    if zigbee.readable():
        zigbee.write('W')

def led_apagar():
    if zigbee.readable():
        zigbee.write('Q')

if __name__=='__main__':
    print "Codigo IX1D \n"
    while True:
        actualizar_led()
        sleep(1)
        M = medir_m()
        if M <= 20:
            while not M > 200:
               #encender_bomba_b()
                sleep(1)
                actualizar_led()
                sleep(0.5)
        #apagar_bomba_b()
