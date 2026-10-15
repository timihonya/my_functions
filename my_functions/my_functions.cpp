#include "my_functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

long long power(int x, int n) {
	if (n == 0) return 1;
	return power(x, n - 1) * x;
}

void num_revert() {
	std::cout << "Введите длину цикла программы: ";
	short tries;
	std::cin >> tries;
	while (tries-- > 0) {
		int sysin, sysout;
		long long n_10 = 0;
		std::string n;
		std::cout << "Введите число, его систему счисления и целевую систему счисления через пробел (до 16)\n";
		std::cin >> n >> sysin >> sysout;
		std::cout << n << " (" << sysin << ") = ";
		std::reverse(n.begin(), n.end());
		for (int i = 0; i < n.size(); ++i) {
			char ch = char(n[i]);
			if (ch != '0') {
				if (ch >= '0' && ch <= '9') {
					n_10 += int(ch - '0') * power(sysin, i);
					std::cout << int(ch - '0') * power(sysin, i) << ((i == n.size() - 1) ? " = " : " + ");
				}
				else if (ch >= 'A' && ch <= 'F') {
					n_10 += (10 + int(ch - 17 - '0')) * power(sysin, i);
					std::cout << (10 + int(ch - 17 - '0')) * power(sysin, i) << ((i == n.size() - 1) ? " = " : " + ");
				}
				else {
					std::cout << " нет ";
					n_10 = 0;
					break;
				}
			}
		}
		std::cout << n_10 << " (" << 10 << ")\n";
		std::vector <int> ans;
		while (n_10 != 0) {
			std::cout << n_10 << " / " << sysout << " = " << n_10 / sysout << " (ост. " << n_10 % sysout << ")" << ((n_10 / sysout == 0) ? ".\n" : "; ");
			if (n_10 / sysout == 0) {
				ans.push_back(n_10);
				break;
			}
			ans.push_back(n_10 % sysout);
			n_10 /= sysout;
		}
		std::cout << "Ответ: ";
		for (int i = ans.size() - 1; i >= 0; --i) {
			if (ans[i] <= 9) {
				std::cout << ans[i];
			}
			else if (ans[i] >= 10 && ans[i] <= 15) {
				std::cout << char(65 + ans[i] % 10);
			}
		}
		std::cout << " (" << sysout << ")\n\n";
	}
	start();
}

void SQEquation() {
	int a, b, c, D;
	std::cout << "Введите коэффициенты через пробел: ";
	std::cin >> a >> b >> c;
	if (a == 0) {
		std::cout << "нет\n";
	}
	else {
		D = power(b, 2) - (4 * a * c);
		std::cout << "D = " << b << "² - 4 * " << a << " * " << c << " = " << D << "\n";
		if (D >= 0) {
			std::cout << "Два решения: " << (-b + sqrt(D)) / (2 * a) << "; " << (-b - sqrt(D)) / (2 * a) << ".\n\n";
		}
		else if (D == 0) {
			std::cout << "Одно решение: " << -b / (2 * a) << ".\n\n";
		}
		else {
			std::cout << "Решений нет.\n\n";
		}
	}
	start();
}

void binary_operations() {
	long long a, b;
	short op;
	std::vector <short> num1, num2;
	std::cout << "Введите первое число: ";
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Введите выполняемую операцию (1 - '+', 2 - '-', 3 - '*', 4 - '/'): ";
	std::cin >> op;
	while (a != 0 && b != 0) {
		if (a != 0) {
			num1.push_back(a % 10);
			a /= 10;
		}
		if (b != 0) {
			num2.push_back(b % 10);
			b /= 10;
		}
	}
	if (op == 1) {

	}
	else if (op == 2) {

	}
	else if (op == 3) {

	}
	else if (op == 4) {

	}
	else {
		std::cout << "ты что-то не то сделал\n";
		start();
	}
}

void start() {
	short ch;
	bool flag;
	std::cout << "закончить выполнение? 0/1: ";
	std::cin >> flag;
	if (!flag) {
		std::cout << "какую функцию вызвать?\n 1. num_revert   2. SQEquation   3. binary_operations\n";
		std::cin >> ch;
		if (ch == 1) {
			num_revert();
		}
		else if (ch == 2) {
			SQEquation();
		}
		else if (ch == 3) {
			binary_operations();
		}

	}
	else {
		std::cout << "окей";
	}
}