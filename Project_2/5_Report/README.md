# Bi-com System
## 1) Description

As we have seen the unidirectional in Remote Keyless Entry(RKE), now in BiCom system we will witness bi-directional i.e.., information from keyfob to car viceversa. The status of the car will also be displayed on the keyfob by LED or display

## 2) Identifying Features

* LCD display should be provided on the keyfob to display the car's status.
* High security is provided to unlock the system.
* It shall print the car's window status on LCD (Blue switch on - All led on at the same time)
* It shall print the car's alarm status on LCD (Blue switch press two times - All led off at the same time)
* It shall print the car's battery information on LCD (Blue switch press three times - All led on in clockwise manner)
* It shall print the car's door status on LCD (Blue switch press four times - All led on in clockwise manner)

## 3) State of art

An RKS, which is widely used in automobiles, accomplishes the tasks of a traditional car key without requiring physical touch. Pressing a button on the remote while within a few yards of the automobile can lock or unlock the doors, as well as conduct other operations. A remote keyless entry system (RKE) that unlocks the doors and a remote keyless ignition system (RKI) that starts the engine are both part of a remote keyless system. 

## 4) 5W's 1H
![](/Project_1/6_ImagesAndVideos/5W1H.jpeg)

## 5) SWOT Analysis
![](/Project_1/6_ImagesAndVideos/swot.jpeg)

 ## 6) Requirements Levels
 ##### 6.1) High Level Requirements 
 | HLR | Depiction |
 |-----|-----------| 
 | HLR_01 | It will print the door's status.|
 | HLR_02 | It will print information regarding the car's battery.|
 | HLR_03 | It will print the alert status. | 
 | HLR_04 | It will print the window's state |
 
 ##### 6.2) Low Level Requirements 
 | HLR | LLR | Depiction |
 |-----|-----|-----------|
 | HLR_01 | LLR_01 | When you click the button, all of the LEDs turn anticlockwise.|
 | HLR_02 | LLR_01 | When you click the button, all of the LEDs turn on in a clockwise direction.|
 |HLR_03 | LLR_01 | When the button is pressed, all LEDs should turn off at the same time. |
 |HLR_04 | LLR_01 | When the button is pressed, all LEDs should turn on at the same time. |
 
## 7) General System Description
###### 7.1) System functions
The BiCom system provides the following car access functions: remote keyless entry, passive entry (PE), passive start (PS) 
and passive lock (PL). In addition, it also includes the following system configuration functionalities: a learning procedure for 
pairing vehicle and key fob, RKE rolling code synchronization, and end-of-line parameters (RSSI compensation, etc.). When the driver 
approaches the vehicle, a secure wireless communication between the key fob and the vehicle control unit authenticates the fob. Bi-directional
wireless communication authenticates the key fob and the vehicle in both one-way and two-way systems. In one-way RF systems the LF downlink 
serves to wake up the key and to receive commands as well as data for the authentication process. The fob then sends the response to the vehicle
via RF uplink. In two-way RF systems the LF downlink only serves to wake up the key fob and to establish the RF up-/downlink. The bi-directional 
RF link handles the entire communication during the authentication process.

###### 7.2) Remote Keyless Entry
In addition to the lock and unlock function, you can include supplemental remote functions in the key fobs even 
with the system.  For example, if the driver wants to lock the doors via RKE, the vehicle needs to check for active 
keys inside the vehicle cabin. If a paired key fob is detected inside the cabin, it must be disabled for the next passive entry request. 

###### 7.3) Bi-directional Authentication
The bi-directional procedure offers increased security compared to uni-directional authentication.
The fob authenticates the vehicle before replying, and in a second step, the vehicle authenticates the fob. 
Both steps use different secret keys.

###### 7.4) Communication Interfaces
A system communicates bidirectionally via three different communication channels:
 • Bidirectional, short-range (4 to 5cm) LF communication 
• Unidirectional, medium-range (about 2 to 3m) 3D-LF communication 
• Long-range (10 to 30m) RF communication, both one and two-way RF 

## 8) Applications
Bicom system uses advanced technology to take vehicle accessibility to a higher level.
With Bicom car owners have simply to pull the door handle while the key fob is on their person; no searching through 
pockets or purses, no button pressing necessary. 





































