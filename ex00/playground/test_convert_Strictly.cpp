
#include "../ScalarConverter.hpp"

// 宣言
//  template <typename T>
//  static bool isInt(T val);
//  template <typename VAL_T, typename LIM_T>
//  static bool isOver(VAL_T val);
//  static bool isFloatCastable(double val);
//  static bool isNanOrInf(const std::string &str);

template <typename T>
bool ScalarConverter::isInt(T val)
{
	return (val == static_cast<T>(static_cast<int>(val)));
}

template <typename VAL_T, typename LIM_T>
bool ScalarConverter::isOver(VAL_T val)
{
	return (std::numeric_limits<LIM_T>::min() > val || std::numeric_limits<LIM_T>::max() < val);
}

bool ScalarConverter::isFloatCastable(double val)
{
	return (val == static_cast<double>(static_cast<float>(val)));
}

bool ScalarConverter::isNanOrInf(const std::string &str)
{
	return (str == "nan" || str == "+inf" || str == "-inf");
}

template <>
bool ScalarConverter::isOver<double, float>(double val)
{
	return (-(std::numeric_limits<float>::max()) > val && std::numeric_limits<float>::max() < val);
}

void ScalarConverter::typePutFloat(const std::string &str)
{
	const_cast<std::string &>(str).resize(str.length() - 1);
	std::istringstream iss(str);
	float val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Float");

	// char
	if (isNanOrInf(str) || !isInt(val) || isOver<float, char>(val)) {
		std::cout << "char: impossible\n";
	} else {
		putCharPrintable(static_cast<int>(val));
	}
	// int
	if (isNanOrInf(str) || !isInt(val) || isOver<float, int>(val)) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
	// float
	if (isInt(val)) {
		std::cout << "float: " << static_cast<float>(val) << ".0f\n";
	} else {
	}
	std::cout << "float: " << static_cast<float>(val) << "f\n";
	// double
	if (isInt(val)) {
		std::cout << "double: " << static_cast<double>(val) << ".0\n";
	} else {
		std::cout << "double: " << static_cast<double>(val) << "\n";
	}
}

void ScalarConverter::typePutDouble(const std::string &str)
{
	std::istringstream iss(str);
	double val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Double");

	// char
	if (isNanOrInf(str) || !isInt(val) || isOver<double, char>(val)) {
		std::cout << "char: impossible\n";
	} else {
		putCharPrintable(static_cast<int>(val));
	}
	// int
	if (isNanOrInf(str) || !isInt(val) || isOver<double, int>(val)) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
	// float
	if (isOver<double, float>(val)) {
		std::cout << "float: impossible\n";
	} else if (isInt(val)) {
		std::cout << "float: " << static_cast<float>(val) << ".0f\n";
	} else {
		std::cout << "float: " << static_cast<float>(val) << "f\n";
	}
	// double
	if (isInt(val)) {
		std::cout << "double: " << static_cast<double>(val) << ".0\n";
	} else {
		std::cout << "double: " << static_cast<double>(val) << "\n";
	}
}