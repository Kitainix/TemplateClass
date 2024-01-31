// При организации шаблонного класса в виде библиотеки требуется весь код, который является шаблоном, оставить в заголовочном файле. 
// В Файл реализации переносятся только те элементы, которые имеют полное определение. Например функции и вспомогательные классы, которые не являются шаблонами.

#pragma once

#ifndef MATH_OOPERATOR_HPP
#define MATH_OOPERATOR_HPP

#include <iostream>

template<typename Type>
class MathOperator {
private:
	Type operand1;
	Type operand2;
public:
	// Конструктор по умолчанию.
	MathOperator() :operand1(Type()), operand2(Type()) {}
	// В создании полей используется Type() для совместимости с любым возможным хранимым типом.

	// Конструктор с параметром.
	MathOperator(Type left, Type right) :operand1(left), operand2(right) {}

	// Сеттеры принимают аргументы шаблонного типа данных. Это позволяет коректно занести информацию в поля того же шаблонного типа.
	void SetLeft(Type num) {
		operand1 = num;
	}
	void SetRight(Type num) {
		operand2 = num;
	}

	// Геттеры возвращают шаблонный тип чтобы не было конфликтов при возврате полей.
	Type GetLeft()const {
		return operand1;
	}
	Type GetRight()const {
		return operand2;
	}
	Type Summ()const {
		return operand1 + operand2;
	}
	Type Multiply()const {
		return operand1 * operand2;
	}
};

template<>
class MathOperator<bool> {
private:
	bool operand1;
	bool operand2;
public:
	MathOperator() :operand1(false), operand2(false) {}

	// Конструктор с параметром.
	MathOperator(bool left, bool right) :operand1(left), operand2(right) {}

	// Сеттеры принимают аргументы шаблонного типа данных. Это позволяет коректно занести информацию в поля того же шаблонного типа.
	void SetLeft(bool num) {
		operand1 = num;
	}
	void SetRight(bool num) {
		operand2 = num;
	}

	// Геттеры возвращают шаблонный тип чтобы не было конфликтов при возврате полей.
	bool GetLeft()const {
		return operand1;
	}
	bool GetRight()const {
		return operand2;
	}
	bool Summ()const {
		return operand1 || operand2;
	}
};

// Обработка объектов шаблонного класса.

// Вариант 1. Обработка конкретной специализации.

void PrintSumm(const MathOperator<int>& obj);

// Вариант 2. Обработка обобщённого вида.

template <typename T>
void PrintMultiply(const MathOperator<T>& obj) {
	std::cout << obj.GetLeft() << '*' << obj.GetRight() << '=' << obj.Multiply() << '\n';
}

// Решение проблемы обработки в специализации шаблона.
template <>
void PrintMultiply<bool>(const MathOperator<bool>& obj) {
	// Вариант 1 обработки: кидаем исключение.
	// throw -1; Если так не делать то проблема с некоректным поведением программы может вылезти в будущем в непредсказуемый момент времени.

	// Вариант 2 обработки: работаем с учётом особенностей входных данных.
	std::cout << obj.GetLeft() << '*' << obj.GetRight() << " Не разрешённая операция.";
}
#endif // !MATH_OOPERATOR_HPP