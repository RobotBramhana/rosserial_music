
> ### Requirements

**Platform**
ROS - Kinetic

**Softwares**
* Arduino IDE - To build and flash the program.
* Doxygen - To generate documentation of the code.

**Hardwares**
* Arduino UNO or Mega or microcontroller.
* Buzzer
* USB cable

> ## Circuit
Connect the piezo buzzer to ```PIN 9``` and ```GND``` as shown in the image below.
![Circuit](Circuit.png)
> ## Instructions
* Open the selected package/project of your choice in Arduino IDE.
* Select the board from ```Tools```
* Build the code.
* Upload/flash the program on the microcontroller.
* To generate documentation, issue the command ```doxygen Doxyfile```. The documentation will be generated in the ```docs``` folder.

Visit [this](https://github.com/RobotBramhana/arduino_music/wiki/Quick-compose-guide) wiki page for composing a new tune.

---

sudo apt-get install arduino arduino-core ros-kinetic-rosserial ros-kinetic-rosserial-arduino

## Author
Sudhanva S


