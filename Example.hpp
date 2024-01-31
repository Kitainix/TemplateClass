﻿#pragma once

#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

// Весь перечень полей и методов должен быть в файле заголовка.
class Example {
private:
	int a;
	float b;
public:
	// Конструктор и деструктор подчиняются тем же правилам, что и остальные методы класса. 
	// Но если это необходимо их можно просто объявить как реализуемые компилятором.
	Example() :a(0), b(0.) {}
	~Example() = default; // Деструктор создаст компилятор.

	// Все методы классов по умолчанию помечаются компилятором как inline.
	int GetA()const {
		return a; // Короткие методы можно оставлять в заголовочном файле.
	}

	// Методы класса чья реализация отделена от объявления теряют приписку inline со стороны компилятора.
	float Workload()const;
	// Функция Workload содержит цикл - это 100% гарантия того, что компилятор не сможет её встроить, а значит её вынос в "cpp" выгоден для работы над проектом.
};

// Перечень операций, которые гарантированно надо выносить в "cpp":
// - работа с ресурсами системы.
// - работа с объектами других классов.

#endif // !EXAMPLE_HPP