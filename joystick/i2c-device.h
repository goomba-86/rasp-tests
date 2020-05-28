#include <vector>

class I2cDevice
{
public:
	I2cDevice(unsigned int device);
	~I2cDevice();
	unsigned char ReadRegister(unsigned int register_address);
    void WriteRegister(unsigned int register_address);
	void WriteRegister(unsigned int register_address, unsigned char value);
	std::vector<char> ReadRegisters(unsigned int number, unsigned int from_address = 0);
private:
	void Open(unsigned int device);
	void Close();

	int file;
};
