// Rowan Simmons
// 11/29/2019
// Lab 9
// Palindrome.cpp: uses a stack to create a palindrome from user input

#include <iostream>
#include <string>
#include <stack>
#include "Palindrome.hpp"

//takes in string input and prints string as palindrome
void palindrome(std::string input)
{
	std::stack <char> palind;

	//output
	std::cout << "Palindrome is: " << std::endl;

	for (int i = 0; i < input.length(); i++)
	{
		palind.push(input[i]); //push on stack
	}
	//output
	std::cout << input;

	while (!palind.empty())
	{
		std::cout << palind.top(); 
		palind.pop(); //pop from stack
	}
	//output
	std::cout << " " << std::endl;
}