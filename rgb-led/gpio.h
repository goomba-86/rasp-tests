#include <string>

enum class PinMode {input, output};
enum class PinValue {high, low};

class Gpio
{
public:
	Gpio(int pin_number);
	~Gpio();
	void DigitalWrite(PinValue value) const;
	PinValue DigitalRead() const;
	void SetPinMode(PinMode mode) const;

private:
	void Export() const;
	void Unexport() const;
	std::string GetPinFolder() const { return gpio_sys_path + "gpio" + std::to_string(pin_number) + "/"; }
	void WriteFile(const std::string& path, const std::string& value) const;
	int ReadFile(const std::string & path) const;
	static const std::string gpio_sys_path;
	int pin_number;
};
