// Rowan Simmons
// 11/29/2019
// Project 9
// Description: Implement linear data structures using STL containers.
// Project 9.cpp: This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "Menu.hpp"
#include <limits>

//validate play or exit
void checkPlay(int* a)
{
	while (std::cin.fail() || std::cin.peek() != '\n' || *a < 1 || *a  > 2)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: " << std::endl;
		std::cin >> *a;
	}
}

//main function to start program
int main()
{
	int play;

	do
	{
		std::cout << "Enter 1 to play, 2 to quit: " << std::endl;
		std::cin >> play;
		checkPlay(&play);

		switch (play)
		{
		case 1: 
			menu();
			break;
		case 2:
			std::cout << "Goodbye." << std::endl;
			break;
		}
	} while (play != 2);

	return 0;
}
