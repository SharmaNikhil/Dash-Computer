#cabin.py
#v0.0

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

#Wait for button to be pressed
#Send RF signal
#Display camera input on screen
#	v0.1 Power up reciever
#	v1.0 Set video output to reciever output (switch RPi output from normal)

#Variables
pin_out_rf_output = 0 #TODO change to actual port
pin_out_ind_r = 0 #TODO change to actual port
pin_out_ind_b = 0 #TODO change to actual port
pin_in_button = 0 #TODO change to actual port

time_rf_signal = 3	#seconds
time_camera_on = 60
time_cycle_delay = 0.1

#Pin setup
GPIO.setup(pin_out_rf_output,GPIO.OUT)
GPIO.setup(pin_out_ind_r,GPIO.OUT)
GPIO.setup(pin_out_ind_b,GPIO.OUT)
GPIO.setup(pin_in_button,GPIO.IN)

while True:
	if GPIO.input(pin_in_button):
		print("Button pressed\n")
		GPIO.output(pin_out_ind_b,1)
		GPIO.output(pin_out_rf_output,1)
		print("RF on\n")
		time.sleep(time_rf_signal)
		GPIO.output(pin_out_rf_output,0)
		time.sleep(time_camera_on)
		GPIO.output(pin_out_ind_b,0)
	else:
		GPIO.output(pin_out_ind_r,1)
	time.sleep(time_cycle_delay)