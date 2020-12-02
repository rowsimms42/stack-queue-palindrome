// Rowan Simmons
// 11/29/2019
// Lab 9
// Buffer.cpp: Uses a queue to simulate a buffer from user input

#include <iostream>
#include <string>
#include <queue>
#include <random>
#include <ctime>
#include <cstdlib>
#include "Buffer.hpp"


//goes here from menu
//simulate buffer using queue
void buffer(std::queue<int> &buff, int percentage_1, int percentage_2, int rounds)
{
	std::queue<int> temp; //second queue to not affect first when printing
	double average = 0.0;
	//double pAverage;

	for (int i = 0; i < rounds; i++)
	{
		//Generate a random number from 1 – 1000 called N.
		int N = rand() % 1000 + 1; //random number generator

		//Appending number: Generate another random number from 1 – 100 
		int appending = rand() % 100 + 1;

		//Removing numbers: Generate another random number from 1 – 100
		int remove = rand() % 100 + 1;

		std::cout << "Round #" << i + 1 << ":" << " " << std::endl;

		//if the outcome is less than or equal to the user specified percentage for adding value(Ex : 25), then append the number N into the queue.
		if (appending <= percentage_1)
		{
			std::cout << "Pushed to buffer." << std::endl;
			//N goes into q
			buff.push(N);
		}
		else
		{
			std::cout << "Not pushed to buffer." << std::endl;
		}

		//if the outcome is less than or equal to the user specified percentage for removing value(Ex : 25), then remove a number from the front of queue.
		if (remove <= percentage_2 && !buff.empty())
		{
			std::cout << "Removed from buffer." << std::endl;
			//remove front of queue
			buff.pop();
		}
		else
		{
			std::cout << "Not removed from buffer." << std::endl;
		}

		//Output the values in the buffer
		//set temp to buff to not affect buff 
		temp = buff;

		std::cout << "Buffer contents: " << std::endl;
		while (!temp.empty())
		{
			std::cout << temp.front() << std::endl;
			temp.pop();
		}

		//output the length of the buffer.
		std::cout << "Length of buffer: " << buff.size() << std::endl;

		//Output the average length of buffer.
		average = (average * ((i + 1) - 1) + buff.size()) / (i + 1);
		std::cout << "Average length of buffer: " << average << std::endl;

		std::cout << " " << std::endl;
	}
}

