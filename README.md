# servo_switch
This implements a very simple A/B mechanical switch box using an Arduino Nano and a mini servo.

I had a need for some physical switch automation in a remote laboratory situation. The direct need was I had two rarely switch an Ethernet connection from the building LAN to a direct attached Ethernet port on the associated PC to perform emergency code recovery.

I found a simple push button physical Ethernet switch for about $12 with two push buttons on the lid. The next problem was how to automate that. I settled on using a micro servo driven by an Arduino. Using the standard servo library, and the standard Serial library, I created a loop that looks for a '=' sign to indicate an incoming command, then the next character must be a '1', '2', or another '='. A '1' selects port 1, a '2' selects port 2, and an '=' reports to the serial port the last requested switch.

As far as the servo activation, the attached horn was perfect for pressing the buttons, and the servo body, fastened to the top with double stick tape, happed to be the perfect offset to have the horn pivot down to press the buttons. All I had to do was to trim the horn length a bit, and bevel the corners.

In the code, in the init block, it selects port 1, then returns to a neutral. Because I really expect port 1 in the 'normal' case.

I found that the horn, on the spline, was offset from '90 degrees' no matter how you splined it, so in the code, there is an offset value, that centers the horn when you select 90 degrees. Then through experimentation, I determined the swing required to properly activate the switches (26 degrees) and added one degree to ensure activation.

And that was it.
