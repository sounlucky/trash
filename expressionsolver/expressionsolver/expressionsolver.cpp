// expressionsolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> polinomial;

size_t& access(size_t i) {
	if (polinomial.size() < i) {
		polinomial.resize(i + 1);
	}
	return polinomial[i];
}

void parse(const char* str) {
	size_t start = 0, end = 0;
	while (str[start] != 0)
		while (str[start] != ' ') {

		}
}

int main()
{
	parse("x^5-x^4=x^3");
	bool nothing_yet = false;
	for (size_t i = 0; polinomial.size() != i; ++i) {
		if (polinomial[i] != 0) {
			std::cout << polinomial[i] << "x^" << i;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
