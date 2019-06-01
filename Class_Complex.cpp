#include <complex>
#include "pch.h"
#include <iostream>
# include <conio.h>;
#include <cmath.h>
#include <c.math>

using namespace std;

class Complex
{
private:
	double real, image;
public:
	Complex() { real = 0; image = 0; }
	Complex& operator+(const Complex & number) // Перегрузка +
	{
		/*number.real = real + number.real;
		number.image = image + number.image;*/
		return Complex(real + number.real, image + number.image);
	} // Перегрузка +
	Complex operator -(Complex &);
	Complex operator *(Complex &);
	Complex operator /(Complex &);
	friend istream &operator>>(istream &, Complex &); // Перегрузка функци-оператора для ввода
	friend ostream &operator<<(ostream &, Complex &);
	template<typename Char, typename Traits>
	friend basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& , Complex &); // перегрузка для вывода алгебраических действий
};

Complex Complex::operator+(Complex & number) // Перегрузка +
{
	/*number.real = real + number.real;
	number.image = image + number.image;*/
	return Complex(real + number.real, image + number.image);
}

Complex Complex::operator-(Complex & number)
{
	number.real = real - number.real;
	number.image = image - number.image;
	return Complex();
}

Complex Complex::operator*(Complex & number)
{
	double i, j;
	i = real * number.real - image * number.image;
	j = real * number.image + number.real * image;
	number.real = i;
	number.image = j;
	return Complex();
}

Complex Complex::operator/(Complex & number)
{
	double i, j, k;
	k = number.real * number.real + number.image * number.image;
	i = (real * number.real + image * number.image) / k;
	j = (number.real * image - real * number.image) / k;
	number.real = i;
	number.image = j;
	return Complex();
}

istream & operator>>(istream &in, Complex & numbers)
{
	/*cout << "Введите действительную часть: ";
	in >> numbers.real;
	cout << "Введите мнимую часть: ";
	in >> numbers.image;
	return in;*/
	in >> numbers.real >> numbers.image;
	return in;
}

ostream & operator<<(ostream &out, Complex &numbers)
{
	/*if (numbers.image < 0)
		out << numbers.real << "+i(" << numbers.image << ")\n";
	else out << numbers.real << "+i" << numbers.image << "\n";
	return out;*/
	out << "(" << numbers.real << ", " << numbers.image << ")";
	return out;
}

//template<typename Char, typename Traits>
//std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& out1, Complex &numbers)
//{
//	if (numbers.image < 0)
//		out1 << numbers.real << "+i(" << numbers.image << ")\n";
//	else out1 << numbers.real << "+i" << numbers.image << "\n";
//	return out1;
//}

int main()
{
	setlocale(LC_ALL, "Russian");
	/*Complex num1, num2;
	cout << "Введите первое комплексное число:" << '\n';
	cin >> num1;
	cout << "Введите второе комплексное число:" << '\n';
	cin >> num2;
	Complex out1;
	std::basic_ostream<char>& operator<<(std::basic_ostream<char>&, Complex &) std::cout << "Сумма комплексных чисел: " << (num1 + num2);
	cout.basic_ostream<char>& operator<<(std::basic_ostream<char>&, Complex &) << "Сумма комплексных чисел: " << (num1 + num2);
	std::basic_ostream<char, std::char_traits>&operator << cout << "Разность комплексных чисел: " << (num1 - num2);
	cout << "Произведение комплексных чисел: " << num1 * num2 << endl;
	cout << "Деление комплексных чисел: " << num1 / num2 << endl;*/

	Complex num1(5, 7);
	Complex num2()
	system("pause");
	return 0;
}
