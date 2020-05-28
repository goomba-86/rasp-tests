#include "i2c-device.h"
#include <iostream>
#include <unistd.h>

int main()
{
	I2cDevice device(0x48);
	
	while(true)
	{
		auto value = static_cast<int>(device.ReadRegister(64));
		auto value2 = static_cast<int>(device.ReadRegister(65));

		auto value3 = static_cast<int>(device.ReadRegister(66));
		auto value4 = static_cast<int>(device.ReadRegister(67));


		std::cout << std::hex << value << " " << value2 << " " << value3 << " " << value4 << std::endl;
		sleep(0.2);
	}
	return 0;
}
