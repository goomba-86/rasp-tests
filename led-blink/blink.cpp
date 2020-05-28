#include <unistd.h>
#include "gpio.h"

int main()
{
	Gpio gpio(17);
	gpio.SetPinMode(PinMode::output);
	while(true)
	{
		gpio.DigitalWrite(WriteValue::high);
		sleep(1);
		gpio.DigitalWrite(WriteValue::low);
		sleep(1);
			
	}
}
