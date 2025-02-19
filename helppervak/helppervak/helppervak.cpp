// helppervak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream> 
#include <vector>

using namespace std;

std::vector<size_t> primes(1, 2);

bool is_prime(size_t number) {
	if (number < 2)
		return false;

	for (auto i : primes){
		if (number == i)
			return true;
		if (number % i == 0)
			return false;
	}

	primes.push_back(number);
	return true;
}

int main()
{
	for (size_t i = 2; i != -1; ++i) {
		if (is_prime(i) && is_prime(i / 10)) {
			std::cout << i << '\n';
		}
	}
}