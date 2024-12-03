#include <iostream>
#include <sstream>
#include <string>

#define HEAD_C "char: "
#define HEAD_I "int: "
#define HEAD_F "float: "
#define HEAD_D "double: "

void ss_test(const std::string &literal)
{
	std::stringstream ss1(literal);
	std::stringstream ss2(literal);
	std::stringstream ss3(literal);

	int num_i;  // 数値以外が入った時点でそこまでの数値でconvert(.も含む)
	if (ss1 >> num_i) {
		std::cout << HEAD_I << num_i << '\n';
	} else {
		ss1.clear();
		std::cout << "int err\n";
	}
	// 1.57275e+07 や 1.57275e-07 は通す
	// 1.57275-7 -> 1.57275
	// 1.57275e -> error
	// \9\9 -> 99
	// \9 -> 9
	// この表記以外のアルファベットが入れば弾く
	float num_f;
	if (ss2 >> num_f) {
		std::cout << HEAD_F << num_f << '\n';
	} else {
		ss2.clear();
		std::cout << HEAD_F << "error" << '\n';
	}
	double num_d;
	if (ss3 >> num_d) {
		std::cout << HEAD_D << num_d << '\n';
	} else {
		ss3.clear();
		std::cout << HEAD_D << "error" << '\n';
	}
	// "K" ->K
	// 'K' -> error ->Kで出力された
	// "Kj" -> error ->Kで出力された
	// \gnl -> g
	// \' -> '
	// '9' -> err
	// 9 -> err
	// \9 -> err
	char num_c;
	if (ss3 >> num_c) {
		std::cout << HEAD_C << num_c << '\n';
	} else {
		ss3.clear();
		std::cout << HEAD_C << "error" << '\n';
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	for (size_t i = 0; argv[i]; i++) {
		std::cout << argv[i] << ';' << std::endl;
	}

	ss_test(argv[1]);
}