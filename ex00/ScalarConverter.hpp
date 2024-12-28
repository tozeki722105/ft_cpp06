#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits>

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
	static void typePutChar(const std::string &str);
	static void typePutInt(const std::string &str);
	static void typePutFloat(const std::string &str);
	static void typePutDouble(const std::string &str);
	static e_type getNumericType(const std::string &str);
	static e_type getType(const std::string &str);

	template <typename ARG_T, typename VALIDATE_T>
	static bool isOverFlow(ARG_T val);
	template <typename ARG_T>
	static bool isOverFlow(ARG_T val);
	template <typename T>
	static bool isInt(T val);
};


template <typename ARG_T, typename VALIDATE_T>
bool ScalarConverter::isOverFlow(ARG_T val)
{
	return (val < std::numeric_limits<VALIDATE_T>::min() ||
			val > std::numeric_limits<VALIDATE_T>::max());
}

template <typename ARG_T>
bool ScalarConverter::isOverFlow(ARG_T val)
{
	return (val < -std::numeric_limits<float>::max() ||
			val > std::numeric_limits<float>::max());
}

template <typename T>
bool ScalarConverter::isInt(T val)
{
	return (val == static_cast<T>(static_cast<long long>(val)));
}



#endif
