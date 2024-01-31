#include <iostream>
#include "MathOperator.hpp"


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	const MathOperator<float> f(1., 2.);
	std::cout << f.Summ() << '\n';
	// f.GetLeft(6); Для константного контекста невозможно вызвать неконстантный метод.

	std::cout << f.GetLeft() << '+' << f.GetRight() << '=' << f.Summ() << '\n';
	// Остальное взаимодействие аналогично любым другим объектам класса.


	MathOperator<float> f2(1.5, 2.9);
	std::cout << f2.Summ() << '\n';

	f2.SetRight(f2.GetRight() + 1.6);
	std::cout << f2.GetLeft() << '+' << f2.GetRight() << '=' << f2.Summ() << '\n';

	// MathOperator<bool> b;

	std::cout << 4 << '*' << 9 << '=' << MathOperator<int>(4,9).Multiply() << '\n';
	// При работе с шаблонными классами нет запретов на использование анонимных объектов. При создании анонимного объекта от шаблонного класса так же указывается его специализация.

	PrintSumm(MathOperator<int>(4, 9));

	MathOperator<int> int_m(1, 54);
	PrintSumm(int_m);
	// PrintSumm(f2); // Невозможно так как в функции упомянута конкретная реализация.

	PrintMultiply(f);
	PrintMultiply(int_m);
	PrintMultiply(MathOperator<bool>(true, false));

	return 0;
}