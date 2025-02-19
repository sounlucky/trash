// walker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <conio.h>
#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iomanip>
#include <functional>
#include <algorithm>

struct option {
	std::string name;
	std::function<void(void)> callback;
};

int my_getch() {
	auto true_getch = _getch();
	return true_getch == 224 ? _getch() : true_getch;
}

int main()
{
	std::vector<option> options{ 
		{"poi", []() {std::cout << "poshel (:" }},
		{"ne ", []() {std::cout << "ne poshel ):"; }},
		{"mult", []() {std::cout << "ne poshel ):"; }},
		{"exit", []() {std::exit(0); }}
	};

	auto current_option = 0;
	while (1) {
		//get input
		auto input = my_getch();

		//clear
		system("cls");
		
		//handle input
		switch (input) {
		case 0:
			//enter
			options[current_option].callback();
			std::cout << std::endl;
			system("pause");
			system("cls");
			break;
		case 72:
			//up
			current_option = (current_option - 1 + options.size()) % options.size();
			break;
		case 80:
			//down
			current_option = (current_option + 1) % options.size();
			break;
		default:
			break;
		};
			
		//redraw
		static auto max_option_size = 1 + std::max_element(options.cbegin(), options.cend(), [](const option& lhs, const option& rhs) { return lhs.name.size() < rhs.name.size(); })->name.size();
		for (auto i = 0; i != options.size(); ++i) {
			std::cout << std::endl;
			std::cout <<  std::right << std::setw(max_option_size)<< options[i].name << (current_option == i ? " <" : "");
			std::cout << std::endl;
		}
	}
}