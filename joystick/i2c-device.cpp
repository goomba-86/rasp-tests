#include "i2c-device.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <iostream>

I2cDevice::I2cDevice(unsigned int device)
{
	Open(device);
}

void I2cDevice::Open(unsigned int device)
{
	if((file = open("/dev/i2c-1", O_RDWR)) < 0)
	{
		std::cout << "Unable to open file." << std::endl;
		return;
	}

	if(ioctl(file, I2C_SLAVE, device) < 0)
	{
		std::cout << "Failed to connect the sensor." << std::endl;
		return;
	}
}

I2cDevice::~I2cDevice()
{
	Close();
}

void I2cDevice::Close()
{
	close(file);	
}

unsigned char I2cDevice::ReadRegister(unsigned int register_address)
{
	WriteRegister(register_address);
	
	char buf[1];
	if(::read(file, buf, 1) != 1)
	{
		std::cout << "Unable to read requested values." << std::endl;
	}
	
	return buf[0];
}

void I2cDevice::WriteRegister(unsigned int register_address)
{	
	char buffer[1] = { static_cast<char>(register_address) };
	if(::write(file, buffer, 1) != 1)
	{
		std::cout << "Unable to write to bus. " << std::endl;
	}
}


void I2cDevice::WriteRegister(unsigned int register_address, unsigned char value)
{	
	char request_read_buffer[2] = { static_cast<char>(register_address), value };
	if(::write(file, request_read_buffer, 2) != 2)
	{
		std::cout << "Unable to write to bus. " << std::endl;
	}
}

std::vector<char> I2cDevice::ReadRegisters(unsigned int number, unsigned int from_address)
{
	return std::vector<char>();
}

