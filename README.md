========================================
About arduino_http_post
========================================
This project is an super simple example of using an Arduino board to POST data
to the cloud via Exosite.  It assumes that your Arduino board has a Wiznet 
Ethernet shield connected.

License is BSD, Copyright 2011, Exosite LLC (see LICENSE file)

Tested with Arduino 22

========================================
Quick Start
========================================
1) Download the Arduino toolchain and development environment<br>
* http://www.arduino.cc/en/Main/software<br>

2) Open the "arduino_http_post.pde" file from the Arduino software<br>

3) Edit the "PUTYOURCIKHERE" value in arduino_http_post.h to match your CIK value<br>
* HINT: Obtain a CIK from https://portals.exosite.com by clicking +Add Device<br>

4) Edit the network values in arduino_http_post.h to match your network setup<br>
* e.g. ip, gateway, subnet<br>

5) In Portals (https://portals.exosite.com), add two DataSources to match the 
data resource numbers the code is using.<br>
* HINT: Goto https://portals.exosite.com/manage/data and click +Add Data Source<br>
* HINT: Ensure the "Resource:" values are set to "1" and "2" respectively to match
the code<br>

6) In the Arduino software, compile and verify there are no errors<br>

7) Go to Tools->Serial Port and select the serial port your Arduino is connected to<br>

8) Go to File->Upload to I/O Board to upload the program<br>

9) After "Done uploading" is displayed, go to https://portals.exosite.com to see
your data in the cloud!<br>
* HINT: Your Arduino must be connected to the Internet via the RJ-45 ethernet jack<br>

For more information on this project and other examples, checkout our Exosite
Garage github page at http://exosite-garage.github.com<br>

========================================
Release Info
========================================
----------------------------------------
Release 2011-10-18
----------------------------------------
--) added readme.md file<br>
