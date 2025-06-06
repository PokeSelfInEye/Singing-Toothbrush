#!/usr/bin/python3 
#specifies the program used to run the script.

import mido
import serial
from mido import MidiFile

port = "/dev/ttyUSB0"
baudrate = 57600

try:
	ser = serial.Serial(port, baudrate, timeout=1)
	print(f"Serial port {ser.name} opened successfully")
except serial.SerialException as e:
    print(f"Error opening serial port: {e}")
    exit()

#load a midi file
#mid = MidiFile('mary4.mid')
#mid = MidiFile('Star_Wars_Main_Theme Stepper.mid')
mid = MidiFile('Axel_F2.mid')
if mid is None: 
	print('Empty Variable')
else: 
	print('File Loaded!')

#print available ports
#print(mido.get_output_names())

#print the contents of the midi file.
#for i, track in enumerate(mid.tracks):
#	print('Track {}: {}'.format(i, track.name))
#	for msg in track:
#		print(msg)

#open a port either external with ttymidi or internal with timidity
#outport = mido.open_output('Midi Through:Midi Through Port-0 14:0')
#outport = mido.open_output('/dev/ttyUSB0')

#play the file on the assigned port
#for msg in MidiFile('mary.mid').play():
for msg in mid.play():
	#outport.send(msg)
	data = msg.bytes()
	ser.write(bytes(data))
	print(f"Sent: {data}")

#close the port
#outport.close()
ser.close()

