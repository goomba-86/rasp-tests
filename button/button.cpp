#include <iostream>
#include "gpio.h"
#include <unistd.h>

int main()
{
	Gpio gpio(17);
	gpio.SetPinMode(PinMode::input);
	while(true)
	{
		auto button_pressed = gpio.DigitalRead() == PinValue::high;
		if(button_pressed)
			std::cout << "Button pressed." << std::endl;
		else
			std::cout << "Button not pressed." << std::endl;
		sleep(1);
	}
}
