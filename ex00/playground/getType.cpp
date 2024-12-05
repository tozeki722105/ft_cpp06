#include <iostream>
#include <sstream>
#include <string>

typedef enum e_type {
	ERROR = 1,
	CHAR = 2,
	INT = 3,
	FLOAT = 4,
	DOUBLE = 5,
} t_type;

t_type getNumericType(const std::string &str)
{
	if (str.empty())
		return ERROR;

	bool point_flag = false;
	size_t i = (str[0] == '+' || str[0] == '-');
	// (.)が先頭
	if (str[i] == '.')
		return ERROR;

	for (; i + 1 < str.length(); i++) {
		// 初めての(.) && 次が数値
		if (!point_flag && str[i] == '.' && std::isdigit(str[i + 1]))
			point_flag = true;
		else if (!std::isdigit(str[i]))
			return ERROR;
	}

	if (str[i] == 'f' && point_flag)
		return FLOAT;
	else if (std::isdigit(str[i]))
		return point_flag ? DOUBLE : INT;
	return ERROR;
}

t_type getType(const std::string &str)
{
	if (str.empty())
		return ERROR;
	// 特殊ケース
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return FLOAT;
	if (str == "+inf" || str == "-inf" || str == "nan")
		return DOUBLE;

	// char type
	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;

	//  numeric type
	if (str.find_first_not_of("0123456789+-.fe") != std::string::npos)
		return ERROR;
	std::string::size_type e_pos = str.find('e');
	if (e_pos == std::string::npos)
		return (getNumericType(str));
	std::string mantissa = str.substr(0, e_pos);
	bool fFlag = str.find('f') == str.length() - 1;  // ex)42e3f
	std::string exponent = str.substr(e_pos + 1, str.length() - e_pos - 1 - fFlag);
	t_type mantissaType = getNumericType(mantissa);
	if (mantissaType == ERROR || mantissaType == FLOAT  // ex)42fe1,42fe2f
			|| getNumericType(exponent) != INT)
		return ERROR;
	return fFlag ? FLOAT : DOUBLE;
	// std::cout << mantissa << ' ' << exponent << ' ';
}

void disp(const std::string &str)
{
	try {
		std::cout << str << ": " << getType(str) << '\n';
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	// eケース
	std::cout << "<イプシロン>\n";
	disp("4e2");
	disp("4e-2");
	disp("4.2e2");
	disp("4.2e-2");
	disp("4.2e-2f");

	//?ケース
	std::cout << "<?ケース>\n";
	disp(".42");
	disp(".42f");
	disp("-.42");
	disp("-.42f");
	disp("42.");
	disp("42.f");
	disp("42f");
	disp("42.e1");
	disp("42.e1f");
	disp(".42e1");
	disp(".42e1f");

	// err
	std::cout << "<エラーケース>\n";
	disp("");
	disp("42f");
	disp("4.2fe1");
	disp("42.0e");
	disp("4.2f.");
	disp("-4-2");
	disp("-42-");
	disp("-42.-2");
	disp("2-4.2");
	disp("4.2e-0.2");
	disp("nAn");
	disp("+infff");
	disp("+iNfff");
}
