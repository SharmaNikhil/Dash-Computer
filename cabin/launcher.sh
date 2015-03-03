#!/bin/sh
#launcher.sh
#navigate to cabin code directory, start cabin.py

cd /home/pi/cabin
ret=$?
if [ ret -eq 0 ]
	echo "Navigated to cabin directory"
	echo "Launching cabin.py"
	sudo python cabin.py
else
	echo "Failed to navigate to cabin directory"
	echo "Return was $ret"
	echo "Exiting launcher.sh"
	exit