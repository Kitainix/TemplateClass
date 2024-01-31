#include "MathOperator.hpp"

void PrintSumm(const MathOperator<int>& obj) {
	std::cout << obj.GetLeft() << '+' << obj.GetRight() << '=' << obj.Summ() << '\n';
}

