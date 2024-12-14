#include <iostream>

int main()
{
	float min = std::numeric_limits<float>::min();
	float max = std::numeric_limits<float>::max();
	float lowest = std::numeric_limits<float>::lowest();
	float negative_max = -std::numeric_limits<float>::max();
	std::cout << min << '\n' << max << '\n' << lowest << '\n' << negative_max << '\n';
	std::cout << static_cast<int>(min) << '\n'
			  << static_cast<int>(max) << '\n'
			  << static_cast<int>(lowest) << '\n'
			  << static_cast<int>(negative_max) << '\n';
}