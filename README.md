Smart Bank Locker Access System with Password and RFID Authentication using LPC2129

Project Overview:

The Smart Bank Locker Access System is an embedded security project developed using the LPC2129 (ARM7) microcontroller. It implements a two-level authentication mechanism using an RFID reader and a 4×4 matrix keypad to provide secure access to a bank locker.

The user must first scan an authorized RFID card and then enter the correct password through the keypad. Access is granted only when both authentication steps are successful.

If the user enters an incorrect password three consecutive times, the system activates a buzzer and locks the system. An LCD displays the access status, while UART communication sends authentication details to a PC for monitoring.



Objectives:

Implement two-level security using RFID and password authentication.
Interface an EM-18 RFID reader with the LPC2129 using UART.
Interface a 4×4 matrix keypad for password entry.
Control a DC geared motor for locker locking and unlocking.
Display authentication status using a 16×2 LCD.
Implement a security mechanism with a maximum of three incorrect password attempts.
Monitor authentication activities through UART communication.


Working Principle:

The system follows a two-level authentication process.

Step 1: RFID Authentication
The user scans an RFID card using the EM-18 reader.
The RFID reader transmits the card ID to the LPC2129 through UART.
The microcontroller compares the received ID with the authorized RFID ID.
If the card is invalid, access is denied.

Step 2: Password Authentication
After successful RFID authentication, the LCD prompts the user to enter a password.
The user enters the password through the 4×4 matrix keypad.
The LPC2129 compares the entered password with the predefined password.

Step 3: Access Control
If both RFID and password authentication are successful:
The DC motor unlocks the locker through the L293D motor driver.
The LED glows.
The LCD displays "Access Granted".

Step 4: Security Mechanism
If the password is incorrect, the attempt counter is incremented.
After three incorrect password attempts:
The buzzer is activated.
The system locks itself.
Further access is restricted.

Step 5: UART Monitoring
Authentication attempts and access status are transmitted to a PC through UART.
This allows the user to monitor system activities through a serial terminal.


System Flow:

System Initialization
LCD displays the welcome message.
Scan RFID card.
Verify RFID card ID.
If valid, prompt for password.
Enter password using the keypad.
Verify password.
If correct, unlock the locker.
If incorrect, increment the attempt counter,led 2 blinks and activate the buzzer.
After three incorrect attempts and lock the system.


Communication Protocol:

UART (Universal Asynchronous Receiver/Transmitter)
UART is used for communication between the EM-18 RFID reader and LPC2129, and for transmitting authentication information to a PC.
Display authentication status through LCD and UART.



Project Details

Project Name: Smart Bank Locker Access System with Password and RFID Authentication using LPC2129
Microcontroller: LPC2129 (ARM7)
Programming Language: Embedded C
Communication: UART
Development Environment: Keil µVision 4
Simulation Tool: Proteus
