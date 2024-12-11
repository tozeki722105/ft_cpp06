#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &str);

private:
	ScalarConverter() {};
	~ScalarConverter() {};

	enum e_type {
		ERROR = 1,
		CHAR = 2,
		INT = 3,
		FLOAT = 4,
		DOUBLE = 5,
	};

	static void putCharPrintable(int c);
	static void typePutfChar(const std::string &str);
	static void typePutInt(const std::string &str);
	static void typePutFloat(const std::string &str);
	static void typePutDouble(const std::string &str);
	static e_type getNumericType(const std::string &str);
	static e_type getType(const std::string &str);
};

#endif
