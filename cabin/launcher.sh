#!/bin/sh
#launcher.sh
#navigate to cabin code directory (/home/pi/cabin), start cabin.py

cd testfolder/
ret=$?
if [ $? -ne 0 ]; then
	echo "Failed to navigate to cabin directory"
	echo "Return was $ret"
	echo "Exiting launcher.sh"
	exit
else	
	echo "Navigated to cabin directory"
	echo "Launching cabin.py"
	sudo python cabin.py
fi