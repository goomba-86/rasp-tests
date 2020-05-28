#include <unistd.h>
#include "gpio.h"
#include <iostream>

int main()
{
	Gpio red(17);
	red.SetPinMode(PinMode::output);
	Gpio green(27);
	green.SetPinMode(PinMode::output);
	Gpio blue(22);
	blue.SetPinMode(PinMode::output);

	short rgb_value = 1;
	while(true)
	{
		sleep(1);
		std::cout << "RGB value: " << rgb_value << std::endl;

		if(rgb_value & 1)
			red.DigitalWrite(PinValue::high);
		else
			red.DigitalWrite(PinValue::low);

		if(rgb_value & 2)
			green.DigitalWrite(PinValue::high);
		else
			green.DigitalWrite(PinValue::low);

		if(rgb_value & 4)
			blue.DigitalWrite(PinValue::high);
		else
			blue.DigitalWrite(PinValue::low);
	
		if(rgb_value < 7)
			rgb_value++;
		else
			rgb_value = 1;
		
	}

	return 0;
}
