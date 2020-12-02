// Rowan Simmons
// 11/29/2019
// Lab 9
// Menu.cpp: contains a menu for the user to test the buffer and create a palindrome, and input validation

#include <iostream>
#include <string>
#include <random>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include "Menu.hpp"
#include "Palindrome.hpp"
#include "Buffer.hpp"


//validate input for buffer or palindrome
void checkAnswer(int* a)
{
	while (std::cin.fail() || std::cin.peek() != '\n' || *a < 1 || *a  > 2)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: " << std::endl;
		std::cin >> *a;
	}
}

//validate input for buffer pecentages
void checkPercentage(int* a)
{
	while (std::cin.fail() || std::cin.peek() != '\n' || *a < 0 || *a  > 100)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: " << std::endl;
		std::cin >> *a;
	}
}

//validate input for number of rounds
void checkRounds(int* a)
{
	while (std::cin.fail() || std::cin.peek() != '\n' || *a < 1 || *a  > 100)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again: " << std::endl;
		std::cin >> *a;
	}
}

//goes here from main
//user input for buffer or palindrome
//For the queue, prompts the user to enter the two percentages, and the total number of rounds. Then, displays the results to the console in each round.
//For the stack, prompts the user to enter a string. Creates the palindrome and then displays it.
void menu()
{
	srand(static_cast<unsigned int>(time(NULL))); //for random number generator

	//variables
	int answer;
	int percentage_1;
	int percentage_2;
	int rounds;
	std::string input;
	int counter = 0;
	std::queue<int> buffQ;

	std::cout << "Enter 1 to test the buffer, or 2 to create a palindrome: " << std::endl;
	std::cin >> answer;
	checkAnswer(&answer);

	if (answer == 1) //test buffer function
	{
		std::cout << "Enter the first percentage (0-100). (ie 25 = 25%). This is the % chance to put a randomly generated number at the end of the buffer: " << std::endl;
		std::cin >> percentage_1;
		checkPercentage(&percentage_1);

		std::cout << "Enter the second percentage (0-100). (ie 25 = 25%). This is the % chance to take out a randomly generated number at the front of the buffer: " << std::endl;
		std::cin >> percentage_2;
		checkPercentage(&percentage_2);

		std::cout << "Enter the total number of rounds (1-100): " << std::endl;
		std::cin >> rounds;
		checkRounds(&rounds);

		//go to buffer function
		buffer(buffQ, percentage_1, percentage_2, rounds);
	}

	else if (answer == 2) //create a palindrome
	{
		//clear input
		std::cin.clear();
		std::cin.ignore();

		std::cout << "Enter a string: " << std::endl;
		std::getline(std::cin, input);

		//go to palindrome function
		palindrome(input);
	}
}