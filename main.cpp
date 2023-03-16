#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

template<typename T>
void show_arr(T* arr, const int length);

template<typename T>
void change_even_odd(T* arr, const int length);

template <typename T>
void func(T* num, int degree);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	srand(time(NULL));

	std::cout << "Exercise 1.\nA program for exchanging the values of even indexes with odd array indexes.\n";
	/*
		Create an array of 10 elements. Write
	a program that will swap all the even and
	odd elements of the array. The element standing at
	position 0 changes values with the element of position 1.
	The element at position 2 changes with the element of position 3
	, etc. Access to the elements of the array is implemented with
	using a pointer variable to the null element
	array.
	Example:
	Initial array:
	[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
	The resulting array:
	[ 2, 1, 4, 3, 6, 5, 8, 7, 10, 9 ]
		
		Создайте массив из 10 элементов. Напишите 
	программу, которая поменяет местами всё чётные и 
	нечётные элементы массива. Элемент, стоящий на
	позиции 0 меняется значениями с элементом позиции 1. 
	Элемент на позиции 2 меняется с элементом позиции 3
	и т. д. Обращение к элементам массива реализуйте с 
	помощью переменной-указателя на нулевой элемент 
	массива.
	Пример:
	Изначальный массив:
	[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
	Итоговый массив:
	[ 2, 1, 4, 3, 6, 5, 8, 7, 10, 9 ]
	*/
	const int length1 = 10;
	int arr1[length1]{ 1,2,3,4,5,6,7,8,9,10 };
	show_arr(arr1, length1);
	change_even_odd(arr1, length1);
	show_arr(arr1, length1);
	std::cout << "\n\n\n";

	
	std::cout << "Exercise 2.\nThe program for raising to a degree.\n";
	/*
		Create a void type function that takes
	the address of a variable and some number. Variable,
	the address of which was transmitted is raised to a power
	equal to the transmitted number. The task must
	solve it without resorting to using the functions
	built into the C++ programming language.
	Code example with function call:
	int n = 10;
	func(&n, 3);
	std::cout << n; // on screen 1000
		
		Создайте функцию типа void, которая принимает 
	адрес переменной и какое-нибудь число. Переменная, 
	адрес которой был передан, возводится в степень, 
	равную переданному числу. Задачу необходимо
	решить, не прибегая к использованию функций,
	встроенных в язык программирования С++.
	Пример кода с вызовом функции:
	int n = 10;
	func(&n, 3);
	std::cout << n; // на экране 1000
	*/
	std::cout << "Enter the number to raise -> ";
	int num;
	std::cin >> num;
	int initial_num = num;
	std::cout << "Enter the degree -> ";
	int degree;
	std::cin >> degree;
	func(&num, degree);
	std::cout << initial_num << '^' << degree << " = " << num << "\n\n\n";




	return 0;
}

template<typename T>
void show_arr(T* arr, const int length) {
	std::cout << "[ ";
	bool first = true;
	for (size_t i = 0; i < length; i++){
		if (!first)
			std::cout << ", ";
		first = false;
		std::cout << *(arr + i) << ' ';
	}
	std::cout << " ]\n";
}

template<typename T>
void change_even_odd(T* arr, const int length) {
	int len = length;
	if (length % 2)
		len--;
	for (size_t i = 0; i < len; i+=2){
		T tmp = *(arr + i);
		*(arr + i) = *(arr + i + 1);
		*(arr + i + 1) = tmp;
	}
}

template <typename T>
void func(T* num, int degree) {
	T multiplicator = *num;
	if (!degree)
		*num = 1;
	else {
		while (--degree) {
			*num *= multiplicator;
		}
	}
}