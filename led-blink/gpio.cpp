#include <fstream>
#include <iostream>
#include <unistd.h>
#include "gpio.h"

const std::string Gpio::gpio_sys_path = "/sys/class/gpio/";

Gpio::Gpio(int pin_number) : pin_number(pin_number)
{
	Export();
}

Gpio::~Gpio()
{
	Unexport();
}

void Gpio::DigitalWrite(WriteValue value) const
{
	auto value_path = GetPinFolder() + "value";
	if(value == WriteValue::high)
		WriteFile(value_path, "1");
	else
		WriteFile(value_path, "0");	
}

void Gpio::Export() const
{
	auto export_path = gpio_sys_path + "export";
	WriteFile(export_path, std::to_string(pin_number));
    usleep(250000);
}

void Gpio::Unexport() const
{
	auto export_path = gpio_sys_path + "unexport";
	WriteFile(export_path, std::to_string(pin_number));
    usleep(250000);
}

void Gpio::WriteFile(const std::string& path, const std::string& value) const
{
	std::ofstream file;
	file.open(path);
	file << value;
	file.close();	
}

void Gpio::SetPinMode(PinMode mode) const
{
	auto direction_path = GetPinFolder() + "direction";
	std::cout << direction_path << std::endl;
	if(mode == PinMode::output)
		WriteFile(direction_path, "out");
	else
		WriteFile(direction_path, "in");
}
