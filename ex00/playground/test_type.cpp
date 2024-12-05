#include <cmath>
#include <iostream>

template <typename T>
void disp_cast(T val)
{
	std::cout << val << '\n';
	std::cout << "char: " << static_cast<char>(val) << '\n';
	std::cout << "int: " << static_cast<int>(val) << '\n';
	std::cout << "float: " << static_cast<float>(val) << '\n';
	std::cout << "double: " << static_cast<double>(val) << '\n';
	std::cout << '\n';
}

int main()
{
	// int i = 'A' + 256;
	// disp_cast(i);
	// int i_minn = -10;
	// disp_cast(i_minn);
	// int i_e = 10e3;
	// disp_cast(i_e);
	// int i_e_plu = 10e+3;
	// disp_cast(i_e_plu);

	// float f = 1.3f;
	// disp_cast(f);
	// float f_e = 1.3e3f;
	// disp_cast(f_e);
	// float f_e_min = 1.3e-3f;
	// disp_cast(f_e_min);
	// float f_e_plu = 1.3e+3f;
	// disp_cast(f_e_plu);

	// double d = 1.2;
	// disp_cast(d);
	// double d_e = 1.2e7;
	// disp_cast(d_e);
	// double d_e_min = 4.9e-324;
	// disp_cast(d_e_min);
	// double d_e_plu = 1.2e+10;
	// disp_cast(d_e_plu);

	// double inf = INFINITY;
	// disp_cast(inf);
	// double inf_min = -inf;
	// disp_cast(inf_min);
	// double d_nan = NAN;
	// disp_cast(d_nan);
	// double d_nan_min = -NAN;
	// disp_cast(d_nan_min);

	// double imax_p1 = 2147483648;
	// disp_cast(imax_p1);

	// float last_dot = -.42f;
	// disp_cast(last_dot);

	// float test = .42fe1f;
	// float test1 = 1f;
	long l = 2147483648;
	int num = static_cast<int>(l);
	// std::cout << num << '\n';

	// .42
	// .42f
	// -.42
	// -.42f
	// 42.
	// 42.f

	// 4e2
	// 4e-2
	// 4.2e2
	// 4.2e-2

	// 4.2f.
	// -4-2
	// -42-
	// -42.-2
	// 2-4.2
	// 4.2e-0.2
	// nAn
	// +infff
	// +iNfff
}
// float inff = 1.0f / 0.0f;
// disp_cast(inff);
// float inff_min = -1.0f / 0.0f;
// disp_cast(inff_min);
// float f_nanf = NAN;
// disp_cast(f_nanf);
// float f_nanf_min = -NAN;
// disp_cast(f_nanf_min);